#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"
#include "game.h"
#include "item.h"
#include "room.h"
#include "text.h"
#include "unit_tests.h"

void process_args(int argc, char *argv[]);

void 
process_args(int argc, char *argv[])
{
        for (int i = 1; i < argc; ++i) {
                char *arg = argv[i];
                if(arg[0] != '-') {
                        // TODO read game file here
                        printl("Invalid argument %s", arg);
                        exit(1);
                }
                if (!strcmp(arg, "-h") || !strcmp(arg, "--help")) {
                        printl("%s [game file] {-h/--help} {-t/--test}", argv[0]);
                        printl("\t-h/--help    display this text and exit");
                        printl("\t-t/--test    run unit tests and exit");
                        printl("");
                        exit(0);
                }
                if (!strcmp(arg, "-t") || !strcmp(arg, "--test")) {
                        int result = test_run_all();
                        exit(result);
                }
        }
}

int 
main(int argc, char *argv[]) 
{
        process_args(argc, argv);

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

        id = room_create("Bedroom", "There's a bed here.");
        printl("Created room %d:", id);
        command_execute("look");

        while (game_is_over() == false) {
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
