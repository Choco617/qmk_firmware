#pragma once
#include "Choco617.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#   define LAYOUT KEYMAP
#endif

#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define _________________COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _________________COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________       KC_K,    KC_H,    KC_COMM, KC_DOT,  TD(TD_SLS)


#define _____________COLEMAK_ADV_WIN_L1____________       KC_Q,    KC_W,    KC_F,    KC_CTLP, KC_B
#define _____________COLEMAK_ADV_WIN_L2____________       KC_CTLA, KC_WINR, KC_ALTS, KC_SHFT, KC_G
#define _____________COLEMAK_ADV_WIN_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define _____________COLEMAK_ADV_WIN_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _____________COLEMAK_ADV_WIN_R2____________       KC_M,    KC_SHFN, KC_ALTE, KC_WINI, KC_CTLO
#define _____________COLEMAK_ADV_WIN_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  TD(TD_SLS)


#define _____________COLEMAK_ADV_MAC_L1____________       KC_Q,    KC_W,    KC_F,    KC_CMDP, KC_B
#define _____________COLEMAK_ADV_MAC_L2____________       KC_CMDA, KC_ALTR, KC_CTLS, KC_SHFT, KC_G
#define _____________COLEMAK_ADV_MAC_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define _____________COLEMAK_ADV_MAC_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _____________COLEMAK_ADV_MAC_R2____________       KC_M,    KC_SHFN, KC_CTLE, KC_ALTI, KC_CMDO
#define _____________COLEMAK_ADV_MAC_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  TD(TD_SLS)


#define _________________LOWER_L1__________________        KC_NO,   KC_NO,   KC_BSLS, KC_AMPR, KC_PSCR
#define _________________LOWER_L2__________________        KC_MINUS,KC_EQL,  KC_TDL,  KC_TDR,  KC_SLCK
#define _________________LOWER_L3__________________        KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,   KC_PAUS

#define _________________LOWER_R1__________________        KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST
#define _________________LOWER_R2__________________        KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PMNS
#define _________________LOWER_R3__________________        KC_TDC,  KC_P1,   KC_P2,   KC_P3,   KC_PPLS



#define _________________RAISE_L1__________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________RAISE_L2__________________        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________RAISE_L3__________________        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11

#define _________________RAISE_R1__________________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________RAISE_R2__________________        KC_F6,   KC_LBRC, KC_INS,  KC_HOME, KC_PGUP
#define _________________RAISE_R3__________________        KC_F12,  KC_RBRC, KC_DEL,  KC_END,  KC_PGDN
