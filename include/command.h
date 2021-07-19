#ifndef COMMAND_H
#define COMMAND_H

#include <stdbool.h>

int command_add(const char *verb, bool (*func)(const char*, const char*));
void command_init();
bool command_execute(const char *input);

#endif // COMMAND_H
