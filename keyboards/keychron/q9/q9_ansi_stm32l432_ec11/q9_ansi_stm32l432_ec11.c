/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
const ckled2001_led PROGMEM g_ckled2001_leds[DRIVER_LED_TOTAL] = {
/* Refer to CKLED manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, I_1,    G_1,    H_1},
    {0, I_2,    G_2,    H_2},
    {0, I_3,    G_3,    H_3},
    {0, I_4,    G_4,    H_4},
    {0, I_5,    G_5,    H_5},
    {0, I_6,    G_6,    H_6},
    {0, I_7,    G_7,    H_7},
    {0, I_8,    G_8,    H_8},
    {0, I_9,    G_9,    H_9},
    {0, I_10,   G_10,   H_10},
    {0, I_11,   G_11,   H_11},
    {0, I_12,   G_12,   H_12},
    {0, I_13,   G_13,   H_13},
    {0, I_14,   G_14,   H_14},
    {0, I_15,   G_15,   H_15},

    {0, F_1,    D_1,    E_1},
    {0, F_2,    D_2,    E_2},
    {0, F_3,    D_3,    E_3},
    {0, F_4,    D_4,    E_4},
    {0, F_5,    D_5,    E_5},
    {0, F_6,    D_6,    E_6},
    {0, F_7,    D_7,    E_7},
    {0, F_8,    D_8,    E_8},
    {0, F_9,    D_9,    E_9},
    {0, F_10,   D_10,   E_10},
    {0, F_11,   D_11,   E_11},
    {0, F_12,   D_12,   E_12},
    {0, F_13,   D_13,   E_13},
    {0, F_14,   D_14,   E_14},
    {0, F_15,   D_15,   E_15},

    {0, C_1,    A_1,    B_1},
    {0, C_2,    A_2,    B_2},
    {0, C_3,    A_3,    B_3},
    {0, C_4,    A_4,    B_4},
    {0, C_5,    A_5,    B_5},
    {1, C_10,   A_10,   B_10},
    {1, C_9,    A_9,    B_9},
    {1, C_8,    A_8,    B_8},
    {1, C_7,    A_7,    B_7},
    {1, C_6,    A_6,    B_6},
    {1, C_5,    A_5,    B_5},
    {1, C_4,    A_4,    B_4},
    {1, C_3,    A_3,    B_3},
    {1, C_2,    A_2,    B_2},
    {1, C_1,    A_1,    B_1},

    {1, I_15,   G_15,   H_15},
    {1, I_13,   G_13,   H_13},
    {1, I_12,   G_12,   H_12},
    {1, I_11,   G_11,   H_11},
    {1, I_10,   G_10,   H_10},
    {1, I_9,    G_9,    H_9},
    {1, I_8,    G_8,    H_8},
    {1, I_7,    G_7,    H_7},
    {1, I_6,    G_6,    H_6},
    {1, I_5,    G_5,    H_5},
    {1, I_4,    G_4,    H_4},
    {1, I_3,    G_3,    H_3},
    {1, I_2,    G_2,    H_2},
    {1, I_1,    G_1,    H_1},

    {1, F_15,   D_15,   E_15},
    {1, F_14,   D_14,   E_14},
    {1, F_13,   D_13,   E_13},
    {1, F_12,   D_12,   E_12},
    {1, F_9,    D_9,    E_9},
    {1, F_8,    D_8,    E_8},
    {1, F_7,    D_7,    E_7},
    {1, F_6,    D_6,    E_6},
    {1, F_3,    D_3,    E_3},
    {1, F_2,    D_2,    E_2},
    {1, F_1,    D_1,    E_1}
};

led_config_t g_led_config = {
     {
        {  0,      1,      2,      3,      4,      5,      6,      7,      8,      9,     10,     11,     12,     13,     14 },
        { 15,     16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     29 },
        { 30,     31,     32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43,     44 },
        { 45, NO_LED,     46,     47,     48,     49,     50,     51,     52,     53,     54,     55,     56,     57,     58 },
        { 59,     60,     61,     62, NO_LED, NO_LED,     63,     64,     65,     66, NO_LED, NO_LED,     67,     68,     69 }
    },
    {
        {0, 0}, {14, 0}, {28, 0}, {42, 0}, {56, 0}, {70, 0}, {98, 0}, {112, 0}, {126, 0}, {140, 0}, {154, 0}, {168, 0}, {182, 0}, {196, 0},           {224, 0},
        {0,16}, {28,16}, {42,16}, {56,16}, {70,16}, {98,16}, {84,16}, {112,16}, {126,16}, {140,16}, {154,16}, {168,16}, {182,16}, {196,16},           {224,16},
        {0,32}, {28,32}, {42,32}, {56,32}, {70,32}, {98,32}, {84,32}, {112,32}, {126,32}, {140,32}, {154,32}, {168,32}, {182,32}, {196,32},           {224,32},
        {0,48},          {28,48}, {42,48}, {56,48}, {70,48}, {98,48}, {112,48}, {126,48}, {140,48}, {154,48}, {168,48}, {182,48}, {196,48}, {210,48},
        {0,64}, {14,64}, {42,64},          {70,64},          {98,64}, {112,64},           {140,64},           {168,64},           {196,64}, {210,64}, {224,64}
    },
    {
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,          4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,          4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,          4,
        4,          4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,          4,          4,          4,    4,          4,          4,    4,    4
    }
};
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
#endif
