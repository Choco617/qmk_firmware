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

#define EID "E1190380"
#define PW "Rheese2019"
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

/*
enum planck_layers {
  _COLEMAK,
  _ADVENTUROUS,
  _QWERTY,
  _LOWER,
  _RAISE,
  _POWER,
  _MACRO,
  _GAMING,
  _RGBLED
};
*/

/*
enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  ADVENTUROUS,
  QWERTY,
  LOWER,
  RAISE,
  POWER,
  GAMING,
  EXT_GAM,
  RGBLED,
  EXT_RGB,
  SwMon,
  DelDng,
  Debug,
  Cmnt,
  UnCm,
  Chr34,
  EWO,
  PVP,
  DelEnd,
  LoginEIDPW,
  Rodman,
  W10F8
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Colemak-DHm
[_COLEMAK] = LAYOUT_kc(
//┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
   TAB,    TDQ,    W,      F,      P,      B,      J,      L,      U,      Y,      SCLN,   BSPC,
   ESC,    A,      R,      S,      T,      G,      M,      N,      E,      I,      O,      QUOT,
   SHCAPS, Z,      X,      C,      D,      V,      K,      H,      COMM,   DOT,    TDS,    SHENT,
   LCTL,   LGUI,   LALT,   POWR,   LOWR,   SHBS,   SPC,    RASE,   LEFT,   DOWN,   UP,     RGHT
//└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

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
 * |DelDng|Cmnt  |PVP   |      |Alt-M |Alt-A |      |      |      |      |      |Rodman|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Un-c  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Chr34 |      |      |      |NumLk | RGB  |      |      |Qwerty|ADVNTR|Colemk|
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

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    
    // layers

    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;

    case ADVENTUROUS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_ADVENTUROUS);
      }
      return false;
      break;

    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _MACRO);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _MACRO);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _MACRO);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _MACRO);
      }
      return false;
      break;

    case GAMING:
      if (record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_MACRO);
        layer_on(_GAMING);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;

    case EXT_GAM:
      if (record->event.pressed) {
        layer_off(_GAMING);
      }
      return false;
      break;
	  
	  
    case RGBLED:
      if (record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_MACRO);
        layer_on(_RGBLED);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;

    case EXT_RGB:
      if (record->event.pressed) {
        layer_off(_RGBLED);
      }
      return false;
      break;

    // macros

    case SwMon:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_RIGHT))));
      }
      return false;
      break;

    case DelDng:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_KP_9)));
      }
      return false;
      break;

    case LoginEIDPW:
      if (record->event.pressed) {
        SEND_STRING(EID SS_TAP(X_TAB) PW SS_TAP(X_ENTER));
      }
      return false;
      break;

    case Debug:
      if (record->event.pressed) {
        SEND_STRING("Debug.Print ");
      }
      return false;
      break;

    case Cmnt:
      if (record->event.pressed) {
        SEND_STRING("'" SS_TAP(X_LEFT) SS_TAP(X_DOWN));
      }
      return false;
      break;

    case UnCm:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_DELETE) SS_TAP(X_UP));
      }
      return false;
      break;

    case Chr34:
      if (record->event.pressed) {
        SEND_STRING(" & Chr(34) & ");
      }
      return false;
      break;

    case EWO:
      if (record->event.pressed) {
        //                 1             2             3             4             5             6             7             8                                                                                                                              1             2             3             4             5             6             7             8             9             10            11            12            13            14            15            16            17            18            19    
        SEND_STRING(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) "Is Not" SS_TAP(X_TAB) "Com" SS_TAP(X_TAB) "Is Not" SS_TAP(X_TAB) "Can" SS_TAP(X_TAB) SS_TAP(X_TAB) "Gilbertson" SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB));
      }
      return false;
      break;

    case PVP:
      if (record->event.pressed) {
      	//   Alt, T, R, T, Up Arrow x19 (to get to swDocMgr 2014), Space, N, Up Arrow x36 (to get to Microsoft XML 6.0), Space, Up Arrow x83 (to get to Microsoft Excel 16.0), Space, Enter
        //                                      1            2            3            4            5            6            7            8            9            10           11           12           13           14           15           16           17           18           19                1            2            3            4            5            6            7            8            9            10           11           12           13           14           15           16           17           18           19           20           21           22           23           24           25           26           27           28           29           30           31           32           33           34           35               1            2            3            4            5            6            7            8            9            10           11           12           13           14           15           16           17           18           19           20           21           22           23           24           25           26           27           28           29           30           31           32           33           34           35           36           37           38           39           40           41           42           43           44           45           46           47           48           49           50           51           52           53           54           55           56           57           58           59           60           61           62           63           64           65           66           67           68           69           70           71           72           73           74           75           76           77           78           79           80           81           82           83
        SEND_STRING(SS_TAP(X_LALT) "trt" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) " N" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) " " SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) " " SS_TAP(X_ENTER));
      }
      return false;
      break;

  	case DelEnd:
  	  if (record->event.pressed) {
  	  	SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_TAP(X_DELETE));
  	  }
  	  return false;
  	  break;
      
    case Rodman:
      if (record->event.pressed) {
        SEND_STRING("RodmanTM " SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        register_code(KC_LSFT);
        SEND_STRING(SS_TAP(X_RIGHT) SS_TAP(X_RIGHT));
        unregister_code(KC_LSFT);
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        register_code(KC_EQL);
        unregister_code(KC_EQL);
        unregister_code(KC_LSFT);
        unregister_code(KC_LCTL);
        SEND_STRING(SS_TAP(X_RIGHT) SS_TAP(X_DELETE));
      }
      return false;
      break;

  }
  return true;
}
*/

