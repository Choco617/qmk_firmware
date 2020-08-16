#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif
#include "Choco617.h"

#define KC_LGN1 TD(TD_LGN)
#define KC_LGN2 LoginEIDPW
#define KC_CAD LCTL(LALT(KC_DEL))
#define KC_ZMO LCTL(LSFT(KC_MINUS))
#define KC_ZMI LCTL(LSFT(KC_EQL))
#define KC_BTAB LSFT(KC_TAB)

// fixes for F1-F7 being weird
#define KC_FF1 KC_F1
#define KC_FF2 KC_F2
#define KC_FF3 KC_F3
#define KC_FF4 KC_F4
#define KC_FF5 KC_F5
#define KC_FF6 KC_F6
#define KC_FF7 KC_F7

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define KC_DWIN GUI_T(KC_MINUS) // D for dash
#define KC_DCTL CTL_T(KC_MINUS)
#define KC_DALT ALT_T(KC_MINUS)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Colemak-DHm, regular, with corner modifiers and arrows
[_COLEMAK] = LAYOUT_wrapper(
//┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
   TAB,    ______________COLEMAK_L1_____________,                     ______________COLEMAK_R1_____________,  BSPC,
   ESC,    ______________COLEMAK_L2_____________,                     ______________COLEMAK_R2_____________,  QUOT,
   SHCAPS, ______________COLEMAK_L3_____________,                     ______________COLEMAK_R3_____________,  SHENT,
                                   DWIN,   LOWR,   SHBS,      SPC,    RASE,   DCTL
//                                └───────┴───────┴───────┘  └───────┴───────┴───────┘
),

// Colemak-DHm with Windows home row mods
[_COLEMAKWIN] = LAYOUT_wrapper(
//┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
   TAB,    __________COLEMAK_ADV_WIN_L1_________,                     __________COLEMAK_ADV_WIN_R1_________,  BSPC,
   ESC,    __________COLEMAK_ADV_WIN_L2_________,                     __________COLEMAK_ADV_WIN_R2_________,  QUOT,
   SHCAPS, __________COLEMAK_ADV_WIN_L3_________,                     __________COLEMAK_ADV_WIN_R3_________,  SHENT,
                                   DALT,   LODEL,  SHBS,      SPARR,  RAENT,  LEAD
//                                └───────┴───────┴───────┘  └───────┴───────┴───────┘
),

// Colemak-DHm with macOS home row mods
[_COLEMAKMAC] = LAYOUT_wrapper(
//┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
   TAB,    __________COLEMAK_ADV_MAC_L1_________,                     __________COLEMAK_ADV_MAC_R1_________,  BSPC,
   ESC,    __________COLEMAK_ADV_MAC_L2_________,                     __________COLEMAK_ADV_MAC_R2_________,  QUOT,
   SHCAPS, __________COLEMAK_ADV_MAC_L3_________,                     __________COLEMAK_ADV_MAC_R3_________,  SHENT,
                                   DWIN,   LODEL,  SHBS,      SPARR,  RAENT,  DCTL
//                                └───────┴───────┴───────┘  └───────┴───────┴───────┘
),

[_QWERTY] = LAYOUT_wrapper(
//┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
   TAB,    ______________QWERTY_L1______________,                     ______________QWERTY_R1______________,  BSPC,
   ESC,    ______________QWERTY_L2______________,                     ______________QWERTY_R2______________,  QUOT,
   SHCAPS, ______________QWERTY_L3______________,                     ______________QWERTY_R3______________,  SHENT,
                                   DWIN,   LOWR,   SHBS,      SPC,    RASE,   DCTL
//                                └───────┴───────┴───────┘  └───────┴───────┴───────┘
),

