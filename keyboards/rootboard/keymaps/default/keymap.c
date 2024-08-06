// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    MAGIC = SAFE_RANGE
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
        KC_X,         KC_F,         KC_D,         KC_P,         KC_J,                    MAGIC,          KC_G,         KC_O,         KC_U,         KC_COMM,
	LCTL_T(KC_N), LALT_T(KC_S), LGUI_T(KC_T), LSFT_T(KC_L), KC_W,                    KC_Y,          LSFT_T(KC_H), LGUI_T(KC_A), LALT_T(KC_E), LCTL_T(KC_I),
        KC_B,         KC_V,         KC_K,         KC_M,         KC_Q,                    KC_Z,          KC_C,         KC_QUOT,      KC_SLASH,     KC_DOT,
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

uint16_t predecessor_key = KC_NO;
uint16_t adaptive_key = KC_NO;
bool send = true;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    send = false;
    uprintf("KL: kc: 0x%04X", keycode);
    dprintf("KL: kc: 0x%04X", keycode);
    if (keycode == KC_F) {
        if (record->event.pressed) {
            adaptive_key = keycode;
            switch (predecessor_key) {
                case KC_C: register_code(KC_H); keycode = KC_H; adaptive_key = KC_H; send = false; break;
                case KC_P: register_code(KC_L); keycode = KC_L; adaptive_key = KC_L; send = false; break;
            }
		}
		else {
			unregister_code(adaptive_key);
		}
	}
    else if (keycode == KC_V) {
        if (record->event.pressed) {
            adaptive_key = keycode;
            switch (predecessor_key) {
                case KC_M: register_code(KC_P); keycode = KC_P; adaptive_key = KC_P; send = false; break;
                case KC_C: register_code(KC_Y); keycode = KC_Y; adaptive_key = KC_Y; send = false; break;
            }
		}
		else {
			unregister_code(adaptive_key);
		}
	}
    else if (keycode == KC_B) {
        if (record->event.pressed) {
            adaptive_key = keycode;
            switch (predecessor_key) {
                case KC_G: register_code(KC_H); keycode = KC_H; adaptive_key = KC_H; send = false; break;
            }
		}
		else {
			unregister_code(adaptive_key);
		}
	}
    else if ((keycode & 0xff) == KC_H) {
        if (record->event.pressed) {
            adaptive_key = keycode;
            switch (predecessor_key) {
                case KC_U: register_code(KC_E); keycode = KC_E; adaptive_key = KC_E; send = false; break;
                case KC_L: register_code(KC_P); keycode = KC_P; adaptive_key = KC_P; send = false; break;
                case KC_G: register_code(KC_B); keycode = KC_B; adaptive_key = KC_B; send = false; break;
            }
		}
		else {
			unregister_code(adaptive_key);
		}
	}
    else if (keycode == KC_P) {
        if (record->event.pressed) {
            adaptive_key = keycode;
            switch (predecessor_key) {
                case KC_H: register_code(KC_Y); keycode = KC_Y; adaptive_key = KC_Y; send = false; break;
                case KC_M: register_code(KC_V); keycode = KC_V; adaptive_key = KC_V; send = false; break;
                case KC_L: register_code(KC_H); keycode = KC_H; adaptive_key = KC_H; send = false; break;
            }
		}
		else {
			unregister_code(adaptive_key);
		}
	}
    else if ((keycode & 0xff) == KC_E) {
        if (record->event.pressed) {
            adaptive_key = keycode;
            switch (predecessor_key) {
                case KC_U: register_code(KC_H); keycode = KC_H; adaptive_key = KC_H; send = false; break;
            }
		}
		else {
			unregister_code(adaptive_key);
		}
	}
    else if (keycode == KC_Y) {
        if (record->event.pressed) {
            adaptive_key = keycode;
            switch (predecessor_key) {
                case KC_C: register_code(KC_V); keycode = KC_V; adaptive_key = KC_V; send = false; break;
            }
		}
		else {
			unregister_code(adaptive_key);
		}
	}


	if (record->event.pressed) {
        predecessor_key = keycode & 0xff;
	}

    return send;
}


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}
