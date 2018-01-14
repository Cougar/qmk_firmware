/* Copyright 2018 Cougar <cougar@random.ee>
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
#include "dz60.h"
#include "action_layer.h"

#define	_LGUI_E	LGUI(KC_E)
#define	_LGUI_R	LGUI(KC_R)
#define	_LGUI_T	LGUI(KC_T)

// Layers
enum {
	_DL = 0,	// default
	_AL,		// layer with arrows
	_F1,		// function layer 1
	_F2,		// function layer 2
	_EL,		// empty layer as template
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DL] = KEYMAP_ISO_WIDE_SHIFTS(
		KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
		KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		KC_BSPC,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
		KC_LCTL, KC_LALT,          MO(_F1),                   KC_SPC,                             MO(_F2), KC_RGUI,          KC_RALT, KC_RCTL),

[_AL] = KEYMAP_ISO_WIDE_SHIFTS(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		TO(_DL),          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_UP,
		_______, _______,          _______,                   _______,                            _______, KC_LEFT,          KC_DOWN, KC_RGHT),

[_F1] = KEYMAP_ISO_WIDE_SHIFTS(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
		_______,          _______, _______, _LGUI_E, _LGUI_R, _LGUI_T, _______, _______, KC_INS,  _______, KC_PSCR, KC_SLCK, KC_PAUS, _______,
		KC_CAPS,          _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_PGUP, KC_RETURN,
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, KC_END,  KC_PGDN,          _______,
		_______, KC_LGUI,          _______,                   _______,                            _______, _______,          _______, _______),

[_F2] = KEYMAP_ISO_WIDE_SHIFTS(
		_______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_PMNS, KC_PPLS,          RESET,
		_______,          RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		TO(_AL),          RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,
		_______,          BL_TOGG, BL_DEC,  BL_INC,  BL_BRTG, _______, BL_BRTG, KC_MUTE, KC_VOLD, KC_VOLU, _______,          _______,
		_______, KC_LALT,          _______,                   _______,                            _______, _______,          _______, _______),

[_EL] = KEYMAP_ISO_WIDE_SHIFTS(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______,          _______,                   _______,                            _______, _______,          _______, _______),
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    return MACRO_NONE;
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		// Turn capslock on
		PORTB &= ~(1<<2);
	} else {
		// Turn capslock off
		PORTB |= (1<<2);
	}
}
