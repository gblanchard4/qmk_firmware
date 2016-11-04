#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "macro.h"
// WUT
#include "keycode.h"
#include "action.h"
#include "action_util.h"
#include "action_code.h"
#include "action_macro.h"
#include "action_layer.h"
#include "bootloader.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"
#include "ergodox.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NPAD 2 // numpad

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | MUTE |           | PSCR|   6  |   7  |   8  |   9  |   0  |  CAD    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   F  |   P  |   G  |  [   |           |  ]   |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSpc  |   A  |   R  |   S  |   T  |  D   |------|           |------|   H  |   N  |   E  |   I  |   O  |   '    |
 * |--------+------+------+------+------+------|  -   |           |   =  |------+------+------+------+------+--------|
 * |Shft2Cap|Z/Undo| X/Cut|C/Copy|V/Paste|  B  |      |           |      |   K  |   M  |   ,  |   .  |  /   |Shft2Cap|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  LGui |AltShf| Left | Right|                                       |  Down|  Up  | Left | Right| RCTL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | VolUp| VolDn|       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Prev |       | PgUp |        |      |
 *                                 | Space| Del  |------|       |------| Enter  | Bksp |
 *                                 |      |      | Next |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,         KC_3,        KC_4,      KC_5,          KC_MUTE,
        KC_TAB,         KC_Q,         KC_W,         KC_F,        KC_P,      KC_G,          KC_LBRC,
        KC_LCTL,        KC_A,         KC_R,         KC_S,        KC_T,      KC_D,
        KC_FN2,     CTL_T(KC_Z),  CTL_T(KC_X),  CTL_T(KC_C), CTL_T(KC_V),      KC_B,          KC_MINS,
        KC_ESC,      KC_LGUI,  LALT(KC_LSFT),        MO(1),       MO(2),
                                                              KC_VOLU,   KC_VOLD,
                                                                         KC_MPRV,
                                                  KC_SPC,      KC_DEL,   KC_MNXT,
        // right hand
        KC_PSCR,       KC_6,          KC_7,          KC_8,        KC_9,      KC_0,          LALT(LCTL(KC_DEL)),
        KC_RBRC,       KC_J,          KC_L,          KC_U,        KC_Y,   KC_SCLN,          KC_BSLS,
                       KC_H,          KC_N,          KC_E,        KC_I,      KC_O,          KC_QUOT,
        KC_EQL,        KC_K,          KC_M,       KC_COMM,       KC_DOT,  KC_SLSH,              KC_FN3,
                                   KC_DOWN,         KC_UP,      KC_LEFT,  KC_RGHT,          KC_RCTL,
                    KC_MPLY,       KC_CALC,
                    KC_PGUP,
                    KC_PGDN,        KC_ENT,        KC_BSPC
),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,    KC_F1,    KC_F2,      KC_F3,     KC_F4,     KC_F5,     KC_TRNS,
       KC_TRNS,  KC_EXLM,    KC_AT,    KC_LCBR,   KC_RCBR,   KC_PIPE,     KC_TRNS,
       KC_TRNS,  KC_HASH,   KC_DLR,    KC_LPRN,   KC_RPRN,    KC_GRV,
       KC_TRNS,  KC_PERC,  KC_CIRC,    KC_LBRC,   KC_RBRC,   KC_TILD,     KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_TRNS,
                                       KC_TRNS,   KC_TRNS,
                                                  KC_TRNS,
                               KC_TRNS,KC_TRNS,   KC_TRNS,
       // right hand
       KC_TRNS,   KC_F6,    KC_F7,       KC_F8,     KC_F9,     KC_F10,     KC_F11,
       KC_TRNS,   KC_UP,     KC_7,        KC_8,      KC_9,    KC_ASTR,     KC_F12,
                KC_DOWN,     KC_4,        KC_5,      KC_6,    KC_PLUS,    KC_TRNS,
       KC_TRNS, KC_AMPR,     KC_1,        KC_2,      KC_3,    KC_BSLS,    KC_TRNS,
                          KC_TRNS,      KC_DOT,      KC_0,     KC_EQL,    KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_TRNS
),
/* Keymap 2: Numpad
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      | NumLk|    / |   *  |   -  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  7   |  8   |  9   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   :  |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   /  |   1  |   2  |   3  | Enter|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |   0  |   .  | Enter|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Numpad Layer
[NPAD] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_TRNS, KC_TRNS,
                     KC_FN6, KC_KP_4, KC_KP_5, KC_KP_6, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_SLSH, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, KC_TRNS,
                          KC_KP_0, KC_KP_0, KC_DOT,  KC_PENT, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};
