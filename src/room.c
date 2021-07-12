#include <stdio.h>
#include <string.h>

#include "limits.h"
#include "item.h"
#include "room.h"
#include "text.h"

struct Room {
        int self_item_id;
};

struct Room room_list[32];
int room_count = 0;

int room_create(const char *name, const char *desc) {
        room_list[room_count].self_item_id = item_create(name, desc);
        return room_count++;
}

bool room_print(int id) {
        if(check_id("room", id, MAX_ROOMS) == false)
                return false;
        print("-= ");
        item_print_name(room_list[id].self_item_id);
        print(" =-\n");
        item_print_desc(room_list[id].self_item_id);
        print("\n\n");
        return true;
}
