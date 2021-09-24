#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>

#include "limits.h"

enum ItemType {
    ITYPE_ITEM = 0,
    ITYPE_ROOM = 1,
    ITYPE_ACTOR = 2,
    ITYPE_PLAYER = 3
};

struct Item {
        char name[MAX_NAME_LEN];
        char desc[MAX_DESC_LEN];
        int location;
        enum ItemType type;
};

bool item_check_id(int item_id);
int item_create(const char *name, const char *desc);
int item_create_type(const char *name, const char *desc, enum ItemType type);
int item_get_id(const char *name);
struct Item *item_get(int id);

#endif // ITEM_H
