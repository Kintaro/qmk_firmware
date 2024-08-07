// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
  MM_C = SAFE_RANGE,
  MM_P
  // More custom keycodes...
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
        KC_X,         KC_F,         KC_D,         OSL(2),         KC_J,                    KC_ESC,        OSL(4),         OSL(8),         OSL(5),         KC_COMM,
	    LCTL_T(KC_N), LALT_T(KC_S), LGUI_T(KC_T), OSL(6), KC_W,                    KC_Y,          OSL(7), LGUI_T(KC_A), LALT_T(KC_E), LCTL_T(KC_I),
        KC_B,         KC_V,         KC_K,         OSL(3),         KC_Q,                    KC_Z,          OSL(1),         KC_QUOT,      KC_SLASH,     KC_DOT,
                                    LT(9, KC_R),  KC_BSPC,      LT(11, KC_TAB),           LT(10, KC_DOT), KC_ENT,       LSFT_T(KC_SPC)
			     ),
    // C
    [1] = LAYOUT_split_3x5_3(
        _______,      KC_H,         _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
	    _______,      _______,      _______,      _______,      _______,                 KC_V,          KC_F,         _______,      _______,      _______,
        _______,      KC_Y,         _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
                                    LT(2, KC_R),  KC_BSPC,      LT(11, KC_TAB),           LT(2, KC_DOT), KC_ENT,       LT(1, KC_SPC)
			     ),
    // P
    [2] = LAYOUT_split_3x5_3(
        _______,      KC_L,         _______,      _______,      _______,                 KC_F,          _______,      _______,      _______,      _______,
	    _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
                                    LT(2, KC_R),  KC_BSPC,      LT(11, KC_TAB),           LT(2, KC_DOT), KC_ENT,       LT(1, KC_SPC)
			     ),
    // M
    [3] = LAYOUT_split_3x5_3(
        _______,      _______,      _______,      KC_V,         _______,                 _______,       _______,      _______,      _______,      _______,
	    _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
        _______,      KC_P,         _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
                                    LT(2, KC_R),  KC_BSPC,      LT(11, KC_TAB),           LT(2, KC_DOT), KC_ENT,       LT(1, KC_SPC)
			     ),
    // G
    [4] = LAYOUT_split_3x5_3(
        _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
	    _______,      _______,      _______,      _______,      _______,                 KC_B,          _______,      _______,      _______,      _______,
        KC_H,         _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
                                    LT(2, KC_R),  KC_BSPC,      LT(11, KC_TAB),           LT(2, KC_DOT), KC_ENT,       LT(1, KC_SPC)
			     ),
    // U
    [5] = LAYOUT_split_3x5_3(
        _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
	    _______,      _______,      _______,      _______,      _______,                 _______,       KC_E,         _______,      KC_H,         _______,
        _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
                                    LT(2, KC_R),  KC_BSPC,      LT(11, KC_TAB),           LT(2, KC_DOT), KC_ENT,       LT(1, KC_SPC)
			     ),
    // L
    [6] = LAYOUT_split_3x5_3(
        _______,      _______,      _______,      KC_H,         _______,                 KC_W,          _______,      _______,      _______,      _______,
	    _______,      _______,      _______,      _______,      _______,                 _______,       KC_P,         _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
                                    LT(2, KC_R),  KC_BSPC,      LT(11, KC_TAB),           LT(2, KC_DOT), KC_ENT,       LT(1, KC_SPC)
			     ),
    // H
    [7] = LAYOUT_split_3x5_3(
        _______,      _______,      _______,      KC_Y,         _______,                 KC_P,          _______,      _______,      _______,      _______,
	    _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
                                    LT(2, KC_R),  KC_BSPC,      LT(11, KC_TAB),           LT(2, KC_DOT), KC_ENT,       LT(1, KC_SPC)
			     ),
    // O
    [8] = LAYOUT_split_3x5_3(
        _______,      _______,      _______,      _______,      _______,                 KC_A,          _______,      _______,      _______,      _______,
	    _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
                                    LT(2, KC_R),  KC_BSPC,      LT(11, KC_TAB),           LT(2, KC_DOT), KC_ENT,       LT(1, KC_SPC)
			     ),
    // Symbols
    [9] = LAYOUT_split_3x5_3(
        KC_ESC,       LSFT(KC_LBRC),LSFT(KC_COMM),LSFT(KC_RBRC), KC_EQL,                 _______,       _______,      KC_UP,      _______,      _______,
	    KC_GRV,       LSFT(KC_9),   KC_SCLN,      LSFT(KC_0),    KC_MINUS,               _______,       KC_LEFT,      KC_DOWN,    KC_RIGHT,     _______,
        _______,      KC_LBRC,      LSFT(KC_DOT), KC_RBRC,       KC_BSLS,                _______,       _______,      _______,    _______,      _______,
                                    KC_LSFT,      _______,       _______,                _______,       _______,      _______
			     ),
    // Num
    [10] = LAYOUT_split_3x5_3(
        _______,      KC_1,      KC_2,      KC_3,      _______,                 _______,       _______,      _______,      _______,      _______,
	    _______,      KC_4,      KC_5,      KC_6,      _______,                 _______,       _______,      _______,      _______,      _______,
        _______,      KC_7,      KC_8,      KC_9,      _______,                 _______,       _______,      _______,      _______,      _______,
                                 KC_0,      _______,   _______,                 _______,       _______,      _______
			     ),
    [11] = LAYOUT_split_3x5_3(
        _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
	    _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
                                    QK_BOOT,  KC_BSPC,          LT(11, KC_TAB),          LT(2, KC_DOT), KC_ENT,       LT(1, KC_SPC)
			     ),
};

bool oneshot = false;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case OSL(1):
        if (record->event.pressed) tap_code16(KC_C);
        return true;
    case OSL(2):
        if (record->event.pressed) tap_code16(KC_P);
        return true;
      case OSL(3):
        if (record->event.pressed) tap_code16(KC_M);
        return true;
      case OSL(4):
        if (record->event.pressed) tap_code16(KC_G);
        return true;
      case OSL(5):
        if (record->event.pressed) tap_code16(KC_U);
        return true;
      case OSL(6):
        if (record->event.pressed) tap_code16(KC_L);
        return true;
      case OSL(7):
        if (record->event.pressed) tap_code16(KC_H);
        return true;
      case OSL(8):
        if (record->event.pressed) tap_code16(KC_O);
        return true;
  }   

  return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
