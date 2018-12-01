#ifndef CGTFS_STOP_H
#define CGTFS_STOP_H

typedef enum {
    LT_STOP,
    LT_STATION,
    LT_STATION_ENTRANCE_EXIT
} location_type_t;

typedef enum {
    WB_UNKNOWN,
    WB_SOME,
    WB_NOT_POSSIBLE
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
    int parent_station;
    char timezone[65];
    wheelchair_boarding_t wheelchair_boarding;
} stop_t;

#endif
