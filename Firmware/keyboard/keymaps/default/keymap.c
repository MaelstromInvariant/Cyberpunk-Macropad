#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
#include "oled_driver.h"
#endif

// ============================================================
// LAYERS
// ============================================================

enum layer_names {
    _BASE,
};


// ============================================================
// KEYMAP
// ============================================================
//
// Physical PCB (matches x,y positions in keyboard.json):
//
//     PrtSc   W       Alt+Tab   Encoder SW
//
//     A       S       D
//
// Matrix:
//
//     [0,0] [0,1] [0,2] [0,3]
//     [1,0] [1,1] [1,2]
//
// ============================================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_PSCR, KC_W,    LALT(KC_TAB), KC_MPLY,
        KC_A,    KC_S,    KC_D
    )
};


// ============================================================
// ENCODER
// ============================================================
//
// Clockwise  = volume up
// Counterclockwise = volume down
//
// Encoder switch = media play/pause
//
// ============================================================

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};


// ============================================================
// EYE STATE
// ============================================================

#ifdef OLED_ENABLE

// Current pupil position
static int8_t eye_x = 64;
static int8_t eye_y = 16;

// Target pupil position
static int8_t target_x = 64;
static int8_t target_y = 16;

// Time until the eye returns to normal
static uint16_t reaction_timer = 0;
static bool reaction_active = false;

// Blink state
static bool eye_blink = false;
static uint16_t blink_timer = 0;

// Surprise state from encoder button
static bool eye_surprised = false;


// ============================================================
// DRAW A RECTANGULAR EYE
// ============================================================

static void draw_eye(void) {

    // Eye dimensions
    const uint8_t left   = 20;
    const uint8_t right  = 108;
    const uint8_t top    = 8;
    const uint8_t bottom = 23;

    // --------------------------------------------------------
    // Outer eye
    // --------------------------------------------------------

    for (uint8_t x = left; x <= right; x++) {

        oled_write_pixel(x, top, true);
        oled_write_pixel(x, bottom, true);
    }

    for (uint8_t y = top; y <= bottom; y++) {

        oled_write_pixel(left, y, true);
        oled_write_pixel(right, y, true);
    }


    // --------------------------------------------------------
    // If blinking, draw a closed eye
    // --------------------------------------------------------

    if (eye_blink) {

        for (uint8_t x = left + 5; x < right - 4; x++) {
            oled_write_pixel(x, 16, true);
            oled_write_pixel(x, 17, true);
        }

        return;
    }


    // --------------------------------------------------------
    // Pupil size
    // --------------------------------------------------------

    uint8_t radius = eye_surprised ? 5 : 3;


    // --------------------------------------------------------
    // Draw pupil
    // --------------------------------------------------------

    for (int8_t dx = -radius; dx <= radius; dx++) {

        for (int8_t dy = -radius; dy <= radius; dy++) {

            if ((dx * dx) + (dy * dy) <= (radius * radius)) {

                int8_t px = eye_x + dx;
                int8_t py = eye_y + dy;

                if (px >= 0 && px < 128 &&
                    py >= 0 && py < 32) {

                    oled_write_pixel(px, py, true);
                }
            }
        }
    }

    // Tiny pupil highlight
    if (!eye_surprised) {

        oled_write_pixel(eye_x - 1, eye_y - 1, false);
    }
}


// ============================================================
// MOVE EYE TOWARD A TARGET
// ============================================================

static void update_eye_position(void) {

    if (eye_x < target_x)
        eye_x++;

    if (eye_x > target_x)
        eye_x--;

    if (eye_y < target_y)
        eye_y++;

    if (eye_y > target_y)
        eye_y--;
}


// ============================================================
// EYE REACTION
// ============================================================

static void eye_react(int8_t x, int8_t y) {

    target_x = x;
    target_y = y;

    reaction_timer = timer_read();
    reaction_active = true;
}


// ============================================================
// EYE BLINKING
// ============================================================

static void update_blink(void) {

    uint16_t now = timer_read();

    if (timer_elapsed(blink_timer) > 5000) {

        eye_blink = true;

        if (timer_elapsed(blink_timer) > 5150) {

            eye_blink = false;
            blink_timer = now;
        }
    }
}


// ============================================================
// OLED TASK
// ============================================================

bool oled_task_user(void) {

    oled_clear();

    // Return toward center after reacting
    if (reaction_active && timer_elapsed(reaction_timer) > 500) {

        target_x = 64;
        target_y = 16;

        reaction_timer = 0;
        reaction_active = false;
        eye_surprised = false;
    }

    update_eye_position();
    update_blink();

    draw_eye();

    oled_set_cursor(0, 0);
    oled_write("CYBER", false);

    oled_set_cursor(6, 0);
    oled_write("EYE", false);

    oled_set_cursor(0, 3);
    oled_write("READY", false);

    return false;
}

#endif


// ============================================================
// KEY REACTIONS
// ============================================================

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef OLED_ENABLE

    if (record->event.pressed) {

        switch (keycode) {

            // Top-left: Print Screen
            case KC_PSCR:
                eye_react(48, 12);
                break;

            // Top-middle: W
            case KC_W:
                eye_react(58, 12);
                break;

            // Top-right: Alt+Tab
            case LALT(KC_TAB):
                eye_react(80, 12);
                break;

            // Bottom-left: A
            case KC_A:
                eye_react(48, 20);
                break;

            // Bottom-middle: S
            case KC_S:
                eye_react(64, 20);
                break;

            // Bottom-right: D
            case KC_D:
                eye_react(80, 20);
                break;

            case KC_MPLY:
                eye_surprised = true;
                eye_react(64, 16);
                break;

            case KC_VOLU:
                eye_react(82, 16);
                break;

            case KC_VOLD:
                eye_react(46, 16);
                break;

            default:
                break;
        }
    }

#endif

    return true;
}
