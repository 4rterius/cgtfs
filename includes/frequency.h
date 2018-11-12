#ifndef CGTFS_FREQUENCY_H
#define CGTFS_FREQUENCY_H

typedef enum ExactTimes {
    NOT_EXACT,
    EXACT
} exact_times_t;

typedef struct Frequency {
    char trip_id[64];
    char start_time[8];
    char end_time[8];
    int headway_secs;
    exact_times_t exact_times;
} frequency_t;

#endif
