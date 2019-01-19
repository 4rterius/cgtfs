#ifndef CGTFS_TESTS_RECORDS_FARE_ATTRIBUTES_C
#define CGTFS_TESTS_RECORDS_FARE_ATTRIBUTES_C

#include "greatest/greatest.h"
#include "records/fare_attributes.h"

TEST fare_attributes_compare(void) {
    fare_attributes_t a = {
        .fare_id = "SOME_ID1",
        .currency_type = "EUR",
        .price = 10.0,
        .payment_method = PM_NOT_SET,
        .transfers = TS_UNLIMITED,
        .transfer_duration = 60.0
    };

    fare_attributes_t b = {
        .fare_id = "SOME_ID1",
        .currency_type = "EUR",
        .price = 10.0,
        .payment_method = PM_NOT_SET,
        .transfers = TS_UNLIMITED,
        .transfer_duration = 60.0
    };

    fare_attributes_t c = {
        .fare_id = "SOME_ID1",
        .currency_type = "EUR",
        .agency_id = "ANOTHER_ID",
        .price = 9.0,
        .payment_method = PM_NOT_SET,
        .transfers = TS_UNLIMITED,
        .transfer_duration = 60.0
    };

    ASSERT_EQ(0, equal_fare_attributes(&a, &b));
    ASSERT_EQ(1, equal_fare_attributes(&a, &c));
    ASSERT_EQ(1, equal_fare_attributes(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordFareAttributes) {
    RUN_TEST(fare_attributes_compare);
}

#endif