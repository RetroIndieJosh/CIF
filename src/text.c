#include <stdarg.h>
#include <string.h>

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
print(const char *format, ...) 
{
        va_list args;
        va_start(args, format);
        int chars = vfprintf(stdout, format, args);
        va_end(args);
        return chars;
}

int 
printl(const char *format, ...) 
{
        va_list args;
        va_start(args, format);
        int chars = vfprintf(stdout, format, args);
        fprintf(stdout, "\n");
        va_end(args);
        return chars;
}

int 
print_error(const char *format, ...) 
{
        va_list args;
        va_start(args, format);
        int chars = vfprintf(stderr, format, args);
        va_end(args);
        return chars;
}

void 
string_copy(char *to, const char *from, size_t max_length) 
{
        if (strlen(from) > max_length)
                print_error("String copy exceeds max length %zu\n", max_length);
        memset(to, 0, max_length);
        strncpy(to, from, max_length);
        to[max_length - 1] = 0;
}
