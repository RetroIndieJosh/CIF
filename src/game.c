#include <stdbool.h>
#include <stdio.h>

#include "command.h"
#include "display.h"
#include "error.h"
#include "input.h"
#include "item.h"
#include "game.h"
#include "room.h"
#include "text.h"

bool game_running = true;
int cur_room = 0;

int game_load();

// TODO should be part of player - location, from actor
int 
game_cur_room_id()
{
        return cur_room;
}

void 
game_end() 
{
        game_running = false;
}

int
game_init()
{
        display_init(80, 25, 24);

        command_init();

        // TODO check error
        game_load();

        return ERROR_OK;
}

bool 
game_is_over() 
{
        return game_running == false;
}

int
game_run()
{
        input_set_prompt(">> ");

        while (game_is_over() == false) {
                display_update();
                input_update();
                if (input_is_ready()) {
                        const char * const input = input_get();
                        printl(">> %s\n", input);
                        command_execute(input);
                        input_clear();
                }
        }

        display_destroy();
        error_print();
        return 0;
}

void
game_set_room(int id)
{
        cur_room = id;
        command_execute("look");
}

int
game_load()
{ 
        // room 0 is inventory
        int inventory_id = room_create("Inventory", "You are carrying:");
        if (inventory_id != INVENTORY_ID) {
                printl("ERROR: Inventory ID %d is not %d. Aborting initialization.", 
                        inventory_id, INVENTORY_ID);
                return ERROR_INITIALIZATION;
        }

        int kitchen_id = room_create("Kitchen", "A boring place to cook.");
        int knife_id = item_create("knife", "It's sharp");
        room_item_add(kitchen_id, knife_id);
        int spatula_id = item_create("spatula", "Flips burgers and pancakes");
        room_item_add(kitchen_id, spatula_id);

        int bedroom_id = room_create("Bedroom", "There's a bed here.");
        room_set_exit(kitchen_id, DIR_SOUTH, bedroom_id);

        game_set_room(kitchen_id);

        return ERROR_OK;
}
