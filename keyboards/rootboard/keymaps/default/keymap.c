// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
        KC_X,    KC_F,    KC_D,    KC_P,    KC_Q,                               KC_J,    KC_QUOTE,    KC_O,    KC_U,    KC_DOT,
			     LCTL_T(KC_N),    LALT_T(KC_S),    LGUI_T(KC_T),    LSFT_T(KC_C),    KC_Y,                               KC_M,    LSFT_T(KC_H),    LGUI_T(KC_A),    LALT_T(KC_E),    LCTL_T(KC_I),
        KC_B,    KC_V,    KC_K,    KC_G,    KC_W,                               KC_Z,    KC_L,    KC_COMM, KC_DOT,  KC_COMM,
                             LT(2, KC_R), KC_BSPC, LT(1, KC_TAB),           LT(1, KC_Q),  KC_ENT,  KC_SPC
			     ),
    [1] = LAYOUT_split_3x5_3(
        KC_Q,    KC_1,    KC_2,    KC_3,    KC_T,                               KC_J,    KC_QUOTE,    KC_O,    KC_U,    KC_DOT,
        KC_A,    KC_4,    KC_5,    KC_6,    KC_G,                               KC_M,    KC_H,    KC_A,    KC_E,    KC_I,
        KC_Z,    KC_7,    KC_8,    KC_9,    KC_0,                               KC_Z,    KC_L,    KC_COMM, KC_DOT,  KC_COMM,
                             QK_BOOTLOADER  , KC_BSPC, KC_SPC,           LT(1, KC_Q),  KC_ENT,  QK_BOOTLOADER
			     ),

    [2] = LAYOUT_split_3x5_3(
        KC_COLON,    KC_LCBR,    KC_LT,    KC_RCBR,    KC_PIPE,                               KC_J,    KC_QUOTE,    KC_O,    KC_U,    KC_DOT,
        KC_EXLM,    KC_LPRN,    KC_SCLN,    KC_RPRN,    KC_QUES,                               KC_M,    KC_H,    KC_A,    KC_E,    KC_I,
        KC_Z,    KC_LEFT_BRACKET,    KC_GT,    KC_RIGHT_BRACKET,    KC_0,                               KC_Z,    KC_L,    KC_COMM, KC_DOT,  KC_COMM,
                             QK_BOOTLOADER  , KC_BSPC, KC_SPC,           LT(1, KC_Q),  KC_ENT,  QK_BOOTLOADER
    )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
