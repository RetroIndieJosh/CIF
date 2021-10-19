#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "limits.h"

#define ITEM_CHECK(id) \
        int item_err = item_check_id(id); \
        if (item_err != ERROR_OK) { \
                printl("Tried to access item #%d but does not exist (error %d)", id, item_err); \
                exit(item_err); \
        }

enum ItemType {
    ITYPE_ITEM = 0,
    ITYPE_ROOM = 1,
    ITYPE_ACTOR = 2,
    ITYPE_PLAYER = 3
};

typedef struct item_s {
        char name[MAX_NAME_LEN];
        char desc[MAX_DESC_LEN];
        int location;
        enum ItemType type;
} item_t;

bool item_check_id(int item_id);
int item_create(const char *name, const char *desc);
int item_create_type(const char *name, const char *desc, enum ItemType type);
int item_get_id(const char *name);
int item_print_name(int item_id);
int item_print_desc(int item_id);
//item_t *item_get(int id);
