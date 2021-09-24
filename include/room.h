#ifndef ROOM_H
#define ROOM_H

#include <stdbool.h>

struct Room {
        int self_item_id;
        int item_list[ITEMS_PER_ROOM];
        int item_count;
};

bool room_check_id(int id);
bool room_contains(int room_id, int item_id);
int room_create(const char *name, const char *desc);
bool room_place_item(int room_id, int item_id);
struct Room *room_get(int id);

#endif // ROOM_H
