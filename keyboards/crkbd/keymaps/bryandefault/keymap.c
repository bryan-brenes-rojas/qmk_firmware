/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

enum custom_keycodes {
  ST_MACRO_0= SAFE_RANGE,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_CAPSLOCK,   KC_Q,         KC_W,         KC_E,         KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINUS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_ESCAPE, LCA_T(KC_A),  LCTL_T(KC_S), RALT_T(KC_D), KC_F,     KC_G,    KC_H,    KC_J,    RALT_T(KC_K),   RCTL_T(KC_L),   LCA_T(KC_SCOLON), KC_QUOTE,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSHIFT,   LGUI_T(KC_Z), KC_X,         LALT_T(KC_C), KC_V,     KC_B,    KC_N,    KC_M,    KC_COMMA,       KC_DOT,   RGUI_T(KC_SLASH),     KC_RSHIFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                MO(2),   LT(2,KC_BSPACE),  KC_TAB,     KC_ENTER,   LT(1,KC_SPACE), MO(1)
                                        //`--------------------------'  `--------------------------'

    ),

    [1] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_DELETE,  KC_EXLM,  KC_AT,  KC_HASH,  KC_DLR,  KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,   KC_LPRN,     KC_RPRN,      KC_QUOTE,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TRNS, KC_F1,  KC_F2,  KC_F3,  KC_F4, KC_F5,                       KC_F6,    KC_UNDS,  KC_PLUS,   KC_LCBR,     KC_RCBR,      KC_PIPE,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TO(3),  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,                      KC_F12,   KC_TILD,  KC_BSLASH, KC_LBRACKET, KC_RBRACKET,  KC_GRAVE,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_TRNS, LCTL(KC_C),  LCTL(KC_V),           KC_TRNS, KC_TRNS, KC_TRNS
                                        //`--------------------------'  `--------------------------'
    ),

    [2] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_DELETE, KC_1, KC_2, KC_3, KC_4, KC_5,                                  KC_6,     KC_7,    KC_8,    KC_9,     KC_0,     KC_AUDIO_VOL_UP,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_PGUP,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,                    KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT, KC_EQUAL,  KC_AUDIO_VOL_DOWN,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_PGDOWN,  ST_MACRO_0, ST_MACRO_1, ST_MACRO_2, ST_MACRO_3,  KC_END,   KC_TRNS,  KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_TRNS, KC_AUDIO_MUTE,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_TRNS,   KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                        //`--------------------------'  `--------------------------'
    ),

    [3] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESCAPE, KC_1, KC_2,    KC_3,     KC_4,    KC_Y,                       KC_Y,     KC_U,   KC_I,    KC_O,     KC_P,    TO(0),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_H,   KC_J,    KC_K,     KC_L,    KC_SCOLON, KC_ENTER,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSHIFT, KC_A,  KC_S,    KC_D,    KC_F,    KC_G,                       KC_N,     KC_M,    KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_TRNS, KC_SPACE,  KC_B,     KC_TRNS, KC_TRNS, KC_SPACE
                                        //`--------------------------'  `--------------------------'
    )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("Gaming"), false);
            break;
    }
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAPS ON \n") : PSTR("    \n"), false);
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        /*oled_render_keylog();*/
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
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
#endif // OLED_DRIVER_ENABLE
