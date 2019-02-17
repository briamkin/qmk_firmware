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
#define _RAISE 1
#define _LOWER 2
#define _FN 3

enum custom_keycodes {
    P_MACRO = SAFE_RANGE
};

// GBP £ Macro (sends alt 156 - windows users only)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case P_MACRO:
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_KP_1));
                SEND_STRING(SS_TAP(X_KP_5));
                SEND_STRING(SS_TAP(X_KP_6));
                SEND_STRING(SS_UP(X_LALT));
                return false; break;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*/ Qwerty
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   '  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Shift |   `  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,   |   .  |  /   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Lower | _FN  | Alt  | Ctrl | GUI  |    Space    |Raise | Left | Down |  Up  |Right | 
     * `-----------------------------------------------------------------------------------'
     */
    [_DEFLT] = LAYOUT( \
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,      \
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,      \
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,  KC_ENT,      \
        KC_LSFT, KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,      \
        MO(_LOWER),MO(_FN),KC_LALT,KC_LCTL,KC_LGUI,KC_SPC,  KC_SPC,MO(_RAISE),KC_LEFT,   KC_DOWN,  KC_UP,  KC_RGHT       \
    ),

    /* Raise / Lower / FN all SAME!
     * ,-----------------------------------------------------------------------------------.
     * |  !   |  @   |  #   |   $  |  %   |  ^   |  &   |  *   |  {   |   }  |  |   |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  `   |      |      |      |      |      |      |      |  [   |   ]  |  \   |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  ~   |      |      |      |      |      |      |      |      |  Up  |  ;   |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      | Left | Down |Right |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  RGB |      |      |      |      |             |      | Bksp | Vol- | Vol+ |      |
     * `-----------------------------------------------------------------------------------'
     */

    [_RAISE] = LAYOUT( \
       KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_PIPE, _______,  \
       _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______,  \
       _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_UP, KC_SCLN, _______,  \
       _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PIPE,  \
       RGB_TOG, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, KC_VOLD, KC_VOLU, _______   \
    ),

    /* Raise / Lower / FN all SAME!
     * ,-----------------------------------------------------------------------------------.
     * |  !   |  @   |  #   |   $  |  %   |  ^   |  &   |  *   |  {   |   }  |  |   |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  `   |      |      |      |      |      |      |      |  [   |   ]  |  \   |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  ~   |      |      |      |      |      |      |      |      |  Up  |  ;   |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      | Left | Down |Right |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  RGB |      |      |      |      |             |      | Bksp | Vol- | Vol+ |      |
     * `-----------------------------------------------------------------------------------'
     */

    [_LOWER] = LAYOUT( \
       KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_PIPE, _______,  \
       _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______,  \
       _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_UP, KC_SCLN, _______,  \
       _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PIPE,  \
       RGB_TOG, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, KC_VOLD, KC_VOLU, _______   \
    ),

    /* Raise / Lower / FN all SAME!
     * ,-----------------------------------------------------------------------------------.
     * |  !   |  @   |  #   |   $  |  %   |  ^   |  &   |  *   |  {   |   }  |  |   |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  `   |      |      |      |      |      |      |      |  [   |   ]  |  \   |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  ~   |      |      |      |      |      |      |      |      |  Up  |  ;   |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      | Left | Down |Right |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  RGB |      |      |      |      |             |      | Bksp | Vol- | Vol+ |      |
     * `-----------------------------------------------------------------------------------'
     */
    
    [_FN] = LAYOUT( \
       KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_PIPE, _______,  \
       _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______,  \
       _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_UP, KC_SCLN, _______,  \
       _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PIPE,  \
       RGB_TOG, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, KC_VOLD, KC_VOLU, _______   \
    ),
};
