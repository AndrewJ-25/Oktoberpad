# Oktoberpad
![image alt](https://github.com/AndrewJ-25/Oktoberpad/blob/6890eaa5336cb1ef0c7b4e39f396ed2ecb21081a/banner.png)
Oktoberpad is my macropad with 9 switches, a rotary encoder and an OLED display, designed following the guide published for Hackclub Blueprint

## TODO:
  - code does not compile. have already identified several bugs


## Features:
  - 9 key layered keyboard
  - 0.91" OLED display
  - EC11 rotary encoder
  - 3D printed case

## CAD Model:
  - 3D printed case held together by 4 M3 bolts and heatset inserts
  - case designed in Onshape
  - PCB held to case using 4 M3 bolts and heatset inserts

## PCB:
  pcb designed in Kicad (this was quite a journey!)

  schematic:
  ![image alt](https://github.com/AndrewJ-25/Oktoberpad/blob/edae228ee6b608626afca5e1cf36875519283d24/schematic.png)

  pcb:
  ![image alt](https://github.com/AndrewJ-25/Oktoberpad/blob/edae228ee6b608626afca5e1cf36875519283d24/pcb.png)

## Firmware
  Oktoberpad uses QMK firmware (again, writing this was quite the journey!)

  - The rotary encoder adjusts volume, or cycles between keyboard layers when pressed and turned
  - OLED display indicates current layer
  - These layers are: emojis, music control, keyboard shortcuts, wechat sticker codes

## BOM

  - 9x Cherry MX Switches
  - 49x DSA Keycaps
  - 8x M3x5x4 Heatset inserts
  - 8x M3x16mm SHCS Bolts
  - 9x 1N4148 DO-35 Diodes.
  - 1x 0.91" 128x32 OLED Display
  - 1x EC11 Rotary Encoder
  - 1x XIAO RP2040
  - 1x Case (2 printed parts)
