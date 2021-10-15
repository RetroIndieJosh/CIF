#include <string.h>

#include "command.h"

#include "error.h"
#include "game.h"
#include "item.h"
#include "limits.h"
#include "parser.h"
#include "room.h"
#include "text.h"

// commands return whether a turn has been taken
// in future, commands will have turn length and return int

typedef struct command_s {
        char verb[TOKEN_LEN];
        int (*func)(const char *noun1, const char *noun2);
} command_t;

command_t command_list[MAX_COMMANDS];
int command_count = 0;

int command_drop(const char *noun1, const char *noun2);
int command_get(const char *noun1, const char *noun2);
int command_inventory(const char *noun1, const char *noun2);
int command_look(const char *noun1, const char *noun2);
int command_move(const char *noun1, const char *noun2);
int command_move_east(const char *noun1, const char *noun2);
int command_move_north(const char *noun1, const char *noun2);
int command_move_south(const char *noun1, const char *noun2);
int command_move_west(const char *noun1, const char *noun2);
int command_quit(const char *noun1, const char *noun2);
int command_use(const char *noun1, const char *noun2);

typedef int (*commandfunc_t)(const char*, const char*);

int 
command_add(const char *verb, commandfunc_t func)
{
        string_copy(command_list[command_count].verb, verb, TOKEN_LEN);
        command_list[command_count].func = func;
        print("Added command '%s' => %p\n", command_list[command_count].verb, 
                        command_list[command_count].func);
        return command_count++;
}

void 
command_init() 
{
        command_add("dr", &command_drop);
        command_add("drop", &command_drop);
        command_add("get", &command_get);
        command_add("i", &command_inventory);
        command_add("inventory", &command_inventory);
        command_add("l", &command_look);
        command_add("look", &command_look);
        command_add("quit", &command_quit);
        command_add("take", &command_get);
        command_add("use", &command_use);

        command_add("move", &command_move);
        command_add("east", &command_move_east);
        command_add("e", &command_move_east);
        command_add("north", &command_move_north);
        command_add("n", &command_move_north);
        command_add("south", &command_move_south);
        command_add("s", &command_move_south);
        command_add("west", &command_move_west);
        command_add("w", &command_move_west);
}

int 
command_execute(const char *input) 
{
        parser_process(input);
        const char *verb = parser_get_token(0);
        if (verb == NULL || is_empty(verb)) {
                return ERROR_DATA_MISSING;
        }
        const char *noun1 = parser_get_token(1);
        const char *noun2 = parser_get_token(2);
        for (int i = 0; i < command_count; ++i) {
                if (strncmp(verb, command_list[i].verb, TOKEN_LEN))
                        continue;
                return (*command_list[i].func)(noun1, noun2);
        }
        print("Sorry, I don't understand that. (No command '%s'.)\n", verb);
        return ERROR_NO_MATCH;
}

int 
command_drop(const char *noun1, const char *noun2) 
{
        print("Drop %s %s\n", noun1, noun2);
        return false;
}

int 
command_get(const char *noun1, const char *noun2) 
{
        if (is_empty(noun1)) {
                printl("What would you like to get?");
                return false;
        }
        // TODO check item location is player current room 
        int item_id = item_get_id(noun1);
        if (item_id < 0) {
                if (is_empty(noun2)) {
                        printl("You see no %s here.", noun1);
                } else {
                        printl("You see no %s %s here.", noun1, noun2);
                }
                return false;
        }
        print("Get %s %s\n", noun1, noun2);
        return true;
}

int 
command_inventory(const char *noun1, const char *noun2)
{
        print("Inventory %s %s\n", noun1, noun2);
        return false;
}

int 
command_look(const char *noun1, const char *noun2) 
{
        if (!is_empty(noun1) || !is_empty(noun2)) {
            printl("Just 'look' will suffice.");
            return ERROR_ARG_EXTRA;
        }

        int room_id = game_cur_room_id();
        room_print_full(room_id);

        return OK;
}

int 
command_move(const char *noun1, const char *noun2)
{
        if (is_empty(noun1)){
                printl("You must specify a direction to move.");
                return ERROR_ARG_MISSING;
        }

        if (!is_empty(noun2)) {
                printl("You need only specify the direction.");
                return ERROR_ARG_EXTRA;
        }

        direction_t direction = room_direction_from_string(noun1);
        int room_id = game_cur_room_id();
        int new_room_id = room_get_exit(room_id, direction);
        if (new_room_id == NOWHERE_ID) {
                printl("No exit in that direction.");
                return OK;
        }

        print("You move to ");
        room_print_name(new_room_id);
        printl(".");
        game_set_room(new_room_id);
        return OK;
}

int 
command_move_east(const char *noun1, const char *noun2)
{
        return command_move("east", noun1);
}

int 
command_move_north(const char *noun1, const char *noun2)
{
        return command_move("east", noun1);
}

int 
command_move_south(const char *noun1, const char *noun2)
{
        return command_move("south", noun1);
}

int 
command_move_west(const char *noun1, const char *noun2)
{
        return command_move("west", noun1);
}

int 
command_quit(const char *noun1, const char *noun2) 
{
        game_end();
        return OK;
}

int 
command_use(const char *noun1, const char *noun2) 
{
        print("Use %s %s\n", noun1, noun2);
        return ERROR_NOT_IMPLEMENTED;
}
