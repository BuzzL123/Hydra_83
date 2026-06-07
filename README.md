# Hydra 83

> _One board. Two protocols. More to come._

![License](https://img.shields.io/badge/license-GPL--2.0-blue.svg) [![QMK](https://img.shields.io/badge/QMK-firmware-blue.svg)](https://qmk.fm/) [![Platform](https://img.shields.io/badge/platform-RP2040-green.svg)](https://www.raspberrypi.com/products/rp2040/)

---

## What Is It?

The **Hydra 83** is a custom 83-key mechanical keyboard that can switch between **USB HID** and **PS/2** via a hardware toggle. The name comes from two things:

- **83** — the total key count
- **Hydra** — the multi-headed creature of myth, representing the board's ability to switch between protocols. In PS/2 mode it's a standard PS/2 keyboard; in USB mode it's a USB keyboard that also accepts a PS/2 mouse on the PS/2 connector

The Hydra is intended to be a series. Future versions may add an integrated USB hub, additional protocol modes, or other switching features.

---

## Features

- **Dual-protocol keyboard output** — USB HID or PS/2 Scan Code Set 2, selected with a hardware toggle
- **PS/2 mouse input in USB mode** — plug a PS/2 mouse into the PS/2 connector while in USB mode; QMK's built-in PS/2 mouse driver reads it and forwards it to the host over USB
- **Full PS/2 keyboard implementation** — make/break codes, typematic repeat, E0-prefixed extended keys, F13–F24, multimedia, browser, and power keys
- **On-board BSS138 level shifters** — two BSS138 MOSFETs handle bidirectional 3.3 V ↔ 5 V translation on the PS/2 clock and data lines; no external components needed
- **OLED display** — SSD1306 128×32 connected via I2C
- **Rotary encoder** — Alps EC11E with push-to-click
- **USB-C connector** — with SRV05-4 ESD protection
- **Hardware mode switch** — debounced in firmware (50 ms)
- **QMK-based firmware** — fully remappable, built on QMK best practices, using QMK built-ins wherever possible

---

## How the Modes Work

### PS/2 Mode

The board operates as a standard PS/2 keyboard. Connect it to any PS/2 port — Scan Code Set 2, typematic repeat, full extended key support, all modifiers. The PS/2 clock and data lines are driven by the RP2040 through the BSS138 level shifters.

### USB Mode

The board enumerates as a USB HID keyboard. The PS/2 connector switches role: it becomes a **PS/2 mouse host**. Plug a PS/2 mouse in and QMK reads it and forwards mouse movement, buttons, and scroll to the host over USB alongside keyboard input — one USB-C cable, both devices.

---

## Layout

The Hydra 83 has 83 keys with an integrated numpad cluster, F1–F12 doubling as F13–F24, and a rotary encoder in the top-right corner.

---

## Repository Layout

```
├── Firmware/
│   ├── config.h
│   ├── halconf.h
│   ├── kb.c
│   ├── kb.h
│   ├── keyboard.json
│   ├── keymaps/
│   │   └── default/
│   │       └── keymap.c
│   ├── Makefile
│   ├── mcuconf.h
│   ├── ps2_keyboard.c
│   ├── ps2_keyboard.h
│   ├── ps2_scancodes.h
│   ├── readme.md
│   └── rules.mk
└── PCB/
    ├── gerbers/
    │   ├── bom.csv
    │   ├── designators.csv
    │   ├── Hydra_83_1.0.zip
    │   ├── netlist.ipc
    │   └── positions.csv
    ├── Hydra83_Schamatics.pdf
    ├── Hydra83__Assembly.pdf
    ├── ibom.html
    ├── kicad/
    │   ├── fabrication-toolkit-options.json
    │   ├── fp-lib-table
    │   ├── Hydra83.kicad_pcb
    │   ├── Hydra83.kicad_prl
    │   ├── Hydra83.kicad_pro
    │   ├── Hydra83.kicad_sch
    │   ├── Hydra83.net
    │   ├── kbplacer.log
    │   └── sch_data.json
    └── layout.png
```

PS/2 mouse host support uses QMK's built-in `PS2_MOUSE` feature, enabled in `rules.mk`.

---

## Hardware

### Key Components

|Ref|Part|Description|
|---|---|---|
|U3|RP2040|Microcontroller|
|U4|W25Q128JVS|128 Mbit external flash|
|U1|XC6206PxxxMR|3.3 V LDO regulator|
|U2, U6|SRV05-4|USB ESD protection|
|Q1, Q2|BSS138|PS/2 bidirectional level shifters|
|J2|USB-C receptacle|USB 2.0, 16-pin|
|P1|Mini-DIN 6-pin|PS/2 connector|
|J3|SSD1306|0.91" 128×32 OLED (I2C)|
|Y1|12 MHz crystal|RP2040 clock source|
|SW1|Tactile switch|BOOTSEL|
|SW2|Tactile switch|RESET|
|SW3|Toggle / jumper|Mode select (USB / PS/2)|
|RE1|Alps EC11E|Rotary encoder with switch|

### GPIO Pin Map

All 30 RP2040 GPIOs are used:

|GPIO|Signal|Notes|
|---|---|---|
|GP0|Row_0|Key matrix|
|GP1|Row_1||
|GP2|Row_2||
|GP3|Row_3||
|GP4|Row_4||
|GP5|Column_0||
|GP6|Column_1||
|GP7|Column_2||
|GP8|Column_3||
|GP9|Column_4||
|GP10|Column_5||
|GP11|Column_6||
|GP12|Column_7||
|GP13|Column_8||
|GP14|Column_9||
|GP15|Column_10||
|GP16|Column_11||
|GP17|Column_12||
|GP18|Column_13||
|GP19|Column_14||
|GP20|Column_15||
|GP21|Column_16||
|GP22|Column_17||
|GP23|Mode_Switch|HIGH = USB, LOW = PS/2|
|GP24|PS/2_Data|Through BSS138 level shifter|
|GP25|PS/2_Clock|Through BSS138 level shifter|
|GP26|I2C1_SDA|OLED (SSD1306)|
|GP27|I2C1_SCL|OLED (SSD1306)|
|GP28|Encoder_Up|Rotary encoder A|
|GP29|Encoder_Down|Rotary encoder B|

### PS/2 Connector Pinout (Mini-DIN 6)

|PS/2 Pin|Signal|Notes|
|---|---|---|
|1|Data|Through BSS138 to GP24|
|3|GND||
|4|VCC|VBUS (5 V)|
|5|Clock|Through BSS138 to GP25|

---

## PCB

KiCad source files, schematic PDF, PCB plot PDF, interactive HTML BOM (`ibom.html`), and JLCPCB fabrication files are all in the `PCB/` directory. The design is still being refined.

To view the interactive BOM, open `ibom.html` in any browser — it shows component placement on the board alongside the BOM table, useful for hand assembly.

---

## Firmware

### Prerequisites

- [QMK Firmware](https://docs.qmk.fm/#/newbs_getting_started) set up locally
- QMK CLI configured
- ARM GCC toolchain (installed by `qmk setup`)

### Build & Flash

```bash
# Copy the Firmware folder into your QMK keyboards directory
cd ~/qmk_firmware/keyboards
mkdir -p hydra83
cp -r /path/to/Hydra_83/Firmware hydra83/hydra83

# Compile
qmk compile -kb hydra83/hydra83 -km default

# Flash — double-tap reset on RP2040 to enter bootloader, then:
qmk flash -kb hydra83/hydra83 -km default
```

Or copy the pre-compiled `.uf2` from the [Releases](https://github.com/BuzzL123/Hydra_83/releases) page onto the `RPI-RP2` drive.

### Keymap Customization

Edit `Firmware/keymaps/default/keymap.c`. Full PS/2 Scan Code Set 2 support is already in the firmware — just change the layout array.

---

## Debugging

```bash
qmk console
```

```
================================
Mode switch: PS/2
================================
[PS2] PS/2 driver activated
[PS2] Key pressed: keycode=0x0004, scancode=0x1C
[PS2] Typematic repeat: keycode=0x0004, scancode=0x1C
[PS2] Key released: keycode=0x0004, scancode=0x1C
================================
Mode switch: USB
================================
[USB] USB driver restored
```

---

## PS/2 Protocol Details

The keyboard side operates in PS/2 **device** mode — the RP2040 acts _as_ a keyboard. Each byte is 11 bits (start, 8 data bits LSB-first, odd parity, stop) at ~10 kHz. The firmware handles:

- Make codes (key down) and break codes (`0xF0` + scancode, key up)
- E0-prefixed extended codes for arrows, navigation, multimedia, browser, and power keys
- Multi-byte sequences for Print Screen and Pause/Break
- Typematic repeat — 500 ms initial delay, ~30 repeats/second

In USB mode the same PS/2 lines (GP24/GP25) switch to input, and QMK's `PS2_MOUSE` driver reads standard PS/2 mouse packets and forwards them over USB HID.

---

## Roadmap

- [ ] Finalize PCB layout
- [ ] Software mode toggle via keypress (in addition to hardware switch)

---

## Contributing

Pull requests are welcome. Open an issue first for significant changes.

---

## License

GPL-2.0 — see LICENSE. Matches the QMK Firmware license for full compatibility.

---

## Author

**Betzalel J. Lewis** — [GitHub](https://github.com/BuzzL123)

_PS/2 device mode proof-of-concept: [QMK PS/2 USB Dual-Mode Keyboard](https://github.com/BuzzL123/QMK-PS2-USB-Dual-Mode-Keyboard)_
