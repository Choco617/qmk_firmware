#include "Choco617.h"

uint16_t copy_paste_timer;

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
}

// Defines actions tor my global custom keycodes. Defined in drashna.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

    case VRSN: // Print firmware version
        if (record->event.pressed) {
            send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), TAP_CODE_DELAY);
        }
        break;

    case KC_COLEMAK ... KC_QWERTY: // set default layer for any of the Colemak variants or Qwerty (not gaming or RGBLED)        
        if (record->event.pressed) {
            set_single_persistent_default_layer(keycode - KC_COLEMAK);
        }
        break;

    case KC_GAMING ... KC_RGBLED: // turn the layer on
        if (record->event.pressed) {
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_ADJUST);
            layer_on(keycode - KC_COLEMAK);
            if (!eeconfig_is_enabled()) {
                eeconfig_init();
            }
            keymap_config.raw = eeconfig_read_keymap();
            // keymap_config.nkro = 1;
            eeconfig_update_keymap(keymap_config.raw);
        }
        return false;
        break;

    case KC_EXT_GAM ... KC_EXT_RGB: // turn the layer off
        if (record->event.pressed) {
            layer_off(keycode - KC_COLEMAK - 2); // offset of 2 works because of the specific sequence in process_records.h
        }
        return false;
        break;

    // Macros
#ifdef MACROS_ENABLED

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
        SEND_STRING("EID" SS_TAP(X_TAB) "PW" SS_TAP(X_ENTER));
        // SEND_STRING(secrets[1] SS_TAP(X_TAB) secrets[2] SS_TAP(X_ENTER));

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
        /*                 1             2             3             4             5             6             7             8                                                                                                                              1             2             3             4             5             6             7             8             9             10            11            12            13            14            15            16            17            18            19    */
        SEND_STRING(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) "Is Not" SS_TAP(X_TAB) "Com" SS_TAP(X_TAB) "Is Not" SS_TAP(X_TAB) "Can" SS_TAP(X_TAB) SS_TAP(X_TAB) "Gilbertson" SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB));
      }
      return false;
      break;

    case PVP:
      if (record->event.pressed) {
        /*   Alt, T, R, T, Up Arrow x19 (to get to swDocMgr 2014), Space, N, Up Arrow x36 (to get to Microsoft XML 6.0), Space, Up Arrow x83 (to get to Microsoft Excel 16.0), Space, Enter  */
        /*                                      1            2            3            4            5            6            7            8            9            10           11           12           13           14           15           16           17           18           19                1            2            3            4            5            6            7            8            9            10           11           12           13           14           15           16           17           18           19           20           21           22           23           24           25           26           27           28           29           30           31           32           33           34           35               1            2            3            4            5            6            7            8            9            10           11           12           13           14           15           16           17           18           19           20           21           22           23           24           25           26           27           28           29           30           31           32           33           34           35           36           37           38           39           40           41           42           43           44           45           46           47           48           49           50           51           52           53           54           55           56           57           58           59           60           61           62           63           64           65           66           67           68           69           70           71           72           73           74           75           76           77           78           79           80           81           82           83                      */
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
#endif // MACROS_ENABLED

#ifdef UNICODE_ENABLE
    case UC_FLIP: // (ノಠ痊ಠ)ノ彡┻━┻
        if (record->event.pressed) {
            send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
        }
        break;
    case UC_TABL: // ┬─┬ノ( º _ ºノ)
        if (record->event.pressed) {
            send_unicode_hex_string("252C 2500 252C 30CE 0028 0020 00BA 0020 005F 0020 00BA 30CE 0029");
        }
        break;
    case UC_SHRG: // ¯\_(ツ)_/¯
        if (record->event.pressed) {
            send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
        }
        break;
    case UC_DISA: // ಠ_ಠ
        if (record->event.pressed) {
            send_unicode_hex_string("0CA0 005F 0CA0");
        }
        break;
#endif
    }
    return process_record_keymap(keycode, record) &&
/*
// this is drashna's, not sure how/if I want to incorporate it into my own stuff:
// process_record_user_rgb is defined in drashna's rgb_stuff.h, which I haven't duplicated for myself
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
        process_record_user_rgb(keycode, record) &&
#endif // RGBLIGHT_ENABLE
*/
        process_record_secrets(keycode, record);

}
