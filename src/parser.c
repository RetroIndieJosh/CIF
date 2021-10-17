#include <stdio.h>
#include <string.h>

#include "limits.h"
#include "math.h"
#include "parser.h"
#include "text.h"

char tokens[TOKEN_COUNT_MAX][TOKEN_LEN+1];
int token_count = 0;

void split_token(const char * input, int index, int start, int end);

//
// public
//

const char *
parser_get_token(int index) 
{
        if (index >= token_count) {
                return "";
        }
        return tokens[index];
}

void 
parser_process(const char * input) 
{
        memset(&tokens, 0, TOKEN_LEN*TOKEN_COUNT_MAX);
        int start = 0;
        token_count = 0;
        for (int end = 0; end < strlen(input); ++end) {
                if (is_whitespace(input[end]) == false) {
                       continue;
                }
                if(start < end) {
                        split_token(input, token_count, start, end);
                        ++token_count;
                        if (token_count >= TOKEN_COUNT_MAX) {
                                return;
                        }
                }
                start = end + 1;
        }

        split_token(input, token_count, start, strlen(input) - 1);
        ++token_count;
}

//
// private
//

void 
split_token(const char * input, int index, int start, int end) 
{
        if(start >= end)
                return;

        // trim leading whitespace
        for (int i = 0; i < start; ++i) {
                if(is_whitespace(input[start]))
                        ++start;
        }

        // trim trailing whitespace
        for (int i = end - 1; i >= 0; --i) {
                if(is_whitespace(input[end]))
                        --end;
        }

        int length = min(end - start + 1, TOKEN_LEN);
        strncpy(tokens[index], input+start, length);
}
