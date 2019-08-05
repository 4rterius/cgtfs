/**
 * @file
 * @brief    Calendar record entity handling functionality.
 */

#ifndef CGTFS_CALENDAR_H
#define CGTFS_CALENDAR_H

#include <stdio.h>
#include <string.h>

#include "xstrlengths.h"


/**
 * Whether service is available on a given day.
 *
 * @ingroup    Core__EntityEnums Core__EntityList__CalendarRecord
 */
typedef enum {
    SA_UNAVAILABLE = 0,  ///< Service is unavailable.
    SA_AVAILABLE = 1,    ///< Service is available.
    SA_NOT_SET
} service_availability_t;

/**
 * calendar.txt record
 *
 * @see        init_calendar_record()
 * @see        read_calendar_record()
 * @see        https://developers.google.com/transit/gtfs/reference/#calendartxt
 *
 * @ingroup    Core__EntityTypes Core__EntityList__CalendarRecord
 */
typedef struct {
    char service_id[CGTFS_SL_IDS];     ///< [Required] Unique ID that identifies a set of dates when the service is available with these params
    service_availability_t monday;     ///< [Required] Whether the service is available on Mondays
    service_availability_t tuesday;    ///< [Required] Whether the service is available on Tuesdays
    service_availability_t wednesday;  ///< [Required] Whether the service is available on Wednesdays
    service_availability_t thursday;   ///< [Required] Whether the service is available on Thursdays
    service_availability_t friday;     ///< [Required] Whether the service is available on Fridays
    service_availability_t saturday;   ///< [Required] Whether the service is available on Saturdays
    service_availability_t sunday;     ///< [Required] Whether the service is available on Sundays
    char start_date[CGTFS_SL_DAT];     ///< [Required] The YYYYMMDD date when the service starts
    char end_date[CGTFS_SL_DAT];       ///< [Required] The YYYYMMDD date when the service ends
} calendar_record_t;


/**
 * Parses the service_availability_t value from given string
 * with regard for the default value as per GTFS reference.
 *
 * @param[in]    value    Char array (string) to parse the enumerator from.
 *
 * @returns      An service_availability_t value;
 *
 * @ingroup      Core__EntityEnums Core__EntityList__CalendarRecord
 */
service_availability_t parse_service_availability(const char *value);

/**
 * Initializes the given calendar record with empty/default values.
 *
 * @param[out]    record    Calendar pointer to initialize.
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__CalendarRecord
 */
void init_calendar_record(calendar_record_t *record);

/**
 * Reads given datafields and field names into the given calendar record struct
 *
 * @param[out]    record          The pointer to write into
 * @param[in]     field_count     Number of rows (columns) the record has
 * @param[in]     field_names     Names of the fields
 * @param[in]     field_values    Contents of the record
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__CalendarRecord
 */
void read_calendar_record(calendar_record_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 *
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 *
 * @returns      0 if structures are equal, non-zero otherwise.
 *
 * @ingroup      Core__EntityFunctions Core__EntityList__CalendarRecord
 */
int equal_calendar_record(const calendar_record_t *a, const calendar_record_t *b);

#endif
