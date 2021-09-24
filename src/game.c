#include <stdbool.h>

#include "game.h"

bool game_running = true;

// TODO should be part of player - location, from actor
int game_cur_room_id()
{
        return 0;
}

void game_end() 
{
        game_running = false;
}

bool game_is_over() 
{
        return game_running == false;
}
