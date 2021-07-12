#ifndef ROOM_H
#define ROOM_H

#include <stdbool.h>

bool room_check_id(int id);
int room_create(const char *name, const char *desc);
bool room_print(int id);

#endif // ROOM_H
