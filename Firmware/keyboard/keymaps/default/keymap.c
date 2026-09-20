#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
#include "oled_driver.h"
#endif

enum layer_names {
    _BASE,
};

// layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_PSCR, KC_W,    LALT(KC_TAB), KC_MPLY,
        KC_A,    KC_S,    KC_D
    )
};

// encoder
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};

#ifdef OLED_ENABLE

// eye
static uint8_t ex = 64, ey = 16;
static uint8_t tx = 64, ty = 16;
static uint16_t react_t = 0;
static bool reacting = false;
static bool blink = false;
static uint16_t blink_t = 0;
static bool surprised = false;

static void draw_eye(void) {
    const uint8_t left = 20, right = 108, top = 8, bottom = 23;
    for (uint8_t i = left; i <= right; i++) {
        oled_write_pixel(i, top, true);
        oled_write_pixel(i, bottom, true);
    }
    for (uint8_t i = top; i <= bottom; i++) {
        oled_write_pixel(left, i, true);
        oled_write_pixel(right, i, true);
    }
    if (blink) {
        for (uint8_t i = left + 5; i < right - 4; i++) {
            oled_write_pixel(i, 16, true);
            oled_write_pixel(i, 17, true);
        }
        return;
    }
    uint8_t r = surprised ? 5 : 3;
    for (int8_t dx = -r; dx <= r; dx++) {
        for (int8_t dy = -r; dy <= r; dy++) {
            if ((dx * dx) + (dy * dy) > (r * r)) continue;
            int px = ex + dx, py = ey + dy;
            if (px >= 0 && px < 128 && py >= 0 && py < 32) oled_write_pixel(px, py, true);
        }
    }
    if (!surprised && ex > left && ey > top) oled_write_pixel(ex - 1, ey - 1, false);
}

static void move_eye(void) {
    if (ex < tx) ex++;
    if (ex > tx) ex--;
    if (ey < ty) ey++;
    if (ey > ty) ey--;
}

static void react(uint8_t nx, uint8_t ny) {
    tx = nx;
    ty = ny;
    react_t = timer_read();
    reacting = true;
}

static void tick_blink(void) {
    uint16_t elapsed = timer_elapsed(blink_t);
    if (elapsed > 5150) {
        blink = false;
        blink_t = timer_read();
    } else if (elapsed > 5000) {
        blink = true;
    }
}

bool oled_task_user(void) {
    oled_clear();
    if (reacting && timer_elapsed(react_t) > 500) {
        tx = 64;
        ty = 16;
        reacting = false;
        surprised = false;
    }
    move_eye();
    tick_blink();
    draw_eye();
    oled_set_cursor(0, 0);
    oled_write("CYBER", false);
    oled_set_cursor(6, 0);
    oled_write("EYE", false);
    oled_set_cursor(0, 3);
    oled_write("READY", false);
    return false;
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    if (record->event.pressed) {
        switch (keycode) {
            case KC_PSCR:      react(48, 12); break;
            case KC_W:         react(58, 12); break;
            case LALT(KC_TAB): react(80, 12); break;
            case KC_A:         react(48, 20); break;
            case KC_S:         react(64, 20); break;
            case KC_D:         react(80, 20); break;
            case KC_MPLY:
                surprised = true;
                react(64, 16);
                break;
        }
    }
#endif
    return true;
}

#ifdef OLED_ENABLE
// encoder: encoder_map skips process_record_user, so react() happens here
bool encoder_update_user(uint8_t index, bool cw) {
    if (index != 0) return true;
    if (cw) {
        tap_code(KC_VOLU);
        react(82, 16);
    } else {
        tap_code(KC_VOLD);
        react(46, 16);
    }
    return false;
}
#endif
