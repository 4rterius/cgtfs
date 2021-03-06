/**
 * @file
 * @brief    Route entity handling functionality.
 */

#ifndef CGTFS_ROUTE_H
#define CGTFS_ROUTE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "xstrlengths.h"


/**
 * The kind of transport the route serves.
 *
 * @ingroup    Core__EntityEnums Core__EntityList__Route
 */
typedef enum {
    RT_STREET_LEVEL = 0,  ///< Any light rail or street level system within a metropolitan area.
    RT_UNDERGROUND = 1,   ///< Any underground rail system within a metropolitan area.
    RT_LONG_RAIL = 2,     ///< Rail. Used for intercity or long-distance travel.
    RT_BUS = 3,           ///< Short- and long-distance bus routes.
    RT_FERRY = 4,         ///< Short- and long-distance boat service.
    RT_CABLE_CAR = 5,     ///< Street-level cable trams where the cable runs beneath the tram.
    RT_SUSPENDED = 6,     ///< Cable transport where the cabins, cars or gondolas are hauled above the ground by one or several cables.
    RT_FUNICULAR = 7,     ///< Any rail system which uses a cable traction for moving on steep inclines.
    RT_NOT_SET
} route_type_t;

/**
 * routes.txt record
 *
 * @see        init_route()
 * @see        read_route()
 * @see        https://developers.google.com/transit/gtfs/reference/#routestxt
 *
 * @ingroup    Core__EntityTypes Core__EntityList__Route
 */
typedef struct {
    char id[CGTFS_SL_IDS];            ///< [Required] Unique ID that identifies the route.
    char agency_id[CGTFS_SL_IDS];     ///< [Optional] Unique ID that identifies the agency handling the route.
    char short_name[CGTFS_SL_NAM];    ///< [Cond. required] Short name of the route.
    char long_name[CGTFS_SL_TXT];     ///< [Cond. required] More descriptive name of the route.
    char desc[CGTFS_SL_DSC];          ///< [Optional] Description of the route.
    route_type_t type;                ///< [Required] What kind of vehicles does this route serve.
    char url[CGTFS_SL_URL];           ///< [Optional] URL of the page about the route.
    char color[CGTFS_SL_COL];         ///< [Optional] An RRGGBB color that corresponds to the route (default FFFFFF).
    char text_color[CGTFS_SL_COL];    ///< [Optional] An RRGGBB color to be drawn against .color (default 000000).
    int sort_order;                   ///< [Optional] Position of the route in the presentation to customers.
} route_t;

/**
 * Parses the route_type_t value from given string
 * with regard for the default value as per GTFS reference.
 *
 * @param[in]    value    Char array (string) to parse the enumerator from.
 *
 * @returns      An route_type_t value;
 *
 * @ingroup      Core__EntityEnums Core__EntityList__Route
 */
route_type_t parse_route_type(const char *value);

/**
 * Initializes the given route record with empty/default values.
 *
 * @param[out]    record    Route record pointer to initialize.
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__Route
 */
void init_route(route_t *record);

/**
 * Reads given datafields and field names into the given route struct.
 *
 * @param[out]    record          The pointer to write into.
 * @param[in]     field_count     Number of rows (columns) the record has.
 * @param[in]     field_names     Names of the fields.
 * @param[in]     field_values    Contents of the record.
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__Route
 */
void read_route(route_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 *
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 *
 * @returns      0 if the structures differ and 1 otherwise
 *
 * @ingroup      Core__EntityFunctions Core__EntityList__Route
 */
int equal_route(const route_t *a, const route_t *b);

#endif
