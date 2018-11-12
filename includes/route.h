#ifndef CGTFS_ROUTE_H
#define CGTFS_ROUTE_H

typedef enum RouteType {
    STREET_LEVEL,
    UNDERGROUND,
    LONG_RAIL,
    BUS,
    FERRY,
    CABLE_CAR,
    SUSPENDED,
    FUNICULAR
} route_type_t;

typedef struct Route {
    char id[64];
    char id[64];
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
