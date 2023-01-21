#include QMK_KEYBOARD_H

// Layers
enum layers {
    BASE         = 0,
    Base_2       = 1,
    NumberPad    = 2,
    VS_Code      = 3,
    IDEA         = 4,
    Sai          = 5,
    Photoshop    = 6,
    Da_Vinci     = 7,
    Excel        = 8,
    Vim          = 9,
    Key_Settings = 10,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Keymap BASE: (Base Layer) Default Layer. These keymaps doesn't really matter,
    as I defined 16 layers for the keyboard, only 2 mentioned below,
    because I am going to define all the keys in VIA*/
    [BASE] = LAYOUT(KC_MPLY, TO(1), KC_NO, KC_NO, KC_NLCK, KC_BSPC, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_P4, KC_P5, KC_P6, KC_PAST, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_PENT, KC_P0, KC_PDOT, KC_PPLS),

    /* Keymap Key_Settings: (Key_Settings Layer)*/
    [Key_Settings] = LAYOUT(RGB_TOG, TO(0), KC_NO, KC_NO, RGB_HUI, RGB_HUD, KC_NO, KC_NO, RGB_SAI, RGB_SAD, KC_NO, KC_NO, RGB_VAI, RGB_VAD, KC_NO, KC_NO, RGB_MOD, RGB_RMOD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET)

};

// 按下 Capslock 的時候，第 6 個 RGB 燈與之後 (也就第 7 個) 的 4 個會亮與第 12 個燈 RGB (也就是第 13 個) 之後的 4 個燈會亮紅色。
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //    {7, 1, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {4, 4, HSV_RED} // Light 4 LEDs, starting with LED 12
);
// Layer 1 啟用的時候，第 9, 10 個燈會亮
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 5, HSV_CYAN});
// Layer 2 啟用的時候，第 11 與 12 個燈會亮紫色。
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({6, 1, HSV_PURPLE});
// etc..

// 接者將您的 rgblight_segment_t 放到 RGBLIGHT_LAYERS_LIST 內
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(my_capslock_layer,
                                                                               my_layer1_layer, // Overrides caps lock layer
                                                                               my_layer2_layer  // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    /*  oled_write_P(PSTR("Layer: "), false); */

    /*   uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("-NUM  ON- ") :  PSTR("-NUM OFF- "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("-CAP  ON- \n") :  PSTR("-CAP OFF- \n"), false);
    */

    //  oled_write_P(PSTR("====================\n"), false);

    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("Layer:System 0\n"), false);
            oled_write_P(PSTR("====================\n"), false);
            oled_write_P(PSTR("To_1 Lyr+\n"), false);
            oled_write_P(PSTR("MyCp Al+T  WinD Mute\n"), false);
            oled_write_P(PSTR("Home End   Scrn Undo\n"), false);
            oled_write_P(PSTR("All  LstPg Lang Save\n"), false);
            oled_write_P(PSTR("Entr Past  Copy Cut \n"), false);
            break;
        case Base_2:
            oled_write_P(PSTR("Layer: Sys_2 1\n"), false);
            oled_write_P(PSTR("====================\n"), false);
            oled_write_P(PSTR("N/A  LED \n"), false);
            oled_write_P(PSTR("WinX WTab Vkey Hide\n"), false);
            oled_write_P(PSTR("Lock Max  PUp  PDow\n"), false);
            oled_write_P(PSTR("Cr+F Min  Cal  Zom-\n"), false);
            oled_write_P(PSTR("**** **** Zom0 Zom+\n"), false);
            break;
        case NumberPad:
            oled_write_P(PSTR("Layer: NumberPad 2\n"), false);
            oled_write_P(PSTR("====================\n"), false);
            oled_write_P(PSTR("Lyr-  Lyr+\n"), false);
            oled_write_P(PSTR("7    8    9    /   \n"), false);
            oled_write_P(PSTR("4    5    6    *   \n"), false);
            oled_write_P(PSTR("1    2    3    -   \n"), false);
            oled_write_P(PSTR("Entr 0    .    +   \n"), false);
            break;
        case VS_Code:
            oled_write_P(PSTR("Layer: VS_Code 3\n"), false);
            oled_write_P(PSTR("====================\n"), false);
            oled_write_P(PSTR("Lyr-  Lyr+\n"), false);
            oled_write_P(PSTR("Comt Srch Fmat Undo\n"), false);
            oled_write_P(PSTR("Repl Find Mov+ Mov-\n"), false);
            oled_write_P(PSTR("Comd Home Cp+  Cp- \n"), false);
            oled_write_P(PSTR("HidN End  Setn Save\n"), false);
            break;
        case IDEA:
            oled_write_P(PSTR("Layer: IDEA 4\n"), false);
            oled_write_P(PSTR("====================\n"), false);
            oled_write_P(PSTR("Lyr-  Lyr+\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case Sai:
            oled_write_P(PSTR("Layer: Sai 5\n"), false);
            oled_write_P(PSTR("====================\n"), false);
            oled_write_P(PSTR("Lyr-  Lyr+\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case Photoshop:
            oled_write_P(PSTR("Layer: Photoshop 6\n"), false);
            oled_write_P(PSTR("====================\n"), false);
            oled_write_P(PSTR("Lyr-  Lyr+\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case Da_Vinci:
            oled_write_P(PSTR("Layer: Da_Vinci 7\n"), false);
            oled_write_P(PSTR("====================\n"), false);
            oled_write_P(PSTR("Lyr-  Lyr+\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case Excel:
            oled_write_P(PSTR("Layer: Excel 8\n"), false);
            oled_write_P(PSTR("====================\n"), false);
            oled_write_P(PSTR("Lyr-  Lyr+\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case Vim:
            oled_write_P(PSTR("Layer: Vim 9\n"), false);
            oled_write_P(PSTR("====================\n"), false);
            oled_write_P(PSTR("Lyr-  Lyr+\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case Key_Settings:
            oled_write_P(PSTR("Layer:Key_Settings10\n"), false);
            oled_write_P(PSTR("====================\n"), false);
            oled_write_P(PSTR("Lyr-  Lyr+\n"), false);
            oled_write_P(PSTR("Hue+ Hue- Sat+ Sat-\n"), false);
            oled_write_P(PSTR("Bri+ Bri- EFX+ EFX-\n"), false);
            oled_write_P(PSTR("REST\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
    }

    /*  oled_write_P(PSTR("Stats:\n"), false); */

    // oled_write_P(PSTR("====================\n"), false);
    return false;
}
#endif

// Encoder Variables

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
