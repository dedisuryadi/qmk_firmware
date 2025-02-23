/*

                                        █         █    █            ▄▄▄▀▀▀▀▀▀▄▄▄        █▀▀▀▀▀▀▀▀▀▀█
                                        █        █     █          ▄▀            ▀▄      █          █
                                        █       █      █        ▄▀                ▀▄    █          █
                                        █      █       █        █                  █    █          █
                                        █     █        █       █                    █   █          █
                                        █    █         █       █                    █   █▄▄▄▄▄▄▄▄▄▄█
                                        █   █ █        █       █                    █   █      █
                                        █  █   █       █        █                  █    █       █
                                        █ █     █      █        ▀▄                ▄▀    █        █
                                        ██       █     █          ▀▄            ▄▀      █         █
                                        █         █    █▄▄▄▄▄▄▄▄    ▀▀▀▄▄▄▄▄▄▀▀▀        █          █

                                        ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
                                        D E F A U L T
*/
#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
//#include "features/achordion.h"
//#include "features/layer_lock.h"
//#include "features/select_word.h"

//#define LAYER_LOCK_IDLE_TIMEOUT 20000
//#define SELECT_WORD_TIMEOUT 10000  // When idle, clear state after 10 seconds.
#define TAPPING_TERM_PER_KEY


#ifdef AUDIO_ENABLE
#include "lib/klounds.h"
#endif //AUDIO ENABLE


uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}


#ifdef TAP_DANCE_ENABLE
#include "quantum.h"
// Tap Dance declarations
enum {
    TD_ESC_CAPS,
};
// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};
#endif


// LEFT HAND HOME ROW MODS ├───────────────────────────────────┐

#define CTL_A MT(MOD_LCTL, KC_A)
//#define ALT_S MT(MOD_LALT, KC_S)
//#define GUI_D MT(MOD_LGUI, KC_D)
//#define SFT_F MT(MOD_LSFT, KC_F)
//#define HYP_G MT(MOD_HYPR, KC_G)

#define ALT_R MT(MOD_LALT, KC_R)
#define GUI_S MT(MOD_LGUI, KC_S)
#define SFT_TT MT(MOD_LSFT, KC_T)
#define HYP_G MT(MOD_HYPR, KC_G)


// RIGHT HAND HOME ROW MODS ├───────────────────────────────────┐

//#define HYP_H MT(MOD_HYPR, KC_H)
//#define SFT_J MT(MOD_RSFT, KC_J)
//#define GUI_K MT(MOD_LGUI, KC_K)
//#define ALT_L MT(MOD_LALT, KC_L)
//#define CTL_SCLN MT(MOD_LCTL, KC_SCLN)

#define HYP_M MT(MOD_HYPR, KC_M)
#define SFT_N MT(MOD_RSFT, KC_N)
#define GUI_E MT(MOD_LGUI, KC_E)
#define ALT_I MT(MOD_LALT, KC_I)
#define CTL_O MT(MOD_LCTL, KC_O)

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘

