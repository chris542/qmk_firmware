#include QMK_KEYBOARD_H
#include "version.h"
#include "layers.c"
#include "ledmap.c"
#include "keymap_korean.h"

#define CK_LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, \
    k10, k11, k12, k13, k14, k15, k16, \
    k20, k21, k22, k23, k24, k25, k26, \
    k30, k31, k32, k33, k34, k35,      \
    k40, k41, k42, k43, k44,           \
                             k53, \
                        k50, k51, k52, \
                                                    k60, k61, k62, k63, k64, k65, k66, \
                                                    k70, k71, k72, k73, k74, k75, k76, \
                                                    k80, k81, k82, k83, k84, k85, k86, \
                                                    k91, k92, k93, k94, k95, k96, \
                                                    ka2, ka3, ka4, ka5, ka6, \
                                                 kb3,\
                                            kb4, kb5, kb6 \
) \
LAYOUT_moonlander( \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6 \
)

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRV
#define ES_GRTR_MAC LSFT(KC_GRV)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRV
#define NO_BSLS_ALT KC_EQL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

//Custom Aliases
#define PLAY_PAUSE KC_MEDIA_PLAY_PAUSE
#define VOL_UP KC_AUDIO_VOL_UP
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define VOL_MUTE KC_AUDIO_MUTE
#define BRIGHTER KC_BRIGHTNESS_UP
#define DIMMER KC_BRIGHTNESS_DOWN

#define M_SCRSHT LCTL(LGUI(LSFT(KC_4)))
#define M_PRV_TAB LGUI(LSFT(KC_LBRC))
#define M_NXT_TAB LGUI(LSFT(KC_RBRC))
#define M_GUI_GRV LGUI(KC_GRV)

#define W_SCRSHT LGUI(LSFT(KC_S))
#define W_PRV_TAB LCTL(LSFT(KC_TAB))
#define W_NXT_TAB LCTL(KC_TAB)

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

