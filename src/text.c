#include <stdarg.h>
#include <string.h>

#include "error.h"
#include "text.h"

bool 
is_empty(const char *msg) 
{
        return !strcmp(msg, "");
}

bool 
is_whitespace(char ch) 
{
        return ch != '\0' && (ch == ' ' || ch == '\n' || ch == '\t');
}

int 
string_copy(char *to, const char *from, size_t max_length) 
{
        if (strlen(from) > max_length)
                return ERROR_MAX_EXCEEDED;
        memset(to, 0, max_length);
        strncpy(to, from, max_length);
        to[max_length - 1] = 0;
        return OK;
}
