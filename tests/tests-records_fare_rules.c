#ifndef CGTFS_TESTS_RECORDS_FARE_RULES_C
#define CGTFS_TESTS_RECORDS_FARE_RULES_C

#include "greatest/greatest.h"
#include "records/fare_rule.h"

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

    ASSERT_EQ(equal_fare_rule(&a, &b), 0);
    ASSERT_EQ(equal_fare_rule(&a, &c), 1);
    ASSERT_EQ(equal_fare_rule(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordFareRule) {
    RUN_TEST(fare_rule_compare);
}

#endif