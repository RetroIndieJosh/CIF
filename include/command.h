#pragma once

#include <stdbool.h>

int command_add(const char *verb, int (*func)(const char*, const char*));
int command_init();
int command_execute(const char *input);
