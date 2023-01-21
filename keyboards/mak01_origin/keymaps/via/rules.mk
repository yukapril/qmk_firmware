# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = halfkay


# Yes

EXTRAKEY_ENABLE = yes
ENCODER_ENABLE = yes
NKRO_ENABLE = yes
OLED_DRIVER_ENABLE = yes
RGBLIGHT_ENABLE = yes
BACKLIGHT_ENABLE = no
EXTRAFLAGS += -flto     # reducing

# No
BOOTMAGIC_ENABLE = no
SLEEP_LED_ENABLE = no
UNICODE_ENABLE = no
BLUETOOTH_ENABLE = no
AUDIO_ENABLE = no
COMMAND_ENABLE = yes        # Commands for debug and configuration
MOUSEKEY_ENABLE = no       # Mouse keys(+4700)
CONSOLE_ENABLE = no        # Console for debug(+400)

# VIA要求禁用项
LEADER_ENABLE = no
FAUXCLICKY_ENABLE = no
MIDI_ENABLE = no
BOOTMAGIC_ENABLE = no
KEY_LOCK_ENABLE = no
TERMINAL_ENABLE = no

VIA_ENABLE = yes
