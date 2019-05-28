#ifndef CGTFS_TESTS_DATABASE_RECORDS_FREQUENCY_C
#define CGTFS_TESTS_DATABASE_RECORDS_FREQUENCY_C

#include "greatest/greatest.h"
#include "database/records/frequency.h"

TEST db_frequency_store(void) {
    feed_db_t db;
    feed_db_status_t res;

    frequency_t record = {
        .trip_id = "TRIPIDVAL",
        .start_time = "10:05:00",
        .end_time = "10:15:00",
        .headway_secs = 1200,
        .exact_times = TE_EXACT
    };

    init_feed_db(&db, "tests_tdw0.db", 1);
    setup_feed_db(&db, 1);

    res = store_frequency_db(&record, &db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    free_feed_db(&db);

    PASS();
}

SUITE(CGTFS_DatabaseFrequency) {
    RUN_TEST(db_frequency_store);
}


#endif