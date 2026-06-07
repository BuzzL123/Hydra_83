#include "kb.h"
#include "ps2_keyboard.h"
#include "print.h"
#include "host.h"

static bool usb_mode = true;
static bool last_mode = true;
static host_driver_t *original_usb_driver = NULL;

bool is_usb_mode(void) { return usb_mode; }
bool is_ps2_mode(void) { return !usb_mode; }

/* * GCC Linker Wrappers
 * These intercept QMK's core calls to the mouse driver.
 * They only allow the mouse driver to run if we are in USB mode.
 */
void __real_ps2_mouse_init(void);
void __wrap_ps2_mouse_init(void) {
    if (usb_mode) {
        __real_ps2_mouse_init();
    }
}

void __real_ps2_mouse_task(void);
void __wrap_ps2_mouse_task(void) {
    if (usb_mode) {
        __real_ps2_mouse_task();
    }
}

void keyboard_pre_init_kb(void) {
    setPinInputHigh(MODE_SWITCH_PIN);
    wait_ms(10); // Allow the pin state to stabilize

    // Read the switch immediately so we know the mode BEFORE core initialization runs
    usb_mode = readPin(MODE_SWITCH_PIN);
    last_mode = usb_mode;

    keyboard_pre_init_user();
}

void keyboard_post_init_kb(void) {
    keyboard_post_init_user();
}

void housekeeping_task_kb(void) {
    static uint32_t mode_change_time = 0;
    bool current_mode = readPin(MODE_SWITCH_PIN);

    if (current_mode != last_mode) {
        if (mode_change_time == 0) {
            mode_change_time = timer_read32();
        } else if (timer_elapsed32(mode_change_time) > 50) {
            last_mode = current_mode;
            usb_mode  = current_mode;
            mode_change_time = 0;

            uprintf("Mode switch: %s\n", usb_mode ? "USB" : "PS/2");

            if (!usb_mode) {
                // --- Switching from USB to PS/2 Device Mode ---
                if (original_usb_driver == NULL) {
                    original_usb_driver = host_get_driver();
                }
                clear_keyboard();
                wait_ms(20);

                // The mouse task wrapper will now automatically ignore calls.
                // Safely hand the pins over to your custom keyboard device code.
                ps2_keyboard_init(PS2_CLOCK_PIN, PS2_DATA_PIN);
                host_set_driver(&ps2_keyboard_host_driver);
            } else {
                // --- Switching from PS/2 Device Mode back to USB Mode ---
                ps2_keyboard_typematic_disable();
                if (original_usb_driver != NULL) {
                    host_set_driver(original_usb_driver);
                }
                wait_ms(20);
                clear_keyboard();
                send_keyboard_report();
                wait_ms(20);

                // Wake up and re-initialize the native QMK mouse host driver
                __real_ps2_mouse_init();
            }
        }
    } else {
        mode_change_time = 0;
    }

    if (!usb_mode) {
        ps2_keyboard_task();
    }

    housekeeping_task_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!usb_mode && host_get_driver() != &ps2_keyboard_host_driver) {
        host_set_driver(&ps2_keyboard_host_driver);
    }
    if (!process_record_user(keycode, record)) return false;
    return true;
}

bool led_update_kb(led_t led_state) {
    if (!usb_mode) return false;
    return led_update_user(led_state);
}

void matrix_init_kb(void) { matrix_init_user(); }
void matrix_scan_kb(void) { matrix_scan_user(); }
