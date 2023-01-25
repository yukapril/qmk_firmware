#include QMK_KEYBOARD_H

// Layers
enum layers {
  BASE,
  LED,
  FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_MUTE, TO(0),   _______, _______,
        TO(1),   TO(2),   _______, _______,
        KC_7,    KC_8,    KC_9,    KC_DEL,
        KC_4,    KC_5,    KC_6,    KC_BSPC,
        KC_1,    KC_2,    KC_3,    KC_ENT,
        LCTL(KC_C), LCTL(KC_V), LCTL(KC_X), LCTL(KC_A)),
    [LED] = LAYOUT(
        RGB_TOG, TO(0),   _______, _______,
        TO(1),   TO(2),   _______, _______,
        RGB_HUI, RGB_SAI, RGB_SPI, RGB_VAI,
        RGB_HUD, RGB_SAD, RGB_SPD, RGB_VAD,
        _______, _______, _______, _______,
        _______, _______, _______, _______),
    [FN] = LAYOUT(
        _______, TO(0),   _______, _______,
        TO(1),   TO(2),   _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______)
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
        oled_write_P(PSTR("LAYER:"), false);
        switch (get_highest_layer(layer_state)) {
            case BASE:
                oled_write_P(PSTR("BASE"), false);
                break;
            case LED:
                oled_write_P(PSTR("LED "), false);
                break;
            case FN:
                oled_write_P(PSTR("FUNC"), false);
                break;
            default:
                oled_write_P(PSTR("XXXX"), false);
        }

        oled_write_P(PSTR(" STAT: "), false);
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
                oled_write_P(PSTR(" 7    8    9   DEL\n"), false);
                oled_write_P(PSTR(" 4    5    6   BSPC\n"), false);
                oled_write_P(PSTR(" 1    2    3   ENT\n"), false);
                oled_write_P(PSTR("COPY PAST CUT  SALL\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                break;
            case LED:
                oled_write_P(PSTR("HUE+ SAT+ SPD+ BRT+\n"), false);
                oled_write_P(PSTR("HUE- SAT- SPD- BRT-\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                break;
            case FN:
                oled_write_P(PSTR("M1   M2   M3   M4\n"), false);
                oled_write_P(PSTR("M5   M6   M7   M8\n"), false);
                oled_write_P(PSTR("M9   M10  M11  M12\n"), false);
                oled_write_P(PSTR("M0   M13  M14  M15\n"), false);
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
        }else if (IS_LAYER_ON(LED)) {
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