enum tap_dance_codes {
  RW,
  FF,
  SYMNUM,
  MOUSEARROW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MacbookLayer] = CK_LAYOUT(
    KC_ESC        , KC_1         , KC_2          , KC_3    , KC_4    , KC_5 , KC_6      ,
    KC_TAB        , KC_Q         , KC_W          , KC_E    , KC_R    , KC_T , KC_Y      ,
    KC_LCTL       , KC_A         , KC_S          , KC_D    , KC_F    , KC_G , M_PRV_TAB ,
    KC_LSFT       , KC_Z         , KC_X          , KC_C    , KC_V    , KC_B ,
    LSFT(KC_LCTL) , XXXXXXX      , LALT(KC_LGUI) , KC_LALT , KC_LGUI ,
                    TG(GameLayer),
    KC_SPC        , LGUI(KC_SPC) , MO(FuncLayer) ,

    KC_5             , KC_6           , KC_7            , KC_8   , KC_9    , KC_0    , KC_BSPC  ,
    M_SCRSHT         , KC_Y           , KC_U            , KC_I   , KC_O    , KC_P    , KC_EQL   ,
    M_NXT_TAB        , KC_H           , KC_J            , KC_K   , KC_L    , KC_SCLN , KC_ENTER ,
    KC_N             , KC_M           , KC_COMM         , KC_DOT , KC_SLSH , KC_RSFT ,
    KC_QUOT          , KC_LEFT        , KC_DOWN         , KC_UP  , KC_RGHT ,
                       TG(WindowsLayer),
    MO(FuncLayer)    , TD(MOUSEARROW) , TD(SYMNUM)
  ),
  [WindowsLayer] = CK_LAYOUT(
    _______ , _______ , _______       , _______ , _______ , _______ , _______   ,
    _______ , _______ , _______       , _______ , _______ , _______ , _______   ,
    _______ , _______ , _______       , _______ , _______ , _______ , W_PRV_TAB ,
    _______ , _______ , _______       , _______ , _______ , _______ ,
    _______ , XXXXXXX , LALT(KC_LGUI) , KC_LGUI , KC_LALT ,
              _______ ,
    _______ , KR_HAEN , _______       ,

    _______   , _______ , _______ , _______ , _______ , _______ , KC_BSPC ,
    W_SCRSHT  , _______ , _______ , _______ , _______ , _______ , _______ ,
    W_NXT_TAB , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______   , _______ , _______ , _______ , _______ , _______ ,
    _______   , _______ , _______ , _______ , _______ ,
                _______ ,
    _______   , _______ , _______
  ),
  [GameLayer] = CK_LAYOUT(
    KC_ESC  , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , KC_GRV  ,
    _______ , _______ , _______ , _______ , _______ , _______ ,
    KC_LCTL , XXXXXXX , XXXXXXX , KC_LGUI , KC_LALT ,
              _______ ,
    KC_SPC  , _______ , _______ ,

    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , KC_UP   , _______ , _______ ,
    XXXXXXX , KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXX ,
              _______ ,
    _______ , _______ , _______
  ),
  [NumpadLayer] = CK_LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,
              _______ ,
    _______ , _______ , _______ ,

    XXXXXXX , XXXXXXX , KC_NLCK , KC_PSLS , KC_PAST , KC_PMNS , KC_BSPC ,
    XXXXXXX , XXXXXXX , KC_P7   , KC_P8   , KC_P9   , KC_PPLS , XXXXXXX ,
    XXXXXXX , XXXXXXX , KC_P4   , KC_P5   , KC_P6   , KC_PENT , XXXXXXX ,
              XXXXXXX , KC_P1   , KC_P2   , KC_P3   , XXXXXXX , XXXXXXX ,
                        KC_P0   , KC_PDOT , XXXXXXX , XXXXXXX , XXXXXXX ,
              XXXXXXX ,
    _______ , XXXXXXX , _______
  ),
  [MouseLayer] = CK_LAYOUT(
    _______       , _______ , _______  , _______ , _______ , _______ , _______ ,
    _______       , _______ , _______  , _______ , _______ , _______ , _______ ,
    KC_LCTL       , _______ , _______  , _______ , _______ , _______ , _______ ,
    KC_LSFT       , _______ , _______  , _______ , _______ , _______ ,
    _______       , XXXXXXX , _______  , _______ , _______ ,
                    _______ ,
    _______       , _______ , _______  ,

    _______       , _______     , _______       , _______    , _______        , _______      , _______      ,
    _______       , XXXXXXX     , KC_MS_WH_LEFT , KC_MS_UP   , KC_MS_WH_RIGHT , XXXXXXX      , XXXXXXX      ,
    XXXXXXX       , KC_MS_WH_UP , KC_MS_LEFT    , KC_MS_DOWN , KC_MS_RIGHT    , XXXXXXX      , KC_MS_ACCEL0 ,
    KC_MS_WH_DOWN , KC_MS_BTN1  , KC_MS_BTN3    , KC_MS_BTN2 , XXXXXXX        , _______      ,
    XXXXXXX       , XXXXXXX     , XXXXXXX       , XXXXXXX    , XXXXXXX        ,
                    _______     ,
    _______       , _______     , XXXXXXX
  ),
  [SymbolLayer] = CK_LAYOUT(
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    _______ , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC ,
    _______ , XXXXXXX , KC_PIPE , KC_TILD , KC_AMPR , XXXXXXX , XXXXXXX ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    _______ , XXXXXXX , XXXXXXX , _______ , _______ ,
              _______ ,
    _______ , _______ , _______ ,

    KC_DELETE , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_BSPC ,
    XXXXXXX   , KC_CIRC , KC_PLUS , KC_LPRN , KC_RPRN , XXXXXXX , XXXXXXX ,
    M_GUI_GRV , KC_MINS , KC_ASTR , KC_LBRC , KC_RBRC , KC_EQL  , XXXXXXX ,
    KC_UNDS   , KC_BSLS , KC_LABK , KC_RABK , KC_QUES , _______ ,
    KC_GRV    , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                _______ ,
    _______   , XXXXXXX , _______
  ),
  [ArrowsLayer] = CK_LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    XXXXXXX , XXXXXXX , XXXXXXX , KC_END  , XXXXXXX , XXXXXXX , XXXXXXX ,
    KC_LCTL , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    KC_LSFT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    _______ , XXXXXXX , _______ , _______ , _______ ,
    _______ ,
    _______ , _______ , _______ ,

    _______ , _______ , _______ , _______ , _______  , _______ , _______ ,
    XXXXXXX , XXXXXXX , XXXXXXX , KC_HOME , XXXXXXX  , XXXXXXX , XXXXXXX ,
    XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX ,
    _______ , XXXXXXX , _______ , _______ , _______  ,
    _______ ,
    _______ , _______ , XXXXXXX
  ),
  [FuncLayer] = CK_LAYOUT(
    XXXXXXX , KC_F1       , KC_F2    , KC_F3      , KC_F4   , KC_F5    , KC_F6       ,
    XXXXXXX , LALT(KC_F4) , XXXXXXX  , XXXXXXX    , XXXXXXX , XXXXXXX  , XXXXXXX     ,
    XXXXXXX , XXXXXXX     , VOL_DOWN , VOL_MUTE   , VOL_UP  , BRIGHTER , WEBUSB_PAIR ,
    XXXXXXX , XXXXXXX     , TD(RW)   , PLAY_PAUSE , TD(FF)  , DIMMER   ,
    RESET   , XXXXXXX     , XXXXXXX  , XXXXXXX    , XXXXXXX ,
    XXXXXXX ,
    XXXXXXX , KR_HANJ     , _______  ,

    KC_F5              , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    XXXXXXX            , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F12  ,
    MU_TOG             , RGB_VAI , XXXXXXX , XXXXXXX , RGB_SAI , XXXXXXX , XXXXXXX ,
    RGB_VAD            , RGB_SPI , RGB_SPD , RGB_SAD , XXXXXXX , XXXXXXX ,
    TOGGLE_LAYER_COLOR , XXXXXXX , XXXXXXX , XXXXXXX , RGB_TOG ,
    XXXXXXX            ,
    _______            , _______ , _______
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

//Static Layer Colour
void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
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

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led || rgb_matrix_get_flags() == LED_FLAG_NONE ) { return; }
  set_layer_color(biton32(layer_state));
}
// END of Static layer colour

