#include "kb.h"

extern bool is_ps2_mode(void);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Layer 0 – Colemak + embedded numpad
    [0] = LAYOUT(
        QK_GESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,  KC_F10, KC_F11,  KC_F12,          KC_NUM, TG(1),   KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,    KC_F,    KC_P,    KC_G,     KC_7,   KC_8,   KC_9,   KC_SLSH, KC_J,   KC_L,   KC_U,    KC_Y,   KC_SCLN, KC_LBRC, KC_RBRC,
        KC_BSPC, KC_A,     KC_R,    KC_S,    KC_T,    KC_D,     KC_4,   KC_5,   KC_6,   KC_ASTR, KC_H,   KC_N,   KC_E,    KC_I,   KC_O,    KC_QUOT, KC_BSLS,
        KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_1,   KC_2,   KC_3,   KC_MINS, KC_K,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI,  KC_LALT, MO(4),            KC_SPC,   KC_0,   KC_DOT, KC_ENT, KC_EQL,  KC_SPC,          KC_APP, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Layer 1 – QWERTY
    [1] = LAYOUT(
        KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC,
        KC_TRNS, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_BSLS,
        KC_TRNS, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_APP, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Layer 2 – Numpad (numpad keycodes on the embedded block)
    [2] = LAYOUT(
        KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_P7,  KC_P8,  KC_P9,  KC_PSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_P4,  KC_P5,  KC_P6,  KC_PAST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_P1,  KC_P2,  KC_P3,  KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS,  KC_P0,  KC_PDOT, KC_PENT, KC_PPLS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // Layer 3 – F13-F24
    [3] = LAYOUT(
        KC_TRNS,           KC_F13,  KC_F14,  KC_F15,  KC_F16,   KC_F17, KC_F18, KC_F19, KC_F20,  KC_F21, KC_F22, KC_F23, KC_F24,           KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // Layer 4 – FN
    [4] = LAYOUT(
        KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_DEL,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  TO(4),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_MPRV,  KC_MPLY, KC_MNXT, KC_PSCR, KC_TRNS,  TO(1),  TO(2),  TO(3),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,          KC_ENT,   TO(0),  KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0: oled_write_P(PSTR("COLEMAK\n"), false); break;
        case 1: oled_write_P(PSTR("QWERTY\n"),  false); break;
        case 2: oled_write_P(PSTR("NUMPAD\n"),  false); break;
        case 3: oled_write_P(PSTR("F13-F24\n"), false); break;
        case 4: oled_write_P(PSTR("FN\n"),      false); break;
        default: oled_write_ln_P(PSTR("???"),   false); break;
    }

    // Show mode (USB vs PS/2) and LED state
    oled_write_P(is_ps2_mode() ? PSTR("PS/2 ") : PSTR("USB  "), false);
    led_t leds = host_keyboard_led_state();
    oled_write_P(leds.num_lock    ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(leds.caps_lock   ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(leds.scroll_lock ? PSTR("SCR")  : PSTR("   "),  false);
    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}
#endif


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
    }
    return false;
}
