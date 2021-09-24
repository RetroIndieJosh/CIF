#include <stdio.h>
#include <string.h>

#include "limits.h"
#include "math.h"
#include "parser.h"
#include "text.h"

char tokens[TOKEN_COUNT][TOKEN_LEN+1];
int token_count = 0;

void split_token(const char * input, int index, int start, int end);

//
// public
//

const char *parser_get_token(int index) 
{
        if (index >= token_count) {
                return NULL;
        }
        return tokens[index];
}

void parser_process(const char * input) 
{
        memset(&tokens, 0, TOKEN_LEN*TOKEN_COUNT);
        int start = 0;
        token_count = 0;
        for (int i = 0; i < strlen(input); ++i) {
                if (input[i] != ' ')
                       continue;
                split_token(input, token_count, start, i-1);
                start = i + 1;
                ++token_count;
                if (token_count >= TOKEN_COUNT) {
                        print_error("Too many tokens; ignoring after char %d\n", i);
                        return;
                }
        }
        split_token(input, token_count, start, strlen(input) - 1);
        ++token_count;
        //print("Parsed: '%s/%s/%s'\n", tokens[0], tokens[1], tokens[2]);
}

//
// private
//

void split_token(const char * input, int index, int start, int end) 
{
        int length = min(end - start + 1, TOKEN_LEN);
        strncpy(tokens[index], input+start, length);
}

