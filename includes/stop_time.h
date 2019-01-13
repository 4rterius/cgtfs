#ifndef CGTFS_STOP_TIME_H
#define CGTFS_STOP_TIME_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum {
    ST_REGULAR = 0,
    ST_NOT_AVAILABLE = 1,
    ST_CONTACT_AGENCY = 2,
    ST_CONTACT_DRIVER = 3,
    ST_NOT_SET
} stop_type_t;

typedef enum {
    TP_APPROXIMATE = 0,
    TP_EXACT = 1,
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

stop_type_t parse_stop_type(const char *value);
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
