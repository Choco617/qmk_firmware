/*
Copyright 2018 Brice Figureau <brice.figureau@gmail.com>
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

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x6060
#define DEVICE_VER 0x0001
#define MANUFACTURER    Choco617
#define PRODUCT         Planck
#define DESCRIPTION     Handwired Planck

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* Planck PCB default pin-out */
#define MATRIX_ROW_PINS { D7, E6, B4, B5 }
#define MATRIX_COL_PINS { D3, D2, D1, D0, F4, F5, F6, F7, B1, B3, B2, B6 }
#define UNUSED_PINS { B0, B1, B2, F0, F1, F4, D4, D5, E6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCING_DELAY 5

/* LED */
#define BACKLIGHT_PIN C6
#define BACKLIGHT_LEVELS 3

/* set up for Tap Dance */
#define TAPPING_TERM 200

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#define IGNORE_MOD_TAP_INTERRUPT


/*
 * Magic Key Options
 *
 * Magic keys are hotkey commands that allow control over firmware functions of
 * the keyboard. They are best used in combination with the HID Listen program,
 * found here: https://www.pjrc.com/teensy/hid_listen.html
 *
 * The options below allow the magic key functionality to be changed. This is
 * useful if your keyboard/keypad is missing keys and you want magic key support.
 *
 */

/* key combination for magic key command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)


#endif