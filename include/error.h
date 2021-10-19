#pragma once

typedef enum error_s {
        OK = 0,
        ERROR_ARG_EXTRA = 0x1,
        ERROR_ARG_MISSING = 0x2,
        ERROR_ARG_TYPE = 0x4,
        ERROR_DATA_MISSING = 0x8,
        ERROR_INITIALIZATION = 0xF,
        ERROR_INVALID_TARGET = 0x10,
        ERROR_NOT_IMPLEMENTED = 0x20,
        ERROR_NO_MATCH = 0x40,
        ERROR_OUT_OF_BOUNDS = 0x80,
        ERROR_ILLEGAL_OVERWRITE = 0xF0,
        ERROR_MAX_EXCEEDED = 0x100
} error_t;

void error_clear();
int error_print();
void error_set(int error_code);
