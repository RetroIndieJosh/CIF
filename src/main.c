#include <stdio.h>
#include <string.h>

#include "command.h"
#include "game.h"
#include "item.h"
#include "room.h"
#include "text.h"

int location = 0;

int main() {
        command_init();
        room_create("Inventory", "");

        int id = room_create("Kitchen", "A boring place to cook.");
        room_place_item(id,
                item_create("knife", "It's sharp")
                );
        room_place_item(id,
                item_create("spatula", "Flips burgers and pancakes")
                );
        printl("Created room %d:", id);
        room_print(id);

        id = room_create("Bedroom", "There's a bed here.");
        printl("Created room %d:", id);
        room_print(id);

        while(game_ended() == false) {
                // prompt
                print(">> ");
                char input[32];
                if(fgets(input, 32, stdin) == NULL) {
                        print("Error processing input.");
                        return 1;
                }
                command_execute(input);
                printl("");
         }

        return 0;
}
