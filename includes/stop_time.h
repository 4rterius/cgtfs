#ifndef CGTFS_STOP_TIME_H
#define CGTFS_STOP_TIME_H

typedef enum StopType {
    REGULAR,
    NOT_AVAILABLE,
    CONTACT_AGENCY,
    CONTACT_DRIVER
} stop_type_t;

typedef enum TimepointPrecision {
    APPROXIMATE,
    EXACT
} timepoint_precision_t;

typedef struct StopTime {
    char trip_id[64];
    char arrival_time[8];
    char departure_time[8];
    char stop_id[64];
    unsigned int stop_sequence;
    char stop_headsign[64];
    stop_type_t pickup_type;
    stop_type_t dropoff_type;
    double shape_dist_traveled;
    timepoint_precision_t timepoint;
} stop_time_t;

#endif
