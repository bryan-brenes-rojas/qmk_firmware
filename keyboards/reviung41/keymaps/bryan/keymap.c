/* Copyright 2020 gtips
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
#include QMK_KEYBOARD_H

enum custom_keycodes {
  ST_MACRO_0= SAFE_RANGE,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3
};

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    KC_CAPS,  KC_Q,         KC_W,          KC_E,          KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,         KC_O,          KC_P,            KC_BSPC,
    KC_ESC,   LCA_T(KC_A),  LCTL_T(KC_S),  RALT_T(KC_D),  KC_F,      KC_G,               KC_H,     KC_J,     RALT_T(KC_K), RCTL_T(KC_L),  LCA_T(KC_SCLN),  KC_QUOT,
    KC_LSFT,  LGUI_T(KC_Z), KC_X,          LALT_T(KC_C),  KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,      KC_DOT,        RGUI_T(KC_SLSH), KC_RSFT,
                                             KC_LALT,   LT(_RAISE,KC_TAB),    KC_SPC,   LT(_LOWER, KC_ENT),    KC_RGUI
  ),
  
  [_LOWER] = LAYOUT_reviung41(
    KC_DEL,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_MINUS,
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5,              KC_F6,    KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,
    _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,             KC_F12,   KC_TILD,  KC_BSLS,  KC_LBRC,  KC_RBRC,  KC_GRV,
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),
  
  [_RAISE] = LAYOUT_reviung41(
    KC_DEL,    KC_1,       KC_2,        KC_3,        KC_4,         KC_5,               KC_6,     KC_7,                KC_8,                KC_9,                  KC_0,      KC_AUDIO_VOL_UP,
    KC_PGUP,   _______,    _______,     _______,     _______,      KC_HOME,            KC_LEFT,  KC_DOWN,             KC_UP,               KC_RIGHT,              KC_EQUAL,  KC_AUDIO_VOL_DOWN,
    KC_PGDOWN, ST_MACRO_0, ST_MACRO_1,  ST_MACRO_2,  ST_MACRO_3,   KC_END,             _______,  KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,   _______,   KC_AUDIO_MUTE,
                                            _______,   _______,  KC_BSPC,  _______,  _______
  ),
  
  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* if (record->event.pressed) { */
    /* set_keylog(keycode, record); */
  /* } */
  switch (keycode) {
        case ST_MACRO_0:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("adc"SS_TAP(X_ENTER));
            } else {
                // when keycode QMKBEST is released
            }
            break;

        case ST_MACRO_1:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("mid"SS_TAP(X_ENTER));
            } else {
                // when keycode QMKBEST is released
            }
            break;

        case ST_MACRO_2:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("top"SS_TAP(X_ENTER));
            } else {
                // when keycode QMKBEST is released
            }
            break;

        case ST_MACRO_3:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("supp"SS_TAP(X_ENTER));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        default:
            return true;
    }
  return true;
}
