#include QMK_KEYBOARD_H


const uint8_t PROGMEM default_color[3] = {0xC9, 0x00, 0x7A};
const uint8_t PROGMEM LEDS[][8] = {
    {3, 4, 5, 0, 3+7, 4+7, 5+7, 0},
    {1, 2, 6, 7, 1+7, 2+7, 6+7, 7+7},
};
const uint8_t PROGMEM RGB_LAYER = 2;
uint8_t HUE_STEP = 40;
uint8_t color_mode = 0;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t layer = get_highest_layer(layer_state);
    if (layer != 2) {
        return true;
    }

    switch (keycode) {
        case KC_Z:
            if (record->event.pressed) {
                HSV rgb_config = rgblight_get_hsv();
                if (color_mode % 2 == 1) {
                    rgb_config.h = (rgb_config.h + HUE_STEP) % 255;
                } else {
                    rgb_config.h = (rgb_config.h - HUE_STEP) % 255;
                }
                for (uint8_t led_index = 0; led_index < 4; led_index++) {
                    rgblight_sethsv_at(rgb_config.h, rgb_config.s, rgb_config.v, led_index);
                }
                rgblight_set();
                color_mode = color_mode + 1;
            } else {
                HSV rgb_config = rgblight_get_hsv();
                for (uint8_t led_index = 0; led_index < 4; led_index++) {
                    rgblight_sethsv_at(rgb_config.h, rgb_config.s, rgb_config.v, led_index);
                }
                rgblight_set();
            }
            break;
        
        case KC_X:
            if (record->event.pressed) {
                HSV rgb_config = rgblight_get_hsv();
                if (color_mode % 2 == 1) {
                    rgb_config.h = (rgb_config.h + HUE_STEP) % 255;
                } else {
                    rgb_config.h = (rgb_config.h - HUE_STEP) % 255;
                }
                for (uint8_t led_index = 0; led_index < 4; led_index++) {
                    rgblight_sethsv_at(rgb_config.h, rgb_config.s, rgb_config.v, led_index);
                }
                rgblight_set();
                color_mode = color_mode + 1;
            } else {
                HSV rgb_config = rgblight_get_hsv();
                for (uint8_t led_index = 0; led_index < 4; led_index++) {
                    rgblight_sethsv_at(rgb_config.h, rgb_config.s, rgb_config.v, led_index);
                }
                rgblight_set();
            }
            break;
        
        case KC_F13:
            if (record->event.pressed) {
                HUE_STEP = (HUE_STEP + 10) % 255;
            }
            return false;
        
        case KC_F14:
            if (record->event.pressed) {
                HUE_STEP = (HUE_STEP - 10) % 255;
            }
            return false;

        default:
            break;
    }
    return true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case RGB_LAYER:
            rgblight_setrgb(default_color[0], default_color[1], default_color[2]);
            break;
        default: // for any other layers, or the default layer
            rgblight_mode(RGBLIGHT_MODE_STATIC_GRADIENT);
            break;
    }
  return state;
}
