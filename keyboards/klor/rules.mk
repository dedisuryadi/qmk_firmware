# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
SPLIT_KEYBOARD = yes
SWAP_HANDS_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = ssd1306
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = no
#PER KEY RGB
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes      # Enable keyboard RGB matrix (do not use together with RGBLIGHT_ENABLE)
RGB_MATRIX_DRIVER = ws2812  # RGB matrix driver support
RGB_MATRIX_SUPPORTED = yes

#SPACE SAVING
EXTRAKEY_ENABLE = no
AUDIO_ENABLE = no
MUSIC_ENABLE = no
LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no

VIA_ENABLE = yes