[_LOWER] = LAYOUT_wrapper(
//┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
   GRV,    ______________LOWER_L1_______________,                     ______________LOWER_R1_______________,  PGUP,
   TRNS,   ______________LOWER_L2_______________,                     ______________LOWER_R2_______________,  PGDN,
   STHPAW, ______________LOWER_L3_______________,                     ______________LOWER_R3_______________,  PENT,
                                   TRNS,   TRNS,   TRNS,      TRNS,   ZADJ,   TDC
//                                └───────┴───────┴───────┘  └───────┴───────┴───────┘
  ),

  [_RAISE] = LAYOUT_wrapper(
//┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
   GRV,    ______________RAISE_L1_______________,                     ______________RAISE_R1_______________,  TRNS,
   TRNS,   ______________RAISE_L2_______________,                     ______________RAISE_R2_______________,  TRNS,
   TRNS,   ______________RAISE_L3_______________,                     ______________RAISE_R3_______________,  TRNS,
                                   TRNS,   MADJ,   DELE,      TRNS,   TRNS,   TRNS
//                                └───────┴───────┴───────┘  └───────┴───────┴───────┘
  ),

  /* Adjust (Lower + Raise)
   *  Alt "macros" above raise/lower are for JDE:
   *    Alt-4 is jump to HDA routing
   *    Alt-M is switch to HMP routing
   *    Alt-A is switch to HDA routing
   *    Alt-H is convert this component to HMP branch
   *    Alt-1 is refresh doc/tooling list
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |Chr34 |Debug |EWO   |      |Alt-4 |Alt-H |                |      |Alt-1 |      |      |Reset |GAMING|
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |DelDng|Cmnt  |PVP   |      |Alt-M |Alt-A |                |      |      |      |      |      |Rodman|
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      |Un-c  |      |      |Shrug |      |                |      |      |Qwerty|Colemk|CMWin |CMMac |
   * |------+------+------+------+------+------|------.  ,------|------+------+------+------+------+------|
   *                             |      |      |NumLk |  |      |      |      |
   *                             `--------------------'  `--------------------,
   */
  [_ADJUST] = LAYOUT(
    Chr34,  Debug,   EWO,   KC_NO,       LALT(KC_P4), LALT(KC_H),                           KC_NO,   LALT(KC_P1), KC_NO,  KC_NO,   RESET,      GAMING,
    DelDng, Cmnt,    PVP,   KC_NO,       LALT(KC_M),  LALT(KC_A),                           KC_NO,   KC_NO,       KC_NO,  KC_NO,   KC_NO,      Rodman,
    KC_NO,  UnCm,    KC_NO, KC_NO,       KC_SHRG,     KC_NO,                                UC_M_WC, UC_M_OS,     QWERTY, COLEMAK, COLEMAKWIN, COLEMAKMAC,
                                         KC_NO,       _______,     KC_NUMLOCK,       KC_NO, _______, KC_NO
  ),

  [_POWER] = LAYOUT_kc(
//┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
   LGN1,   NO,     NO,     BTN2,   BTN1,   NO,                        PGUP,   HOME,   UP,     END,    BTAB,   NO,
   LGN2,   LPRN,   RPRN,   MUTE,   VOLU,   NO,                        PGDN,   LEFT,   DOWN,   RGHT,   TAB,    NO,
   SEC3,   NO,     NO,     NO,     VOLD,   NO,                        NO,     BSPC,   DEL,    ZMO,    ZMI,    NO,
                                   TRNS,   TRNS,   CAD,       TRNS,   TRNS,   TRNS
//                                └───────┴───────┴───────┘  └───────┴───────┴───────┘
  ),

  [_GAMING] = LAYOUT_kc(
//┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
   1,      TAB,    Q,      W,      E,      R,                         T,      NO,     NO,     NO,     NO,     NO,
   2,      ESC,    A,      S,      D,      F,                         G,      NO,     NO,     EXT_GAM,UP,     ENT,
   3,      LSFT,   Z,      X,      C,      V,                         NO,     NO,     NO,     LEFT,   DOWN,   RGHT,
                                   LCTL,   LCTL,   SPC,       NO,     NO,     NO
//                                └───────┴───────┴───────┘  └───────┴───────┴───────┘
  ),

  [_SOUTHPAW] = LAYOUT_kc(
//┌───────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
   EXT_SP, PSLS,   P7,     P8,     P9,     PAST,                      NO,     NO,     NO,     NO,     NO,     BSPC,
   ESC,    BSPC,   P4,     P5,     P6,     PMNS,                      NO,     NO,     NO,     NO,     NO,     NO,
   NO,     DEL,    P1,     P2,     P3,     PPLS,                      NO,     NO,     NO,     NO,     NO,     NO,
                                   TDC,    P0,     PENT,      NO,     NO,     NO
//                                └───────┴───────┴───────┘  └───────┴───────┴───────┘
  ),
};

// leader key definitions, just for crkbd
LEADER_EXTERNS();
void matrix_scan_user(void) {
	LEADER_DICTIONARY() {
		leading = false;
		leader_end();

		SEQ_ONE_KEY(KC_C) {
			SEND_STRING("Console.WriteLine($\"");
		}
		SEQ_ONE_KEY(KC_D) {
			SEND_STRING("Debug.Print ");
		}
    SEQ_ONE_KEY(KC_B) {
      SEND_STRING("BUT" SS_TAP(X_ENTER));
    }
    SEQ_ONE_KEY(KC_T) {
      SEND_STRING(SS_LALT(SS_TAP(X_F4)));
    }

	}
}
