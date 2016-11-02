#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // Media Layer
// #define NPAD 2 // numpad

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
[MDIA] = KEYMAP(
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



/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
    CUSTOM_KEY,
    L_CTRL_ALT_ENT,
    R_CTRL_ALT_ENT,
    LSFT_2_CAP,
    RSFT_2_CAP,
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),        // FN1  = Momentary Layer 1 (Symbols)
    [2] = ACTION_FUNCTION(LSFT_2_CAP),          // FN29 = Toggle CapsLock if both Shifts hit
    [3] = ACTION_FUNCTION(RSFT_2_CAP),          // FN30 = Toggle CapsLock if both Shifts hit
    [4] = ACTION_LAYER_MOMENTARY(1),            // FN4  = Momentary Layer to use with F* keys on top row
    [5] = ACTION_LAYER_MOMENTARY(2),            // FN5  = Momentary to use with F* keys on top row + util
    [6] = ACTION_MODS_KEY(KC_LSFT, KC_SCLN),    // FN1  = Shifted SemiColon // : in Workman
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
    {
        // print("action_function called\n");
        // print("id  = "); phex(id); print("\n");
        // print("opt = "); phex(opt); print("\n");

    // Toggle capslock when pressing both left and right shift keys
    //
    if (id == LSFT_2_CAP || id == RSFT_2_CAP) {
        uint8_t curr_weak_mods = 0;

        // Set weak_mods value for each shift key
        if (id == LSFT_2_CAP) {
            dprintf("->left shift: %u\n", id);
            curr_weak_mods = MOD_BIT(KC_LSHIFT);
        } else {
            dprintf("->right shift: %u\n", id);
            curr_weak_mods = MOD_BIT(KC_RSHIFT);
        }

        if (record->event.pressed) {

            // Get the previous weak_mods value
            uint8_t prev_weak_mods = get_weak_mods();
            dprintf("-->prev_weak_mods: %u\n", prev_weak_mods);

            // When a shift key is pressed, check previous weak_mods value.
            // If 0, then no shift key is held down.
            // If not 0, then at least one shift key is held down.
            if (prev_weak_mods != 0) {

                // Toggle capslock if more than one shift key is pressed.
                dprintf("--->press, toggle capslock\n");
                add_key(KC_CAPSLOCK);
                send_keyboard_report();
                del_key(KC_CAPSLOCK);
                send_keyboard_report();
            } else {

                // Set the appropriate weak_mods value if just one shift key is pressed.
                dprintf("--->press, curr_weak_mods: %u\n", curr_weak_mods);
                add_weak_mods(curr_weak_mods);
                send_keyboard_report();
            }
        } else {

            // Unset the weak_mods value when shift key is released.
            dprintf("--->release, curr_weak_mods: %u\n", curr_weak_mods);
            del_weak_mods(curr_weak_mods);
            send_keyboard_report();
        }
    }
};
