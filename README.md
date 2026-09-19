# Cyberpunk Macro-Pad

A cyberpunk-themed 6-key macropad with a rotary encoder, OLED display, and RGB lighting.
(Its awesome ik :3)



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
<img width="1052" height="737" alt="image" src="https://github.com/user-attachments/assets/a104a7f1-2d1c-4624-bcb2-695044eef0ce" />
The PCB is relatively simple and as an easter egg I added silkscreens on the PCB with labels to make it appear as if it was actually made by a Cyberpunk corporation.
I know that the common users isn't even likely to see that. However, I found it cool.
;)


The `PCB/` folder contains:

* KiCad schematic
* KiCad PCB layout
* KiCad project files

The `Production/` folder contains the manufacturing files, including the Gerbers.
<img width="1210" height="906" alt="image" src="https://github.com/user-attachments/assets/25a0ae71-7c2c-4688-98ed-715afccfd1b1" />


## CAD

The case was designed in Fusion.

The `CAD/` folder contains the assembled STEP model.

The `Production/` folder contains the STL files for the upper and lower case.
<img width="710" height="566" alt="image" src="https://github.com/user-attachments/assets/7d98bf65-65bf-4b1b-a1b7-03b2dac3d34e" />
I used grills above one of the LEDs so the user doesn't get blasted by unobstructed, pure, unfiltered 500THz electromagnetic radiation (technically true).
The other LED is close to the keyboard and naturally creates an ambient underglow
I decided to keep the area around the main keyboard exposed to give it the Cyberpunk- vibe.
<img width="656" height="213" alt="image" src="https://github.com/user-attachments/assets/b5ffdf39-ffcc-417c-8517-1a1163f993f6" />
<img width="771" height="576" alt="image" src="https://github.com/user-attachments/assets/be04faf4-1194-4388-a565-030af0d06e06" />


## Firmware

The firmware is written using QMK.

The QMK keyboard files are located in:
`Firmware/keyboard/`


The keyboard uses a 6-key matrix and supports the rotary encoder and media controls.



## AI Usage

I used AI to better understand some of the components and concepts involved and I heavily relied on Claude while writing the QMK firmware because I was new to QMK. I also used Claude, ChatGPT, and Copilot to review the project and help find bugs and inconsistencies.
