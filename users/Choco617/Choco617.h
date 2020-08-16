/*
Copyright 2019 Matt Gilbertson <gilbe415@umn.edu> @Choco617

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include "quantum.h"
#include "version.h"
#include "eeprom.h"
#include "wrappers.h"
#include "process_records.h"
#ifdef TAP_DANCE_ENABLE
#   include "tap_dances.h"
#endif // TAP_DANCE_ENABLE
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#   // include "rgb_stuff.h"
#endif

/* set up universal delays here */
#define TAP_CODE_DELAY 5
#define MACRO_TIMER 5

/* Define layer names */
enum userspace_layers {
    _COLEMAK = 0,
    _COLEMAKWIN,
    _COLEMAKMAC,
    _QWERTY,
    _GAMING,
    _RGBLED,
    _SOUTHPAW,
    _LOWER,
    _RAISE,
    _ADJUST,
    _POWER,
};

/*
define modifiers here, since MOD_* doesn't seem to work for these
 */


bool mod_key_press_timer (uint16_t code, uint16_t mod_code, bool pressed);
bool mod_key_press (uint16_t code, uint16_t mod_code, bool pressed, uint16_t this_timer);
bool send_game_macro(const char *str, keyrecord_t *record, bool override);
void matrix_init_keymap(void);
void shutdown_keymap(void);
void suspend_power_down_keymap(void);
void suspend_wakeup_init_keymap(void);
void matrix_scan_keymap(void);
layer_state_t layer_state_set_keymap (layer_state_t state);
layer_state_t default_layer_state_set_keymap (layer_state_t state);
void led_set_keymap(uint8_t usb_led);
void eeconfig_init_keymap(void);

typedef union {
    uint32_t raw;
    struct {
        bool     rgb_layer_change :1;
        bool     is_overwatch     :1;
        bool     nuke_switch      :1;
        uint8_t  unicode_mod      :4;
        bool     swapped_numbers  :1;
    };
} userspace_config_t;

extern userspace_config_t userspace_config;

