#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    MAC,
    WIN,
    SYMB,
    NUM,
    NAV,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define ALT_A MT(MOD_LALT, KC_A)
#define SFT_D MT(MOD_LSFT, KC_D)
#define LNUM_F LT(NUM, KC_F)
#define LNAV_J LT(NAV, KC_J)
#define SFT_K MT(MOD_RSFT, KC_K)
#define ALT_SCN MT(MOD_RALT, KC_SCLN)
#define LSYM_BS LT(SYMB, KC_BSPC)
#define TMUX_L LCTL(KC_A)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC] = LAYOUT(
        XXXXXXX,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,XXXXXXX,       XXXXXXX,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,XXXXXXX,
        KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,XXXXXXX,       XXXXXXX,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSLS,
        CTL_ESC,  ALT_A,   KC_S,  SFT_D, LNUM_F,   KC_G,XXXXXXX,       XXXXXXX,   KC_H, LNAV_J,  SFT_K,   KC_L,ALT_SCN,KC_QUOT,
        KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                          KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_LGUI,XXXXXXX,                       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                                        LSYM_BS, KC_DEL,XXXXXXX,        TMUX_L, KC_ENT, KC_SPC
    ),

    [SYMB] = LAYOUT(
        _______,_______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,XXXXXXX,
        _______, KC_GRV,KC_PIPE,KC_LABK,KC_RABK,KC_UNDS,_______,       _______,KC_DQUO,KC_LCBR,KC_RCBR, KC_DLR,KC_PERC,KC_BSPC,
        _______,KC_EXLM, KC_EQL,KC_COLN,KC_MINS,KC_PLUS,_______,       _______,KC_SCLN,KC_LPRN,KC_RPRN,KC_HASH,KC_CIRC,_______,
        _______,KC_TILD,KC_ASTR,KC_LBRC,KC_RBRC,KC_AMPR,                       _______,  KC_AT,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                       _______,_______,_______,_______,_______,_______,
                                        _______,_______,_______,       _______,_______,_______
    ),

    [NUM] = LAYOUT(
        _______,_______,_______,_______,_______,_______,_______,      _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,      _______,_______,   KC_7,   KC_8,   KC_9,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,      _______,_______,   KC_4,   KC_5,   KC_6,_______,_______,
        _______,_______,_______,_______,_______,_______,                      _______,   KC_1,   KC_2,   KC_3,_______,_______,
        _______,_______,_______,_______,_______,_______,                      _______,_______,_______,_______,_______,_______,
                                        _______,_______,_______,      _______,_______,_______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
