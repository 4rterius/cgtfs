/**
 * @file
 * @brief    Stop time entity handling functionality.
 */

#ifndef CGTFS_STOP_TIME_H
#define CGTFS_STOP_TIME_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "xstrlengths.h"


/**
 * Whether passangers are picked up / dropped off at the stop
 * normally, never, or only on special arrangements.
 *
 * @ingroup    Core__EntityEnums Core__EntityList__StopTime
 */
typedef enum {
    ST_REGULAR = 0,         ///< Regularly scheduled pickup.
    ST_NOT_AVAILABLE = 1,   ///< No pickup available.
    ST_CONTACT_AGENCY = 2,  ///< Must phone agency to arrange pickup.
    ST_CONTACT_DRIVER = 3,  ///< Must coordinate with driver to arrange pickup.
    ST_NOT_SET
} stop_type_t;

/**
 * Whether timepoints are considered exact or approximate.
 *
 * @ingroup    Core__EntityEnums Core__EntityList__StopTime
 */
typedef enum {
    TP_APPROXIMATE = 0,  ///< Approximate (default behavior; when the field is empty).
    TP_EXACT = 1,        ///< Exact.
    TP_NOT_SET
} timepoint_precision_t;

/**
 * stop_times.txt record
 *
 * @see        init_stop_time()
 * @see        read_stop_time()
 * @see        https://developers.google.com/transit/gtfs/reference/#stop_timestxt
 *
 * @ingroup    Core__EntityTypes Core__EntityList__StopTime
 */
typedef struct {
    char trip_id[CGTFS_SL_IDS];          ///< [Required] Unique ID that identifies the trip.
    char arrival_time[CGTFS_SL_TIM];     ///< [Required] Time (HH:MM:SS) when a vehicle arrives to the stop for a particular trip.
    char departure_time[CGTFS_SL_TIM];   ///< [Required] Time (HH:MM:SS) when a vehicle departs from the stop for a particular trip.
    char stop_id[CGTFS_SL_IDS];          ///< [Required] Unique ID that identifies the stop.
    unsigned int stop_sequence;          ///< [Required] Number that identifies the order of stops for a trip.
    char stop_headsign[CGTFS_SL_NAM];    ///< [Optional] Text that appears to the passangers to identify the trip's destination.
    stop_type_t pickup_type;             ///< [Optional] Whether and how are passangers picked up.
    stop_type_t dropoff_type;            ///< [Optional] Whether and how are passangers dropped off.
    double shape_dist_traveled;          ///< [Optional] How much distance the vehicle traveled up to the stop.
    timepoint_precision_t timepoint;     ///< [Optional] Whether times are exact.
} stop_time_t;


/**
 * Parses the stop_type_t value from given string
 * with regard for the default value as per GTFS reference.
 *
 * @param[in]    value    Char array (string) to parse the enumerator from.
 *
 * @returns      An stop_type_t value.
 *
 * @ingroup      Core__EntityEnums Core__EntityList__StopTime
 */
stop_type_t parse_stop_type(const char *value);

/**
 * Parses the timepoint_precision_t value from given string
 * with regard for the default value as per GTFS reference.
 *
 * @param[in]    value    Char array (string) to parse the enumerator from.
 *
 * @returns      An timepoint_precision_t value.
 *
 * @ingroup      Core__EntityEnums Core__EntityList__StopTime
 */
timepoint_precision_t parse_timepoint_precision(const char *value);

/**
 * Initializes the given stop time record with empty/default values.
 *
 * @param[out]    record    Stop time record pointer to initialize.
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__StopTime
 */
void init_stop_time(stop_time_t *record);

/**
 * Reads given datafields and field names into the given stop time struct.
 *
 * @param[out]    record          The pointer to write into.
 * @param[in]     field_count     Number of rows (columns) the record has.
 * @param[in]     field_names     Names of the fields.
 * @param[in]     field_values    Contents of the record.
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__StopTime
 */
void read_stop_time(stop_time_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 *
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 *
 * @returns      0 if structures are equal, non-zero otherwise.
 *
 * @ingroup      Core__EntityFunctions Core__EntityList__StopTime
 */
int equal_stop_time(const stop_time_t *a, const stop_time_t *b);

#endif
