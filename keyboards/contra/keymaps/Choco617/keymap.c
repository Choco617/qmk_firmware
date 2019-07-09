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

#define EID "oldID"
#define PW "oldpass"
#define EID2 KC_SECRET_1
#define PW2 KC_SECRET_2
#define CAD LCTL(LALT(KC_DEL))

#define KC_TDQ TD(TD_Q)
#define KC_TDS TD(TD_SLS)
#define KC_SHENT SFT_T(KC_ENT)
#define KC_SHCAPS SFT_T(KC_CAPS)
#define KC_SHBS SFT_T(KC_BSPC)
#define KC_POWR MO(_POWER)
#define KC_LOWR LOWER
#define KC_RASE RAISE

#define KC_SPARR LT(_POWER, KC_SPC)
#define KC_RAENT LT(_RAISE, KC_ENT)
#define KC_LODEL LT(_LOWER, KC_DEL)
// #define KC_MMAC MO(_MACRO)
#define KC_MADJ MO(_ADJUST)
#define KC_ACTL CTL_T(KC_A)
#define KC_RRWIN GUI_T(KC_R) // KC_RWIN is already defined
#define KC_SALT ALT_T(KC_S)
#define KC_TSHF SFT_T(KC_T)
#define KC_NSHF SFT_T(KC_N)
#define KC_EALT ALT_T(KC_E)
#define KC_IWIN GUI_T(KC_I)
#define KC_OCTL CTL_T(KC_O)
#define KC_PCTL CTL_T(KC_P)

#define KC_TDL TD(TD_LPN)
#define KC_TDR TD(TD_RPN)
#define KC_TDC TD(TD_COLON)

#define KC_DELE DelEnd

#define KC_LGN1 TD(TD_LGN)
#define KC_LGN2 LoginEIDPW
#define KC_CAD CAD
#define KC_ZMO LCTL(LSFT(KC_MINUS))
#define KC_ZMI LCTL(LSFT(KC_EQL))

#define KC_EX_GAM EXT_GAM

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Colemak-DHm
  /*
[_COLEMAK] = LAYOUT_kc(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   TAB,    TDQ,    W,      F,      P,      B,      J,      L,      U,      Y,      SCLN,   BSPC,
   ESC,    A,      R,      S,      T,      G,      M,      N,      E,      I,      O,      QUOT,
   SHCAPS, Z,      X,      C,      D,      V,      K,      H,      COMM,   DOT,    TDS,    SHENT,
   LCTL,   LGUI,   LALT,   POWR,   LOWR,   SHBS,   SPC,    RASE,   LEFT,   DOWN,   UP,     RGHT
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),
  */
[_COLEMAK] = LAYOUT_ortho_4x12(
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
   KC_TAB,         _________________COLEMAK_L1________________,           _________________COLEMAK_R1________________,      KC_BSPC,
   KC_ESC,         _________________COLEMAK_L2________________,           _________________COLEMAK_R2________________,      KC_QUOT,
   KC_SHCAPS,      _________________COLEMAK_L3________________,           _________________COLEMAK_R3________________,      KC_SHENT,
   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_LODEL,  KC_SHBS,   KC_SPARR,  KC_RAENT,  KC_NO,     KC_NO,     KC_NO,     KC_NO
//└──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┘
   )

