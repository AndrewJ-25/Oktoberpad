// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _EMOJI,
    _MUSIC,
    _SHORTCUT,
    _WECHAT
};

/*
 * Emoji:
 * ┌───┬───┬───┐
 * │ 😁│ 😎│ 🫡│
 * ├───┼───┼───┤
 * │ ❤️│ 🔥│ 🤷‍♂️│
 * ├───┼───┼───┤
 * │ 😭│ 🥀│ 💀│
 * └───┴───┴───┘
 *
 * Music:
 * ┌────┬────┬────┐
 * │prev│play│next│
 * ├────┼────┼────┤
 * │mute│ up │down│
 * ├────┼────┼────┤
 * │    │    │    │
 * └────┴────┴────┘
 *
 * Shortcut:
 *
 * command +
 * ┌───┬───┬───┐
 * │ C │ V │ X │
 * ├───┼───┼───┤
 * │ A │ Z │^Z │
 * ├───┼───┼───┤
 * │ W │ T │^T │
 * └───┴───┴───┘
 *
 * Wechat stickers:
 * ┌─────────┬────────┬──────────┐
 * │[Grin]   │[Trick] │[ThumbsUp]│
 * ├─────────┼────────┼──────────┤
 * │[Awesome]│[Wow]   │[Scream]  │
 * ├─────────┼────────┼──────────┤
 * │[Wilt]   │[Hammer]│[Hurt]    │
 * └─────────┴────────┴──────────┘
 */



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_EMOJI] = LAYOUT(
                      SEND_STRING("😁"), SEND_STRING("😎"), SEND_STRING("🫡"),
                      SEND_STRING("❤️"), SEND_STRING("🔥"), SEND_STRING("🤷‍♂️"),
                      SEND_STRING("😭"), SEND_STRING("🥀"), SEND_STRING("💀")
                      ),
    [_MUSIC] = LAYOUT(
                      KC_MPRV, KC_MPLY, KC_MNXT,
                      KC_MUTE, KC_VOLD, KC_VOLU,
                      KC_NO,   KC_NO,   KC_NO
                      ),
    [_SHORTCUT] = LAYOUT(
                         LGUI(KC_C),  LGUI(KC_V), LGUI(KC_X),
                         LGUI(KC_A),  LGUI(KC_Z), LGUI(LSFT(KC_Z)),
                         LGUI(KC_W),  LGUI(KC_T), LGUI(LSFT(KC_T))
                         ),
    [_WECHAT] = LAYOUT(
                       SEND_STRING("[Grin]"),  SEND_STRING("[Trick]"), SEND_STRING("[ThumbsUp]"),
                       SEND_STRING("[Awesome]"),  SEND_STRING("[Wow]"), SEND_STRING("[Scream]"),
                       SEND_STRING("[Wilt]"),  SEND_STRING("[Hammer]"), SEND_STRING("[Hurt]"),
    )};

bool encoder_button_pressed(void) {
    return readPin(KNOB_BUTTON);
}

void cycle_layer(bool clockwise) {
    uint8_t layer = biton32(layer_state); // get current active layer
    if (clockwise) {
        layer = (layer + 1) % 4; // cycle forwards
    } else {
        layer = (layer + 3) % 4; // cycle backward
    }
    layer_clear();   // turn off all layers
    layer_on(layer); // enable new layer
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (encoder_button_pressed()) {
        // Button pressed => cycle layers
        cycle_layer(clockwise);
    } else {
        // Button not pressed => adjust volume
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}

#ifdef OLED_ENABLE
void oled_task_user(void) { // Callback function: called every few ms
    oled_write_ln_P(PSTR("Layer:"), false);
    switch (biton32(layer_state)) {
        case _EMOJI: oled_write_ln_P(PSTR("Emoji"), false); break;
        case _MUSIC: oled_write_ln_P(PSTR("Music"), false); break;
        case _SHORTCUT: oled_write_ln_P(PSTR("Shortcuts"), false); break;
        case _WECHAT: oled_write_ln_P(PSTR("Wechat stickers"), false); break;
    }
}
#endif
