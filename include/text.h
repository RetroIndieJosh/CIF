#ifndef TEXT_H
#define TEXT_H

#include <stdio.h>

int print(const char *format, ...);
int print_error(const char *format, ...);
void string_copy(char *to, const char *from, size_t max_length);

#endif // TEXT_H
