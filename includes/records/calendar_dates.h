/**
 * @file
 * @brief    Calendar date entity handling functionality.
 */

#ifndef CGTFS_CALENDAR_DATES_H
#define CGTFS_CALENDAR_DATES_H

#include <stdio.h>
#include <string.h>

#include "xstrlengths.h"


/**
 * What kind of exception does calendar_date_t present.
 *
 * @ingroup    Core__EntityEnums Core__EntityList__CalendarDate
 */
typedef enum {
    ET_ADDED = 1,    ///< Service is added.
    ET_REMOVED = 2,  ///< Service is removed.
    ET_NOT_SET
} exception_type_t;

/**
 * calendar_dates.txt record
 *
 * @see        init_calendar_date()
 * @see        read_calendar_date()
 * @see        https://developers.google.com/transit/gtfs/reference/#calendar_datestxt
 *
 * @ingroup    Core__EntityTypes Core__EntityList__CalendarDate
 */
typedef struct {
    char service_id[CGTFS_SL_IDS];     ///< [Required] Unique ID that identifies a set of dates to which the exception applies
    char date[CGTFS_SL_DAT];           ///< [Required] The applicable date
    exception_type_t exception_type;   ///< [Required] Whether the service is available on the given date
} calendar_date_t;


/**
 * Parses the exception_type_t value from given string
 * with regard for the default value as per GTFS reference.
 *
 * @param[in]    value    Char array (string) to parse the enumerator from.
 *
 * @returns      An exception_type_t value.
 *
 * @ingroup      Core__EntityEnums Core__EntityList__CalendarDate
 */
exception_type_t parse_exception_type(const char *value);

/**
 * Initializes the given calendar date record with empty/default values.
 *
 * @param[out]    record    Calendar date pointer to initialize.
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__CalendarDate
 */
void init_calendar_date(calendar_date_t *record);

/**
 * Reads given datafields and field names into the given calendar date record struct
 *
 * @param[out]    record          The pointer to write into
 * @param[in]     field_count     Number of rows (columns) the record has
 * @param[in]     field_names     Names of the fields
 * @param[in]     field_values    Contents of the record
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__CalendarDate
 */
void read_calendar_date(calendar_date_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 *
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 *
 * @returns      0 if the structures differ and 1 otherwise
 *
 * @ingroup      Core__EntityFunctions Core__EntityList__CalendarDate
 */
int equal_calendar_date(const calendar_date_t *a, const calendar_date_t *b);

#endif
