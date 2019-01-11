#ifndef CGTFS_TRIP_H
#define CGTFS_TRIP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum {
    WA_UNKNOWN = 0,
    WA_POSSIBLE = 1,
    WA_NOT_POSSIBLE = 2,
    WA_NOT_SET
} wheelchair_accessible_t;

typedef enum {
    BA_UNKNOWN = 0,
    BA_POSSIBLE = 1,
    BA_NOT_POSSIBLE = 2,
    BA_NOT_SET
} bikes_allowed_t;

typedef struct {
    char route_id[65];
    char service_id[65];
    char trip_id[65];
    char headsign[65];
    char short_name[65];
    unsigned int direction_id;
    char block_id[65];
    char shape_id[65];
    wheelchair_accessible_t wheelchair_accessible;
    bikes_allowed_t bikes_allowed;
    int is_null;
} trip_t;

wheelchair_accessible_t parse_wheelchair_accessibility(const char *value);
bikes_allowed_t parse_bike_allowance(const char *value);

trip_t empty_trip(void);
trip_t read_trip(const int field_count, const char **field_names, const char **field_values);

#endif
