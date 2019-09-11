/* Copyright 2019 Maxime Beilles
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum id75_layers {
	/* Layouts */
	_L_QWERTY,
	_L_COLEMAK,
	_L_DVORAK,
	/* Modifiers */
	_L_RAISE,
	_L_LOWER,
	_L_COMB,
};

enum id75_keycodes {
	QWERTY = SAFE_RANGE,
	COLEMAK,
	DVORAK,
};

#define LOWER MO(_L_LOWER)
#define RAISE MO(_L_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* =========== Qwerty
	 *            .-----------------------------------------------------------------------------------------------------------------------.
	 * Shifted    |   ~   |   !   |   @   |   #   |   $   |   %   |   ^   |   7   |   *   |   (   |   )   |   _   |   =   |       |       |
	 * Default    |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |   +   |  Del  | Pg Up |
	 *            |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 *            |       |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   {   |   }   |   |   |       |
	 *            |  Tab  |   q   |   w   |   e   |   r   |   t   |   y   |   u   |   i   |   o   |   p   |   [   |   ]   |   \   | Pg Dn |
	 *            |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 *            |       |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   :   |   "   |       |       |       |
	 *            |  Esc  |   a   |   s   |   d   |   f   |   g   |   h   |   j   |   k   |   l   |   ;   |   '   | Enter | Bcksp | Home  |
	 *            |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 *            |       |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   <   |   >   |   ?   |       |       |       |       |
	 *            | Shift |   z   |   x   |   c   |   v   |   b   |   n   |   m   |   ,   |   .   |   /   | Shift | Shift |  Up   |  End  |
	 *            |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 *            |       |       |       |       | Layer |       |       | Layer |       |       |       |       |       |       |       |
	 *            | Cntrl | Hyper |  Alt  | Super | LOWER | Space | Space | RAISE | Super |  Alt  | Menu  | Ctrl  | Left  | Down  | Right |
	 *            `-----------------------------------------------------------------------------------------------------------------------`
	 */
	[_L_QWERTY] = LAYOUT_ortho_5x15( \
			KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_PGUP, \
			KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN, \
			KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_BSPC, KC_HOME, \
			KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_END,  \
			KC_LCTL,  KC_HYPR, KC_LALT, KC_LGUI, LOWER,  KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_MENU, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
	),
	/* =========== Colemak
	 *            .-----------------------------------------------------------------------------------------------------------------------.
	 * Shifted    |   ~   |   !   |   @   |   #   |   $   |   %   |   ^   |   7   |   *   |   (   |   )   |   _   |   =   |       |       |
	 * Default    |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |   +   |  Del  | Pg Up |
	 *            |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 *            |       |   Q   |   W   |   F   |   P   |   G   |   J   |   L   |   U   |   Y   |   :   |   {   |   }   |   |   |       |
	 *            |  Tab  |   q   |   w   |   f   |   p   |   g   |   j   |   l   |   u   |   y   |   ;   |   [   |   ]   |   \   | Pg Dn |
	 *            |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 *            |       |   A   |   R   |   S   |   T   |   D   |   H   |   N   |   E   |   I   |   O   |   "   |       |       |       |
	 *            |  Esc  |   a   |   r   |   s   |   t   |   d   |   h   |   n   |   e   |   i   |   o   |   '   | Enter | Bcksp | Home  |
	 *            |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 *            |       |   Z   |   X   |   C   |   V   |   B   |   K   |   M   |   <   |   >   |   ?   |       |       |       |       |
	 *            | Shift |   z   |   x   |   c   |   v   |   b   |   k   |   m   |   ,   |   .   |   /   | Shift | Shift |  Up   |  End  |
	 *            |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 *            |       |       |       |       | Layer |       |       | Layer |       |       |       |       |       |       |       |
	 *            | Cntrl | Hyper |  Alt  | Super | LOWER | Space | Space | RAISE | Super |  Alt  | Menu  | Ctrl  | Left  | Down  | Right |
	 *            `-----------------------------------------------------------------------------------------------------------------------`
	 */
	[_L_COLEMAK] = LAYOUT_ortho_5x15( \
			KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_PGUP, \
			KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,   KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN, \
			KC_ESC,   KC_A,    KC_R,    KC_S,    KC_T,   KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,  KC_BSPC, KC_HOME, \
			KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_END,  \
			KC_LCTL,  KC_HYPR, KC_LALT, KC_LGUI, LOWER,  KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_MENU, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
	),
	/* =========== Dvorak
	 *            .-----------------------------------------------------------------------------------------------------------------------.
	 * Shifted    |   ~   |   !   |   @   |   #   |   $   |   %   |   ^   |   7   |   *   |   (   |   )   |   {   |   }   |       |       |
	 * Default    |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   [   |   ]   |  Del  | Pg Up |
	 *            |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 *            |       |   "   |   <   |   >   |   P   |   Y   |   F   |   G   |   C   |   R   |   L   |   ?   |   +   |   |   |       |
	 *            |  Tab  |   '   |   ,   |   .   |   p   |   y   |   f   |   g   |   c   |   r   |   l   |   /   |   =   |   \   | Pg Dn |
	 *            |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 *            |       |   A   |   O   |   E   |   U   |   I   |   D   |   H   |   T   |   N   |   S   |   _   |       |       |       |
	 *            |  Esc  |   a   |   o   |   e   |   u   |   i   |   d   |   h   |   t   |   n   |   s   |   -   | Enter | Bcksp | Home  |
	 *            |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 *            |       |   :   |   Q   |   J   |   K   |   X   |   B   |   M   |   W   |   V   |   Z   |       |       |       |       |
	 *            | Shift |   ;   |   q   |   j   |   k   |   x   |   b   |   m   |   w   |   v   |   z   | Shift | Shift |  Up   |  End  |
	 *            |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 *            |       |       |       |       | Layer |       |       | Layer |       |       |       |       |       |       |       |
	 *            | Cntrl | Hyper |  Alt  | Super | LOWER | Space | Space | RAISE | Super |  Alt  | Menu  | Ctrl  | Left  | Down  | Right |
	 *            `-----------------------------------------------------------------------------------------------------------------------`
	 */
	[_L_DVORAK] = LAYOUT_ortho_5x15( \
			KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_DEL,  KC_PGUP, \
			KC_TAB,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,   KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS, KC_PGDN, \
			KC_ESC,   KC_A,    KC_O,    KC_E,    KC_U,   KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, KC_ENT,  KC_BSPC, KC_HOME, \
			KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,   KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, KC_RSFT, KC_UP,   KC_END,  \
			KC_LCTL,  KC_HYPR, KC_LALT, KC_LGUI, LOWER,  KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_MENU, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
	),
	/* =========== Layer Up
	 * .-----------------------------------------------------------------------------------------------------------------------.
	 * |       |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |       |       |
	 * |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 * |       |  F13  |  F14  |  F15  |  F16  |  F17  |  F18  |  F19  |  F20  |  F21  |  F22  |  F23  |  F24  |       |       |
	 * |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 * |       | Caplk | Numlk | Scrlk |       |       |       |       |       |       |       |       |       |       |       |
	 * |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 * |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
	 * |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 * |       |       |       |       | Comb  |       |       | ===== |       |       |       |       |       |       |       |
	 * `-----------------------------------------------------------------------------------------------------------------------`
	 */
	[_L_RAISE] = LAYOUT_ortho_5x15( \
			_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, \
			_______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______, _______, \
			_______, KC_LCAP, KC_LNUM, KC_LSCR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
	),
	/* =========== Layer Down
	 * .-----------------------------------------------------------------------------------------------------------------------.
	 * |       |       |       |       |       |       |       |       |       |       |       | Numlk |   /   |   *   | Bkspc |
	 * |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 * |       |       |       |       |       |       |       |       |       |       |       |   7   |   8   |   9   |   -   |
	 * |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 * |       |       |       |       |       |       |       |       |       |       |       |   4   |   5   |   6   |   +   |
	 * |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 * |       |       |       |       |       |       |       |       |       |       |       |   1   |   2   |   3   | Enter |
	 * |-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
	 * |       |       |       |       |       |       |       |       |       |       |       |   0   |   0   |   .   | Enter |
	 * `-----------------------------------------------------------------------------------------------------------------------`
	 */
	[_L_LOWER] = LAYOUT_ortho_5x15( \
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_BSPC, \
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, \
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, \
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, \
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_0, KC_KP_0, KC_PDOT, KC_PENT  \
	),
	/* =========== Layer Comb
	 * .----------------------------------------------------------------------------------------------------------------------------------------.
	 * |       | Br Dn     | Br Up     | Wndow     | Apps      | Prev  | Pause | Next  | Sn Mt | Sn Dn | Sn Up | Eject |       |       |  Reset  |
	 * |-------|-----------|-----------|-----------|-----------|-------|-------|-------|-------|-------|-------|-------|-------|-------|---------|
	 * |       | Backlight |    RGB    | RGB Cycle | RGB Cycle |       |       |       |       |       |       |       |       |       |         |
	 * |       |  Toggle   |  Toggle   |   Next    |   Prev    |       |       |       |       |       |       |       |       |       |         |
	 * |-------|-----------|-----------|-----------|-----------|-------|-------|-------|-------|-------|-------|-------|-------|-------|---------|
	 * |       | RGB Hue   | RGB Hue   |           |           |       |       |       |       |       |       |       |       |       | Qwerty  |
	 * |       | Decrease  | Increase  |           |           |       |       |       |       |       |       |       |       |       |         |
	 * |-------|-----------|-----------|-----------|-----------|-------|-------|-------|-------|-------|-------|-------|-------|-------|---------|
	 * |       | RGB Hue   | RGB Hue   |           |           |       |       |       |       |       |       |       |       |       | Colemak |
	 * |       | Decrease  | Increase  |           |           |       |       |       |       |       |       |       |       |       |         |
	 * |-------|-----------|-----------|-----------|-----------|-------|-------|-------|-------|-------|-------|-------|-------|-------|---------|
	 * |       | RGB Satur | RGB Satur |           |           |       |       |       |       |       |       |       |       |       | Dvorak  |
	 * |       | Decrease  | Increase  |           |           |       |       |       |       |       |       |       |       |       |         |
	 * `-----------------------------------------------------------------------------------------------------------------------------------------`
	 */
	[_L_COMB] = LAYOUT_ortho_5x15( \
			_______, KC_BRIU, KC_BRID, _______, KC_APP,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_EJCT, _______, _______, RESET,   \
			_______, _______, RGB_TOG, RGB_MOD, RGB_RMOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
			_______, RGB_HUD, RGB_HUI, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, QWERTY,  \
			_______, RGB_VAD, RGB_VAI, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, COLEMAK, \
			_______, RGB_SAD, RGB_SAI, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, DVORAK   \
	),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case QWERTY:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_L_QWERTY);
			}
			return false;
		case COLEMAK:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_L_COLEMAK);
			}
			return false;
		case DVORAK:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_L_DVORAK);
			}
			return false;
		default:
			return true;
	}
}

layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, _L_LOWER, _L_RAISE, _L_COMB);
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
