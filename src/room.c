#include <stdio.h>
#include <string.h>

#include "limits.h"
#include "item.h"
#include "room.h"
#include "text.h"

struct Room {
        int self_item_id;
        int item_list[ITEMS_PER_ROOM];
        int item_count;
};

struct Room room_list[32];
int room_count = 0;

// private decls
void room_list_items(int room_id);

//
// public
//

bool room_check_id(int room_id) {
        return check_id("room", room_id, room_count);
}

int room_create(const char *name, const char *desc) {
        if(room_count >= MAX_ROOMS)
                return false;
        room_list[room_count].self_item_id = item_create(name, desc);
        room_list[room_count].item_count = 0;
        return room_count++;
}

bool room_place_item(int room_id, int item_id) {
        if(room_check_id(room_id) == false || item_check_id(item_id) == false)
                return false;
        int i = room_list[room_id].item_count;
        room_list[room_id].item_list[i] = item_id;
        room_list[room_id].item_count++;
        return true;
}

bool room_print(int room_id) {
        if(room_check_id(room_id) == false)
                return false;
        print("-= ");
        item_print_name(room_list[room_id].self_item_id);
        print(" =-\n");
        item_print_desc(room_list[room_id].self_item_id);
        print("\n");
        room_list_items(room_id);
        print("\n");
        return true;
}

// 
// private
//

void room_list_items(int room_id) {
        print("%d items\n", room_list[room_id].item_count);
        if(room_list[room_id].item_count == 0)
                return;
        for(int i = 0; i < room_list[room_id].item_count; ++i) {
                item_print_name(room_list[room_id].item_list[i]);
                print(" ");
        }
        print("\n");
}

