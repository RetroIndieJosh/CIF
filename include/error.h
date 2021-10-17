#pragma once

typedef enum error_s {
        OK,
        ERROR_ARG_EXTRA,
        ERROR_ARG_MISSING,
        ERROR_ARG_TYPE,
        ERROR_DATA_MISSING,
        ERROR_INITIALIZATION,
        ERROR_INVALID_TARGET,
        ERROR_NOT_IMPLEMENTED,
        ERROR_NO_MATCH,
        ERROR_OUT_OF_BOUNDS,
        ERROR_ILLEGAL_OVERWRITE,
        ERROR_MAX_EXCEEDED

} error_t;
