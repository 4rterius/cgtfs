/**
 * @file
 * @brief    Frequency entity handling functionality.
 */

#ifndef CGTFS_FREQUENCY_H
#define CGTFS_FREQUENCY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * Whether timepoints are considered exact or approximate.
 */
typedef enum {
    TE_NOT_EXACT = 0,  ///< Approximate (default behavior; when the field is empty)
    TE_EXACT = 1,      ///< Exact
    TE_NOT_SET
} time_exactness_t;

/**
 * frequencies.txt record
 * @see init_frequency()
 * @see read_frequency()
 * @see https://developers.google.com/transit/gtfs/reference/#frequenciestxt
 */
typedef struct {
    char trip_id[65];              ///< [Required] A unique ID of the trip on which the frequency applies.
    char start_time[9];            ///< [Required] Time when the first vehicle departs from the first stop with the frequency.
    char end_time[9];              ///< [Required] Time when the service changes to a different frequency / ends.
    int headway_secs;              ///< [Required] Time between departures from the same stop.
    time_exactness_t exact_times;  ///< [Optional] Whether times are exact.
    int is_null;
} frequency_t;

/**
 * Parses the time_exactness_t value from given string
 * with regard for the default value as per GTFS reference.
 * @param[in] value Char array (string) to parse the enumerator from.
 * @returns An time_exactness_t value;
 */
time_exactness_t parse_time_exactness(const char *value);

/**
 * Initializes the given frequency record with empty/default values.
 * @param[out] record Frequency record pointer to initialize.
 */
void init_frequency(frequency_t *record);

/**
 * Reads given datafields and field names into the given frequency struct.
 * @param[out] record        The pointer to write into.
 * @param[in]  field_count   Number of rows (columns) the record has.
 * @param[in]  field_names   Names of the fields.
 * @param[in]  field_values  Contents of the record.
 */
void read_frequency(frequency_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 * @param[in] a  First structure
 * @param[in] b  Second structure
 * @returns 0 if structures are equal, non-zero otherwise.
 */
int equal_frequency(const frequency_t *a, const frequency_t *b);

#endif