enum custom_keycodes {
    OS_SWAP = SAFE_RANGE,
    CMD_SHIFT_3,
    COLON_EQ,
    UPDIR,
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘

enum klor_layers {
//    _QWERTY,
    _COLEMAK,
    _SYM,
    _NAV,
    _FN,
    _NUM,
    _BTN,
};

// LAYER SWITCH MODS
// LT(layer, kc)	Turn on layer when held, kc when tapped
//#define MOU LT(_COLEMAK, KC_DEL)
#define TAB LT(_NAV , KC_TAB)
#define BSP LT(_FN, KC_BSPC)
#define DEL LT(_BTN, KC_DEL)
//#define OSS LT(_BTN, OSM(MOD_LSFT))
#define ENT LT(_NUM, KC_ENT)
#define SPC LT(_SYM, KC_SPC)

// HOLD MOD
#define KC_QH LT(0, KC_Q)
#define KC_WH LT(0, KC_W)
#define KC_ZH LT(0, KC_Z)
#define KC_XH LT(0, KC_X)
#define KC_CH LT(0, KC_C)
#define KC_VH LT(0, KC_V)
//#define KC_ESCH LT(0, KC_ESC)
//#define KC_OH LT(0, KC_O)
//#define KC_PH LT(0, KC_P)
//#define KC_LLBH LT(0, LLAY_BTN)
//#define KC_RLBH LT(0, RLAY_BTN)


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
//        case MOD_RSFT:
//        case MOD_LSFT:
//        case SFT_F:
//        case SFT_TT:
//        case SFT_J:
//        case SFT_N:
//            return TAPPING_TERM - 50;
        case KC_WH:
            return TAPPING_TERM + 300;
        case KC_QH:
            return TAPPING_TERM + 350;
        case KC_ZH:
        case KC_XH:
        case KC_CH:
        case KC_VH:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

// COMBOS
enum combos {
    CB_OSM,
    CB_ALTBSPC,
    CB_SLEEP,
    CB_WP,
    CB_MSCD,
    CB_MSCU,
    CB_GUI_TAB,
    CB_CTL_TAB,
    CB_GUI_TAB_TAB,
    CB_LBRC,
    CB_RBRC,
    CB_COLON_EQ,
    CB_ESC,
    CB_BTN_LAYER,
    CB_NAV_LAYER,
    CB_TMUX_CMD,
};
const uint16_t PROGMEM cb_osm[] = {SPC, ENT, COMBO_END};
const uint16_t PROGMEM cb_altbspc[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM cb_sleep[] = {TAB, DEL, COMBO_END};
const uint16_t PROGMEM cb_wp[] = {KC_WH, KC_P, COMBO_END};
const uint16_t PROGMEM cb_mscd[] = {KC_CH, KC_D, COMBO_END};
const uint16_t PROGMEM cb_mscu[] = {KC_XH, KC_CH, COMBO_END};
const uint16_t PROGMEM cb_gui_tab[] = {KC_K, KC_P, COMBO_END};
const uint16_t PROGMEM cb_ctl_tab[] = {KC_QH, KC_P, COMBO_END};
const uint16_t PROGMEM cb_gui_tab_tab[] = {KC_K, KC_B, COMBO_END};
const uint16_t PROGMEM cb_lbrc[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM cb_rbrc[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cb_colon_eq[] = {KC_B, KC_J, COMBO_END};
const uint16_t PROGMEM cb_esc[] = {KC_QH, KC_WH, COMBO_END};
const uint16_t PROGMEM cb_btn_layer[] = {HYP_M, ALT_I, COMBO_END};
const uint16_t PROGMEM cb_nav_layer[] = {SFT_N, GUI_E, ALT_I, COMBO_END};
const uint16_t PROGMEM cb_tmux_cmd[] = {KC_L, KC_U, KC_Y, COMBO_END};
combo_t key_combos[] = {
        [CB_WP] = COMBO(cb_wp, G(KC_GRV)),
        [CB_ESC] = COMBO(cb_esc, KC_ESC),
        [CB_TMUX_CMD] = COMBO_ACTION(cb_tmux_cmd),
        [CB_BTN_LAYER] = COMBO(cb_btn_layer, TG(_BTN)),
        [CB_NAV_LAYER] = COMBO(cb_nav_layer, TG(_NAV)),
        [CB_COLON_EQ] = COMBO_ACTION(cb_colon_eq),
        [CB_MSCD] = COMBO(cb_mscd, KC_MS_WH_DOWN),
        [CB_MSCU] = COMBO(cb_mscu, KC_MS_WH_UP),
        [CB_GUI_TAB] = COMBO_ACTION(cb_gui_tab),
        [CB_CTL_TAB] = COMBO_ACTION(cb_ctl_tab),
        [CB_GUI_TAB_TAB] = COMBO_ACTION(cb_gui_tab_tab),
        [CB_LBRC] = COMBO(cb_lbrc, KC_LBRC),
        [CB_RBRC] = COMBO(cb_rbrc, KC_RBRC),
        [CB_OSM] = COMBO(cb_osm, OSM(MOD_LSFT)),
        [CB_ALTBSPC] = COMBO(cb_altbspc, A(KC_BSPC)),
        [CB_SLEEP] = COMBO_ACTION(cb_sleep),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case CB_COLON_EQ:
            if (pressed) {
                SEND_STRING(" := ");
            }
            break;

        case CB_GUI_TAB_TAB:
            if (pressed) {
                register_code(KC_LGUI);
                wait_ms(250);
                tap_code(KC_TAB);
                wait_ms(250);
                tap_code(KC_TAB);
                wait_ms(100);
                unregister_code(KC_LGUI);
            }
            break;

        case CB_GUI_TAB:
            if (pressed) {
                register_code(KC_LGUI);
                wait_ms(250);
                tap_code(KC_TAB);
                wait_ms(100);
                unregister_code(KC_LGUI);
            }
            break;

        case CB_CTL_TAB:
            if (pressed) {
                register_code16(C(KC_TAB));
                wait_ms(300);
                unregister_code16(C(KC_TAB));
            }
            break;

        case CB_TMUX_CMD:
            if (pressed) {
                tap_code16(LCTL(KC_B));
                tap_code16(LSFT(KC_SCLN));
            }
            break;

        case CB_SLEEP:
            if (pressed) {
                // Macro actions
                tap_code(KC_ESC);
                wait_ms(100);
                tap_code16(LCTL(LALT(LSFT(LGUI(KC_SCLN)))));
                wait_ms(100);
                tap_code16(LGUI(KC_SPC));
                wait_ms(500);
                tap_code(KC_S);
                tap_code(KC_L);
                tap_code(KC_E);
                tap_code(KC_E);
                tap_code(KC_P);
                wait_ms(800);
                tap_code(KC_ENT);
            }
            break;
    }
}

bool is_ctl_tab_active = false;
bool is_alt_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

void matrix_scan_user(void) {
//    select_word_task();
//    layer_lock_task();
//    achordion_task();
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 900) {
            unregister_code(KC_LGUI);
            is_alt_tab_active = false;
        }
    } else if (is_ctl_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 900) {
            unregister_code(KC_LCTL);
            is_ctl_tab_active = false;
        }
    }
    // Other tasks...
}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
   ┌───────────────────────────────────────────────────────────┐
   │ q w e r t y                                               │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    Q    │    W    │    E    │    R    │    T    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    Y    │    U    │    I    │    O    │    P    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │   TAB   │    A    │    S    │    D    │    F    │    G    ├─╯                ╰─┤    H    │    J    │    K    │    L    │    ;    │    "    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │   DEL   │    Z    │    X    │    C    │    V    │    B    ││  MUTE  ││PLY/PSE ││    N    │    M    │    ,    │    .    │    /    │  SHIFT  │
   └─────────┴─────────┴─────────┼─────────┼─H────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │  CTRL   │  _____  │  SPACE  │   ALT   ││ CMD/WIN │  ENTER  │  _____  │ BSPACE  │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */
