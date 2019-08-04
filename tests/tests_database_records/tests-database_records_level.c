#ifndef CGTFS_TESTS_DATABASE_RECORDS_LEVEL_C
#define CGTFS_TESTS_DATABASE_RECORDS_LEVEL_C

#include "greatest/greatest.h"
#include "database/records/level.h"

TEST db_level_store(void) {
    feed_db_t db;
    feed_db_status_t res;

    level_t record = {
        .id = "SOMEID123",
        .name = "a b c d e f",
        .index = -123.9
    };

    if (FEED_DB_SUCCESS != init_feed_db(&db, "tests_tdw0.db", 1))
        FAILm(db.error_msg);

    setup_feed_db(&db);

    res = store_level_db(&record, &db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");


    if (FEED_DB_SUCCESS != free_feed_db(&db))
        FAILm("Failed to free a feed_db_t instance");

    PASS();
}

SUITE(CGTFS_DatabaseLevel) {
    RUN_TEST(db_level_store);
}


#endif