#include <stdio.h>
#include <string.h>

#include "room.h"
#include "parser.h"

int location = 0;

int main() {
        int id = room_create("Kitchen", "A boring place to cook.");
        printf("Created room %d:\n\n", id);
        room_print(id);
        id = room_create("Bedroom", "There's a bed here.");
        printf("\nCreated room %d:\n\n", id);
        room_print(id);

        // prompt
        printf(">> ");
        char input[32];
        if(fgets(input, 32, stdin) == NULL) {
                printf("Error processing input.");
                return 1;
        }
        process_tokens(input);

        int token_count = count_tokens();
        printf("You typed %d tokens:\n", token_count);
        for(int i = 0; i < token_count; ++i)
                printf("\tToken %d: '%s'\n", i, get_token(i));
        return 0;
}