// BASE LAYER
//[_QWERTY] = LAYOUT(
// //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
//              KC_QH,   KC_WH,     KC_E,        KC_R,     KC_T,                              KC_Y,     KC_U,     KC_I,     KC_OH,       KC_PH,
//     KC_ESC,  CTL_A,   ALT_S,    GUI_D,       SFT_F,    HYP_G,                             HYP_H,    SFT_J,    GUI_K,     ALT_L,    CTL_SCLN,   KC_QUOT,
//     KC_LLBH, KC_ZH,   KC_XH,    KC_CH,       KC_VH,     KC_B,  TO_COLEMAK,   KC_MPLY,      KC_N,     KC_M,  KC_COMM,    KC_DOT,     KC_SLSH,   KC_RLBH,
//                               KC_BTN1,         SPC,      TAB,     QK_REP,     QK_AREP,       BSP,      ENT,      DEL,
//                               KC_WH_U,     KC_WH_D,                                               KC_WH_L,  KC_WH_R
// ),

// COLEMAK LAYER, USING WARPD
[_COLEMAK] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                KC_QH,    KC_WH,     KC_K,     KC_P,     KC_B,                              KC_J,     KC_L,      KC_U,     KC_Y,   KC_QUOT,
     KC_ESC,    CTL_A,    ALT_R,    GUI_S,    SFT_TT,    HYP_G,                             HYP_M,    SFT_N,     GUI_E,    ALT_I,     CTL_O,  KC_SCLN,
