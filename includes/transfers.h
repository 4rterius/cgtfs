#ifndef CGTFS_TRANSFERS_H
#define CGTFS_TRANSFERS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum {
    TT_RECOMMENDED = 0,
    TT_TIMED = 1,
    TT_TIME_REQUIRED = 2,
    TT_NOT_POSSIBLE = 3,
    TT_NOT_SET
} transfer_type_t;

/**
 * transfers.txt record
 * @see init_transfer()
 * @see read_transfer()
 * @see https://developers.google.com/transit/gtfs/reference/#transferstxt
 */
typedef struct {
    char from_stop_id[65];           ///< [Required] Unique ID that identifies a stop where connection between routes starts.
    char to_stop_id[65];             ///< [Required] Unique ID that identifies a stop where connection between routes ends.
    transfer_type_t transfer_type;   ///< [Required] Whether and how the transfer is possible.
    unsigned int min_transfer_time;  ///< [Optional] Amount of time needed to transfer between routes at these stops (if possible).
    int is_null;
} transfer_t;

transfer_type_t parse_transfer_type(const char *value);

/**
 * Initializes the given transfer record with empty/default values.
 * @param[out] record Transfer record pointer to initialize.
 */
void init_transfer(transfer_t *record);

/**
 * Reads given datafields and field names into the given transfer struct.
 * @param[out] record        The pointer to write into.
 * @param[in]  field_count   Number of rows (columns) the record has.
 * @param[in]  field_names   Names of the fields.
 * @param[in]  field_values  Contents of the record.
 */
void read_transfer(transfer_t *record, int field_count, const char **field_names, const char **field_values);

#endif
