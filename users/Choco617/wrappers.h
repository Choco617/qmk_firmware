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
#define KEYMAP_wrapper(...)                  LAYOUT_kc(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT_kc(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)

/*
// F-keys fix
#define KC_FF1 KC_F1
#define KC_FF2 KC_F2
#define KC_FF3 KC_F3
#define KC_FF4 KC_F4
#define KC_FF5 KC_F5
#define KC_FF6 KC_F6
#define KC_FF7 KC_F7
*/

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

#define ______________QWERTY_L1______________        Q,    W,    E,    R,    T
#define ______________QWERTY_L2______________        A,    S,    D,    F,    G
#define ______________QWERTY_L3______________        Z,    X,    C,    V,    B

#define ______________QWERTY_R1______________        Y,    U,    I,    O,    P
#define ______________QWERTY_R2______________        H,    J,    K,    L,    SCLN
#define ______________QWERTY_R3______________        N,    M,    COMM, DOT,  TDS


#define ______________COLEMAK_L1_____________       Q,    W,    F,    P,    B
#define ______________COLEMAK_L2_____________       A,    R,    S,    T,    G
#define ______________COLEMAK_L3_____________       Z,    X,    C,    D,    V

#define ______________COLEMAK_R1_____________       J,    L,    U,    Y,    SCLN
#define ______________COLEMAK_R2_____________       M,    N,    E,    I,    O
#define ______________COLEMAK_R3_____________       K,    H,    COMM, DOT,  TDS


#define __________COLEMAK_ADV_WIN_L1_________       ALTQ, W,    F,    CTLP, B
#define __________COLEMAK_ADV_WIN_L2_________       CTLA, WINR, ALTS, SHFT, G
#define __________COLEMAK_ADV_WIN_L3_________       Z,    X,    C,    D,    V

#define __________COLEMAK_ADV_WIN_R1_________       J,    CTLL, U,    Y,    SCLN
#define __________COLEMAK_ADV_WIN_R2_________       M,    SHFN, ALTE, WINI, CTLO
#define __________COLEMAK_ADV_WIN_R3_________       K,    H,    COMM, DOT,  TDS


#define __________COLEMAK_ADV_MAC_L1_________       Q,    W,    F,    CMDP, B
#define __________COLEMAK_ADV_MAC_L2_________       CMDA, ALTR, CTLS, SHFT, G
#define __________COLEMAK_ADV_MAC_L3_________       Z,    X,    C,    D,    V

#define __________COLEMAK_ADV_MAC_R1_________       J,    CMDL, U,    Y,    SCLN
#define __________COLEMAK_ADV_MAC_R2_________       M,    SHFN, CTLE, ALTI, CMDO
#define __________COLEMAK_ADV_MAC_R3_________       K,    H,    COMM, DOT,  TDS


#define ______________LOWER_L1_______________       NO,   DQUO, MINUS,AMPR, PSCR
#define ______________LOWER_L2_______________       MINUS,EQL,  TDL,  TDR,  SLCK
#define ______________LOWER_L3_______________       MPRV, MPLY, MNXT, NO,   PAUS

#define ______________LOWER_R1_______________       PSLS, P7,   P8,   P9,   PAST
#define ______________LOWER_R2_______________       NO,   P4,   P5,   P6,   PMNS
#define ______________LOWER_R3_______________       TDC,  P1,   P2,   P3,   PPLS



#define ______________RAISE_L1_______________       1,    2,    3,    4,    5
#define ______________RAISE_L2_______________       FF1,  FF2,  FF3,  FF4,  FF5
#define ______________RAISE_L3_______________       FF7,  F8,   F9,   F10,  F11

#define ______________RAISE_R1_______________       6,    7,    8,    9,    0
#define ______________RAISE_R2_______________       FF6,  LBRC, INS,  HOME, PGUP
#define ______________RAISE_R3_______________       F12,  RBRC, DEL,  END,  PGDN
