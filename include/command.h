#ifndef COMMAND_H
#define COMMAND_H

int command_add(const char *verb, void (*func)(const char*, const char*));
void command_init();
void command_execute(const char *input);

#endif // COMMAND_H
