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
    char id[65];
    char agency_id[65];
    char short_name[65];
    char long_name[257];
    char desc[513];
    route_type_t type;
    char url[129];
    char color[7];
    char text_color[7];
    unsigned int sort_order;
} route_t;

#endif
