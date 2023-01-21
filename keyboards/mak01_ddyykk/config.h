#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4346 /* ASCII码 43=C 46=F */
#define PRODUCT_ID      0x584A /* ASCII码 58=X 4A=J */
#define DEVICE_VER      0x0003
#define MANUFACTURER    Designed by SCF
#define PRODUCT         SCF-NUMPAD-1
//#define DESCRIPTION     www.zfrontier.com/user/home/3132245

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 4

// ROWS: Top to bottom, COLS: Left to right

#define MATRIX_ROW_PINS { F0, F1, F4, F5, F6, F7 }
#define MATRIX_COL_PINS { B6, B5, B4, D7 }
#define UNUSED_PINS

//RGB跟随主机休眠
#define RGBLIGHT_SLEEP
/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/*强制开启全键无冲突*/
#define FORCE_NKRO

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#define RGB_DI_PIN D3
//#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS

#define RGBLIGHT_LAYERS

#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#define OLED_DISPLAY_128X64
#define OLED_DISPLAY_ADDRESS 0x3C
#define OLED_BRIGHTNESS 128

//#endif



//#define NO_ACTION_MACRO          //reducing memory
//#define NO_ACTION_FUNCTION       // reducing memory
#ifndef NO_DEBUG
//#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
