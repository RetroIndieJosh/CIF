#pragma once

#include <stdbool.h>

int game_cur_room_id();
void game_end();
int game_init();
bool game_is_over();
int game_run();
void game_set_room(int id);
int game_turn();
