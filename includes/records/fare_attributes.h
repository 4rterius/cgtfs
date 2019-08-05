/**
 * @file
 * @brief    Fare attribute entity handling functionality.
 */

#ifndef CGTFS_FARE_ATTRIBUTES_H
#define CGTFS_FARE_ATTRIBUTES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "xstrlengths.h"


/**
 * When the fare must be paid by the customer.
 *
 * @ingroup    Core__EntityEnums Core__EntityList__FareAttributes
 */
typedef enum {
    PM_ON_BOARD = 0,    ///< Fare is paid on board.
    PM_BEFOREHAND = 1,  ///< Fare is paid before boarding.
    PM_NOT_SET
} payment_method_t;

/**
 * Number of transfers allowed on the fare.
 *
 * @ingroup    Core__EntityEnums Core__EntityList__FareAttributes
 */
typedef enum {
    TS_NOT_ALLOWED = 0,  ///< Zero
    TS_ONCE = 1,         ///< Once
    TS_TWICE = 2,        ///< Twice
    TS_UNLIMITED,        ///< As many as customer wishes (when the field is empty)
    TS_NOT_SET           // when the field has bad value (not in {0, 1, 2, (empty)})
} transfers_state_t;

/**
 * fare_attributes.txt record
 *
 * @see        init_fare_attributes()
 * @see        read_fare_attributes()
 * @see        https://developers.google.com/transit/gtfs/reference/#fare_attributestxt
 *
 * @ingroup    Core__EntityTypes Core__EntityList__FareAttributes
 */
typedef struct {
    char fare_id[CGTFS_SL_IDS];         ///< [Required] Unique ID that identifies the fare class.
    double price;                       ///< [Required] The fare price.
    char currency_type[CGTFS_SL_CUR];   ///< [Required] The currency in which the price is specified.
    payment_method_t payment_method;    ///< [Required] When the fare must be paid.
    transfers_state_t transfers;        ///< [Required] The number of transfers allowed on this fare.
    char agency_id[CGTFS_SL_IDS];       ///< [Optional] (If several agencies specified in the feed) The agency to which this fare applies.
    double transfer_duration;           ///< [Optional] The length in seconds of possible transfer OR how long a ticket is valid.
} fare_attributes_t;


/**
 * Parses the payment_method_t value from given string
 * with regard for the default value as per GTFS reference.
 *
 * @param[in]    value    Char array (string) to parse the enumerator from.
 *
 * @returns      An payment_method_t value;
 *
 * @ingroup      Core__EntityEnums Core__EntityList__FareAttributes
 */
payment_method_t parse_payment_method(const char *value);

/**
 * Parses the transfers_state_t value from given string
 * with regard for the default value as per GTFS reference.
 *
 * @param[in]    value    Char array (string) to parse the enumerator from.
 *
 * @returns      An transfers_state_t value;
 *
 * @ingroup      Core__EntityEnums Core__EntityList__FareAttributes
 */
transfers_state_t parse_transfer_state(const char *value);

/**
 * Initializes the given fare attributes record with empty/default values.
 *
 * @param[out]    record    Fare attributes record pointer to initialize.
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__FareAttributes
 */
void init_fare_attributes(fare_attributes_t *record);

/**
 * Reads given datafields and field names into the given fare attributes struct.
 *
 * @param[out]    record          The pointer to write into.
 * @param[in]     field_count     Number of rows (columns) the record has.
 * @param[in]     field_names     Names of the fields.
 * @param[in]     field_values    Contents of the record.
 *
 * @ingroup       Core__EntityFunctions Core__EntityList__FareAttributes
 */
void read_fare_attributes(fare_attributes_t *record, int field_count, const char **field_names, const char **field_values);

/**
 * Compares two structures.
 *
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 *
 * @returns      0 if structures are equal, non-zero otherwise.
 *
 * @ingroup      Core__EntityFunctions Core__EntityList__FareAttributes
 */
int equal_fare_attributes(const fare_attributes_t *a, const fare_attributes_t *b);

#endif
