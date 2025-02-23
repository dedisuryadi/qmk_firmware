EXTRAFLAGS += -flto

#SRC += features/layer_lock.c
#SRC += features/select_word.c
#SRC += features/achordion.c

WPM_ENABLE = no
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = no
AUDIO_ENABLE = no
MUSIC_ENABLE = no
MAGIC_ENABLE = no
BOOTMAGIC_ENABLE = yes

CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes

#DYNAMIC_MACRO_ENABLE = yes
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = no
TAP_DANCE_ENABLE = no
LEADER_ENABLE = no

#HAPTIC FEEBACK
HAPTIC_ENABLE = no

#PER KEY RGB
RGB_MATRIX_ENABLE = no
VIA_ENABLE = yes


# size shaving
QMK_SETTINGS = no
MIDI_ENABLE = no
SLEEP_LED_ENABLE = no
SWAP_HANDS_ENABLE = no
UCIS_ENABLE = no
UNICODEMAP_ENABLE = no
UNICODE_ENABLE = no
NKRO_ENABLE = no
AUTO_SHIFT_MODIFIERS = no
AUTO_SHIFT_ENABLE = no
BACKLIGHT_ENABLE = no
BLUETOOTH_ENABLE = no
KEY_LOCK_ENABLE = no
POINTING_DEVICE_ENABLE = no
STENO_ENABLE = no
TERMINAL_ENABLE = no
UCIS_ENABLE = no
UNICODE_ENABLE = no
UNICODEMAP_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MUSIC_ENABLE = no
AVR_USE_MINIMAL_PRINTF = yes
FAUXCLICKY_ENABLE = no

