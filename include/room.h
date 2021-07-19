#ifndef ROOM_H
#define ROOM_H

#include <stdbool.h>

bool room_check_id(int id);
bool room_contains(int room_id, int item_id);
int room_create(const char *name, const char *desc);
bool room_place_item(int room_id, int item_id);
bool room_print(int id);

#endif // ROOM_H
