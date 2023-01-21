#include QMK_KEYBOARD_H

// Layers
enum layers {
  BASE,
  FN,
  FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_MUTE, TO(0), KC_Y, KC_Z,
        TO(1),   TO(2), KC_C, KC_D,
        KC_E,    KC_F,  KC_G, KC_H,
        KC_I,    KC_J,  KC_K, KC_L,
        KC_M,    KC_N,  KC_O, KC_P,
        KC_Q,    KC_R,  KC_S, KC_T),
    [FN] = LAYOUT(
        RGB_TOG, TO(0),   KC_TRNS, KC_TRNS,
        TO(1),   TO(2),   KC_TRNS, KC_TRNS,
        RGB_HUI, RGB_SPI, KC_TRNS, KC_TRNS,
        RGB_HUD, RGB_SPD, KC_TRNS, KC_TRNS,
        RGB_VAI, RGB_SAI, KC_TRNS, KC_TRNS,
        RGB_VAD, RGB_SAD, KC_TRNS, KC_TRNS),
    [FN2] = LAYOUT(
        KC_TRNS, TO(0),   KC_TRNS, KC_TRNS,
        TO(1),   TO(2),   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};


#ifdef RGBLIGHT_ENABLE
    // // 按下 Capslock 的時候，第 6 個 RGB 燈與之後 (也就第 7 個) 的 4 個會亮與第 12 個燈 RGB (也就是第 13 個) 之後的 4 個燈會亮紅色。
    // const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //     {4, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
    // );
    // // Layer 1 啟用的時候，第 9, 10 個燈會亮
    // const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //     {0, 5, HSV_CYAN}
    // );
    // // Layer 2 啟用的時候，第 11 與 12 個燈會亮紫色。
    // const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //     {6, 1, HSV_PURPLE}
    // );


    // // 接者將您的 rgblight_segment_t 放到 RGBLIGHT_LAYERS_LIST 內
    // const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    //     my_capslock_layer,
    //     my_layer1_layer, // Overrides caps lock layer
    //     my_layer2_layer // Overrides other layers
    // );

    // void keyboard_post_init_user(void) {
    //     // Enable the LED layers
    //     rgblight_layers = my_rgb_layers;
    // }

    // layer_state_t layer_state_set_user(layer_state_t state) {
    //     // Both layers will light up if both kb layers are active
    //     rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    //     rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    //     return state;
    // }

    // bool led_update_user(led_t led_state) {
    //     rgblight_set_layer_state(0, led_state.caps_lock);
    //     return true;
    // }

#endif


#ifdef OLED_ENABLE
    bool oled_task_user(void) {
        // Line 1
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state)) {
            case BASE:
                oled_write_P(PSTR("0"), false);
                break;
            case FN:
                oled_write_P(PSTR("1"), false);
                break;
            case FN2:
                oled_write_P(PSTR("2"), false);
                break;
            default:
                oled_write_P(PSTR("X"), false);
        }

        oled_write_P(PSTR(" LED: "), false);
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.num_lock ? PSTR("N") : PSTR(" "), false);
        oled_write_P(led_state.caps_lock ? PSTR("C") : PSTR(" "), false);
        oled_write_P(led_state.scroll_lock ? PSTR("S") : PSTR(" "), false);
        oled_write_P(PSTR("\n"), false);

        // Line 2
        oled_write_P(PSTR("====================\n"), false);

        // Line 3-8
        switch (get_highest_layer(layer_state)) {
            case BASE:
                oled_write_P(PSTR("detail BASE\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                break;
            case FN:
                oled_write_P(PSTR("HUI SPI ___ ___\n"), false);
                oled_write_P(PSTR("HUD SPD ___ ___\n"), false);
                oled_write_P(PSTR("VAI SAI ___ ___\n"), false);
                oled_write_P(PSTR("VAD SAD ___ ___\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                break;
            case FN2:
                oled_write_P(PSTR("detail FN2\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                break;
            default:
                oled_write_P(PSTR("detail default\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
        }

        return false;
    }
#endif


#ifdef ENCODER_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
        if (IS_LAYER_ON(BASE)) {
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            }
        }else if (IS_LAYER_ON(FN)) {
            if (index == 0) {
                if (clockwise) {
                    // 灯光控制，必须用函数控制，不能用tap_code
                    rgblight_step();
                } else {
                    rgblight_step_reverse();
                }
            }
        }

        return false;
    }
#endif
