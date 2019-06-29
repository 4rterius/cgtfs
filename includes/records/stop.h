/**
 * @file
 * @brief    Stop entity handling functionality.
 */

#ifndef CGTFS_STOP_H
#define CGTFS_STOP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * What kind of a location the entity is.
 * 
 * @ingroup    Core__EntityEnums
 */
typedef enum {
    LT_STOP = 0,                   ///< Stop.
    LT_STATION = 1,                ///< Station, an area with one or more stops.
    LT_STATION_ENTRANCE_EXIT = 2,  ///< Station entrance/exit.
    LT_NOT_SET
} location_type_t;

/**
 * Whether wheelchair boardings/entrances are possible.
 * 
 * @ingroup    Core__EntityEnums
 */
typedef enum {
    WB_UNKNOWN_OR_INHERITED = 0,  ///< No information available or the parent's value applies.
    WB_SOME = 1,                  ///< Possible.
    WB_NOT_POSSIBLE = 2,          ///< Not possible.
    WB_NOT_SET
} wheelchair_boarding_t;

/**
 * stops.txt record
 * 
 * @see        init_stop()
 * @see        read_stop()
 * @see        https://developers.google.com/transit/gtfs/reference/#stopstxt
 * 
 * @ingroup    Core__EntityTypes
 */
typedef struct {
    char id[65];                                ///< [Required] Unique ID that identifies this stop.
    char code[65];                              ///< [Optional] Unique short text that identifies this stop to passangers.
    char name[65];                              ///< [Required] People-friendly name of the stop.
    char desc[513];                             ///< [Optional] Description of the stop.
    long double lat;                            ///< [Required] Latitude of the stop's location.
    long double lon;                            ///< [Required] Longitude of the stop's location.
    char zone_id[65];                           ///< [Optional] ID of the zone in which the stop is located.
    char url[129];                              ///< [Optional] URL address of a web page about this stop.
    location_type_t location_type;              ///< [Optional] What kind of a entity this record represents.
    char parent_station[65];                    ///< [Optional] Unique ID that identifies the parent station enitity if any.
    char timezone[65];                          ///< [Optional] Timezone in which the stop is located (https://en.wikipedia.org/wiki/List_of_tz_database_time_zones).
    wheelchair_boarding_t wheelchair_boarding;  ///< [Optional] Whether wheelchair boardings are possible at the stop.
    int is_null;
} stop_t;

/**
 * Parses the location_type_t value from given string
 * with regard for the default value as per GTFS reference.
 * 
 * @param[in]    value    Char array (string) to parse the enumerator from.
 * 
 * @returns      An location_type_t value.
 * 
 * @ingroup      Core__EntityEnums
 */
location_type_t parse_location_type(const char *value);

/**
 * Parses the wheelchair_boarding_t value from given string
 * with regard for the default value as per GTFS reference.
 * 
 * @param[in]    value    Char array (string) to parse the enumerator from.
 * 
 * @returns      An wheelchair_boarding_t value.
 * 
 * @ingroup      Core__EntityEnums
 */
wheelchair_boarding_t parse_wheelchair_boarding(const char *value);

/**
 * Initializes the given stop record with empty/default values.
 * 
 * @param[out]    record    Stop record pointer to initialize.
 * 
 * @ingroup       Core__EntityFunctions
 */
void init_stop(stop_t *record);

/**
 * Reads given datafields and field names into the given stop struct.
 * 
 * @param[out]    record          The pointer to write into.
 * @param[in]     field_count     Number of rows (columns) the record has.
 * @param[in]     field_names     Names of the fields.
 * @param[in]     field_values    Contents of the record.
 * 
 * @ingroup       Core__EntityFunctions
 */
void read_stop(stop_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 * 
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 * @returns      0 if structures are equal, non-zero otherwise.
 * 
 * @ingroup      Core__EntityFunctions
 */
int equal_stop(const stop_t *a, const stop_t *b);

#endif
