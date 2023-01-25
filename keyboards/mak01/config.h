#pragma once

#include "config_common.h"

// 键盘配列
#define MATRIX_ROWS 6
#define MATRIX_COLS 4

// 键盘接线引脚定义
#define MATRIX_ROW_PINS { F0, F1, F4, F5, F6, F7 }
#define MATRIX_COL_PINS { B6, B5, B4, D7 }

// 引脚布局排列方式 COL2ROW or ROW2COL
#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { D4 } // 编码器引脚A定义，必须写在键盘config.h中
#define ENCODERS_PAD_B { D6 } // 编码器引脚B定义，必须写在键盘config.h中
#define ENCODER_RESOLUTION 4 // 编码器在每个棘爪之间脉冲个数

#define DYNAMIC_KEYMAP_LAYER_COUNT 3 // VIA软件中 可设置的键层数量（默认4），必须写在键盘config.h中

// 强制开启全键无冲
#define FORCE_NKRO

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 3

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
/* Change USB Polling Rate to 1000hz and a larger keys per scan for elite gaming*/
#define USB_POLLING_INTERVAL_MS 1

// OLED
#ifdef OLED_ENABLE
    #define OLED_DISPLAY_128X64
#endif


#define RGB_DI_PIN D3

#ifdef RGB_DI_PIN
    // #define RGBLIGHT_ANIMATIONS
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
#endif // !RGB_DI_PIN
