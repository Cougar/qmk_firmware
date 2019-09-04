#include QMK_KEYBOARD_H

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Fillers to make layering more clear
#define _LAYER_ KC_TRNS

#define	_LGUI_E	LGUI(KC_E)
#define	_LGUI_R	LGUI(KC_R)
#define	_LGUI_T	LGUI(KC_T)
#define	_LG_UP	LGUI(KC_UP)
#define	_LG_DWN	LGUI(KC_DOWN)
#define	_LG_LFT	LGUI(KC_LEFT)
#define	_LG_RGT	LGUI(KC_RGHT)
#define	_LG_HOM	LGUI(KC_HOME)
#define	_LG_END	LGUI(KC_END)
#define	_LG_PGU	LGUI(KC_PGUP)
#define	_LG_PGD	LGUI(KC_PGDN)
#define	_LG_PAU	LGUI(KC_PAUS)

#define KC_REC DYN_REC_START1
#define KC_DONE DYN_REC_STOP
#define KC_PLAY DYN_MACRO_PLAY1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ESC│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │   │   │PRC│SLC│BRK│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┼───┼───┼───┼───┤
 * │GSC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ BKSPC │   │REC│STP│PLY│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┼───┼───┼───┤
 * │ TAB │ q │ w │ e │ r │ t │ y │ u │ i │ o │ p │ [ │ ] │     │   │INS│HOM│PGU│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐ENT ├───┼───┼───┼───┤
 * │ BKSPC│ a │ s │ d │ f │ g │ h │ j │ k │ l │ ; │ ' │ \ │    │   │DEL│END│PGD│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┼───┼───┼───┼───┤
 * │ LSHIFT │ z │ x │ c │ v │ b │ n │ m │ , │ . │ / │  RSHIFT  │   │   │ ↑ │   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┼───┼───┼───┼───┤
 * │LCTL│LALT│ FN │                        │ FN │RGUI│RALT│RCTL│   │ ← │ ↓ │ → │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┴───┴───┴───┴───┘
 *
 * SHIFT
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ESC│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │   │   │PRC│SLC│BRK│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┼───┼───┼───┼───┤
 * │ ~ │ ! │ " │ # │ $ │ % │ ^ │ & │ * │ ( │ ) │ _ │ + │ BKSPC │   │REC│STP│PLY│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┼───┼───┼───┤
 * │ TAB │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ { │ } │     │   │INS│HOM│PG⇑│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐ENT ├───┼───┼───┼───┤
 * │ BKSPC│ A │ S │ D │ F │ G │ H │ J │ K │ L │ : │ " │ | │    │   │DEL│END│PG⇓│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┼───┼───┼───┼───┤
 * │ LSHIFT │ Z │ X │ C │ V │ B │ N │ M │ < │ > │ ? │  RSHIFT  │   │   │ ↑ │   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┼───┼───┼───┼───┤
 * │LCTL│LALT│ FN │                        │ FN │RGUI│RALT│RCTL│   │ ← │ ↓ │ → │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┴───┴───┴───┴───┘
 *
 * FN
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ • │ • │ • │ • │ • │ • │ • │ • │ • │ • │ • │ • │ • │MUT│VO-│VO+│ • │ • │LGP│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┼───┼───┼───┼───┤
 * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│  DEL  │   │ • │ • │ • │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┼───┼───┼───┤
 * │  •  │RGB│HU+│HU-│LGR│MOD│SA+│SA-│VA+│VA-│ • │ • │ • │     │   │ • │LGH│LG⇑│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐RET ├───┼───┼───┼───┤
 * │ CAPS │ • │ • │ • │ • │ • │ ← │ ↓ │ ↑ │ → │HOM│PGU│ • │    │   │ • │LGE│LG⇓│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┼───┼───┼───┼───┤
 * │    •   │ • │ • │BL-│BL │BL+│ • │ • │ • │END│PGD│     •    │   │   │LG↑│   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┼───┼───┼───┼───┤
 * │ •  │LGUI│ •• │                        │ •• │ •  │ •  │ •  │   │LG←│LG↓│LG→│
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┴───┴───┴───┴───┘
 */

LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS,
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC, XXXXXXX, KC_REC,  KC_DONE, KC_PLAY,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          XXXXXXX, KC_INS,  KC_HOME, KC_PGUP,
    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    XXXXXXX, KC_DEL,  KC_END,  KC_PGDN,
    KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,
    KC_LCTL, KC_LALT, MO(1),                              KC_SPC,                             MO(1),   KC_RGUI, XXXXXXX, KC_RALT, KC_RCTL, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT),

LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _LG_PAU,
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,  _______, _______, _______, _______,
    _______, RGB_TOG, RGB_HUI, RGB_HUD, _LGUI_R, RGB_MOD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______,          _______, _______, _LG_HOM, _LG_PGU,
    KC_CAPS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_PGUP, KC_RETURN,                 _______, _______, _LG_END, _LG_PGD,
    _______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  _______, _______, _______, KC_END,  KC_PGDN, _______,          _______, _______, _______, _LG_UP,  _______,
    _______, KC_LGUI, _LAYER_,                            _______,                            _LAYER_, _______, _______, _______, _______, _______, _LG_LFT, _LG_DWN, _LG_RGT),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
    return true;
}

void led_set_user(uint8_t usb_led) {
}
