#pragma once

#include <stdbool.h>

#include "limits.h"

extern const int NO_ITEM;
extern const int NOWHERE_ID;
extern const int INVENTORY_ID;

typedef enum direction_s {
        DIR_EAST,
        DIR_NORTH,
        DIR_SOUTH,
        DIR_WEST,
        DIR_COUNT,
        DIR_NONE
} direction_t;

typedef struct room_s {
        int self_item_id;
        int item_list[ITEMS_PER_ROOM];
        int item_count;
        int exit[DIR_COUNT];
} room_t;

int room_check_id(int id);
bool room_contains(int room_id, int item_id);
int room_create(const char *name, const char *desc);
direction_t room_direction_from_string(const char *str);
int room_get_exit(int room_id, direction_t direction);
int room_item_add(int room_id, int item_id);
int room_item_remove(int room_id, int item_id);
int room_print_desc(int room_id);
int room_print_name(int room_id);
int room_print_full(int room_id);
int room_set_exit(int from_id, direction_t direction, int to_id);
