                                      /* Copyright 2017 Mathias Andersson <wraul@dbox.se>
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
#include QMK_KEYBOARD_H

//Layers
enum layers {
  BASE = 0,
  FUNCTION,
};






const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Keymap BASE: (Base Layer) Default Layer */
  [BASE] = LAYOUT(
    KC_MPLY, TO(1), KC_NO, KC_NO,
    KC_NLCK, KC_BSPC, KC_NO, KC_NO,
    KC_P7, KC_P8, KC_P9, KC_PSLS,
    KC_P4, KC_P5, KC_P6, KC_PAST,
    KC_P1, KC_P2, KC_P3, KC_PMNS,
    KC_PENT, KC_P0, KC_PDOT, KC_PPLS),

  /* Keymap FUNCTION: (Function Layer)*/


  [FUNCTION] = LAYOUT(
    RGB_TOG, TO(0), KC_NO, KC_NO,
		RGB_HUI, RGB_HUD, KC_NO, KC_NO,
		RGB_SAI, RGB_SAD, KC_NO, KC_NO,
		RGB_VAI, RGB_VAD, KC_NO, KC_NO,
		RGB_MOD, RGB_RMOD, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, RESET)


};


#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
/*  oled_write_P(PSTR("Layer: "), false); */

   uint8_t led_usb_state = host_keyboard_leds();
oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("-NUM  ON- ") :  PSTR("-NUM OFF- "), false);
oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("-CAP  ON- \n") :  PSTR("-CAP OFF- \n"), false);

  oled_write_P(PSTR("====================\n"), false);

    switch (get_highest_layer(layer_state)) {
      case BASE:
          oled_write_P(PSTR("  NUM BS    /|||  \n"), false);
          oled_write_P(PSTR("  7 8 9 /   /|||  \n"), false);
          oled_write_P(PSTR("  4 5 6 *    |||  \n"), false);
          oled_write_P(PSTR("  1 2 3 -    |||  \n"), false);
          oled_write_P(PSTR("  = 0 . +   ||||| \n"), false);
          break;
      case FUNCTION:
      oled_write_P(PSTR("  SeXiang + - \n"), false);
      oled_write_P(PSTR("  BaoHeDu + - X X \n"), false);
      oled_write_P(PSTR("  LiangDu + - X X \n"), false);
      oled_write_P(PSTR("  XiaoGuo + - X X \n"), false);
      oled_write_P(PSTR("  X X X RESET \n"), false);
          break;

    }



/*  oled_write_P(PSTR("Stats:\n"), false); */

  oled_write_P(PSTR("====================\n"), false);


}
#endif




//Encoder Variables

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
return true;
}
