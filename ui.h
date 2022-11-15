/*
 * Nibbler - Emulator for Voja's 4-bit processor.
 *
 * Copyright (c) 2022 Octavian Voicu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _UI_H
#define _UI_H

#include "clock.h"
#include "vm.h"

#include <stdbool.h>
#include <ncurses.h>
#include <time.h>

#define DISPLAY_PAGES 2

struct ui {
	memory_word_t last_pages[DISPLAY_PAGES][PAGE_SIZE];
	memory_word_t last_dimmer;
	bool last_matrix_off;

	WINDOW *status;
	WINDOW *display;
	vm_clock_t t_last_ui_update;

	bool quit;
	bool single_step;
};

#define STEP_MODE 1
#define RED_MODE 2

void init_ui(struct ui *ui, int ui_options);

/* The UI can interact with the memory, e.g. to override the page register. */
void update_ui(struct vm_state *vm, struct ui *ui);

void exit_ui(struct ui *ui);

#endif /* _UI_H */
