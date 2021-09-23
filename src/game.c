#include <stdbool.h>

#include "game.h"

bool game_running = true;

void game_end() 
{
        game_running = false;
}

bool game_is_over() 
{
        return game_running == false;
}
