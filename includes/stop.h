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

/**
 * stops.txt record
 * @see init_stop()
 * @see read_stop()
 * @see https://developers.google.com/transit/gtfs/reference/#stopstxt
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

location_type_t parse_location_type(const char *value);
wheelchair_boarding_t parse_wheelchair_boarding(const char *value);

/**
 * Initializes the given stop record with empty/default values.
 * @param[out] record Stop record pointer to initialize.
 */
void init_stop(stop_t *record);

/**
 * Reads given datafields and field names into the given stop struct.
 * @param[out] record        The pointer to write into.
 * @param[in]  field_count   Number of rows (columns) the record has.
 * @param[in]  field_names   Names of the fields.
 * @param[in]  field_values  Contents of the record.
 */
void read_stop(stop_t *record, int field_count, const char **field_names, const char **field_values);

#endif
