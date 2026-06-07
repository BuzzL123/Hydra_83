#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25

#define NO_USB_STARTUP_CHECK true

/* Shared PS/2 Port Pins */
#define PS2_CLOCK_PIN   GP25
#define PS2_DATA_PIN    GP24
#define MODE_SWITCH_PIN GP23

/* OLED */
#ifdef OLED_ENABLE
#define I2C1_SDA_PIN        GP26
#define I2C1_SCL_PIN        GP27
#define I2C_DRIVER          I2CD1
#define OLED_DISPLAY_128X32
#define OLED_BRIGHTNESS     128
#endif

/* GPIO Compatibility Shims for Modern QMK API */
#define setPinInput(pin)         gpio_set_pin_input(pin)
#define setPinInputHigh(pin)     gpio_set_pin_input_high(pin)
#define setPinInputLow(pin)      gpio_set_pin_input_low(pin)
#define setPinOutput(pin)        gpio_set_pin_output(pin)
#define writePinHigh(pin)        gpio_write_pin_high(pin)
#define writePinLow(pin)         gpio_write_pin_low(pin)
#define readPin(pin)             gpio_read_pin(pin)
#define togglePin(pin)           gpio_toggle_pin(pin)
