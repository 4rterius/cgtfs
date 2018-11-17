#ifndef CGTFS_ROUTE_H
#define CGTFS_ROUTE_H

typedef enum {
    RT_STREET_LEVEL,
    RT_UNDERGROUND,
    RT_LONG_RAIL,
    RT_BUS,
    RT_FERRY,
    RT_CABLE_CAR,
    RT_SUSPENDED,
    RT_FUNICULAR
} route_type_t;

typedef struct {
    char id[64];
    char agency_id[64];
    char short_name[64];
    char long_name[256];
    char desc[512];
    route_type_t type;
    char url[128];
    char color[6];
    char text_color[6];
    unsigned int sort_order;
} route_t;

#endif
