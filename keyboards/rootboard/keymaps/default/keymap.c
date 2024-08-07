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
        KC_X,         KC_F,         KC_D,         OSL(2),         KC_J,                    KC_ESC,        KC_G,         KC_O,         KC_U,         KC_COMM,
	    LCTL_T(KC_N), LALT_T(KC_S), LGUI_T(KC_T), LSFT_T(KC_L), KC_W,                    KC_Y,          LSFT_T(KC_H), LGUI_T(KC_A), LALT_T(KC_E), LCTL_T(KC_I),
        KC_B,         KC_V,         KC_K,         KC_M,         KC_Q,                    KC_Z,          OSL(1),         KC_QUOT,      KC_SLASH,     KC_DOT,
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
        _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
	    _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
                                    LT(2, KC_R),  KC_BSPC,      LT(11, KC_TAB),           LT(2, KC_DOT), KC_ENT,       LT(1, KC_SPC)
			     ),
    // Num
    [10] = LAYOUT_split_3x5_3(
        _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
	    _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,                 _______,       _______,      _______,      _______,      _______,
                                    LT(2, KC_R),  KC_BSPC,      LT(11, KC_TAB),           LT(2, KC_DOT), KC_ENT,       LT(1, KC_SPC)
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
