// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    FMAGIC = SAFE_RANGE,
    PMAGIC,
    XMAGIC,
    YMAGIC,
    HMAGIC,
    EMAGIC,
    BMAGIC,
    VMAGIC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │GUI├───┐           ┌───┤Alt│
      *           └───┤Bsp├───┐   ┌───┤Ent├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */
    [0] = LAYOUT_split_3x5_3(
        KC_X,         FMAGIC,         KC_D,         PMAGIC,         KC_J,                    XMAGIC,          KC_G,         KC_O,         KC_U,         KC_COMM,
	LCTL_T(KC_N), LALT_T(KC_S), LGUI_T(KC_T), LSFT_T(KC_L), KC_W,                    YMAGIC,          LSFT_T(HMAGIC), LGUI_T(KC_A), LALT_T(EMAGIC), LCTL_T(KC_I),
        BMAGIC,         VMAGIC,         KC_K,         KC_M,         KC_Q,                    KC_Z,          KC_C,         KC_QUOT,      KC_SLASH,     KC_DOT,
                                    LT(2, KC_R),  KC_BSPC,      LT(1, KC_TAB),           LT(2, KC_DOT), KC_ENT,       LT(1, KC_SPC)
			     ),
    [1] = LAYOUT_split_3x5_3(
        KC_Q,    KC_1,    KC_2,    KC_3,    KC_T,                               KC_J,    KC_QUOTE,   KC_UP,    KC_U,    KC_DOT,
        KC_SCLN,    KC_4,    KC_5,    KC_6,    KC_EQUAL,                               KC_M,    KC_LEFT,    KC_DOWN,    KC_RIGHT,    KC_I,
        KC_Z,    KC_7,    KC_8,    KC_9,    KC_0,                               KC_Z,    KC_LSFT,    KC_LCTL, KC_LALT,  KC_COMM,
                             QK_BOOTLOADER  , KC_BSPC, KC_SPC,           LT(1, KC_Q),  KC_ENT,  QK_BOOTLOADER
			     ),

    [2] = LAYOUT_split_3x5_3(
        KC_COLON, KC_LCBR,         KC_LT,         KC_RCBR,          KC_PIPE,          KC_J,    KC_QUOTE,    KC_UP,    KC_U,    KC_DOT,
	KC_MINUS, KC_LPRN,         KC_SCLN,       KC_RPRN,          KC_QUES,          KC_M,    KC_LSFT,    KC_LALT,    KC_RIGHT,    KC_I,
        KC_EXLM,  KC_LEFT_BRACKET, KC_GT,         KC_RIGHT_BRACKET, KC_DOT,           KC_Z,    KC_L,    KC_COMM, KC_DOT,  KC_COMM,
                                   QK_BOOTLOADER, KC_BSPC,          KC_SPC,           LT(1, KC_Q),  KC_ENT,  KC_ESC
    )
};

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case FMAGIC:
        case PMAGIC:
        case XMAGIC:
        case YMAGIC:
        case HMAGIC:
        case EMAGIC:
        case BMAGIC:
        case VMAGIC:
            return false;  // Ignore ALTREP keys.
    }

    return true;  // Other keys can be repeated.
}

static void process_fmagic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_C: SEND_STRING("h"); break;
        case KC_P: SEND_STRING("l"); break;
        default: SEND_STRING("f"); break;
    }
}

static void process_pmagic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_M: SEND_STRING("v"); break;
        case KC_L: SEND_STRING("h"); break;
        case KC_H: SEND_STRING("y"); break;
        default: SEND_STRING("p"); break;
    }
}

static void process_vmagic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_M: SEND_STRING("p"); break;
        case KC_C: SEND_STRING("y"); break;
        default: SEND_STRING("v"); break;
    }
}

static void process_bmagic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_G: SEND_STRING("h"); break;
        default: SEND_STRING("b"); break;
    }
}

static void process_ymagic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_C: SEND_STRING("v"); break;
        default: SEND_STRING("y"); break;
    }
}

static void process_hmagic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_U: SEND_STRING("e"); break;
        case KC_L: SEND_STRING("p"); break;
        case KC_C: SEND_STRING("f"); break;
        case KC_G: SEND_STRING("b"); break;
        default: SEND_STRING("h"); break;
    }
}

static void process_emagic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_U: SEND_STRING("h"); break;
        default: SEND_STRING("e"); break;
    }
}

static void process_bmagic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_G: SEND_STRING("h"); break;
        default: SEND_STRING("b"); break;
    }
}

static void process_xmagic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_P: SEND_STRING("f"); break;
        case KC_H: SEND_STRING("p"); break;
        case KC_O: SEND_STRING("a"); break;
        case KC_U: SEND_STRING("e"); break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case FMAGIC: 
            if (record->event.pressed) {
                process_fmagic(get_last_keycode(), get_last_mods());
            }
            return false;
        case PMAGIC: 
            if (record->event.pressed) {
                process_pmagic(get_last_keycode(), get_last_mods());
            }
            return false;
        case XMAGIC: 
            if (record->event.pressed) {
                process_xmagic(get_last_keycode(), get_last_mods());
            }
            return false;
        case YMAGIC: 
            if (record->event.pressed) {
                process_ymagic(get_last_keycode(), get_last_mods());
            }
            return false;
        case HMAGIC: 
            if (record->event.pressed) {
                process_hmagic(get_last_keycode(), get_last_mods());
            }
            return false;
        case EMAGIC: 
            if (record->event.pressed) {
                process_emagic(get_last_keycode(), get_last_mods());
            }
            return false;
        case BMAGIC: 
            if (record->event.pressed) {
                process_bmagic(get_last_keycode(), get_last_mods());
            }
            return false;
        case VMAGIC: 
            if (record->event.pressed) {
                process_vmagic(get_last_keycode(), get_last_mods());
            }
            return false;
    }

    return true;
}


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}
