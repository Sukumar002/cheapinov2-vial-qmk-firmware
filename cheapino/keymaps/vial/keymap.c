#include QMK_KEYBOARD_H

#include "dynamic_keymap.h"
#include "eeconfig.h"
#include "vial.h"

// The first five layers are restored from the user's CheapinoV2.vil.
// Layer 5 is intentionally transparent throughout for future customization.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(LT(4, KC_Q), KC_W, KC_E, KC_R, KC_T, KC_MUTE, KC_Y, KC_U, KC_I, KC_O, KC_P, LSFT_T(KC_A), KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, RSFT_T(KC_SCLN), LCTL_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, RCTL_T(KC_SLSH), LGUI_T(KC_ENT), LT(1, KC_TAB), LT(1, KC_TAB), LT(3, KC_BSPC), LT(2, KC_ENT), LGUI_T(KC_SPC)),
    [1] = LAYOUT_split_3x5_3(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, LSFT_T(KC_1), KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, RSFT_T(KC_0), KC_F11, KC_F12, KC_BSLS, KC_LBRC, KC_RBRC, KC_EQUAL, KC_MINUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [2] = LAYOUT_split_3x5_3(KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_SCRL, KC_TRNS, KC_VOLU, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_NUM_LOCK, KC_VOLD, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS_LOCK, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [3] = LAYOUT_split_3x5_3(KC_TRNS, QK_MAGIC_SWAP_LALT_LGUI, QK_MAGIC_UNSWAP_LALT_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [4] = LAYOUT_split_3x5_3(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL0, KC_TRNS, KC_WH_D, KC_WH_L, KC_MS_U, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL1, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN4, KC_BTN5, KC_BTN3, KC_BTN2, KC_BTN1),
    [5] = LAYOUT_split_3x5_3(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

// Seed the Vial combo table after EEPROM and Vial initialization have completed.
// The marker makes this a one-time default: later user edits (including clearing
// all combos) are never overwritten on subsequent boots.
#define CHEAPINO_VIAL_DEFAULT_COMBOS_MAGIC 0x4348504F

void keyboard_post_init_user(void) {
    if (eeconfig_read_kb() == CHEAPINO_VIAL_DEFAULT_COMBOS_MAGIC) {
        return;
    }

    bool has_existing_combo = false;
    for (uint8_t i = 0; i < VIAL_COMBO_ENTRIES; ++i) {
        vial_combo_entry_t entry = {0};
        if (dynamic_keymap_get_combo(i, &entry) != 0) {
            continue;
        }
        if (entry.input[0] != KC_NO || entry.input[1] != KC_NO ||
            entry.input[2] != KC_NO || entry.input[3] != KC_NO ||
            entry.output != KC_NO) {
            has_existing_combo = true;
            break;
        }
    }

    if (!has_existing_combo) {
        static const vial_combo_entry_t defaults[] = {
            {{KC_J, KC_K, KC_NO, KC_NO}, LALT_T(KC_BSPC)},
            {{KC_D, KC_F, KC_NO, KC_NO}, LALT_T(KC_TAB)},
            {{KC_S, KC_D, KC_NO, KC_NO}, LGUI_T(KC_GRV)},
            {{KC_K, KC_L, KC_NO, KC_NO}, LGUI_T(KC_DEL)},
            {{KC_J, KC_L, KC_NO, KC_NO}, LCTL_T(KC_QUOT)},
            {{KC_S, KC_F, KC_NO, KC_NO}, LCTL_T(KC_ESC)},
        };
        _Static_assert(sizeof(defaults) / sizeof(defaults[0]) <= VIAL_COMBO_ENTRIES,
                       "VIAL_COMBO_ENTRIES is too small for Cheapino defaults");

        for (uint8_t i = 0; i < sizeof(defaults) / sizeof(defaults[0]); ++i) {
            if (dynamic_keymap_set_combo(i, &defaults[i]) != 0) {
                // Do not mark initialization complete if EEPROM rejected a write.
                return;
            }
        }
    }

    eeconfig_update_kb(CHEAPINO_VIAL_DEFAULT_COMBOS_MAGIC);
    // vial_init() already ran earlier in keyboard_setup(); reload now that the
    // defaults have been written so the combo engine sees them immediately.
    vial_init();
}

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [4] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [5] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
