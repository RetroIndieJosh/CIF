#pragma once

#define ERROR_OK (0x0)
#define ERROR_ARG_EXTRA (0x1)
#define ERROR_ARG_MISSING (0x2)
#define ERROR_ARG_TYPE (0x4)
#define ERROR_DATA_MISSING (0x8)
#define ERROR_INITIALIZATION (0xF)
#define ERROR_INVALID_TARGET (0x10)
#define ERROR_NOT_IMPLEMENTED (0x20)
#define ERROR_NO_MATCH (0x40)
#define ERROR_OUT_OF_BOUNDS (0x80)
#define ERROR_ILLEGAL_OVERWRITE (0xF0)
#define ERROR_MAX_EXCEEDED (0x100)

void error_clear();
int error_print();
void error_set(int error_code);
