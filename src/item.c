#include "item.h"
#include "text.h"

struct Item {
        char name[MAX_NAME_LEN];
        char desc[MAX_DESC_LEN];
};

struct Item item_list[MAX_ITEMS];
int item_count = 0;

int item_create(const char *name, const char *desc) {
        string_copy(item_list[item_count].name, name, MAX_NAME_LEN);
        string_copy(item_list[item_count].desc, desc, MAX_DESC_LEN);
        return item_count++;
}

bool item_print_desc(int id) {
        if(check_id("item", id, MAX_ITEMS) == false)
                return false;
        print("%s", item_list[id].desc);
        return true;
}

bool item_print_name(int id) {
        if(check_id("item", id, MAX_ITEMS) == false)
                return false;
        print("%s", item_list[id].name);
        return true;
}

