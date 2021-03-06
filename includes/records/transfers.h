/**
 * @file
 * @brief    Transfer entity handling functionality.
 */

#ifndef CGTFS_TRANSFERS_H
#define CGTFS_TRANSFERS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "xstrlengths.h"


/**
 * Whether a transfer between two stops is possible and how.
 *
 * @ingroup    Core__EntityEnums Core__EntityList__Transfer
 */
typedef enum {
    TT_RECOMMENDED = 0,    ///< This is a recommended transfer point between routes (also on empty field value).
    TT_TIMED = 1,          ///< Departing vehicle waits for the arriving one, with enough time for a passenger to transfer.
    TT_TIME_REQUIRED = 2,  ///< This transfer requires a minimum amount of time between arrival and departure to ensure a connection.
    TT_NOT_POSSIBLE = 3,   ///< Transfers are not possible between the specified stops.
    TT_NOT_SET
} transfer_type_t;

/**
 * transfers.txt record
 *
 * @see        init_transfer()
 * @see        read_transfer()
 * @see        https://developers.google.com/transit/gtfs/reference/#transferstxt
 *
 * @ingroup    Core__EntityTypes Core__EntityList__Transfer
 */
typedef struct {
    char from_stop_id[CGTFS_SL_IDS];   ///< [Required] Unique ID that identifies a stop where connection between routes starts.
    char to_stop_id[CGTFS_SL_IDS];     ///< [Required] Unique ID that identifies a stop where connection between routes ends.
    transfer_type_t transfer_type;     ///< [Required] Whether and how the transfer is possible.
    unsigned int min_transfer_time;    ///< [Optional] Amount of time needed to transfer between routes at these stops (if possible).
} transfer_t;

/**
 * Parses the transfer_type_t value from given string
 * with regard for the default value as per GTFS reference.
 *
 * @param[in]    value    Char array (string) to parse the enumerator from.
 *
 * @returns      An transfer_type_t value.
 *
 * @ingroup      Core__EntityEnums Core__EntityList__Transfer
 */
transfer_type_t parse_transfer_type(const char *value);

/**
 * Initializes the given transfer record with empty/default values.
 *
 * @param[out]    record    Transfer record pointer to initialize.
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__Transfer
 */
void init_transfer(transfer_t *record);

/**
 * Reads given datafields and field names into the given transfer struct.
 *
 * @param[out]    record          The pointer to write into.
 * @param[in]     field_count     Number of rows (columns) the record has.
 * @param[in]     field_names     Names of the fields.
 * @param[in]     field_values    Contents of the record.
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__Transfer
 */
void read_transfer(transfer_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 *
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 *
 * @returns      0 if the structures differ and 1 otherwise
 *
 * @ingroup      Core__EntityFunctions Core__EntityList__Transfer
 */
int equal_transfer(const transfer_t *a, const transfer_t *b);

#endif
