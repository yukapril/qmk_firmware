VIA_ENABLE = yes

ENCODER_ENABLE = yes # 编码器开关
ENCODER_MAP_ENABLE = no # 编码器MAP开关，打开后keymap.c使用MAP形式调整编码器，不打开使用函数形式调整编码器
OLED_ENABLE = yes # OLED 开关
OLED_DRIVER = SSD1306 # OLED 驱动
# NKRO_ENABLE = no # 估计是N键无冲开关
RGBLIGHT_ENABLE = yes # RGB灯开关
# BACKLIGHT_ENABLE = no # 背景灯开关
EXTRAKEY_ENABLE = yes # 使用系统和音频控制键开关
EXTRAFLAGS += -flto # reducing
