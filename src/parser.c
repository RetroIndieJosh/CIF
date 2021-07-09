#include <stdio.h>
#include <string.h>

#include "parser.h"

char tokens[4][8];
int token_count = 0;

const char *get_token(int index) {
        if(index >= token_count)
                fprintf(stderr, "Invalid token index %d (%d tokens)", index, token_count);
        return tokens[index];
}

int count_tokens() {
        return token_count;
}

void process_tokens(const char * input) {
        int start = 0;
        token_count = 0;
        for(int i = 0; i < strlen(input); ++i) {
                if(input[i] != ' ')
                       continue;
                split_token(input, token_count, start, i);
                start = i + 1;
                ++token_count;
                if(token_count >= 4) {
                        fprintf(stderr, "Too many tokens; ignoring after char %d\n", i);
                        return;
                }
        }
        split_token(input, token_count, start, strlen(input) - 1);
        ++token_count;
}

void split_token(const char * input, int index, int start, int end) {
        int length = end - start;
        if(length > 8)
                fprintf(stderr, "Token too long (%d > 8\n", length);
        strncpy(tokens[index], input+start, length);
}

