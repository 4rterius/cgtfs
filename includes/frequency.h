#ifndef CGTFS_FREQUENCY_H
#define CGTFS_FREQUENCY_H

typedef enum {
    ET_NOT_EXACT,
    ET_EXACT
} exact_times_t;

typedef struct {
    char trip_id[65];
    char start_time[9];
    char end_time[9];
    int headway_secs;
    exact_times_t exact_times;
} frequency_t;

#endif
