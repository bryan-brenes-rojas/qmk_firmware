/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAME 3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)


enum custom_keycodes {
  ST_MACRO_0= SAFE_RANGE,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , KC_BSPC,
     RALT_T(KC_ESC) , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                 KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  , RALT_T(KC_MINS),
     LCTL_T(KC_CAPS), KC_A  ,  KC_S  , KC_D  , KC_F  , KC_G  ,                KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN, RCTL_T(KC_QUOT),
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                 KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH, KC_RSFT,
                      KC_LEFT,KC_RIGHT,                                       KC_DOWN, KC_UP,
                                      KC_LGUI,_______,                           _______, KC_LGUI,
                                      KC_LALT, LT(2,KC_BSPC),                 LT(1,KC_SPC), KC_RALT,
                                      KC_LCTL, LCA_T(KC_TAB),                 LCA_T(KC_ENT), KC_RCTL
  ),

  [_LOWER] = LAYOUT_5x6(

     _______,_______,_______,_______,_______,_______,                           _______, _______ , _______ , _______ ,_______ ,_______,
     KC_DEL,   KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                        KC_CIRC,KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN,KC_QUOT,
     KC_TRNS,  KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_F5,                          KC_F6,  KC_UNDS , KC_PLUS , KC_LCBR ,KC_RCBR,KC_PIPE,
     TO(_GAME),KC_F7,   KC_F8, KC_F9,   KC_F10 ,KC_F11,                         KC_F12, KC_TILD , KC_BSLS , KC_LBRC ,KC_RBRC,KC_GRV,
                                             _______,_______,            _______, _______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),

  [_RAISE] = LAYOUT_5x6(
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
       KC_DEL ,  KC_1 , KC_2 , KC_3 , KC_4 , KC_5 ,                             KC_6  , KC_7 , KC_8 , KC_9 ,KC_0 ,KC_AUDIO_VOL_UP ,
       KC_PGUP,  _______,_______,_______,_______,KC_HOME,                        KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT ,KC_EQUAL,KC_AUDIO_VOL_DOWN,
       KC_PGDOWN,ST_MACRO_0,ST_MACRO_1  ,ST_MACRO_2,ST_MACRO_3,KC_END,           _______,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,_______,KC_AUDIO_MUTE,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ),

  [_GAME] = LAYOUT_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , KC_BSPC,
     KC_ESC , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  , TO(_QWERTY),
     KC_CAPS, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  , KC_SCLN, KC_QUOT,
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT , KC_SLSH, KC_RSFT,
                      KC_LEFT,KC_RIGHT,                                       KC_DOWN, KC_UP,
                                      RAISE,_______,                           _______, LOWER,
                                      KC_LALT,KC_SPC,                         KC_SPC, KC_RCTL,
                                      KC_LCTL, KC_TAB,                        KC_ENT, KC_RALT
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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


