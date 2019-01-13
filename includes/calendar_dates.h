#ifndef CGTFS_CALENDAR_DATES_H
#define CGTFS_CALENDAR_DATES_H

#include <stdio.h>
#include <string.h>


typedef enum {
    ET_ADDED = 1,
    ET_REMOVED = 2,
    ET_NOT_SET
} exception_type_t;

/**
 * calendar_dates.txt record
 * @see init_calendar_date()
 * @see read_calendar_date()
 * @see https://developers.google.com/transit/gtfs/reference/#calendar_datestxt
 */
typedef struct {
    char service_id[65];              ///< [Required] Unique ID that identifies a set of dates to which the exception applies
    char date[9];                     ///< [Required] The applicable date
    exception_type_t exception_type;  ///< [Required] Whether the service is available on the given date
    int is_null;
} calendar_date_t;


exception_type_t parse_exception_type(const char *value);

/**
 * Initializes the given calendar date record with empty/default values.
 * @param[out] record Calendar date pointer to initialize.
 */
void init_calendar_date(calendar_date_t *record);

/**
 * Reads given datafields and field names into the given calendar date record struct
 * @param[out] record        The pointer to write into
 * @param[in]  field_count   Number of rows (columns) the record has
 * @param[in]  field_names   Names of the fields
 * @param[in]  field_values  Contents of the record
 */
void read_calendar_date(calendar_date_t *record, int field_count, const char **field_names, const char **field_values);

#endif
