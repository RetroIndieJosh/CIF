#pragma once

typedef enum error_s {
        OK,
        ERROR_INITIALIZATION,
        ERROR_ROOM_HAS_CONNECTION,
        ERROR_ARG_MISSING,
        ERROR_ARG_EXTRA,
        ERROR_ARG_TYPE,
        ERROR_NO_MATCH,
        ERROR_DATA_MISSING,
        ERROR_NOT_IMPLEMENTED
} error_t;