#ifndef CGTFS_TESTS_DATABASE_RECORDS_FARE_ATTRIBUTES_C
#define CGTFS_TESTS_DATABASE_RECORDS_FARE_ATTRIBUTES_C

#include "greatest/greatest.h"
#include "database/records/fare_attributes.h"

TEST db_fare_attributes_store(void) {
    feed_db_t db;
    feed_db_status_t res;

    fare_attributes_t record = {
        .fare_id = "p",
        .price = 1.25,
        .currency_type = "USD",
        .payment_method = PM_ON_BOARD,
        .transfers = TS_NOT_ALLOWED
    };

    init_feed_db(&db, "tests_tdw0.db", 1);
    setup_feed_db(&db);

    res = store_fare_attributes_db(&record, &db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    free_feed_db(&db);

    PASS();
}

SUITE(CGTFS_DatabaseFareAttributes) {
    RUN_TEST(db_fare_attributes_store);
}


#endif