#ifndef CGTFS_TRANSFERS_H
#define CGTFS_TRANSFERS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum {
    TT_RECOMMENDED = 0,
    TT_TIMED = 1,
    TT_TIME_REQUIRED = 2,
    TT_NOT_POSSIBLE = 3,
    TT_NOT_SET
} transfer_type_t;

typedef struct {
    char from_stop_id[65];
    char to_stop_id[65];
    transfer_type_t transfer_type;
    unsigned int min_transfer_time;
    int is_null;
} transfer_t;

transfer_type_t parse_transfer_type(char *value);

transfer_t empty_transfer(void);
transfer_t read_transfer(int field_count, char **field_names, char **field_values);

#endif
