#pragma once

#include <stdbool.h>
#include <stdio.h>

bool is_whitespace(char ch);
bool is_empty(const char *msg);
int trim_left(const char *msg);
int trim_right(const char *msg);
int string_copy(char *to, const char *from, size_t max_length);
