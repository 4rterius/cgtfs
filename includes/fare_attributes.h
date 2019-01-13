#ifndef CGTFS_FARE_ATTRIBUTES_H
#define CGTFS_FARE_ATTRIBUTES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum {
    PM_ON_BOARD = 0,
    PM_BEFOREHAND = 1,
    PM_NOT_SET
} payment_method_t;

typedef enum {
    TS_NOT_ALLOWED = 0,
    TS_ONCE = 1,
    TS_TWICE = 2,
    TS_UNLIMITED,  // when the field is empty
    TS_NOT_SET     // when the field has bad value (not in {0, 1, 2, empty})
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


payment_method_t parse_payment_method(const char *value);
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
