/*
Base Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>
Modified 2017 Andrew Novak <ndrw.nvk@gmail.com>
Modified 2018 Wayne Jones (WarmCatUK) <waynekjones@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public LicensezZZ
along with Thiszq   1wqis program.  If not, see <http://www.gnu.org/licenses/>.
*/ 
#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "rgblight.h"

#define ______ KC_TRNS
#define _DEFLT 0
#define _FN 1

enum custom_keycodes {
    P_MACRO = SAFE_RANGE
};

// GBP £ Macro (sends alt 156 - windows users only)
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (record->event.pressed) {
//         switch(keycode) {
//             case P_MACRO:
//                 SEND_STRING(SS_DOWN(X_LALT));
//                 SEND_STRING(SS_TAP(X_KP_1));
//                 SEND_STRING(SS_TAP(X_KP_5));
//                 SEND_STRING(SS_TAP(X_KP_6));
//                 SEND_STRING(SS_UP(X_LALT));
//                 return false; break;
//         }
//     }
//     return true;
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*/ Qwerty
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  | 
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   '  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+ Enter|
     * |    Shift    |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,   |   .  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | _FN  | Ctrl | Alt  |     GUI     |    Space    |Raise | Left |Right |  Up  | Down | 
     * `-----------------------------------------------------------------------------------'
     */
    [_DEFLT] = LAYOUT( \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,      \
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,      \
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,  KC_ENT,      \
        KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_ENT,      \
        MO(_FN), KC_LCTL,KC_LALT,KC_LGUI,KC_LGUI,  KC_SPC,  KC_SPC, MO(_FN), KC_LEFT,    KC_RGHT,  KC_UP,  KC_DOWN       \
    ),

    /* FN
     * ,-----------------------------------------------------------------------------------.
     * |      |  !   |  @   |  #   |   $  |  %   |  ^   |  &   |  *   |  {   |   }  |  =   |   
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | RGB  | RGB  | RGB  |      |      |      |      |  Up  |  [   |   ]  |  |   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | RGB  | RGB  | RGB  |      |      |      | Left | Down |Right |   ;  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+  /   |
     * |             | RGB  | RGB  |      |      |      |      |  -   |  +   |   =  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |             |             |      |      | Vol- | Vol+ |      |
     * `-----------------------------------------------------------------------------------'
     */
    
    [_FN] = LAYOUT( \
       _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR,  KC_EQL,  \
       _______, RGB_VAD, RGB_MOD, RGB_HUI, _______, _______, _______, _______,   KC_UP, KC_LBRC, KC_RBRC, KC_PIPE,  \
       _______, RGB_TOG, RGB_SAI, RGB_HUD, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, _______,  \
       _______, _______, RGB_SAD, RGB_VAI, _______, _______, _______, KC_MINS, KC_PLUS,  KC_EQL, _______, _______,  \
       _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______   \
    )
};
