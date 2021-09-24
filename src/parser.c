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
        for (int end = 0; end < strlen(input); ++end) {
                if (input[end] != ' ')
                       continue;
                split_token(input, token_count, start, end);
                start = end + 1;
                ++token_count;
                if (token_count >= TOKEN_COUNT) {
                        return;
                }
        }

        split_token(input, token_count, start, strlen(input) - 1);
        ++token_count;
}

//
// private
//

void split_token(const char * input, int index, int start, int end) 
{
        // clean whitespace
        for (int i = end - 1; i >= 0; --i) {
                if(is_whitespace(input[end]))
                        --end;
        }

        int length = min(end - start + 1, TOKEN_LEN);
        strncpy(tokens[index], input+start, length);
}

