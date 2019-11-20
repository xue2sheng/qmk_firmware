#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _NUMBERS,
    _CODE,
    _NAVIGATION,
    _ADJUST
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COMMAND_ESCAPE,
    TAB_LGUI,
    NAVIGATION_SPACE,
    ALT_QUOTE,
    RGB_RST
};

#define NUMBERS  MO(_NUMBERS)
#define CODE  MO(_CODE)
#define ADJUST MO(_ADJUST)

#define KC_CMES COMMAND_ESCAPE
#define KC_TBGU TAB_LGUI
#define KC_NVSP NAVIGATION_SPACE
#define KC_ALQU ALT_QUOTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           MO(_ADJUST),KC_LCTRL, KC_LALT, KC_LGUI,MO(_NUMBERS),KC_SPC,KC_SPC,MO(_CODE), KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT
          //`------------------------------------------------------------------------------------------------------------'
  ),


  [_NUMBERS] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR,  KC_ASTR,KC_LPRN, KC_RPRN,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,                    KC_F12,S(KC_NUHS),S(KC_NUBS),_______,_______,_______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
          //`------------------------------------------------------------------------------------------------------------'
  ),


  [_CODE] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      KC_TILD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,                    KC_F12, KC_NUHS, KC_NUBS, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  ),


  [_ADJUST] = LAYOUT( /* Base */
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_TOG, RGB_MOD, XXXXXXX,LCA(KC_DEL),LALT(KC_PSCR),KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______,   RESET,   RESET, _______, _______, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  )
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _NUMBERS, _CODE, _ADJUST);
}

uint16_t custom_lt_timer;
keypos_t prv_key_pressed;

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;

    inline void tap(uint16_t keycode) {
        register_code(keycode);
        unregister_code(keycode);
    };

    if (record->event.pressed) {
        #ifdef SSD1306OLED
            set_keylog(keycode, record);
        #endif
        prv_key_pressed = record->event.key;
    }

    #define IS_KEYPOS_SAME(keyone, keytwo) ((keyone.col == keytwo.col) && (keyone.row == keytwo.row))
    #define ANOTHER_KEY_PRESSED (!IS_KEYPOS_SAME(prv_key_pressed, record->event.key))

  switch (keycode) {
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
        case COMMAND_ESCAPE:
            if (record->event.pressed) {
                custom_lt_timer = timer_read();
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LCTL);
                if (timer_elapsed(custom_lt_timer) < 150 && (!ANOTHER_KEY_PRESSED)) {
                    tap(KC_ESC);
                }
            }
            return false;
            break;
        case TAB_LGUI:
            if (record->event.pressed) {
                custom_lt_timer = timer_read();
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LGUI);
                if (timer_elapsed(custom_lt_timer) < 150 && (!ANOTHER_KEY_PRESSED)) {
                    tap(KC_TAB);
                }
            }
            return false;
            break;
        case NAVIGATION_SPACE:
            if (record->event.pressed) {
                custom_lt_timer = timer_read();
                layer_on(_NAVIGATION);
            } else {
                layer_off(_NAVIGATION);
                if (timer_elapsed(custom_lt_timer) < 150 && (!ANOTHER_KEY_PRESSED)) {
                    tap(KC_SPC);
                }
            }
            return false;
            break;
        case ALT_QUOTE:
            if (record->event.pressed) {
                custom_lt_timer = timer_read();
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LALT);
                if (timer_elapsed(custom_lt_timer) < 150 && (!ANOTHER_KEY_PRESSED)) {
                    tap(KC_QUOT);
                }
            }
            return false;
            break;
    #endif
    default:
      result = true;
      break;
  }

  return result;
}

void matrix_init_user(void) {

}

