BOOTLOADER = rp2040
BOARD = GENERIC_RP_RP2040

# Feature flags are specified in keyboard.json; avoid duplicate definitions here
# (bootmagic, mousekey, extrakey, console, command, nkro)
BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE  = no
AUDIO_ENABLE     = no

OLED_ENABLE      = yes
ENCODER_ENABLE   = yes

# Enable native QMK PS/2 Mouse support
PS2_ENABLE = yes
PS2_DRIVER = vendor
PS2_MOUSE_ENABLE = yes
PS2_MOUSE_DRIVER = busywait

# Linker trick: intercept the native mouse functions so we can gate them
LDFLAGS += -Wl,--wrap=ps2_mouse_init -Wl,--wrap=ps2_mouse_task

SRC += ps2_keyboard.c \
       kb.c

