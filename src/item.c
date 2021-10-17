#include <stdlib.h>
#include <string.h>

#include "error.h"
#include "item.h"
#include "text.h"

#define ITEM_CHECK(id) \
        int err = item_check_id(id); \
        if (err != OK) { \
                printl("Tried to access item #%d but does not exist (error %d)", id, err); \
                exit(err); \
        }

item_t item_list[MAX_ITEMS];
int item_count = 0;

item_t *item_get(int id);

bool 
item_check_id(int item_id) 
{
        return check_id("item", item_id, item_count);
}

int 
item_create(const char *name, const char *desc) 
{
        if (item_count >= MAX_ITEMS)
                return ERROR_MAX_EXCEEDED;
        item_t *cur_item = &item_list[item_count];
        string_copy(cur_item->name, name, MAX_NAME_LEN);
        string_copy(cur_item->desc, desc, MAX_DESC_LEN);
        cur_item->location = -1;
        cur_item->type = ITYPE_ITEM;

        return item_count++;
}

int 
item_create_type(const char *name, const char *desc, enum ItemType type) 
{
        int item_id = item_create(name, desc);
        item_list[item_id].type = type;
        return item_id;
}

// returns -1 for not found
int 
item_get_id(const char *item_name) 
{
        for (int i = 0; i < item_count; ++i) {
                if (strcmp(item_name, item_list[i].name))
                        continue;
                return i;
        }
        return -1;
}

int 
item_print_name(int item_id)
{
        ITEM_CHECK(item_id);
        item_t *item = item_get(item_id);
        return print("%s", item->name);
}

int 
item_print_desc(int item_id) 
{
        item_t *item = item_get(item_id);
        if (item == NULL) {
                printl("Tried to access item #%d but does not exist", item_id);
                exit(ERROR_INVALID_TARGET);
        }
        return print("%s", item->desc);
}


//
// private
//

item_t *
item_get(int id)
{
        ITEM_CHECK(id);
        return &item_list[id];
}
