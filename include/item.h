#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>

#include "limits.h"

int item_create(const char *name, const char *desc);
bool item_print_desc(int id);
bool item_print_name(int id);

#endif // ITEM_H
