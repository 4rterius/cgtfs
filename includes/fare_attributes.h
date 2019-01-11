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

typedef struct {
    char fare_id[65];
    double price;
    char currency_type[4];
    payment_method_t payment_method;
    transfers_state_t transfers;
    char agency_id[65];
    double transfer_duration;
    int is_null;
} fare_attributes_t;


payment_method_t parse_payment_method(const char *value);
transfers_state_t parse_transfer_state(const char *value);

void init_fare_attributes(fare_attributes_t *record);
void read_fare_attributes(fare_attributes_t *record, int field_count, const char **field_names, const char **field_values);

#endif
