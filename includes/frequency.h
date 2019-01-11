#ifndef CGTFS_FREQUENCY_H
#define CGTFS_FREQUENCY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum {
    TE_NOT_EXACT = 0,
    TE_EXACT = 1,
    TE_NOT_SET
} time_exactness_t;

typedef struct {
    char trip_id[65];
    char start_time[9];
    char end_time[9];
    int headway_secs;
    time_exactness_t exact_times;
    int is_null;
} frequency_t;

time_exactness_t parse_time_exactness(const char *value);

void init_frequency(frequency_t *record);
void read_frequency(frequency_t *record, int field_count, const char **field_names, const char **field_values);

#endif
