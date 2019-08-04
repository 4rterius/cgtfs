#ifndef CGTFS_TESTS_DATABASE_RECORDS_SHAPE_C
#define CGTFS_TESTS_DATABASE_RECORDS_SHAPE_C

#include "greatest/greatest.h"
#include "database/records/shape.h"

TEST db_shape_store(void) {
    feed_db_t db;
    feed_db_status_t res;

    shape_t record = {
        .id = "some shape id",
        .pt_lat = 40.989400000000003,
        .pt_lon = -75.188280000000006,
        .pt_sequence = 123,
        .dist_traveled = 32861.371900999999
    };

    init_feed_db(&db, "tests_tdw0.db", 1);
    setup_feed_db(&db);

    res = store_shape_db(&record, &db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    free_feed_db(&db);

    PASS();
}

SUITE(CGTFS_DatabaseShape) {
    RUN_TEST(db_shape_store);
}


#endif