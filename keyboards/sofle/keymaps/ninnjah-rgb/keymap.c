 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
  * 
  * This program is free software: you can redistribute it and/or modify 
  * it under the terms of the GNU General Public License as published by 
  * the Free Software Foundation, either version 2 of the License, or 
  * (at your option) any later version. 
  * 
  * This program is distributed in the hope that it will be useful, 
  * but WITHOUT ANY WARRANTY; without even the implied warranty of 
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
  * GNU General Public License for more details. 
  * 
  * You should have received a copy of the GNU General Public License 
  * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
  */ 

#include QMK_KEYBOARD_H
#include "oled.c"
#include "rgb.c"

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD,   KC_VOLU),           ENCODER_CCW_CW(KC_WH_D,   KC_WH_U) },
    [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [3] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
    [4] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |-------.  E  ,-------|   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------| VolUp |< N >| Pg Up |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |-------.  C  ,-------|   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------| Mute  |< O >|       |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.  D  ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| VolDn |< E >| Pg Dn |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|  R  |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /      \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /        \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /          \      \ |      |      |      |      |
 *            `-----------------------------------'            '------''---------------------------'
 */

[0] = LAYOUT(
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MNXT,    KC_MPLY,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
             KC_LCMD, KC_LCTL, KC_LALT,   MO(1),  KC_SPC,                          KC_ENT,   MO(1),    KC_MINS, KC_EQL,  KC_RCMD
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |-------.  E  ,-------|  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|       |< N >|       |------+------+------+------+------+------|
 * |  \   |PRINTS|      |      |      | TG(2)|-------.  C  ,-------|CTK-L | HOME |  UP  | END  |DELETE| F12  |
 * |------+------+------+------+------+------|       |< O >|       |------+------+------+------+------+------|
 * |      |INSERT|      |      |      | F13  |-------.  D  ,-------|CTL-R | LEFT | DOWN |RIGHT |      |      |
 * |------+------+------+------+------+------|       |< E >|       |------+------+------+------+------+------|
 * |      |DELETE|      |      |      | F14  |-------|  R  |-------| PGUP |PGDOWN|      |      |      |      |
 * `-----------------------------------------/       /      \      \-----------------------------------------'
 *            | TG(2)|      |      |      | /       /        \      \  |      |      |      |      |
 *            |      |      |      |      |/       /          \      \ |      |      |      |      |
 *            `-----------------------------------'            '------''---------------------------'
 */

[1] = LAYOUT(
     KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                            KC_F6,    KC_F7,   KC_F8,   KC_F9,    KC_F10,    KC_F11,
    KC_BSLS, KC_PSCR,  _______,  _______,  _______,    TG(2),                      RCTL(KC_LEFT),  KC_HOME, KC_UP,   KC_END,   KC_DELETE, KC_F12,
    _______,  KC_INS,  _______,  _______,  _______,  _______,                     RCTL(KC_RIGHT),  KC_LEFT, KC_DOWN, KC_RIGHT, _______,   _______,
    _______,  KC_DEL,  _______,  _______,  _______,  _______,    _______,    _______,    KC_PGUP,  KC_PGDN, _______, _______,  _______,   _______,
             _______,  _______,  _______,  _______,  _______,                            _______,  _______, _______, _______,  _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |-------.  E  ,-------|  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|       |< N >|       |------+------+------+------+------+------|
 * |      |      |      |  UP  |      |      |-------.  C  ,-------|CTK-L |  7   |  8   |  9   |      | F12  |
 * |------+------+------+------+------+------|       |< O >|       |------+------+------+------+------+------|
 * |      |      | LEFT | DOWN |RIGHT |      |-------.  D  ,-------|CTL-R |  4   |  5   |  6   | PLUS |      |
 * |------+------+------+------+------+------|       |< E >|       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|  R  |-------| PGUP |  1   |  2   |  3   |ENTER |      |
 * `-----------------------------------------/       /      \      \-----------------------------------------'
 *            |  Z   |  X   |      |      | / ENTER /        \ SPACE\  |      |  0   |  .   |      |
 *            |      |      |      |      |/       /          \      \ |      |      |      |      |
 *            `-----------------------------------'            '------''---------------------------'
 */
[2] = LAYOUT(
    _______,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                            KC_F6,    KC_F7,   KC_F8,   KC_F9,    KC_F10,    KC_F11,
     KC_GRV, _______,  _______,    KC_UP,  _______,  _______,                            _______,  KC_KP_7, KC_KP_8, KC_KP_9,  _______,   KC_F12,
    _______, _______,  KC_LEFT,  KC_DOWN, KC_RIGHT,   KC_F13,                            _______,  KC_KP_4, KC_KP_5, KC_KP_6,  KC_PPLS,   _______,
    _______, _______,  _______,  _______,  _______,   KC_F14,    _______,    _______,    _______,  KC_KP_1, KC_KP_2, KC_KP_3,  KC_PENT,   _______,
                KC_Z,     KC_X,  _______,  _______,   KC_ENT,                            KC_SPC,   _______, KC_KP_0, KC_PDOT,  _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |-------.  E  ,-------|  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|       |< N >|       |------+------+------+------+------+------|
 * |      |      |      |  UP  |      |      |-------.  C  ,-------|CTK-L |  7   |  8   |  9   |      | F12  |
 * |------+------+------+------+------+------|       |< O >|       |------+------+------+------+------+------|
 * |      |      | LEFT | DOWN |RIGHT |      |-------.  D  ,-------|CTL-R |  4   |  5   |  6   | PLUS |      |
 * |------+------+------+------+------+------|       |< E >|       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|  R  |-------| PGUP |  1   |  2   |  3   |ENTER |      |
 * `-----------------------------------------/       /      \      \-----------------------------------------'
 *            |  Z   |  X   |      |      | / ENTER /        \ SPACE\  |      |  0   |  .   |      |
 *            |      |      |      |      |/       /          \      \ |      |      |      |      |
 *            `-----------------------------------'            '------''---------------------------'
 */
[3] = LAYOUT(
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MNXT,    KC_MPLY,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
             KC_LCMD, KC_LCTL, KC_LALT,   MO(4),  KC_SPC,                             KC_SPC,   MO(4),    KC_MINS, KC_EQL,  KC_RCMD
),
[4] = LAYOUT(
       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,                            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,                            KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,KC_QUOT,                          KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC, KC_MPLY,    KC_MNXT,    KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
             KC_LCMD, KC_LCTL, KC_LALT,   MO(4),  KC_ENT,                            KC_SPC,   MO(4),    KC_MINS, KC_EQL,  KC_RCMD
),
};
