#include <stdio.h>
#include <string.h>

#include "error.h"
#include "item.h"
#include "room.h"
#include "text.h"

const int NO_ITEM = -1;
const int NOWHERE_ID = -1;
const int INVENTORY_ID = 0;

room_t room_list[32];
int room_count = 0;

room_t *room_get(int id);
int room_list_items(int room_id);

int
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
        
        for(int i = 0; i < ITEMS_PER_ROOM; ++i)
                room_list[room_count].item_list[i] = -1;

        return room_count++;
}

direction_t 
room_direction_from_string(const char *str)
{
        if (!strcmp(str, "east"))
                return DIR_EAST;
        if (!strcmp(str, "north"))
                return DIR_NORTH;
        if (!strcmp(str, "south"))
                return DIR_SOUTH;
        if (!strcmp(str, "west"))
                return DIR_WEST;
        return DIR_NONE;
}

int 
room_get_exit(int room_id, direction_t direction)
{
        room_t *room = room_get(room_id);
        return room->exit[direction];
}

int 
room_item_add(int room_id, int item_id) 
{
        if (room_check_id(room_id) != OK || item_check_id(item_id) != OK)
                return ERROR_INVALID_TARGET;
        int i = room_list[room_id].item_count;
        room_list[room_id].item_list[i] = item_id;
        room_list[room_id].item_count++;
        return OK;
}

int
room_item_remove(int room_id, int item_id) 
{
        if (room_check_id(room_id) == false || item_check_id(item_id) == false)
                return ERROR_INVALID_TARGET;

        room_t *room = room_get(room_id);
        for(int i = 0; i < room->item_count; ++i) {
                if(room->item_list[i] != item_id)
                        continue;
                
                // remove item and close gap
                for(int k = i; k < room->item_count; ++k)
                        room->item_list[k-1] = room->item_list[k];
                return OK;
        }
        return ERROR_NO_MATCH;
}

int 
room_print_desc(int room_id)
{
        room_t *room = room_get(room_id);
        return item_print_desc(room->self_item_id);
}

int 
room_print_name(int room_id)
{
        room_t *room = room_get(room_id);
        return item_print_name(room->self_item_id);
}

int 
room_print_full(int room_id)
{
        room_t *room = room_get(room_id);
        int char_count = 0;
        char_count += print("-= ");
        char_count += item_print_name(room->self_item_id);
        char_count += printl(" =-");
        char_count += item_print_desc(room->self_item_id);
        char_count += printl("");
        return char_count;
}

int 
room_set_exit(int from_id, direction_t direction, int to_id)
{
        if(direction >= DIR_COUNT)
                return ERROR_OUT_OF_BOUNDS;

        room_t *from = room_get(from_id);
        if (from == NULL)
                return ERROR_INVALID_TARGET;
        if (from->exit[direction] != NOWHERE_ID)
                return ERROR_ILLEGAL_OVERWRITE;

        int check_to = room_check_id(to_id);
        if (check_to != OK)
                return check_to;

        from->exit[direction] = to_id;
        return OK;
}

// 
// private
//

room_t *
room_get(int room_id) 
{
        if (room_check_id(room_id) != OK)
                return NULL;
        return &room_list[room_id];
}

int 
room_list_items(int room_id) 
{
        int char_count = 0;
        char_count += print("%d items\n", room_list[room_id].item_count);
        if (room_list[room_id].item_count == 0)
                return char_count;
        for (int i = 0; i < room_list[room_id].item_count; ++i) {
                char_count += item_print_name(room_list[room_id].item_list[i]);
                char_count += print(" ");
        }
        char_count += print("\n");
        return char_count;
}
