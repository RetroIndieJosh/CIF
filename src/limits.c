#include "limits.h"
#include "text.h"

bool check_id(const char *label, int id, int max) 
{
        if (id >= max) {
                print_error("%s ID %d exceeds max id %d", label, id, max - 1);
                return false;
        }
        return true;
}

