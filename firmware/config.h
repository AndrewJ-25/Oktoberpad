#pragma once

// ---------- Hardware ----------
#define MATRIX_ROWS 3
#define MATRIX_COLS 3
#define MATRIX_ROW_PINS { GP3, GP4, GP2 }     // row pins
#define MATRIX_COL_PINS { GP26, GP27, GP28 }  // column pins
#define DIRECT_PINS { GP29 }                  // Encoder button pin
#define DIODE_DIRECTION COL2ROW               // matches json

// ---------- Rotary encoder ----------
#define ENCODERS_PAD_A { GP1 }
#define ENCODERS_PAD_B { GP0 }
#define ENCODER_RESOLUTION 4                  // matches json

// ---------- I2C OLED ----------
#define OLED_DRIVER SSD1306
#define OLED_I2C_SDA_PIN GP6
#define OLED_I2C_SCL_PIN GP7
#define OLED_TIMEOUT 300000                     // auto-off after 300s

// ---------- USB ----------
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0100
#define MANUFACTURER    Andrew_Jia
#define PRODUCT         Oktoberpad
#define DESCRIPTION     QMK keyboard

// ---------- Features ----------
#define TAPPING_TERM 200                       // ms for tap-hold
