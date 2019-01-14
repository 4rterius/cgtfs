#ifndef CGTFS_STOP_TIME_H
#define CGTFS_STOP_TIME_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * Whether passangers are picked up / dropped off at the stop
 * normally, never, or only on special arrangements.
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
 */
typedef enum {
    TP_APPROXIMATE = 0,  ///< Approximate (default behavior; when the field is empty).
    TP_EXACT = 1,        ///< Exact.
    TP_NOT_SET
} timepoint_precision_t;

/**
 * stop_times.txt record
 * @see init_stop_time()
 * @see read_stop_time()
 * @see https://developers.google.com/transit/gtfs/reference/#stop_timestxt
 */
typedef struct {
    char trip_id[65];                 ///< [Required] Unique ID that identifies the trip.
    char arrival_time[9];             ///< [Required] Time (HH:MM:SS) when a vehicle arrives to the stop for a particular trip.
    char departure_time[9];           ///< [Required] Time (HH:MM:SS) when a vehicle departs from the stop for a particular trip.
    char stop_id[65];                 ///< [Required] Unique ID that identifies the stop.
    unsigned int stop_sequence;       ///< [Required] Number that identifies the order of stops for a trip.
    char stop_headsign[65];           ///< [Optional] Text that appears to the passangers to identify the trip's destination.
    stop_type_t pickup_type;          ///< [Optional] Whether and how are passangers picked up.
    stop_type_t dropoff_type;         ///< [Optional] Whether and how are passangers dropped off.
    double shape_dist_traveled;       ///< [Optional] How much distance the vehicle traveled up to the stop.
    timepoint_precision_t timepoint;  ///< [Optional] Whether times are exact.
    int is_null;
} stop_time_t;


/**
 * Parses the stop_type_t value from given string
 * with regard for the default value as per GTFS reference.
 * @param[in] value Char array (string) to parse the enumerator from.
 * @returns An stop_type_t value;
 */
stop_type_t parse_stop_type(const char *value);

/**
 * Parses the timepoint_precision_t value from given string
 * with regard for the default value as per GTFS reference.
 * @param[in] value Char array (string) to parse the enumerator from.
 * @returns An timepoint_precision_t value;
 */
timepoint_precision_t parse_timepoint_precision(const char *value);

/**
 * Initializes the given stop time record with empty/default values.
 * @param[out] record Stop time record pointer to initialize.
 */
void init_stop_time(stop_time_t *record);

/**
 * Reads given datafields and field names into the given stop time struct.
 * @param[out] record        The pointer to write into.
 * @param[in]  field_count   Number of rows (columns) the record has.
 * @param[in]  field_names   Names of the fields.
 * @param[in]  field_values  Contents of the record.
 */
void read_stop_time(stop_time_t *record, int field_count, const char **field_names, const char **field_values);

#endif
