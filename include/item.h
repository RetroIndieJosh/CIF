#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>

#include "limits.h"

#define ITYPE_ITEM 0
#define ITYPE_ROOM 1
#define ITYPE_ACTOR 2
#define ITYPE_PLAYER 3

bool item_check_id(int item_id);
int item_create(const char *name, const char *desc);
int item_create_type(const char *name, const char *desc, int type);
int item_get_id(const char *name);
bool item_print_desc(int id);
bool item_print_name(int id);

#endif // ITEM_H
