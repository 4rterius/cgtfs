#ifndef CGTFS_TRIP_H
#define CGTFS_TRIP_H

typedef enum {
    WA_UNKNOWN,
    WA_POSSIBLE,
    WA_NOT_POSSIBLE
} wheelchair_accessible_t;

typedef enum {
    BA_UNKNOWN,
    BA_POSSIBLE,
    BA_NOT_POSSIBLE
} bikes_allowed_t;

typedef struct {
    char id[65];
    char route_id[65];
    char service_id[65];
    char headsign[65];
    char short_name[65];
    unsigned int direction_id;
    char block_id[65];
    char shape_id[65];
    wheelchair_accessible_t wheelchair_accessible;
    bikes_allowed_t bikes_allowed;
} trip_t;

#endif
