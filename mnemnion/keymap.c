#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
  SWITCH_WIN,
  BSWITCH_WIN,
  MOOM_ACTIVATE,
  FONT_UP,
  FONT_DOWN,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * ,--------------------------------------------------.    ,--------------------------------------------------.
 * |    0   |   1  |   2  |   3  |   4  |   5  |  6   |    |  38  |  39  |  40  |  41  |  42  |  43  |   44   |
 * |--------+------+------+------+------+------+------|    |------+------+------+------+------+------+--------|
 * |    7   |   8  |   9  |  10  |  11  |  12  |  13  |    |  45  |  46  |  47  |  48  |  49  |  50  |   51   |
 * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
 * |   14   |  15  |  16  |  17  |  18  |  19  |------|    |------|  52  |  53  |  54  |  55  |  56  |   57   |
 * |--------+------+------+------+------+------|  26  |    |  58  |------+------+------+------+------+--------|
 * |   20   |  21  |  22  |  23  |  24  |  25  |      |    |      |  59  |  60  |  61  |  62  |  63  |   64   |
 * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
 *   |  27  |  28  |  29  |  30  |  31  |                                |  65  |  66  |  67  |  68  |  69  |
 *   `----------------------------------'                                `----------------------------------'
 *                                       ,-------------.  ,-------------.
 *                                       |  32  |  33  |  |  70  |  71  |
 *                                ,------+------+------|  |------+------+------.
 *                                |      |      |  34  |  |  72  |      |      |
 *                                |  35  |  36  |------|  |------|  74  |  75  |
 *                                |      |      |  37  |  |  73  |      |      |
 *                                `--------------------'  `--------------------'
 */
[0] = LAYOUT_ergodox(
    // left hand
    KC_EQUAL, KC_1, KC_2, KC_3, KC_4, KC_5, SWITCH_WIN,
    KC_MINUS, KC_Q, KC_W, KC_E, KC_R, KC_T, TG(2),
    KC_BSPACE, KC_A, KC_S, KC_D, KC_F, KC_G,
    OSM(MOD_LSFT), CTL_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_LGUI,
     KC_GRAVE, KC_BSLASH, KC_LGUI, KC_LEFT, KC_RIGHT,

    // left thumb
    	KC_LCTRL, LALT_T(KC_ESCAPE),
    		KC_HOME,
    	KC_SPACE, KC_TAB, KC_END,

    // right hand
    BSWITCH_WIN, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DELETE,
    TG(1), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLASH,
    KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
    KC_RGUI, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
     KC_UP, KC_DOWN, KC_LBRACKET, KC_RBRACKET, MO(1),

    // right thumb
    RALT_T(KC_ESCAPE), KC_RCTRL,
    KC_PGUP,
    KC_PGDOWN, KC_TAB, KC_ENTER
),


// Red LED
[1] = LAYOUT_ergodox(
    // left hand
    KC_ESCAPE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,
    _______, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, _______,
    _______, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRAVE,
    _______, KC_PERC, KC_CIRC, KC_LBRACKET, KC_RBRACKET, KC_TILD, _______,
     _______, _______, _______, _______, _______,

    // left thumb
    	RGB_MOD, _______,
    		_______,
    	RGB_VAD, RGB_VAI, _______,

    // right hand
    _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    _______, KC_UP, KC_7, KC_8, KC_9, KC_ASTR, KC_F12,
    KC_DOWN, KC_4, KC_5, KC_6, _______, _______,
    _______, KC_AMPR, KC_1, KC_2, KC_3, KC_BSLASH, MOOM_ACTIVATE,
     _______, KC_DOT, KC_0, KC_EQUAL, _______,

    // right thumb
    RGB_TOG, RGB_SLD,
    _______,
    _______, RGB_HUD, RGB_HUI
),

// Green LED
[2] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, FONT_DOWN,
    _______, _______, _______, KC_MS_UP, _______, _______, _______,
    _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______,
    _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2,

    // left thumb
    	_______, _______,
    		_______,
    	_______, _______, _______,

    // right hand
    FONT_UP, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_MEDIA_PLAY_PAUSE,
    _______, _______, _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, _______, _______,
     KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE, _______, _______,

    // right thumb
    _______, _______,
    _______,
    _______, _______, KC_WWW_BACK
)

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

#define SEND(case_enum, string) \
     case case_enum:\
     if (record -> event.pressed) {\
        SEND_STRING(string);\
     }\
     return false;\
     break


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // custom cases
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    // SEND_STRING cases
    SEND(SWITCH_WIN, SS_LGUI("`"));
    SEND(BSWITCH_WIN, SS_LGUI(SS_LSFT("`")));
    SEND(MOOM_ACTIVATE, SS_LCTRL(SS_LGUI("z")));
    SEND(FONT_UP, SS_LGUI("+"));
    SEND(FONT_DOWN, SS_LGUI("-"));
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
