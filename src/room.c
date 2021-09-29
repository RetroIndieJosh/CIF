#include <stdio.h>
#include <string.h>

#include "item.h"
#include "room.h"
#include "text.h"

room_t room_list[32];
int room_count = 0;

void room_list_items(int room_id);

bool 
room_check_id(int room_id) 
{
        return check_id("room", room_id, room_count);
}

bool 
room_contains(int room_id, int item_id) 
{
        for (int i = 0; i < ITEMS_PER_ROOM; ++i) {
                if (room_list[room_id].item_list[i] == item_id)
                        return true;
        }
        return false;
}

int 
room_create(const char *name, const char *desc) 
{
        if (room_count >= MAX_ROOMS)
                return false;
        room_list[room_count].self_item_id = item_create_type(name, desc, ITYPE_ROOM);
        room_list[room_count].item_count = 0;
        return room_count++;
}

bool 
room_place_item(int room_id, int item_id) 
{
        if (room_check_id(room_id) == false || item_check_id(item_id) == false)
                return false;
        int i = room_list[room_id].item_count;
        room_list[room_id].item_list[i] = item_id;
        room_list[room_id].item_count++;
        return true;
}

room_t *
room_get(int room_id) 
{
        if (room_check_id(room_id) == false)
                return NULL;
        return &room_list[room_id];
}

// 
// private
//

void 
room_list_items(int room_id) 
{
        print("%d items\n", room_list[room_id].item_count);
        if (room_list[room_id].item_count == 0)
                return;
        for (int i = 0; i < room_list[room_id].item_count; ++i) {
                item_t *item = item_get(room_list[room_id].item_list[i]);
                print("%s ", item->name);
        }
        print("\n");
}