OSM(MOD_LSFT),  KC_ZH,    KC_XH,    KC_CH,     KC_D,     KC_VH,     KC_MUTE,   KC_MPLY,     KC_F,     KC_H,   KC_COMM,   KC_DOT,   KC_SLSH,  OSM(MOD_LSFT),
                                  KC_BTN1,      SPC,       TAB,     QK_AREP,    QK_REP,      BSP,      ENT,       DEL,
                                  KC_WH_U,  KC_WH_D,                                       KC_WH_L,  KC_WH_R
 ),

// NAVIGATION LAYER
[_NAV] = LAYOUT(
//╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                    ___,      ___,      ___,      ___,      ___,                        A(KC_LEFT),A(KC_DOWN),A(KC_UP),A(KC_RIGHT),  G(KC_LEFT),
       KC_TRNS, KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  KC_HYPR,                           KC_LEFT,  KC_DOWN,    KC_UP,   KC_RIGHT,    TG(_NAV),  KC_TRNS,
      TG(_NAV),     ___,      ___,  TG(_FN), TG(_NUM), TG(_BTN),     QK_BOOT,   EE_CLR,    KC_PGDN,  KC_HOME,   KC_END,   KC_PGUP,  G(KC_RIGHT),  TG(_NAV),
                                   TG(_NAV),      SPC,      TAB,     QK_AREP,  QK_REP,      KC_ESC, S(KC_LBRC), S(KC_RBRC),
                                   KC_WH_L,  KC_WH_R,                                         KC_TRNS,   KC_TRNS
),

// NUMBER AND SYMBOL LAYER
[_NUM] = LAYOUT(
   //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
//               DM_REC1,  DM_PLY1,  DM_RSTP,  DM_PLY2,  DM_REC2,                           KC_EQUAL,    KC_7,     KC_8,   KC_9,  KC_0,
                   ___,      ___,      ___,      ___,      ___,                           KC_EQUAL,    KC_7,     KC_8,   KC_9,  KC_0,
      KC_TRNS, KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  KC_HYPR,                           KC_MINUS,    KC_4,     KC_5,   KC_6,  KC_LBRC,  KC_RBRC,
     TG(_NUM),     ___,      ___,  TG(_FN), TG(_NAV), TG(_BTN),     KC_MUTE,   KC_MPLY,     KC_GRV,    KC_1,     KC_2,   KC_3,  KC_BSLS,  TG(_NUM),
                                  TG(_NUM),      SPC,      TAB,     QK_AREP,  QK_REP,          BSP,      ENT,     DEL,
                                   KC_WH_U,  KC_WH_D,                                              KC_WH_L,  KC_WH_R

),


// FUNCTION LAYER
[_FN] = LAYOUT(
     //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
              CMD_SHIFT_3, KC_MPRV,  KC_MPLY,  KC_MNXT, KC_CAPS,                             KC_F12,   KC_F7,   KC_F8,   KC_F9,  KC_F15,
 KC_TRNS,         KC_LCTL, KC_LALT,  KC_LGUI,  KC_LSFT, QK_CAPS_WORD_TOGGLE,                 KC_F11,   KC_F4,   KC_F5,   KC_F6,  KC_F14,  KC_TRNS,
 TG(_FN),         OS_SWAP, KC_LPAD,  KC_BRID,  KC_BRIU, KC_MCTL,      EE_CLR,   QK_BOOT,     KC_F10,   KC_F1,   KC_F2,   KC_F3,  KC_F13,  TG(_FN),
                                     TG(_FN),      SPC,     TAB,     QK_AREP,    QK_REP,      BSP,      ENT,       DEL,
                                     KC_BRID,  KC_BRIU,                                              KC_VOLD,  KC_VOLU

),

// BUTTON LAYER
[_BTN] = LAYOUT(
                 KC_MS_LEFT, KC_ACL0, KC_ACL1,  KC_ACL2, KC_MS_RIGHT,                            ___,          ___,          ___,            ___,  KC_MS_BTN4,
         KC_ESC,    KC_LCTL, KC_LALT, KC_LGUI,  KC_LSFT, KC_HYPR,                         KC_MS_LEFT,   KC_MS_DOWN,      KC_MS_UP,    KC_MS_RIGHT,   TG(_BTN), TG(_BTN),
       TG(_BTN),        ___, KC_ACL0, KC_ACL1,  KC_ACL2, TG(_BTN), KC_MUTE,   KC_MPLY, KC_MS_WH_LEFT,  KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_MS_BTN5, TG(_BTN),
                                      KC_BTN1,  KC_BTN2,  KC_BTN3, QK_AREP,   QK_REP,       KC_TRNS,       KC_TRNS,       KC_TRNS,
                                      KC_VOLD,  KC_VOLU,                                                   KC_BRID,       KC_BRIU

),

