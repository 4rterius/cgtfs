#ifndef CGTFS_TRANSFERS_H
#define CGTFS_TRANSFERS_H

typedef enum {
    TT_RECOMMENDED,
    TT_TIMED,
    TT_TIME_REQUIRED,
    TT_NOT_POSSIBLE
} transfer_type_t;

typedef struct {
    char from_stop_id[64];
    char to_stop_id[64];
    transfer_type_t transfer_type;
    unsigned int min_transfer_time;
} transfer_t;

#endif