// Colemak adventurous, Windows
[_COLEMAKWIN] = LAYOUT_kc(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   TAB,    TDQ,    W,      F,      PCTL,   B,      J,      L,      U,      Y,      SCLN,   BSPC,
   ESC,    ACTL,   RRWIN,  SALT,   TSHF,   G,      M,      NSHF,   EALT,   IWIN,   OCTL,   QUOT,
   SHCAPS, Z,      X,      C,      D,      V,      K,      H,      COMM,   DOT,    TDS,    SHENT,
   NO,     NO,     NO,     NO,     LODEL,  SHBS,   SPARR,  RAENT,  NO,     NO,     NO,     NO
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

// Colemak adventurous, macOS
[_COLEMAKMAC] = LAYOUT_kc(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   TAB,    TDQ,    W,      F,      PCTL,   B,      J,      L,      U,      Y,      SCLN,   BSPC,
   ESC,    ACTL,   RRWIN,  SALT,   TSHF,   G,      M,      NSHF,   EALT,   IWIN,   OCTL,   QUOT,
   SHCAPS, Z,      X,      C,      D,      V,      K,      H,      COMM,   DOT,    TDS,    SHENT,
   NO,     NO,     NO,     NO,     LODEL,  SHBS,   SPARR,  RAENT,  NO,     NO,     NO,     NO
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

// Qwerty
[_QWERTY] = LAYOUT_kc(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   TAB,    TDQ,    W,      E,      R,      T,      Y,      U,      I,      O,      P,      BSPC,
   ESC,    A,      S,      D,      F,      G,      H,      J,      K,      L,      SCLN,   QUOT,
   LSFT,   Z,      X,      C,      V,      B,      N,      M,      COMM,   DOT,    TDS,    SHENT,
   LCTL,   LGUI,   LALT,   POWR,   LOWR,   SHBS,   SPC,    RASE,   LEFT,   DOWN,   UP,     RGHT
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

// Lower
[_LOWER] = LAYOUT_kc(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   GRV,    NO,     NO,     BSLS,   AMPR,   PSCR,   NO,     PSLS,   P7,     P8,     P9,     PAST,
   TRNS,   MINUS,  EQL,    TDL,    TDR,    SLCK,   HOME,   PGUP,   P4,     P5,     P6,     PMNS,
   TRNS,   MPRV,   MPLY,   MNXT,   VOLD,   PAUS,   END,    PGDN,   P1,     P2,     P3,     PPLS,
   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   DEL,    TRNS,   MADJ,   P0,     P0,     TDC,    PENT
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

// Raise
[_RAISE] = LAYOUT_kc(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   GRV,    1,      2,      3,      4,      5,      6,      7,      8,      9,      0,      TRNS,
   TRNS,   F1,     F2,     F3,     F4,     F5,     F6,     LBRC,   INS,    HOME,   PGUP,   TRNS,
   TRNS,   F7,     F8,     F9,     F10,    F11,    F12,    RBRC,   DEL,    END,    PGDN,   TRNS,
   TRNS,   TRNS,   TRNS,   TRNS,   MADJ,   DELE,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

/* Macro (Lower + Raise)
 *  Lgn is actually tap-dance between password-only (plus Enter)
 *  								  and the same thing preceded by Ctrl-Alt-Del
 *  Alt "macros" above raise/lower are for JDE:
 *		Alt-4 is jump to HDA routing
 *		Alt-M is switch to HMP routing
 *		Alt-A is switch to HDA routing
 *		Alt-H is convert this component to HMP branch
 *		Alt-1 is refresh doc/tooling list
 * ,-----------------------------------------------------------------------------------.
 * |SwMon |Debug |EWO   |      |Alt-4 |Alt-H |      |Alt-1 |      |      |Reset |GAMING|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |DelDng|Cmnt  |PVP   |      |Alt-M |Alt-A |      |      |      |      |RGB   |Rodman|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Un-c  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Chr34 |      |      |      |NumLk | RGB  |      |Qwerty|Colemk|CMWin |CMMac |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {SwMon,  Debug,   EWO,   PW2,         LALT(KC_P4), LALT(KC_H), KC_NO,   LALT(KC_P1), KC_NO,  KC_NO,   RESET,      GAMING},
  {DelDng, Cmnt,    PVP,   KC_SECRET_2, LALT(KC_M),  LALT(KC_A), KC_NO,   KC_NO,       KC_NO,  KC_NO,   RGBLED,     Rodman},
  {KC_NO,  UnCm,    KC_NO, KC_NO,       KC_NO,       KC_NO,      KC_NO,   KC_NO,       KC_NO,  KC_NO,   KC_NO,      KC_NO},
  {KC_NO,  Chr34,   KC_NO, KC_NO,       _______,     KC_NUMLOCK, RGB_TOG, _______,     QWERTY, COLEMAK, COLEMAKWIN, COLEMAKMAC}
},

// Power
[_POWER] = LAYOUT_kc(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   LGN1,   NO,     NO,     BTN2,   BTN1,   NO,     NO,     HOME,   UP,     END,    NO,     NO,
   LGN2,   LPRN,   RPRN,   MUTE,   VOLU,   NO,     NO,     LEFT,   DOWN,   RGHT,   NO,     NO,
   NO,     NO,     NO,     NO,     VOLD,   NO,     NO,     BSPC,   DEL,    ZMO,    ZMI,    NO,
   NO,     NO,     NO,     TRNS,   NO,     CAD,    TRNS,   NO,     NO,     NO,     NO,     NO
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

/* Gaming layer
 * ,-----------------------------------------------------------------------------------.
 * |  1   | Tab  |  Q   |  W   |  E   |  R   |  T   |      |      | Ins  | Home | PgUp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  2   | Esc  |  A   |  S   |  D   |  F   |  G   |      |      | Del  | End  | PgDn |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  3   | Shft |  Z   |  X   |  C   |  V   |      |      |      | Exit |  Up  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  4   | Ctrl |      |      | Spce | Spce | Spce | Spce |      | Left |  Dn  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_kc(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   1,      TAB,    Q,      W,      E,      R,      T,      NO,     NO,     INS,    HOME,   PGUP,
   2,      ESC,    A,      S,      D,      F,      G,      NO,     NO,     DEL,    END,    PGDN,
   3,      LSFT,   Z,      X,      C,      V,      NO,     NO,     NO,     EX_GAM, UP,     ENT,
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


