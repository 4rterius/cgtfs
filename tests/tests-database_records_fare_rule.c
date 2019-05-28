#ifndef CGTFS_TESTS_DATABASE_RECORDS_FARE_RULE_C
#define CGTFS_TESTS_DATABASE_RECORDS_FARE_RULE_C

#include "greatest/greatest.h"
#include "database/records/fare_rule.h"

TEST db_fare_rule_store(void) {
    feed_db_t db;
    feed_db_status_t res;

    fare_rule_t record = {
        .fare_id = "p",
        .route_id = "STBA",
        .origin_id = "ID01",
        .destination_id = "ID09",
        .contains_id = "ID05"
    };

    init_feed_db(&db, "tests_tdw0.db", 1);
    setup_feed_db(&db, 1);

    res = store_fare_rule_db(&record, &db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    free_feed_db(&db);

    PASS();
}

SUITE(CGTFS_DatabaseFareFule) {
    RUN_TEST(db_fare_rule_store);
}


#endif