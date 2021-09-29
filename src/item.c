#include <string.h>

#include "item.h"
#include "text.h"

item_t item_list[MAX_ITEMS];
int item_count = 0;

bool 
item_check_id(int item_id) 
{
        return check_id("item", item_id, item_count);
}

int 
item_create(const char *name, const char *desc) 
{
        if (item_count >= MAX_ITEMS)
                return -1;
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

item_t *
item_get(int id)
{
        if (item_check_id(id) == false)
                return NULL;
        return &item_list[id];
}
