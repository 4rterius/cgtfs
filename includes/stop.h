#ifndef CGTFS_STOP_H
#define CGTFS_STOP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum {
    LT_STOP = 0,
    LT_STATION = 1,
    LT_STATION_ENTRANCE_EXIT = 2,
    LT_NOT_SET
} location_type_t;

typedef enum {
    WB_UNKNOWN_OR_INHERITED = 0,
    WB_SOME = 1,
    WB_NOT_POSSIBLE = 2,
    WB_NOT_SET
} wheelchair_boarding_t;

typedef struct {
    char id[65];
    char code[65];
    char name[65];
    char desc[513];
    long double lat;
    long double lon;
    char zone_id[65];
    char url[129];
    location_type_t location_type;
    char parent_station[65];
    char timezone[65];
    wheelchair_boarding_t wheelchair_boarding;
    int is_null;
} stop_t;

location_type_t parse_location_type(const char *value);
wheelchair_boarding_t parse_wheelchair_boarding(const char *value);

stop_t empty_stop(void);
stop_t read_stop(int field_count, const char **field_names, const char **field_values);

#endif
