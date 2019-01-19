#ifndef CGTFS_TESTS_RECORDS_FARE_ATTRIBUTES_C
#define CGTFS_TESTS_RECORDS_FARE_ATTRIBUTES_C

#include "greatest/greatest.h"
#include "records/fare_attributes.h"

TEST fare_attributes_read(void) {

    #define FIELDS_NUM 7
    char *field_names[FIELDS_NUM] = {
        "fare_id", "price", "currency_type", "payment_method",
        "transfers", "agency_id", "transfer_duration"
    };
    char *field_values[FIELDS_NUM] = {
        "17", "2.85", "EUR", "0", "", "1", "6000"
    };

    fare_attributes_t fa_1;
    read_fare_attributes(&fa_1, FIELDS_NUM, (const char **)field_names, (const char **)field_values);

    ASSERT_STR_EQ("17", fa_1.fare_id);
    ASSERT_STR_EQ("EUR", fa_1.currency_type);
    ASSERT_STR_EQ("1", fa_1.agency_id);
    ASSERT_EQ(2.85, fa_1.price);
    ASSERT_EQ(PM_ON_BOARD, fa_1.payment_method);
    ASSERT_EQ(TS_UNLIMITED, fa_1.transfers);
    ASSERT_EQ(6000.0, fa_1.transfer_duration);

    PASS();
}

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
    RUN_TEST(fare_attributes_read);
    RUN_TEST(fare_attributes_compare);
}

#endif