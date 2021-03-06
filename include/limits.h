#pragma once

#include <stdbool.h>

#define MAX_COMMANDS 8
#define MAX_ITEMS 256
#define MAX_ROOMS 32
#define ITEMS_PER_ROOM 32

#define MAX_NAME_LEN 32
#define MAX_DESC_LEN 256

#define TOKEN_COUNT_MAX 3
#define TOKEN_LEN 10

int check_id(const char *label, int id, int max);