// Animated Layer Colour
layer_state_t layer_state_set_user(layer_state_t state) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_layer_breathing);
    return state;
}
//END of Animated Layer Colour

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
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

static tap dance_state[4];

uint8_t dance_step(qk_tap_dance_state_t *state);
uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->interrupted && !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_rewind(qk_tap_dance_state_t *state, void *user_data);
void rewind_finished(qk_tap_dance_state_t *state, void *user_data);
void rewind_reset(qk_tap_dance_state_t *state, void *user_data);

void on_rewind(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_REWIND);
        tap_code16(KC_MEDIA_REWIND);
        tap_code16(KC_MEDIA_REWIND);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_REWIND);
    }
}
void rewind_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_REWIND); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
    }
}
void rewind_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_REWIND); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
    }
    dance_state[0].step = 0;
}

void on_fastforward(qk_tap_dance_state_t *state, void *user_data);
void fastforward_finished(qk_tap_dance_state_t *state, void *user_data);
void fastforward_reset(qk_tap_dance_state_t *state, void *user_data);
void on_fastforward(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_FAST_FORWARD);
        tap_code16(KC_MEDIA_FAST_FORWARD);
        tap_code16(KC_MEDIA_FAST_FORWARD);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_FAST_FORWARD);
    }
}
void fastforward_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_FAST_FORWARD); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
    }
}
void fastforward_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_FAST_FORWARD); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
    }
    dance_state[1].step = 0;
}

void symnum_finished(qk_tap_dance_state_t *state, void *user_data);
void symnum_reset(qk_tap_dance_state_t *state, void *user_data);
void symnum_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: 
            if(layer_state_is(NumpadLayer)){
                layer_off(NumpadLayer);
            } else {
                layer_on(NumpadLayer); 
            }
            break;
        case SINGLE_HOLD: layer_on(SymbolLayer); break;
    }
}
void symnum_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_HOLD: layer_off(SymbolLayer); break;
    }
    dance_state[2].step = 0;
}

void mousearrow_finished(qk_tap_dance_state_t *state, void *user_data);
void mousearrow_reset(qk_tap_dance_state_t *state, void *user_data);
void mousearrow_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: 
            if(layer_state_is(MouseLayer)){
                layer_off(MouseLayer);
            } else {
                layer_on(MouseLayer); 
            }
            break;
        case SINGLE_HOLD: layer_on(ArrowsLayer); break;
    }
}
void mousearrow_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_HOLD: layer_off(ArrowsLayer); break;
    }
    dance_state[3].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [RW] = ACTION_TAP_DANCE_FN_ADVANCED(on_rewind, rewind_finished, rewind_reset),
    [FF] = ACTION_TAP_DANCE_FN_ADVANCED(on_fastforward, fastforward_finished, fastforward_reset),
    [SYMNUM] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, symnum_finished, symnum_reset, 100),
    [MOUSEARROW] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, mousearrow_finished, mousearrow_reset, 100),
};

