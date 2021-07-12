#include <string.h>

#include "item.h"
#include "text.h"

struct Item {
        char name[MAX_NAME_LEN];
        char desc[MAX_DESC_LEN];
};

struct Item item_list[MAX_ITEMS];
int item_count = 0;

bool item_check_id(int item_id) {
        return check_id("item", item_id, item_count);
}

int item_create(const char *name, const char *desc) {
        if(item_count >= MAX_ITEMS)
                return -1;
        string_copy(item_list[item_count].name, name, MAX_NAME_LEN);
        string_copy(item_list[item_count].desc, desc, MAX_DESC_LEN);
        return item_count++;
}

// returns -1 for not found
int item_get_id(const char *item_name) {
        for(int i = 0; i < item_count; ++i) {
                if(strcmp(item_name, item_list[i].name))
                        continue;
                return i;
        }
        print_error("No item by name '%s'\n", item_name);
        return -1;
}

bool item_print_desc(int item_id) {
        if(item_check_id(item_id) == false)
                return false;
        print("%s", item_list[item_id].desc);
        return true;
}

bool item_print_name(int item_id) {
        if(item_check_id(item_id) == false)
                return false;
        print("%s", item_list[item_id].name);
        return true;
}

