#ifndef CGTFS_ROUTE_H
#define CGTFS_ROUTE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum {
    RT_STREET_LEVEL = 0,
    RT_UNDERGROUND = 1,
    RT_LONG_RAIL = 2,
    RT_BUS = 3,
    RT_FERRY = 4,
    RT_CABLE_CAR = 5,
    RT_SUSPENDED = 6,
    RT_FUNICULAR = 7,
    RT_NOT_SET
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
    int sort_order;
    int is_null;
} route_t;


route_type_t parse_route_type(const char *value);

void init_route(route_t *record);
void read_route(route_t *record, int field_count, const char **field_names, const char **field_values);

#endif