// SYMBOL LAYER
[_SYM] = LAYOUT(
        //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                     ___,      ___,   KC_DEL,  KC_BSPC, QK_CAPS_WORD_TOGGLE,                S(KC_EQUAL),    S(KC_7),     S(KC_8),   S(KC_9),  S(KC_0),
       TG(_SYM), KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  KC_HYPR,                           S(KC_MINUS),    S(KC_4),     S(KC_5),   S(KC_6),  S(KC_LBRC),  S(KC_RBRC),
       TG(_SYM),     ___,      ___,  TG(_FN), TG(_NAV), TG(_BTN),     KC_MUTE,   KC_MPLY,     S(KC_GRV),    S(KC_1),     S(KC_2),   S(KC_3),  S(KC_BSLS),    UPDIR,
                                    TG(_SYM),      SPC,     TAB,     QK_AREP,  QK_REP,         COLON_EQ,    KC_SCLN,  S(KC_SCLN),
                                     KC_WH_U,  KC_WH_D,                                                     KC_WH_L,     KC_WH_R
),

};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ LEADER KEY                                                                                                                                 │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘


#ifdef AUDIO_ENABLE
float leader_start_song[][2] = SONG(AUDIO_ON_SOUND);
float leader_succeed_song[][2] = SONG(GUITAR_SOUND);
float leader_fail_song[][2] = SONG(AG_NORM_SOUND);
float QWERTY_SONG[][2] = SONG(STARTUP_SOUND); // _QWERTY
float COLEMAK_SONG[][2] = SONG(PLANCK_SOUND); // _COLEMAK
float NAV_SONG[][2] = SONG(PREONIC_SOUND); // _NAV
float NUM_SONG[][2] = SONG(VOICE_CHANGE_SOUND); // _NUM
float FN_SONG[][2] = SONG(CHROMATIC_SOUND); // _FN
float SYM_SONG[][2] = SONG(MAJOR_SOUND); // _SYM
float BTN_SONG[][2] = SONG(MINOR_SOUND); // _BTN
#endif


#ifdef LEADER_ENABLE

bool did_leader_succeed = false;

#ifdef OLED_ENABLE
const char PROGMEM rec_ico[] = {0xD1, 0xE1, 0};
const char PROGMEM stop_ico[] = {0xD3, 0xE1, 0};
const char PROGMEM play_ico[] = {0xD2, 0xE1, 0};
#endif

void leader_start_user(void) {
    did_leader_succeed = false;
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_start_song);
#endif
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_E)) {
        SEND_STRING(SS_LCTL(SS_LSFT("t")));
        did_leader_succeed = true;
    } else if (leader_sequence_two_keys(KC_E, KC_D)) {
        SEND_STRING(SS_LGUI("r") "cmd\n" SS_LCTL("c"));
        did_leader_succeed = true;
    } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
        // Leader, d, d, s => Types the below string
        SEND_STRING("https://start.duckduckgo.com\n");
        did_leader_succeed = true;
    }
    else if (leader_sequence_one_key(KC_Q)) {
        SEND_STRING(SS_LGUI("q"));
        did_leader_succeed = true;
    }
    else if (leader_sequence_one_key(KC_W)) {
        SEND_STRING(SS_LGUI("w"));
        did_leader_succeed = true;
    }
    else if (leader_sequence_one_key(KC_Z)) {
        SEND_STRING(SS_LGUI("z"));
        did_leader_succeed = true;
    }
    else if (leader_sequence_one_key(KC_X)) {
        SEND_STRING(SS_LGUI("x"));
        did_leader_succeed = true;
    }
    else if (leader_sequence_one_key(KC_C)) {
        SEND_STRING(SS_LGUI("c"));
        did_leader_succeed = true;
    }
    else if (leader_sequence_one_key(KC_V)) {
        SEND_STRING(SS_LGUI("v"));
        did_leader_succeed = true;
    }
