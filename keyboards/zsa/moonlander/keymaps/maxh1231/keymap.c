#include "features/select_word.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum layers {
    MAC,
    WIN,
    SYMB,
    NUM,
    NAV,
};

enum custom_keycodes { RGB_SLD = SAFE_RANGE, SELWFWD, SELWBAK, SELLINE, ST_MACRO_0 };
enum tap_dance_codes { DFM, DFW };

// home row mods
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define ALT_A MT(MOD_LALT, KC_A)
#define SFT_D MT(MOD_LSFT, KC_D)
#define SFT_K MT(MOD_RSFT, KC_K)
#define ALT_SCN MT(MOD_RALT, KC_SCLN)
#define CTL_QUT MT(MOD_RCTL, KC_QUOT)
// layer mods
#define LNUM_F LT(NUM, KC_F)
#define LNAV_J LT(NAV, KC_J)
#define LSYM_BS LT(SYMB, KC_BSPC)
// tmux leader
#define TMUX_L LCTL(KC_A)
// media keys
#define MEDPT KC_MEDIA_PREV_TRACK
#define MEDNT KC_MEDIA_NEXT_TRACK
#define MEDPP KC_MEDIA_PLAY_PAUSE
// dual mods
#define CTL_ALT LALT(KC_LEFT_CTRL)

