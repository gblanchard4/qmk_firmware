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
    // [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),        // FN1  = Momentary Layer 1 (Symbols)
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


// void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
//     {
//         // print("action_function called\n");
//         // print("id  = "); phex(id); print("\n");
//         // print("opt = "); phex(opt); print("\n");
// 
//     // Toggle capslock when pressing both left and right shift keys
//     //
//     if (id == LSFT_2_CAP || id == RSFT_2_CAP) {
//         uint8_t curr_weak_mods = 0;
// 
//         // Set weak_mods value for each shift key
//         if (id == LSFT_2_CAP) {
//             dprintf("->left shift: %u\n", id);
//             curr_weak_mods = MOD_BIT(KC_LSHIFT);
//         } else {
//             dprintf("->right shift: %u\n", id);
//             curr_weak_mods = MOD_BIT(KC_RSHIFT);
//         }
// 
//         if (record->event.pressed) {
// 
//             // Get the previous weak_mods value
//             uint8_t prev_weak_mods = get_weak_mods();
//             dprintf("-->prev_weak_mods: %u\n", prev_weak_mods);
// 
//             // When a shift key is pressed, check previous weak_mods value.
//             // If 0, then no shift key is held down.
//             // If not 0, then at least one shift key is held down.
//             if (prev_weak_mods != 0) {
// 
//                 // Toggle capslock if more than one shift key is pressed.
//                 dprintf("--->press, toggle capslock\n");
//                 add_key(KC_CAPSLOCK);
//                 send_keyboard_report();
//                 del_key(KC_CAPSLOCK);
//                 send_keyboard_report();
//             } else {
// 
//                 // Set the appropriate weak_mods value if just one shift key is pressed.
//                 dprintf("--->press, curr_weak_mods: %u\n", curr_weak_mods);
//                 add_weak_mods(curr_weak_mods);
//                 send_keyboard_report();
//             }
//         } else {
// 
//             // Unset the weak_mods value when shift key is released.
//             dprintf("--->release, curr_weak_mods: %u\n", curr_weak_mods);
//             del_weak_mods(curr_weak_mods);
//             send_keyboard_report();
//         }
//     }
// };

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
    {
        // print("action_function called\n");
        // print("id  = "); phex(id); print("\n");
        // print("opt = "); phex(opt); print("\n");

    // Toggle capslock when pressing both left and right shift keys
    //
    if (id == LSFT_2_CAP && id == RSFT_2_CAP) {
        uint8_t curr_weak_mods = 0;
            add_key(KC_R);            
            add_key(KC_L);
            send_keyboard_report();
    }
    else if (id == LSFT_2_CAP || id == RSFT_2_CAP) {
        uint8_t curr_weak_mods = 0;

        // Set weak_mods value for each shift key
        if (id == LSFT_2_CAP) {
            add_key(KC_L);
            send_keyboard_report();
        } else {
            add_key(KC_R);
            send_keyboard_report();
        }
    }
};
