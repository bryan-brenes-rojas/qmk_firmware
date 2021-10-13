#include QMK_KEYBOARD_H

/* #define QWERTY 0 // Base qwerty */
/* #define CHARS 1  // Special characters */
/* #define MEDIA 2  // Media keys */
/* #define GAME 3   // Gaming */

enum custom_keycodes {
    ST_MACRO_0= SAFE_RANGE,
    ST_MACRO_1,
    ST_MACRO_2,
    ST_MACRO_3
};



/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | \|     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | ESC    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | -_    |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
           KC_ESC,   KC_F1       ,KC_F2        ,KC_F3        ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL,   KC_1        ,KC_2         ,KC_3         ,KC_4   ,KC_5   ,
           KC_CAPS,  KC_Q        ,KC_W         ,KC_E         ,KC_R   ,KC_T   ,
           KC_ESC,  LCA_T(KC_A) ,LCTL_T(KC_S) ,RALT_T(KC_D) ,KC_F   ,KC_G   ,
           KC_LSFT,  LGUI_T(KC_Z),KC_X         ,LALT_T(KC_C) ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,KC_LEFT,KC_RGHT,
			   KC_LCTL,KC_LALT,
                                           KC_HOME,
                     LT(2,KC_BSPC),KC_TAB ,KC_END ,

  KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_AUDIO_MUTE , KC_AUDIO_VOL_DOWN  , KC_AUDIO_VOL_UP, TO(3), KC_1,
	KC_6   ,KC_7   ,KC_8           ,KC_9           ,KC_0           ,KC_BSLS,
	KC_Y   ,KC_U   ,KC_I           ,KC_O           ,KC_P           ,KC_MINS,
	KC_H   ,KC_J   ,RALT_T(KC_K)   ,RCTL_T(KC_L)   ,LCA_T(KC_SCLN) ,KC_QUOT,
	KC_N   ,KC_M   ,KC_COMM,       KC_DOT          ,RGUI_T(KC_SLSH),KC_RSFT,
         KC_DOWN ,KC_UP         ,KC_LBRC,        KC_RBRC,
           KC_RGUI,KC_RCTL,
           KC_PGUP,
           KC_PGDN,KC_ENTER ,LT(1,KC_SPC)
    ),
    [1] = LAYOUT(
    _______, _______    ,_______     ,_______     ,_______,_______  ,_______  ,_______  ,_______,
    KC_EQL,   KC_1        ,KC_2         ,KC_3         ,KC_4   ,KC_5   ,
    KC_DEL,   KC_EXLM     ,KC_AT        ,KC_HASH      ,KC_DLR ,KC_PERC,
    _______, KC_F1       ,KC_F2        ,KC_F3        ,KC_F4  ,KC_F5,
    TO(3),    KC_F7       ,KC_F8        ,KC_F9        ,KC_F10 ,KC_F11,
            _______ ,_______ ,_______,_______,
  _______,_______,
                                    _______,
              _______   ,_______ ,_______ ,

  _______  ,_______ ,_______ ,_______ ,_______ , _______  , _______, KC_FN0, KC_1,
  KC_6   ,KC_7   ,KC_8           ,KC_9           ,KC_0           ,KC_BSLS,
  KC_CIRC,KC_AMPR,KC_ASTR        ,KC_LPRN        ,KC_RPRN        ,KC_QUOT,
  KC_F6  ,KC_UNDS,KC_PLUS        ,KC_LCBR        ,KC_RCBR        ,KC_PIPE,
  KC_F12 ,KC_TILD,KC_BSLS,        KC_LBRC        ,KC_RBRC        ,KC_GRV,
         _______ ,_______         ,_______,        _______,
           _______,_______,
           _______,
           _______,_______ , _______
    ),
[2] = LAYOUT(
    _______, _______    ,_______     ,_______     ,_______,_______  ,_______  ,_______  ,_______,
    KC_EQL,   KC_1        ,KC_2         ,KC_3         ,KC_4        ,KC_5   ,
    KC_DEL,   KC_1        ,KC_2         ,KC_3         ,KC_4        ,KC_5   ,
    _______, _______    ,_______     ,_______     ,_______    ,_______,
    _______, ST_MACRO_0  ,ST_MACRO_1  ,ST_MACRO_2   ,ST_MACRO_3  ,_______,
            _______ ,_______ ,_______,_______,
  _______,_______,
                                    _______,
              _______   ,_______ ,_______ ,

  _______  ,_______           ,_______                    ,_______                   ,_______       ,_______   ,_______, KC_FN0, KC_1,
  KC_6      ,KC_7               ,KC_8                        ,KC_9                       ,KC_0           ,KC_BSLS,
  KC_6      ,KC_7               ,KC_8                        ,KC_9                       ,KC_0           ,KC_AUDIO_VOL_UP,
  KC_LEFT   ,KC_DOWN            ,KC_UP                       ,KC_RIGHT                   ,KC_EQL         ,KC_AUDIO_VOL_DOWN,
  _______  ,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,         KC_MEDIA_NEXT_TRACK        ,_______       ,KC_AUDIO_MUTE,
         _______ ,_______         ,_______,        _______,
           _______,_______,
           _______,
           _______,_______ , _______
    ),
[3] = LAYOUT(
           KC_ESC,  KC_F1       ,KC_F2        ,KC_F3        ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL,  KC_1        ,KC_2         ,KC_3         ,KC_4   ,KC_5   ,
           KC_ESC,  KC_Q        ,KC_W         ,KC_E         ,KC_R   ,KC_T   ,
           KC_TAB,  KC_A        ,KC_S         ,KC_D         ,KC_F   ,KC_G   ,
           KC_LSFT, KC_Z        ,KC_X         ,KC_C         ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,KC_LEFT,KC_RGHT,
         KC_LCTL,KC_LALT,
                                           KC_HOME,
                     KC_SPC, KC_TAB ,KC_END ,

  KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_AUDIO_MUTE  ,KC_AUDIO_VOL_DOWN  ,KC_AUDIO_VOL_UP, TO(0), KC_1,
  KC_6   ,KC_7   ,KC_8           ,KC_9           ,KC_0               ,KC_BSLS,
  KC_Y   ,KC_U   ,KC_I           ,KC_O           ,KC_P               ,KC_MINS,
  KC_H   ,KC_J   ,KC_K           ,KC_L           ,KC_SCLN            ,KC_QUOT,
  KC_N   ,KC_M   ,KC_COMM,       KC_DOT          ,KC_SLSH            ,KC_RSFT,
         KC_DOWN ,KC_UP         ,KC_LBRC,        KC_RBRC,
           KC_RGUI,KC_RCTL,
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
    )
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

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

void led_set_user(uint8_t usb_led) {

}
