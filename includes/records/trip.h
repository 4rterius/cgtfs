/**
 * @file
 * @brief    Trip entity handling functionality.
 */

#ifndef CGTFS_TRIP_H
#define CGTFS_TRIP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * Whether it is possible to access a trip using wheelchairs.
 * 
 * @ingroup    Core__EntityEnums
 */
typedef enum {
    WA_UNKNOWN = 0,
    WA_POSSIBLE = 1,
    WA_NOT_POSSIBLE = 2,
    WA_NOT_SET
} wheelchair_accessible_t;

/**
 * Whether bikes are allowed on a trip.
 * 
 * @ingroup    Core__EntityEnums
 */
typedef enum {
    BA_UNKNOWN = 0,
    BA_POSSIBLE = 1,
    BA_NOT_POSSIBLE = 2,
    BA_NOT_SET
} bikes_allowed_t;

/**
 * trips.txt record
 * 
 * @see        init_trip()
 * @see        read_trip()
 * @see        https://developers.google.com/transit/gtfs/reference/#tripstxt
 * 
 * @ingroup    Core__EntityTypes
 */
typedef struct {
    char route_id[65];                              ///< Unique ID that identifies the route of the trip.
    char service_id[65];                            ///< Unique ID that identifies a set of dates when the service is available.
    char id[65];                                    ///< Unique ID that identifies the trip.
    char headsign[65];                              ///< Text that appears to the passangers to identify the trip's destination.
    char short_name[65];                            ///< Text that appears to the passangers to identify the trip.
    unsigned int direction_id;                      ///< Binary value that indicates the direction of travel of this trip.
    char block_id[65];                              ///< Unique ID that identifies the block to which the trip belongs.
    char shape_id[65];                              ///< Unique ID that identifies the shape for the trip.
    wheelchair_accessible_t wheelchair_accessible;  ///< Whether the vehicle used on the trip can accommodate a rider in a wheelchair.
    bikes_allowed_t bikes_allowed;                  ///< Whether the vehicle used on the trip can accommodate a bicycle.
    int is_null;
} trip_t;

/**
 * Parses the wheelchair_accessible_t value from given string
 * with regard for the default value as per GTFS reference.
 * 
 * @param[in]    value    Char array (string) to parse the enumerator from.
 * 
 * @returns      An wheelchair_accessible_t value.
 * 
 * @ingroup      Core__EntityEnums
 */
wheelchair_accessible_t parse_wheelchair_accessibility(const char *value);

/**
 * Parses the bikes_allowed_t value from given string
 * with regard for the default value as per GTFS reference.
 * 
 * @param[in]    value    Char array (string) to parse the enumerator from.
 * 
 * @returns      An bikes_allowed_t value.
 * 
 * @ingroup      Core__EntityEnums
 */
bikes_allowed_t parse_bike_allowance(const char *value);

/**
 * Initializes the given trip record with empty/default values.
 * 
 * @param[out]    record    Trip record pointer to initialize.
 * 
 * @ingroup       Core__EntityFunctions
 */
void init_trip(trip_t *record);

/**
 * Reads given datafields and field names into the given trip struct.
 * 
 * @param[out]    record          The pointer to write into.
 * @param[in]     field_count     Number of rows (columns) the record has.
 * @param[in]     field_names     Names of the fields.
 * @param[in]     field_values    Contents of the record.
 * 
 * @ingroup       Core__EntityFunctions
 */
void read_trip(trip_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 * 
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 * 
 * @returns      0 if structures are equal, non-zero otherwise.
 * 
 * @ingroup      Core__EntityFunctions
 */
int equal_trip(const trip_t *a, const trip_t *b);

#endif