//    else if (leader_sequence_one_key(KC_TAB)) {
//        layer_lock_on(_NUM);
//        did_leader_succeed = true;
//    }
//    else if (leader_sequence_one_key(QK_LEAD)) {
//        layer_lock_on(_NAV);
//        did_leader_succeed = true;
//    }
//    else if (leader_sequence_one_key(KC_M)) {
//        layer_lock_on(_QWERTY);
//        did_leader_succeed = true;
//    }
//    else if (leader_sequence_one_key(KC_COMM)) {
//        layer_lock_on(_COLEMAK);
//        did_leader_succeed = true;
//    }
//    else if (leader_sequence_one_key(KC_DOT)) {
//        layer_lock_on(_NAV);
//        did_leader_succeed = true;
//    }
//    else if (leader_sequence_one_key(KC_J)) {
//        layer_lock_on(_NUM);
//        did_leader_succeed = true;
//    }
//    else if (leader_sequence_one_key(KC_K)) {
//        layer_lock_on(_FN);
//        did_leader_succeed = true;
//    }
//    else if (leader_sequence_one_key(KC_L)) {
//        layer_lock_on(_BTN);
//        did_leader_succeed = true;
//    }
//    else if (leader_sequence_one_key(KC_U)) {
//        layer_lock_on(_SYM);
//        did_leader_succeed = true;
//    }

#ifdef AUDIO_ENABLE
    if (did_leader_succeed) {
        PLAY_SONG(leader_succeed_song);
    } else {
        PLAY_SONG(leader_fail_song);
    }
#endif

#ifdef OLED_ENABLE
    if (did_leader_succeed) {
        oled_write_P(play_ico, false);
    } else {
        oled_write_P(stop_ico, false);
    }
#endif
}
#endif


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
//    if (!process_select_word(keycode, record, SELWORD)) { return false; }
//    if (!process_achordion(keycode, record)) { return false; }

    switch (keycode) {
//        case TO_QWERTY:
//            if (record->event.pressed) {
//                set_single_persistent_default_layer(_QWERTY);
//                return false;
//            }
//        case TO_COLEMAK:
//            if (record->event.pressed) {
//                set_single_persistent_default_layer(_COLEMAK);
//                return false;
//            }


        case OS_SWAP:
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                    keymap_config.swap_lctl_lgui = true;  // ─── MAC
                    #ifdef AUDIO_ENABLE
                    PLAY_SONG(mac_song);
                    #endif // AUDIO_ENABLE
                }
                else {
                    keymap_config.swap_lctl_lgui = false; // ─── WIN
                    #ifdef AUDIO_ENABLE
                    PLAY_SONG(winxp_song);
                    #endif // AUDIO_ENABLE
                }
                #ifdef HAPTIC_ENABLE
                DRV_pulse(pulsing_strong);
                #endif // HAPTIC_ENABLE
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard();  // ──── clear to prevent stuck keys
                return false;
            }

        case CMD_SHIFT_3:
            if (record->event.pressed) {
                // Send CMD+SHIFT+3 keypress
                SEND_STRING(SS_LGUI(SS_LSFT("3")));
            }
            break;

        case UPDIR:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            break;

        case COLON_EQ:
            if (record->event.pressed) {
                SEND_STRING(" := ");
            }
            break;

        case KC_QH:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_Q)); // Intercept hold function to send Gui-Q
                return false;
            }
            return true;             // Return true for normal processing of tap keycode

        case KC_WH:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_W)); // Intercept hold function to send Gui-W
                return false;
            }
            return true;             // Return true for normal processing of tap keycode

        case KC_ZH:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_Z)); // Intercept hold function to send Gui-Z
                return false;
            }
            return true;             // Return true for normal processing of tap keycode

        case KC_XH:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_X)); // Intercept hold function to send Gui-X
                return false;
            }
            return true;             // Return true for normal processing of tap keycode

        case KC_CH:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_C)); // Intercept hold function to send Gui-C
                return false;
            }
            return true;             // Return true for normal processing of tap keycode

        case KC_VH:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_V)); // Intercept hold function to send Gui-V
                return false;
            }
            return true;             // Return true for normal processing of tap keycode

