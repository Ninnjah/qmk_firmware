/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#define EE_HANDS

// Disabled to save space
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT
// #define DISABLE_LEADER

// Vial Support
#define VIAL_KEYBOARD_UID { 0x05, 0xCD, 0x9F, 0x8A, 0xF4, 0xDF, 0xDE, 0xB2 }
#define VIAL_UNLOCK_COMBO_ROWS { 0, 1 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }
// Set number of layers for VIA (+30 per layer)
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

/* By default left side is selected as master, 
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options. */

// Add RGB underglow and top facing lighting
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE

#define WS2812_DI_PIN D3
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 14
#undef RGBLED_SPLIT
#define RGBLED_SPLIT {7, 7}
#define RGBLIGHT_LED_MAP { 1, 4, 3, 2, 7, 6, 5, 1, 4, 3, 2, 7, 6, 5}
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_HUE_STEP 3
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_GRADIENT+0

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE