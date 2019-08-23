// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus62.h"
#include "action_layer.h"
#include "eeconfig.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _NAV 1
#define _CODE 2
#define _CONSTANTS 3
#define _MEDIA 4
#define _ADJUST 5

enum custom_keycodes {
  SPNAV = SAFE_RANGE,
  ENTAD,
  SPCCOD,
  END_CONSTANT
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define RSEN MT(MOD_RSFT, KC_ENT) // Tap for enter, hold for right shift
#define LCCA MT(MOD_LCTL, KC_CAPS)  // Tap for caps lock, hold for left control
#define ALTBSP MT(MOD_LCTL, KC_BSPC)
#define GUIENT MT(MOD_LGUI, KC_ENT)
#define KC_UNDO LCTL(KC_Z)


#define TO_DEF TO(_DEFAULT)
#define TO_CON  TO(_CONSTANTS)
#define MO_ADJ  MO(_ADJUST)
#define MO_MED  MO(_MEDIA)

#define ENDCON END_CONSTANT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = { /* qwerty */
		{ KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,  XXXXXXX, KC_6,    KC_7,   KC_8,    KC_9,   KC_0,    KC_GRV },
		{ KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,  XXXXXXX, KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    KC_BSPC },
		{ LCCA,    KC_A,    KC_S,    KC_D,    KC_F,   KC_G,  XXXXXXX, KC_H,    KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT },
		{ KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,  GUIENT,  KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, RSEN },
		{ KC_DEL,  KC_BSPC, KC_UNDO, KC_LALT, SPCCOD, SPNAV, ALTBSP,  SPNAV,   SPCCOD, KC_RCTL, MO_MED, MO_ADJ,  TO_CON }
},

[_NAV] = {
		{ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  },
		{ _______, _______, _______, KC_UP,   _______, KC_INS,  XXXXXXX, KC_INS,  _______, KC_UP,   _______, _______, _______ },
		{ _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PSCR, XXXXXXX, KC_PSCR, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},

[_CODE] = {
		{ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  },
		{ _______, _______, _______, KC_LCBR, KC_RCBR, _______, XXXXXXX, _______, KC_AMPR, KC_PIPE, _______, _______, _______ },
		{ _______, _______, _______, KC_LPRN, KC_RPRN, _______, XXXXXXX, _______, KC_UNDS, KC_MINS, _______, _______, _______ },
		{ _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, KC_PLUS, KC_EQL,  _______, KC_BSLS, _______ },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},

[_CONSTANTS] = {
		{ TO_DEF, TO_DEF,  TO_DEF,  TO_DEF,  TO_DEF,  TO_DEF,  XXXXXXX, TO_DEF,  TO_DEF,  TO_DEF,  TO_DEF,  TO_DEF,  TO_DEF },
		{ TO_DEF, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), XXXXXXX, S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), KC_BSPC },
		{ TO_DEF, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), XXXXXXX, S(KC_H), S(KC_J), S(KC_K), S(KC_L), TO_DEF,  TO_DEF },
		{ TO_DEF, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), ENDCON,  S(KC_N), S(KC_M), TO_DEF,  TO_DEF,  TO_DEF,  ENDCON },
		{ KC_DEL, KC_BSPC, TO_DEF,  TO_DEF,  KC_UNDS, KC_UNDS, KC_BSPC, KC_UNDS, KC_UNDS, TO_DEF,  TO_DEF,  TO_DEF,  TO_DEF }
},

[_MEDIA] = {
		{ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  },
		{ _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______ },
		{ _______, _______, KC_MUTE, KC_VOLU, KC_MNXT, _______, XXXXXXX, _______, _______, _______, _______, _______, _______ },
		{ _______, _______, KC_MPLY, KC_VOLD, KC_MPRV, _______, _______, _______, _______, _______, _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},

[_ADJUST] = {
		{ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  },
		{ _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
		{ RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
}


/*
[_TRNS] = {
		{ _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},
*/
};



const uint16_t PROGMEM fn_actions[] = {

};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
//    set_unicode_input_mode(UC_LNX); // Linux
		set_unicode_input_mode(UC_OSX); // Mac OSX
//    set_unicode_input_mode(UC_WIN); // Windows (with registry key, see wiki)
		//set_unicode_input_mode(UC_WINC); // Windows (with WinCompose, see wiki)
};

uint16_t custom_lt_timer;
keypos_t prv_key_pressed;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

	if(record->event.pressed) prv_key_pressed = record->event.key;
	#define IS_KEYPOS_SAME(keyone,keytwo)  ((keyone.col==keytwo.col)&&(keyone.row==keytwo.row))
	#define ANOTHER_KEY_PRESSED (!IS_KEYPOS_SAME(prv_key_pressed, record->event.key))

	switch (keycode) {
		case SPNAV:
			if (record->event.pressed) {
				custom_lt_timer = timer_read();
				layer_on(_NAV);
			} else {
				layer_off(_NAV);
				if (timer_elapsed(custom_lt_timer)<150 && (!ANOTHER_KEY_PRESSED)) {
					register_code(KC_SPC);
					unregister_code(KC_SPC);
				}
			}
			return false;
			break;
		case ENTAD:
			if (record->event.pressed) {
				custom_lt_timer = timer_read();
				layer_on(_ADJUST);
			} else {
				layer_off(_ADJUST);
				if (timer_elapsed(custom_lt_timer)<150 && (!ANOTHER_KEY_PRESSED)) {
					register_code(KC_ENT);
					unregister_code(KC_ENT);
				}
			}
			return false;
			break;
		case SPCCOD:
			if (record->event.pressed) {
				custom_lt_timer = timer_read();
				layer_on(_CODE);
			} else {
				layer_off(_CODE);
				if (timer_elapsed(custom_lt_timer)<150 && (!ANOTHER_KEY_PRESSED)) {
					register_code(KC_SPC);
					unregister_code(KC_SPC);
				}
			}
			return false;
			break;
		case END_CONSTANT:
			if (record->event.pressed) {
				SEND_STRING(" = ");
				layer_off(_CONSTANTS);
			}
			return false;
			break;

	}
	return true;
}
