#ifndef CGTFS_STOP_TIME_H
#define CGTFS_STOP_TIME_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum {
    ST_REGULAR = 0,
    ST_NOT_AVAILABLE = 1,
    ST_CONTACT_AGENCY = 2,
    ST_CONTACT_DRIVER = 3,
    ST_NOT_SET
} stop_type_t;

typedef enum {
    TP_APPROXIMATE = 0,
    TP_EXACT = 1,
    TP_NOT_SET
} timepoint_precision_t;

typedef struct {
    char trip_id[65];
    char arrival_time[9];
    char departure_time[9];
    char stop_id[65];
    unsigned int stop_sequence;
    char stop_headsign[65];
    stop_type_t pickup_type;
    stop_type_t dropoff_type;
    double shape_dist_traveled;
    timepoint_precision_t timepoint;
    int is_null;
} stop_time_t;

stop_type_t parse_stop_type(const char *value);
timepoint_precision_t parse_timepoint_precision(const char *value);

stop_time_t empty_stop_time(void);
stop_time_t read_stop_time(int field_count, const char **field_names, const char **field_values);

#endif
