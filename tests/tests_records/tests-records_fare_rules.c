#ifndef CGTFS_TESTS_RECORDS_FARE_RULES_C
#define CGTFS_TESTS_RECORDS_FARE_RULES_C

#include "greatest/greatest.h"
#include "records/fare_rule.h"

TEST fare_rule_read(void) {

    #define FIELDS_NUM_5 5
    char *field_names[FIELDS_NUM_5] = {
        "fare_id", "route_id", "origin_id", "destination_id", "contains_id"
    };
    char *field_values[FIELDS_NUM_5] = {
        "b", "TSW", "2", "8", "6"
    };

    fare_rule_t fr_1;
    read_fare_rule(&fr_1, FIELDS_NUM_5, (const char **)field_names, (const char **)field_values);

    ASSERT_STR_EQ("b", fr_1.fare_id);
    ASSERT_STR_EQ("TSW", fr_1.route_id);
    ASSERT_STR_EQ("2", fr_1.origin_id);
    ASSERT_STR_EQ("8", fr_1.destination_id);
    ASSERT_STR_EQ("6", fr_1.contains_id);

    PASS();
}

TEST fare_rule_compare(void) {
    fare_rule_t a = {
        .fare_id = "SOME_ID1",
        .route_id = "SUM_ROUT",
        .origin_id = "BS1",
        .destination_id = "BS117",
        .contains_id = ""
    };

    fare_rule_t b = {
        .fare_id = "SOME_ID1",
        .route_id = "SUM_ROUT",
        .origin_id = "BS1",
        .destination_id = "BS117",
        .contains_id = ""
    };

    fare_rule_t c = {
        .fare_id = "SOME_ID2",
        .route_id = "SUM_ROUT",
        .origin_id = "BS1",
        .destination_id = "BS117",
        .contains_id = ""
    };

    ASSERT_EQ(0, equal_fare_rule(&a, &b));
    ASSERT_EQ(1, equal_fare_rule(&a, &c));
    ASSERT_EQ(1, equal_fare_rule(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordFareRule) {
    RUN_TEST(fare_rule_read);
    RUN_TEST(fare_rule_compare);
}

#endif