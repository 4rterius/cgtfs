#ifndef CGTFS_FARE_ATTRIBUTES_H
#define CGTFS_FARE_ATTRIBUTES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * When the fare must be paid by the customer.
 */
typedef enum {
    PM_ON_BOARD = 0,    ///< Fare is paid on board.
    PM_BEFOREHAND = 1,  ///< Fare is paid before boarding.
    PM_NOT_SET
} payment_method_t;

/**
 * Number of transfers allowed on the fare.
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
 * @see init_fare_attributes()
 * @see read_fare_attributes()
 * @see https://developers.google.com/transit/gtfs/reference/#fare_attributestxt
 */
typedef struct {
    char fare_id[65];                 ///< [Required] Unique ID that identifies the fare class.
    double price;                     ///< [Required] The fare price.
    char currency_type[4];            ///< [Required] The currency in which the price is specified.
    payment_method_t payment_method;  ///< [Required] When the fare must be paid.
    transfers_state_t transfers;      ///< [Required] The number of transfers allowed on this fare.
    char agency_id[65];               ///< [Optional] (If several agencies specified in the feed) The agency to which this fare applies.
    double transfer_duration;         ///< [Optional] The length in seconds of possible transfer OR how long a ticket is valid.
    int is_null;
} fare_attributes_t;


/**
 * Parses the payment_method_t value from given string
 * with regard for the default value as per GTFS reference.
 * @param[in] value Char array (string) to parse the enumerator from.
 * @returns An payment_method_t value;
 */
payment_method_t parse_payment_method(const char *value);

/**
 * Parses the transfers_state_t value from given string
 * with regard for the default value as per GTFS reference.
 * @param[in] value Char array (string) to parse the enumerator from.
 * @returns An transfers_state_t value;
 */
transfers_state_t parse_transfer_state(const char *value);

/**
 * Initializes the given fare attributes record with empty/default values.
 * @param[out] record Fare attributes record pointer to initialize.
 */
void init_fare_attributes(fare_attributes_t *record);

/**
 * Reads given datafields and field names into the given fare attributes struct.
 * @param[out] record        The pointer to write into.
 * @param[in]  field_count   Number of rows (columns) the record has.
 * @param[in]  field_names   Names of the fields.
 * @param[in]  field_values  Contents of the record.
 */
void read_fare_attributes(fare_attributes_t *record, int field_count, const char **field_names, const char **field_values);

#endif
