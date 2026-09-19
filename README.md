# Cyberpunk Macro-Pad

A cyberpunk-themed 6-key macropad with a rotary encoder, OLED display, and RGB lighting.


This was made for Hack Club's Hackpad/Stardance hardware projects.

## Features

* 6 MX-style mechanical switches
* EC11 rotary encoder
* Encoder push button
* 0.91" OLED display
* 2× WS2812 RGB LEDs
* USB-C
* Seeed Studio XIAO RP2040
* Custom PCB
* Custom 3D-printed case

## Controls

| Control                   | Function     |
| -------------------------    | ------------  |
| PrtSc                        | Screenshot    |
| W,A,S,D                      | Movement keys |
| Alt Tab                      | Switches tabs |
| Encoder clockwise            | Volume up     |
| Encoder counter-clockwise    | Volume down   |
| Encoder press                | Play / Pause  |

## Why I made it

idk looks cool ig


## Hardware

The macropad is built around a Seeed Studio XIAO RP2040.

The six switches are arranged as a small keyboard matrix. The rotary encoder is connected separately, and the encoder's push button is used as a media control.

The PCB also has two WS2812 LEDs and an I2C connection for the OLED display.

## PCB

The PCB was designed in KiCad.

The `PCB/` folder contains:

* KiCad schematic
* KiCad PCB layout
* KiCad project files

The `Production/` folder contains the manufacturing files, including the Gerbers.

## CAD

The case was designed in Fusion.

The `CAD/` folder contains the assembled STEP model.

The `Production/` folder contains the STL files for the upper and lower case.

## Firmware

The firmware is written using QMK.

The QMK keyboard files are located in:

```text
Firmware/keyboard/
```

The keyboard uses a 6-key matrix and supports the rotary encoder and media controls.



## AI Usage

I used AI to better understand the components.
I heavily relied on Claude to help me with the code because I was new to QMK firmware.
Also, I used Claude, ChatGPT, Copilot to review my projects and find any bugs.
