#ifndef LIMITS_H
#define LIMITS_H

#include <stdbool.h>

#define MAX_ITEMS 256
#define MAX_ROOMS 32

#define MAX_NAME_LEN 32
#define MAX_DESC_LEN 256

bool check_id(const char *label, int id, int max);

#endif // LIMITS_H