const key_override_t   only_bktk     = ko_make_with_layers(MOD_MASK_SHIFT, KC_GRV, KC_GRV, (1U << SYMB));
const key_override_t   only_eql      = ko_make_with_layers(MOD_MASK_SHIFT, KC_EQL, KC_EQL, (1U << SYMB));
const key_override_t   only_mins     = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, KC_MINS, (1U << SYMB));
const key_override_t   only_lbrc     = ko_make_with_layers(MOD_MASK_SHIFT, KC_LBRC, KC_LBRC, (1U << SYMB));
const key_override_t   only_rbrc     = ko_make_with_layers(MOD_MASK_SHIFT, KC_RBRC, KC_RBRC, (1U << SYMB));
const key_override_t   only_scln     = ko_make_with_layers(MOD_MASK_SHIFT, KC_SCLN, KC_SCLN, (1U << SYMB));
const key_override_t **key_overrides = (const key_override_t *[]){&only_bktk, &only_eql, &only_mins, &only_lbrc, &only_rbrc, &only_scln, NULL};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC] = LAYOUT(
        XXXXXXX,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,XXXXXXX,       XXXXXXX,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,TD(DFW),
        KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,XXXXXXX,       XXXXXXX,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSLS,
        CTL_ESC,  ALT_A,   KC_S,  SFT_D, LNUM_F,   KC_G,XXXXXXX,       XXXXXXX,   KC_H, LNAV_J,  SFT_K,   KC_L,ALT_SCN,CTL_QUT,
        KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                          KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_LGUI,XXXXXXX,                       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                                        LSYM_BS, KC_DEL,XXXXXXX,        TMUX_L, KC_ENT, KC_SPC
    ),

    [WIN] = LAYOUT(
        _______,_______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,TD(DFM),
        _______,_______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                       _______,_______,_______,_______,_______,_______,
        _______,KC_LGUI,_______,_______,KC_LALT,_______,                       _______,_______,_______,_______,_______,_______,
                                        _______,_______,_______,    ST_MACRO_0,_______,_______
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
        _______,_______,_______,_______,_______,_______,_______,      _______,_______, KC_TAB,KC_PSLS,KC_PAST,KC_MINS,_______,
        _______,_______,_______,_______,_______,_______,_______,      _______,_______,   KC_7,   KC_8,   KC_9,KC_PLUS,_______,
        _______,_______,_______,_______,_______,_______,_______,      _______,_______,   KC_4,   KC_5,   KC_6,KC_PLUS,_______,
        _______,_______,_______,_______,_______,_______,                      _______,   KC_1,   KC_2,   KC_3, KC_ENT,_______,
        _______,_______,_______,_______,_______,_______,                      _______,   KC_0,   KC_0, KC_DOT, KC_ENT,_______,
                                        _______,_______,_______,      _______,_______,_______
    ),

    [NAV] = LAYOUT(
        _______,_______,  MEDPT,  MEDPP,  MEDNT,_______,_______,      _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,  KC_UP,_______,_______,_______,      _______,_______,_______,_______,_______,_______,_______,
        CTL_ALT,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,      _______,_______,_______,KC_RSFT,_______,KC_RALT,CTL_ESC,
        _______,_______,SELWBAK,SELLINE,SELWFWD,_______,                      _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                      _______,_______,_______,_______,_______,_______,
                                        _______,_______,_______,      _______,_______,_______
    ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R',
                            'L', 'L', 'L',  'R', 'R', 'R'
);

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [MAC] = {
              {0,0,0},     {0,0,255},     {0,0,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255},     {0,0,255},     {0,0,255},
              {0,0,0},       {0,0,0},       {0,0,0},   {0,255,255},   {0,255,255},       {0,0,0},       {0,0,0},
              {0,0,0},     {0,0,255},     {0,0,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255},     {0,0,255},     {0,0,255},
              {0,0,0},       {0,0,0},       {0,0,0},   {0,255,255},   {0,255,255},       {0,0,0},       {0,0,0}
    },

    [WIN] = {
              {0,0,0},     {0,0,255},     {0,0,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},  {74,255,246},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255},     {0,0,255},     {0,0,255},
              {0,0,0},       {0,0,0},       {0,0,0},   {0,255,255},   {0,255,255},       {0,0,0},       {0,0,0},
              {0,0,0},     {0,0,255},     {0,0,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255}, {198,255,255},     {0,0,255},       {0,0,0},
        {144,200,255},     {0,0,255},     {0,0,255},     {0,0,255},
              {0,0,0},       {0,0,0},       {0,0,0},   {0,255,255},   {0,255,255},       {0,0,0},       {0,0,0}
    },

    [SYMB] = {
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},  {46,251,252},  {46,251,252},  {46,251,252},       {0,0,0},
              {0,0,0},  {46,251,252},  {46,251,252},  {46,251,252},       {0,0,0},
              {0,0,0},  {46,251,252},  {46,251,252},  {46,251,252},       {0,0,0},
              {0,0,0},  {46,251,252},  {46,251,252},  {46,251,252},       {0,0,0},
              {0,0,0},  {46,251,252},  {46,251,252},  {46,251,252},
              {0,0,0},       {0,0,0},       {0,0,0},   {0,255,255},   {0,255,255},       {0,0,0},       {0,0,0},
              {0,0,0},   {0,255,255},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},  {46,251,252},  {46,251,252},  {46,251,252},       {0,0,0},
              {0,0,0},  {46,251,252},  {46,251,252},  {46,251,252},       {0,0,0},
              {0,0,0},  {46,251,252},  {46,251,252},  {46,251,252},       {0,0,0},
              {0,0,0},  {46,251,252},  {46,251,252},  {46,251,252},       {0,0,0},
              {0,0,0},  {46,251,252},  {46,251,252},  {46,251,252},
              {0,0,0},       {0,0,0},       {0,0,0},   {0,255,255},   {0,255,255},       {0,0,0},       {0,0,0}
    },

    [NUM] = {
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
         {46,255,255},  {74,255,246},  {74,255,246},   {0,255,255},   {0,255,255},
        {255,180,255}, {144,200,255}, {144,200,255}, {144,200,255},     {0,0,255},
        {170,255,255}, {144,200,255}, {144,200,255}, {144,200,255}, {144,200,255},
        {210,180,255}, {144,200,255}, {144,200,255}, {144,200,255}, {144,200,255},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0}
    },

    [NAV] = {
              {0,0,0},       {0,0,0}, {198,255,255},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
         {24,246,235},       {0,0,0},  {24,246,235},       {0,0,255},     {0,0,0},
         {24,246,235},  {24,246,235},  {24,246,235},       {0,0,255},     {0,0,0},
         {24,246,235},       {0,0,0},  {24,246,235},       {0,0,255},     {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0}, {198,255,255},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0}, {198,255,255},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0}, {198,255,255},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
              {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0}
    },
};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color( i, 0, 0, 0 );
        } else {
            RGB rgb = hsv_to_rgb( hsv );
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (rawhid_state.rgb_control) {
        return false;
    }
    if (keyboard_config.disable_layer_led) { return false; }
    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE)
                rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_select_word(keycode, record)) { return false; }
    switch (keycode) {
        case SELWBAK:  // Backward word selection.
            if (record->event.pressed) {
                select_word_register('B');
            } else {
                select_word_unregister();
            }
            break;

        case SELWFWD:  // Forward word selection.
            if (record->event.pressed) {
                select_word_register('W');
            } else {
                select_word_unregister();
            }
            break;

        case SELLINE:  // Line selection.
            if(record->event.pressed) {
                select_word_register('L');
            } else {
                select_word_unregister();
            }
            break;

        case ST_MACRO_0:
            if (record->event.pressed) {
                SEND_STRING(
                SS_TAP(X_D)SS_DELAY(25) SS_LSFT(SS_TAP(X_R))SS_DELAY(25) SS_TAP(X_C)SS_DELAY(25) SS_TAP(X_2)SS_DELAY(25) SS_LSFT(SS_TAP(X_5))SS_DELAY(25)                                                     SS_LSFT(SS_TAP(X_MINUS))SS_DELAY(25) SS_TAP(X_B)SS_DELAY(25) SS_TAP(X_1)SS_DELAY(25) SS_TAP(X_2)SS_DELAY(25) SS_LSFT(SS_TAP(X_F))SS_DELAY(25)
                SS_TAP(X_5)SS_DELAY(25) SS_TAP(X_Y)
            );
            }
            break;

        case RGB_SLD:
            if (rawhid_state.rgb_control) {
                return false;
            }
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];
uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case DOUBLE_TAP: layer_move(1); break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
    }
    dance_state[0].step = 0;
}

void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case DOUBLE_TAP: layer_move(0); break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DFW] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
        [DFM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
};

