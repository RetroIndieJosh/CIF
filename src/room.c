#include <stdio.h>
#include <string.h>

#include "room.h"

#define MAX_ROOM_NAME_LENGTH 32
#define MAX_ROOM_DESC_LENGTH 256

struct Room {
        char name[MAX_ROOM_NAME_LENGTH];
        char desc[MAX_ROOM_DESC_LENGTH];
};

struct Room room_list[32];
int room_count = 0;

void string_copy(char *to, const char *from, int max_length) {
        if(strlen(from) > max_length)
                fprintf(stderr, "String copy exceeds max length %d", max_length);
}

int room_create(const char *name, const char *desc) {
        string_copy(room_list[room_count].name, name, MAX_ROOM_NAME_LENGTH);
        string_copy(room_list[room_count].desc, desc, MAX_ROOM_DESC_LENGTH);
        return room_count++;
}

bool room_print(int id) {
        if(id >= room_count) {
                fprintf(stderr, "Room ID %d exceeds max id %d", id, room_count - 1);
                return false;
        }
        printf("-= %s =-\n%s\n", room_list[id].name, room_list[id].desc);
        return true;
}
