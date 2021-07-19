#include <stdbool.h>

#include "game.h"

bool game_running = true;

void game_end() {
        game_running = false;
}

bool game_ended() {
        return game_running == false;
}
