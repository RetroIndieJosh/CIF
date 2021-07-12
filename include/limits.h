#ifndef LIMITS_H
#define LIMITS_H

#include <stdbool.h>

#define MAX_COMMANDS 8
#define MAX_ITEMS 256
#define MAX_ROOMS 32
#define ITEMS_PER_ROOM 32

#define MAX_NAME_LEN 32
#define MAX_DESC_LEN 256

#define TOKEN_COUNT 3
#define TOKEN_LEN 10

bool check_id(const char *label, int id, int max);

#endif // LIMITS_H
