#pragma once
#include "Choco617.h"

#if defined(KEYMAP_SAFE_RANGE)
#   define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#   define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    VRSN = PLACEHOLDER_SAFE_RANGE,              // Prints QMK Firmware and board info
    KC_COLEMAK,        // Sets default layer to COLEMAK
    KC_COLEMAKWIN,     // Sets default layer to COLEMAK, adventurous for Windows
    KC_COLEMAKMAC,     // Sets default layer to COLEMAK, adventurous for macOS
    KC_QWERTY,         // Sets default layer to QWERTY
    KC_GAMING,         // Sets default layer to GAMING
    KC_RGBLED,         // Sets default layer to RGBLED
    KC_EXT_GAM,
    KC_EXT_RGB,
    KC_SECRET_1,       // test1
    KC_SECRET_2,       // test2
    KC_SECRET_3,       // test3
    KC_SECRET_4,       // test4
    KC_SECRET_5,       // test5
    KC_FLIP,           // (ಠ痊ಠ)┻━┻
    KC_TABL,           // ┬─┬ノ( º _ ºノ)
    KC_SHRG,           // ¯\_(ツ)_/¯
    KC_DISA,           // ಠ_ಠ
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
    NEW_SAFE_RANGE     //use "NEWPLACEHOLDER" for keymap specific codes
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

#define KC_SEC1 KC_SECRET_1
#define KC_SEC2 KC_SECRET_2
#define KC_SEC3 KC_SECRET_3
#define KC_SEC4 KC_SECRET_4
#define KC_SEC5 KC_SECRET_5

#define COLEMAK KC_COLEMAK
#define COLEMAKWIN KC_COLEMAKWIN
#define COLEMAKMAC KC_COLEMAKMAC
#define QWERTY KC_QWERTY
#define GAMING KC_GAMING
#define RGBLED KC_RGBLED
#define EXT_GAM KC_EXT_GAM
#define EXT_RGB KC_EXT_RGB

#define KC_RESET RESET
#define KC_RST KC_RESET

#ifdef SWAP_HANDS_ENABLE
#define KC_C1R3 SH_TT
#else // SWAP_HANDS_ENABLE
#define KC_C1R3 KC_BSPC
#endif // SWAP_HANDS_ENABLE


// macro definitiont
#define KC_DELE DelEnd
// Tap Dance definitions
#define KC_TDQ TD(TD_Q)
#define KC_TDS TD(TD_SLS)
#define KC_TDL TD(TD_LPN)
#define KC_TDR TD(TD_RPN)
#define KC_TDC TD(TD_COLON)
// LT and Mod-Tap definitions
#define KC_SHENT SFT_T(KC_ENT)
#define KC_SHCAPS SFT_T(KC_CAPS)
#define KC_SHBS SFT_T(KC_BSPC)
#define KC_POWR MO(_POWER)
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_MADJ MO(_ADJUST)
#define KC_ZADJ LT(_ADJUST, KC_P0)
#define KC_SPARR LT(_POWER, KC_SPC) // SPace or ARRow layer (actually named POWER)
#define KC_RAENT LT(_RAISE, KC_ENT) // RAise or ENTer
#define KC_LODEL LT(_LOWER, KC_DEL) // LOwer or DELete
// Colemak home row mods, Windows
#define KC_CTLA CTL_T(KC_A)
#define KC_WINR GUI_T(KC_R)
#define KC_ALTS ALT_T(KC_S)
#define KC_SHFT SFT_T(KC_T)
#define KC_SHFN SFT_T(KC_N)
#define KC_ALTE ALT_T(KC_E)
#define KC_WINI GUI_T(KC_I)
#define KC_CTLO CTL_T(KC_O)
#define KC_CTLP CTL_T(KC_P)
#define KC_CTLL CTL_T(KC_L)
// Colemak home row mods, macOS
#define KC_CMDA GUI_T(KC_A)
#define KC_ALTR ALT_T(KC_R)
#define KC_CTLS CTL_T(KC_S)
							// T is still shift
							// N is still shift
#define KC_CTLE CTL_T(KC_E)
#define KC_ALTI ALT_T(KC_I)
#define KC_CMDO GUI_T(KC_O)
#define KC_CMDP GUI_T(KC_P)
#define KC_CMDL GUI_T(KC_L)
#define KC_ALTQ ALT_T(KC_Q) // for Alt-Tab in Win
#define KC_CMDQ GUI_T(KC_Q) // for Cmd-Tab in Mac