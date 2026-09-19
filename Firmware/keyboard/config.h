#pragma once

// =========================
// OLED
// =========================

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7

#define OLED_DISPLAY_ADDRESS 0x3C
#define OLED_DISPLAY_128X32
#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 32
#define OLED_BRIGHTNESS 180

// Update frequently enough for the eye animation
#define OLED_UPDATE_INTERVAL 50


// =========================
// RGB LEDs
// =========================

#define WS2812_DI_PIN GP3
#define RGBLIGHT_LED_COUNT 2

#define RGBLIGHT_LIMIT_VAL 100


// =========================
// Encoder
// =========================

#define ENCODER_MAP_KEY_DELAY 10