#pragma once

#include <stdbool.h>

int command_add(const char *verb, int (*func)(const char*, const char*));
void command_init();
int command_execute(const char *input);
