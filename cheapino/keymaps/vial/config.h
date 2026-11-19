#pragma once

#define VIAL_KEYBOARD_UID {0x79, 0xED, 0x40, 0xBB, 0x09, 0x8B, 0xC1, 0x9E}
// Unlock combo is two inner thumb keys.
#define VIAL_UNLOCK_COMBO_ROWS { 6, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 11, 5 }

// Dynamic Vial feature allocation.
#define DYNAMIC_KEYMAP_LAYER_COUNT 14
#define VIAL_COMBO_ENTRIES 16
#define VIAL_TAP_DANCE_ENTRIES 16

// Evaluate Vial combos using layer 0 keycodes, regardless of the active layer.
#define COMBO_ONLY_FROM_LAYER 0

// Default tap-hold timing (milliseconds).
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 175
