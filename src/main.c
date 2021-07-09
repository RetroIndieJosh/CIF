#include <stdio.h>
#include <string.h>

void process_tokens(const char * input);
void split_token(const char * input, int index, int start, int end);

char tokens[4][8];
int token_count = 0;

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

int main() {
        char input[32];
        if(fgets(input, 32, stdin) == NULL) {
                printf("Error processing input.");
                return 1;
        }
        process_tokens(input);
        printf("You typed %d tokens:\n", token_count);
        for(int i = 0; i < token_count; ++i)
                printf("\tToken %d: '%s'\n", i, tokens[i]);
        return 0;
}
