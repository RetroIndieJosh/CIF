#include <stdio.h>
#include <string.h>

#include "room.h"
#include "parser.h"
#include "text.h"

int location = 0;

int main() {
        int id = room_create("Kitchen", "A boring place to cook.");
        print("Created room %d:\n\n", id);
        room_print(id);
        id = room_create("Bedroom", "There's a bed here.");
        print("\nCreated room %d:\n\n", id);
        room_print(id);

        // prompt
        print(">> ");
        char input[32];
        if(fgets(input, 32, stdin) == NULL) {
                print("Error processing input.");
                return 1;
        }
        process_tokens(input);

        int token_count = count_tokens();
        print("You typed %d tokens:\n", token_count);
        for(int i = 0; i < token_count; ++i)
                print("\tToken %d: '%s'\n", i, get_token(i));
        return 0;
}
