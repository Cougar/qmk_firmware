/* Copyright 2018-2023 Cougar <cougar@random.ee>
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

// Keymap for KLE http://www.keyboard-layout-editor.com/#/gists/fc16db556acb736110777d2532ba5a01
// Keymap for QMK Configurator https://gist.github.com/Cougar/1b8b3f3411b2236df13381b71e753f07

#include QMK_KEYBOARD_H

#define	_LGUI_E	LGUI(KC_E)
#define	_LGUI_R	LGUI(KC_R)
#define	_LGUI_T	LGUI(KC_T)
#define _MNU_F2 LT(_F2, KC_APP)

enum custom_keycodes {
    _QPVERS = SAFE_RANGE,
};

// Layers
enum {
    _DL = 0, // default US QWERTY
    _AL,     // layer with arrow keys
    _F1,     // function layer 1
    _F2,     // function layer 2
    _SP,     // speacials Fn1+Fn2
//  _EL,     // empty layer as template
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* LAYOUT_60_iso (without key 31) https://i.imgur.com/jz4s3iR.jpeg
 * One layer takes 150 bytes of flash
 *
 * _DL - default
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Backspc│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │Enter│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │Backsp│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ \ │    │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │ LShift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │  RShift  │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │LCtr│LAlt│Fn1 │         Space          │Mn/2│RGui│RAlt│RCtr│
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 *
 * _AL - layer with arrows, activate: Fn2+Caps, deactivate: Caps
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Backspc│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │Enter│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │ _DL  │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ \ │    │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │ LShift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │  ↑       │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │LCtr│LAlt│LGui│         Space          │AltG│ ←  │ ↓  │ →  │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 *
 * _F1 - function layer 1
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Del   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │RMc│   │LGE│LGR│LGT│   │   │Ins│   │Prt│ScL│Pau│Retrn│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │ Caps │PMc│   │   │   │   │ ← │ ↓ │ ↑ │ → │Hom│PgU│   │    │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │ LShift │   │   │   │   │   │   │BBc│BFw│End│PgD│          │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │LCtr│LAlt│    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 *
 * _F2 - function layer 2
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │F11│F12│F13│F14│F15│F16│F17│F18│F19│F20│KP-│KP+│       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │RTg│Hu+│Sa+│Br+│Ef+│   │   │   │   │   │   │   │KEntr│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │ _AL  │RMo│Hu-│Sa-│Br-│Ef-│   │MPv│MPl│MNx│   │   │   │    │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │ LShift │Bl │Bl-│Bl+│Brh│   │   │Mut│Vo-│Vo+│   │  RShift  │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │Ctrl│LAlt│    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 *
 * _SP - specials
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │BL │   │   │   │   │   │   │   │   │   │   │   │   │ Reset │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │Debug│   │Win│   │   │   │   │   │   │OSX│   │   │   │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │Lnx│   │   │   │    │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │        │   │   │   │Ver│   │   │   │   │   │   │          │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 *
 */

[_DL] = LAYOUT_60_iso(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
    KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    KC_BSPC,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
    KC_LSFT, _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    KC_LCTL, KC_LALT,          MO(_F1),                   KC_SPC,                             _MNU_F2, KC_RGUI,          KC_RALT, KC_RCTL),

[_AL] = LAYOUT_60_iso(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    TO(_DL),          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_UP,
    _______, _______,          KC_LGUI,                   _______,                            KC_ALGR, KC_LEFT,          KC_DOWN, KC_RGHT),

[_F1] = LAYOUT_60_iso(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
    _______,          DM_REC1, _______, _LGUI_E, _LGUI_R, _LGUI_T, _______, _______, KC_INS,  _______, KC_PSCR, KC_SCRL, KC_PAUS,
    KC_CAPS,          DM_PLY1, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_PGUP, _______, KC_RETURN,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_WBAK, KC_WFWD, KC_END,  KC_PGDN,          _______,
    _______, KC_LGUI,          _______,                   _______,                            MO(_SP), _______,          _______, _______),

[_F2] = LAYOUT_60_iso(
    _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_PMNS, KC_PPLS,          _______,
    _______,          RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______,
    TO(_AL),          RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_PENT,
    _______, _______, BL_TOGG, BL_DOWN, BL_UP,   BL_BRTG, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,          _______,
    _______, KC_LALT,          MO(_SP),                   _______,                            _______, _______,          _______, _______),
[_SP] = LAYOUT_60_iso(
    QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          QK_RBT,
    DB_TOGG,          _______, UC_WIN,  _______, _______, _______, _______, _______, _______, UC_MAC,  _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, UC_LINX, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _QPVERS, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______,          _______,                   _______,                            _______, _______,          _______, _______),
};

void caps_word_set_user(bool active) {
    // this works with one LED only that can't be changed during Caps Word anyway
    led_t led_status = (led_t)host_keyboard_leds();
    if (active)
        // invert LED when active
        led_status.raw = ~led_status.raw;
    led_update_kb(led_status);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case _QPVERS:
            SEND_STRING(QMK_KEYBOARD ":" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);
            break;
        }
    }
    return true;
};