//        case KC_ESCH:
//            if (!record->tap.count && record->event.pressed) {
//                tap_code16(KC_CAPS); // Intercept hold function to SEND CAPS LOCK
//                return false;
//            }
//            return true;             // Return true for normal processing of tap keycode

//        case KC_OH:
//            if (!record->tap.count && record->event.pressed) {
//                tap_code16(S(KC_9)); // Intercept hold function to (
//                return false;
//            }
//            return true;             // Return true for normal processing of tap keycode

//        case KC_PH:
//            if (!record->tap.count && record->event.pressed) {
//                tap_code16(S(KC_0)); // Intercept hold function to SEND )
//                return false;
//            }
//            return true;             // Return true for normal processing of tap keycode
//
//        case KC_LLBH: // go to symbol layer on tap and to number layer on hold
//            if (record->tap.count && record->event.pressed) {
//                layer_move(_SYM);
//            } else if (record->event.pressed) {
//                layer_move(_NUM);
//            }
//            return false;
//
//        case KC_RLBH: // go to nav layer on tap and to fn layer on hold
//            if (record->tap.count && record->event.pressed) {
//                layer_move(_NAV);
//            } else if (record->event.pressed) {
//                layer_move(_FN);
//            }
//            return false;
    }
    return true;
}



#ifndef OLED_ENABLE
#ifdef AUDIO_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
//    case _QWERTY:
//        PLAY_SONG(QWERTY_SONG);
//        break;
    case _COLEMAK:
        PLAY_SONG(COLEMAK_SONG);
        break;
    case _NAV:
        PLAY_SONG(NAV_SONG);
        break;
    case _NUM:
        PLAY_SONG(NUM_SONG);
        break;
    case _FN:
        PLAY_SONG(FN_SONG);
        break;
    case _SYM:
        PLAY_SONG(SYM_SONG);
        break;
    }
  return state;
}
#endif
#endif


#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state) < _NAV) {  /* Layer QWERTY and COLEMAK */
        if (index == 0) {
            is_alt_tab_active = true;
            register_code(KC_LGUI);
            if (clockwise) {
                tap_code(KC_TAB);
            } else {
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT); // this fixes the getting stuck problem
            }
        } else {
            is_ctl_tab_active = true;
            register_code(KC_LCTL);
            if (!clockwise) {
                tap_code(KC_TAB);
            } else {
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT); // this fixes the getting stuck problem
            }
        }
        alt_tab_timer = timer_read();
        return false;
    }
    if (index == 0) {
        if (clockwise) {
            tap_code(dynamic_keymap_get_keycode(biton32(layer_state),0,0));
        } else {
            tap_code(dynamic_keymap_get_keycode(biton32(layer_state),3,0));
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(dynamic_keymap_get_keycode(biton32(layer_state),4,0));
        } else {
            tap_code(dynamic_keymap_get_keycode(biton32(layer_state),7,0));
        }
    }
    return false;
}

#endif


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ O L E D                                                                                                                                    │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#ifdef OLED_ENABLE

char layer_state_str[24];
char o_text[24] = "";

// ┌───────────────────────────────────────────────────────────┐
// │ o l e d   g r a p h i c s                                 │
// └───────────────────────────────────────────────────────────┘

