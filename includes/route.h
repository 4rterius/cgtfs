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

/**
 * routes.txt record
 * @see init_route()
 * @see read_route()
 * @see https://developers.google.com/transit/gtfs/reference/#routestxt
 */
typedef struct {
    char id[65];          ///< [Required] Unique ID that identifies the route.
    char agency_id[65];   ///< [Optional] Unique ID that identifies the agency handling the route.
    char short_name[65];  ///< [Cond. required] Short name of the route.
    char long_name[257];  ///< [Cond. required] More descriptive name of the route.
    char desc[513];       ///< [Optional] Description of the route.
    route_type_t type;    ///< [Required] What kind of vehicles does this route serve.
    char url[129];        ///< [Optional] URL of the page about the route.
    char color[7];        ///< [Optional] An RRGGBB color that corresponds to the route (default FFFFFF).
    char text_color[7];   ///< [Optional] An RRGGBB color to be drawn against .color (default 000000).
    int sort_order;       ///< [Optional] Position of the route in the presentation to customers.
    int is_null;
} route_t;


route_type_t parse_route_type(const char *value);

/**
 * Initializes the given route record with empty/default values.
 * @param[out] record Route record pointer to initialize.
 */
void init_route(route_t *record);

/**
 * Reads given datafields and field names into the given route struct.
 * @param[out] record        The pointer to write into.
 * @param[in]  field_count   Number of rows (columns) the record has.
 * @param[in]  field_names   Names of the fields.
 * @param[in]  field_values  Contents of the record.
 */
void read_route(route_t *record, int field_count, const char **field_names, const char **field_values);

#endif
