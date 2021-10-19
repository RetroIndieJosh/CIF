#include <stdio.h>

#include "error.h"

int error = 0;

void 
error_clear()
{
        error = 0;
}

int
error_print()
{
        int len = 0;

        if (error == ERROR_OK)
                return printf("No errors\n");
        
        printf("Error:\n");
        if (error & ERROR_ARG_EXTRA)
                len += printf("\textra argument");
        if (error & ERROR_ARG_TYPE)
                len += printf("\targument is wrong type");
        if (error & ERROR_DATA_MISSING)
                len += printf("\tmissing data");
        if (error & ERROR_INITIALIZATION)
                len += printf("\tinvalid initialization");
        if (error & ERROR_INVALID_TARGET)
                len += printf("\tinvalid target");
        if (error & ERROR_NOT_IMPLEMENTED)
                len += printf("\tnot implemented");
        if (error & ERROR_NO_MATCH)
                len += printf("\tno match");
        if (error & ERROR_OUT_OF_BOUNDS)
                len += printf("\tout of bounds");
        if (error & ERROR_ILLEGAL_OVERWRITE)
                len += printf("\tillegal overwrite");
        if (error & ERROR_MAX_EXCEEDED)
                len += printf("\texceeded maximum");
        return len;
}

void 
error_set(int error_code)
{
        error |= error_code;
}
