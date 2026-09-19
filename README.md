# Cyberpunk Macro-Pad

A cyberpunk-themed 6-key macropad with a rotary encoder, OLED display, and RGB lighting.
(Its awesome ik :3)
<img width="771" height="576" alt="image" src="https://github.com/user-attachments/assets/be04faf4-1194-4388-a565-030af0d06e06" />


## Features

* 6 MX-style mechanical switches
* EC11E rotary encoder
* Encoder push button
* 0.91" OLED display
* 2× SK6812 RGB LEDs
* USB-C
* Seeed Studio XIAO RP2040
* Custom PCB
* Custom 3D-printed case

## BOM
| Component.                   |Quantity   |
| -------------------------    | ------------  |
| Seeed Studio Xiao RP2040                     | 1    |
| 0.91 inch OLED                    | 1|
| Diodes                | 7|
| EC11E Rotary Encoder            | 1  |
| SK6812 | 2 |
| MX Switches  | 6 |
| Keycaps          | 6|
| M3x16mm Screws |2|
| M3x5mx14mm heatset-inserts |2|
  

## Controls

| Control                   | Function     |
| -------------------------    | ------------  |
| PrtSc                        | Screenshot    |
| W,A,S,D                      | Movement keys |
| Alt+Tab                      | Switches tabs |
| Encoder clockwise            | Volume up     |
| Encoder counter-clockwise    | Volume down   |
| Encoder press                | Play / Pause  |

## Why I made it

idk looks cool ig


## Hardware

The macropad is built around a Seeed Studio XIAO RP2040.

The six switches are arranged as a small keyboard matrix. The rotary encoder is connected separately, and the encoder's push button is used as a media control.

The PCB also has two SK6812 LEDs and an I2C connection for the OLED display.

## PCB

The PCB was designed in KiCad.
<img width="1052" height="737" alt="image" src="https://github.com/user-attachments/assets/a104a7f1-2d1c-4624-bcb2-695044eef0ce" />
The PCB is relatively simple, but as an easter egg I added silkscreen labels to make it look like it was actually made by a Cyberpunk corporation.
I know the average user isn't even likely to see them, but I found it cool. ;)


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
The case consists of an upper and lower part, which are secured with two screws and two heat-set inserts.

I used grills above one of the LEDs so the user doesn't get blasted by unobstructed, pure and unfiltered 500 THz electromagnetic radiation 
(technically true).

The other LED is close to the keyboard and naturally creates an ambient underglow.
I decided to keep the area around the main keyboard slightly exposed to give it the Cyberpunk vibe.
<img width="656" height="213" alt="image" src="https://github.com/user-attachments/assets/b5ffdf39-ffcc-417c-8517-1a1163f993f6" />



## Firmware

The firmware is written using QMK.

The QMK keyboard files are located in:
`Firmware/keyboard/`

The keyboard uses a 6-key matrix and supports the rotary encoder, OLED display, RGB lighting, and media controls.
The OLED panel displays an eye-animation which reacts when you press a key!

👁️👄👁️ 

## What I learnt
- KiCAD
- DRC
- PCB and schematics design
- Debugging and resolving PCB design issues
- How keyboard matrices work
- Fusion
- QMK
- GitHub
- Creating a prototype model to virtually put it all together

## Future Improvements
- Add better OLED animations
- Add configurable RGB effects
- Improve the LED diffusion
- Possibly add a buzzer or additional features


## AI Usage

I used AI to better understand some of the components and concepts involved and I heavily relied on Claude while writing the QMK firmware because I was new to QMK. I also used Claude, ChatGPT, and Copilot to review the project and help find bugs and inconsistencies.