void render_os_lock_status(void) {
    static const char PROGMEM sep_v[] = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0};
    static const char PROGMEM sep_h1[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM sep_h2[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM face_1[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xE1, 0};
    static const char PROGMEM face_2[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xE1, 0};
    static const char PROGMEM os_m_1[] = {0x95, 0x96, 0};
    static const char PROGMEM os_m_2[] = {0xB5, 0xB6, 0};
    static const char PROGMEM os_w_1[] = {0x97, 0x98, 0};
    static const char PROGMEM os_w_2[] = {0xB7, 0xB8, 0};
    static const char PROGMEM s_lock[] = {0x8F, 0x90, 0};
    static const char PROGMEM n_lock[] = {0x91, 0x92, 0};
    static const char PROGMEM c_lock[] = {0x93, 0x94, 0};
    static const char PROGMEM b_lock[] = {0xE1, 0xE1, 0};
    #ifdef AUDIO_ENABLE
      static const char PROGMEM aud_en[] = {0xAF, 0xB0, 0};
      static const char PROGMEM aud_di[] = {0xCF, 0xD0, 0};
    #endif
    #ifdef HAPTIC_ENABLE
      static const char PROGMEM hap_en[] = {0xB1, 0xB2, 0};
    #endif

// os mode status ────────────────────────────────────────┐

    oled_write_ln_P(sep_v, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_1, false); // ──── MAC
    } else {
        oled_write_P(os_w_1, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_1, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_2, false); // ──── MAC
    } else {
        oled_write_P(os_w_2, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_2, false);
    oled_write_ln_P(sep_v, false);


// lock key layer status ─────────────────────────────────┐

    led_t led_usb_state = host_keyboard_led_state();

    if (led_usb_state.num_lock) {
        oled_write_P(n_lock, false); // ──── NUMLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.caps_lock) {
        oled_write_P(c_lock, false); // ─── CAPSLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.scroll_lock) { // ─ SCROLLLOCK
        oled_write_P(s_lock, false);
    } else {
        oled_write_P(b_lock, false);
    }


    // hardware feature status ──────────────────────────────┐

    oled_write_P(sep_h2, false);

    #ifndef AUDIO_ENABLE
        oled_write_P(b_lock, false);
    #endif
    #ifndef HAPTIC_ENABLE
        oled_write_P(b_lock, false);
    #endif

    #ifdef AUDIO_ENABLE // ────────────────── AUDIO
        if (is_audio_on()) {
          oled_write_P(aud_en, false);
        } else {
          oled_write_P(aud_di, false);
        }
    #endif // AUDIO ENABLE

     #ifdef HAPTIC_ENABLE // ─────────────── HAPTIC
        oled_write_P(hap_en, false);
     #endif // HAPTIC ENABLE

}


layer_state_t layer_state_set_user(layer_state_t state) {
      switch (get_highest_layer(state)) {
            case _COLEMAK:
                strcpy ( layer_state_str, "1._COLEMAK");
                break;
            case _NAV:
                strcpy ( layer_state_str, "3._NAV");
                break;
            case _NUM:
                strcpy ( layer_state_str, "5._NUM");
                break;
            case _FN:
                strcpy ( layer_state_str, "4._FN");
                break;
            case _BTN:
                strcpy ( layer_state_str, "6._BTN");
                break;
            case _SYM:
                strcpy ( layer_state_str, "2._SYM");
                break;
            default:
                strcpy ( layer_state_str, "...");
      }
  return state;
}


// ┌───────────────────────────────────────────────────────────┐
// │ w r i t e   t o   o l e d                                 │
// └───────────────────────────────────────────────────────────┘



bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }

    if (is_keyboard_master()) {  // ────────────────────────── PRIMARY SIDE

        // layer status ──────────────────────────────────────────────────┐
//        #ifdef DYNAMIC_MACRO_ENABLE
//            if(dmacro_num == 1){ oled_write_P(rec_ico, false); }
//            if(dmacro_num == 2){ oled_write_P(stop_ico, false); }
//            if(dmacro_num == 3){ oled_write_P(play_ico, false); }
//        #endif //DYNAMIC_MACRO_ENABLE


        // layer status ──────────────────────────────────────────────────┐
//        oled_write_ln(o_text, false);
        oled_write_ln(layer_state_str, false);

        render_os_lock_status();

    } else {  // ─────────────────────────────────────────── SECONDARY SIDE

        // KLOR face ─────────────────────────────────────────────────────┐

        static const char PROGMEM klor_face[] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x18, 0x04, 0x02,
            0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc1, 0x01, 0x01, 0x02, 0x02, 0x04, 0x04, 0x04,
            0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40,
            0x80, 0x80, 0x40, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x08,
            0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20,
            0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x18, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x83, 0x83, 0x40, 0x40, 0x40, 0x40, 0x20, 0x21, 0x21, 0x20,
            0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x30, 0x40,
            0x80, 0x80, 0x00, 0x00, 0x01, 0x86, 0x98, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20,
            0x10, 0x10, 0x10, 0x10, 0x08, 0x0f, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x02, 0x04, 0x08, 0x10,
            0x10, 0x20, 0x20, 0x40, 0x40, 0x41, 0x42, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        oled_write_raw_P(klor_face, sizeof(klor_face));
    }
    return false;
}
#endif // OLED_ENABLE
