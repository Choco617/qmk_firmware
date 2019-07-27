#include QMK_KEYBOARD_H

/* Copyright 2015-2017 Jack Humbert
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

#include "contra.h"
#include "action_layer.h"
#include "Choco617.h"

#define KC_LGN1 TD(TD_LGN)
#define KC_LGN2 LoginEIDPW
#define KC_CAD LCTL(LALT(KC_DEL))
#define KC_ZMO LCTL(LSFT(KC_MINUS))
#define KC_ZMI LCTL(LSFT(KC_EQL))

// fixes for F1-F7 being weird
#define KC_FF1 KC_F1
#define KC_FF2 KC_F2
#define KC_FF3 KC_F3
#define KC_FF4 KC_F4
#define KC_FF5 KC_F5
#define KC_FF6 KC_F6
#define KC_FF7 KC_F7

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Colemak-DHm, regular, with corner modifiers and arrows
[_COLEMAK] = LAYOUT_wrapper(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   TAB,    ______________COLEMAK_L1_____________,  ______________COLEMAK_R1_____________,  BSPC,
   ESC,    ______________COLEMAK_L2_____________,  ______________COLEMAK_R2_____________,  QUOT,
   SHCAPS, ______________COLEMAK_L3_____________,  ______________COLEMAK_R3_____________,  SHENT,
   LCTL,   LGUI,   LALT,   POWR,   LOWR,   SHBS,   SPC,    RASE,   LEFT,   DOWN,   UP,     RGHT
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),


// Colemak-DHm with Windows home row mods
[_COLEMAKWIN] = LAYOUT_wrapper(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   TAB,    __________COLEMAK_ADV_WIN_L1_________,  __________COLEMAK_ADV_WIN_R1_________,  BSPC,
   ESC,    __________COLEMAK_ADV_WIN_L2_________,  __________COLEMAK_ADV_WIN_R2_________,  QUOT,
   SHCAPS, __________COLEMAK_ADV_WIN_L3_________,  __________COLEMAK_ADV_WIN_R3_________,  SHENT,
   NO,     NO,     NO,     NO,     LODEL,  SHBS,   SPARR,  RAENT,  NO,     NO,     NO,     NO
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

// Colemak-DHm with macOS home row mods
[_COLEMAKMAC] = LAYOUT_wrapper(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   TAB,    __________COLEMAK_ADV_MAC_L1_________,  __________COLEMAK_ADV_MAC_R1_________,  BSPC,
   ESC,    __________COLEMAK_ADV_MAC_L2_________,  __________COLEMAK_ADV_MAC_R2_________,  QUOT,
   SHCAPS, __________COLEMAK_ADV_MAC_L3_________,  __________COLEMAK_ADV_MAC_R3_________,  SHENT,
   NO,     NO,     NO,     NO,     LODEL,  SHBS,   SPARR,  RAENT,  NO,     NO,     NO,     NO
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

[_QWERTY] = LAYOUT_wrapper(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   TAB,    ______________QWERTY_L1______________,  ______________QWERTY_R1______________,  BSPC,
   ESC,    ______________QWERTY_L2______________,  ______________QWERTY_R2______________,  QUOT,
   SHCAPS, ______________QWERTY_L3______________,  ______________QWERTY_R3______________,  SHENT,
   LCTL,   LGUI,   LALT,   POWR,   LOWR,   SHBS,   SPC,    RASE,   LEFT,   DOWN,   UP,     RGHT
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

[_LOWER] = LAYOUT_wrapper(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   GRV,    ______________LOWER_L1_______________,  ______________LOWER_R1_______________,  PGUP,
   TRNS,   ______________LOWER_L2_______________,  ______________LOWER_R2_______________,  PGDN,
   TRNS,   ______________LOWER_L3_______________,  ______________LOWER_R3_______________,  PENT,
   NO,     NO,     NO,     NO,     TRNS,   TRNS,   PENT,   MADJ,   P0,     NO,     NO,     NO
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

[_RAISE] = LAYOUT_wrapper(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   GRV,    ______________RAISE_L1_______________,  ______________RAISE_R1_______________,  TRNS,
   TRNS,   ______________RAISE_L2_______________,  ______________RAISE_R2_______________,  TRNS,
   TRNS,   ______________RAISE_L3_______________,  ______________RAISE_R3_______________,  TRNS,
   NO,     NO,     NO,     NO,     MADJ,   DELE,   TRNS,   TRNS,   NO,     NO,     NO,     NO 
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

/* Adjust (Lower + Raise)
 *  Alt "macros" above raise/lower are for JDE:
 *		Alt-4 is jump to HDA routing
 *		Alt-M is switch to HMP routing
 *		Alt-A is switch to HDA routing
 *		Alt-H is convert this component to HMP branch
 *		Alt-1 is refresh doc/tooling list
 * ,-----------------------------------------------------------------------------------.
 * |Chr34 |Debug |EWO   |      |Alt-4 |Alt-H |      |Alt-1 |      |      |Reset |GAMING|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |DelDng|Cmnt  |PVP   |      |Alt-M |Alt-A |      |      |      |      |RGB   |Rodman|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Un-c  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |NumLk | RGB  |      |Qwerty|Colemk|CMWin |CMMac |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {Chr34,  Debug,   EWO,   KC_NO,       LALT(KC_P4), LALT(KC_H), KC_NO,   LALT(KC_P1), KC_NO,  KC_NO,   RESET,      GAMING},
  {DelDng, Cmnt,    PVP,   KC_NO,       LALT(KC_M),  LALT(KC_A), KC_NO,   KC_NO,       KC_NO,  KC_NO,   RGBLED,     Rodman},
  {KC_NO,  UnCm,    KC_NO, KC_NO,       KC_NO,       KC_NO,      KC_NO,   KC_NO,       KC_NO,  KC_NO,   KC_NO,      KC_NO},
  {KC_NO,  KC_NO,   KC_NO, KC_NO,       _______,     KC_NUMLOCK, RGB_TOG, _______,     QWERTY, COLEMAK, COLEMAKWIN, COLEMAKMAC}
},

// Power
[_POWER] = LAYOUT_kc(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   LGN1,   NO,     NO,     BTN2,   BTN1,   NO,     NO,     HOME,   UP,     END,    NO,     NO,
   LGN2,   LPRN,   RPRN,   MUTE,   VOLU,   NO,     NO,     LEFT,   DOWN,   RGHT,   NO,     NO,
   SEC3,   NO,     NO,     NO,     VOLD,   NO,     NO,     BSPC,   DEL,    ZMO,    ZMI,    NO,
   NO,     NO,     NO,     TRNS,   NO,     CAD,    TRNS,   NO,     NO,     NO,     NO,     NO
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

[_GAMING] = LAYOUT_kc(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   1,      TAB,    Q,      W,      E,      R,      T,      NO,     NO,     INS,    HOME,   PGUP,
   2,      ESC,    A,      S,      D,      F,      G,      NO,     NO,     DEL,    END,    PGDN,
   3,      LSFT,   Z,      X,      C,      V,      NO,     NO,     NO,     EXT_GAM,UP,     ENT,
   4,      LCTL,   NO,     NO,     SPC,    SPC,    SPC,    SPC,    NO,     LEFT,   DOWN,   RGHT
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘   
),

/* RGB palette layer
 * ,-----------------------------------------------------------------------------------.
 * | Hue- | Hue+ |      |      |      |Static|Snake |      |      |      |      |On/Off|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Sat- | Sat+ |      |      |      |Brethe|KntRdr|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Brt- | Brt+ |      |      |      |Rainbo|Xmas  |      |      | Exit |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Mode-| Mode+|      |      |      |Swirl |StcGrd|      |      |      |      | Exit |
 * `-----------------------------------------------------------------------------------'
 */

[_RGBLED] = {
  {RGB_HUD,  RGB_HUI, KC_NO, KC_NO, KC_NO, RGB_M_P,  RGB_M_SN, KC_NO, KC_NO, KC_NO,   KC_NO, RGB_TOG},
  {RGB_SAD,  RGB_SAI, KC_NO, KC_NO, KC_NO, RGB_M_B,  RGB_M_K,  KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO},
  {RGB_VAD,  RGB_VAI, KC_NO, KC_NO, KC_NO, RGB_M_R,  RGB_M_X,  KC_NO, KC_NO, EXT_RGB, KC_NO, KC_NO},
  {RGB_RMOD, RGB_MOD, KC_NO, KC_NO, KC_NO, RGB_M_SW, RGB_M_G,  KC_NO, KC_NO, KC_NO,   KC_NO, EXT_RGB}
},


};