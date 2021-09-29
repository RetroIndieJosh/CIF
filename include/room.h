#pragma once

#include <stdbool.h>

#include "limits.h"

typedef struct room_s {
        int self_item_id;
        int item_list[ITEMS_PER_ROOM];
        int item_count;
} room_t;

bool room_check_id(int id);
bool room_contains(int room_id, int item_id);
int room_create(const char *name, const char *desc);
bool room_place_item(int room_id, int item_id);
room_t *room_get(int id);
