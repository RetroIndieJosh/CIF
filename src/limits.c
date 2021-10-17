#include "error.h"
#include "limits.h"
#include "text.h"

int
check_id(const char *label, int id, int max) 
{
        // TODO should we check for equal to zero? is that an error? or should
        // we sometimes manipualte NOWHERE and NO_ITEM?
        if (id < 0 || id >= max) {
                print_error("%s ID %d is invalid (0-%d)", label, id, max - 1);
                return ERROR_INVALID_TARGET;
        }
        return OK;
}

