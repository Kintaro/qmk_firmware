// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "print.h"

enum custom_keycodes {
  FMAGIC = SAFE_RANGE,
  VMAGIC,
  BMAGIC,
  HMAGIC,
  PMAGIC,
  EMAGIC,
  YMAGIC,
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
        KC_X,         FMAGIC,         KC_D,         PMAGIC,         KC_J,                    QK_AREP,          KC_G,         KC_O,         KC_U,         KC_COMM,
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

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case PMAGIC: return KC_F; break;
        case KC_O: return KC_A; break;
        case KC_U: return KC_E; break;
        case KC_L: return KC_W; break;
    }

    return KC_TRNS;
}

static void process_f_magic(uint16_t keycode, uint8_t mods, keyrecord_t* record) {
    if (record->event.pressed) {
    switch (keycode) {
        case KC_C: SEND_STRING("h"); break;
        case KC_P: SEND_STRING("l"); break;
        default: set_last_keycode("FMAGIC"); SEND_STRING("f"); break;    
    }
    }
}

static void process_v_magic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_M: SEND_STRING("p"); break;
        case KC_C: SEND_STRING("y"); break;
        default: SEND_STRING("v"); break; 
    }
}

static void process_b_magic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_G: SEND_STRING("h"); break;
        default: SEND_STRING("b"); break; 
    }
}

static void process_h_magic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_U: SEND_STRING("e"); break;
        case KC_L: SEND_STRING("p"); break;
        default: SEND_STRING("h"); break; 
    }
}

static void process_p_magic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_H: SEND_STRING("y"); break;
        default: SEND_STRING("p"); break; 
    }
}

static void process_e_magic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_U: SEND_STRING("h"); break;
        default: SEND_STRING("e"); break; 
    }
}

static void process_y_magic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_C: SEND_STRING("v"); break;
        default: SEND_STRING("y"); break; 
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    dprintf("%i record user", keycode);
  switch (keycode) {
        case FMAGIC: { process_f_magic(get_last_keycode(), get_last_mods(), record);  } return false;
        case VMAGIC: { process_v_magic(get_last_keycode(), get_last_mods());  } return false;
        case BMAGIC: { process_b_magic(get_last_keycode(), get_last_mods());  } return false;
        case HMAGIC: { process_h_magic(get_last_keycode(), get_last_mods());  } return false;
        case PMAGIC: { process_p_magic(get_last_keycode(), get_last_mods());  } return false;
        case EMAGIC: { process_e_magic(get_last_keycode(), get_last_mods());  } return false;
        case YMAGIC: { process_y_magic(get_last_keycode(), get_last_mods());  } return false;
        }

    return true;
}


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
