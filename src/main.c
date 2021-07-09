#include <stdio.h>
#include <string.h>

#include "parser.h"

int main() {
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
