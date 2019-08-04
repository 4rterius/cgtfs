#ifndef CGTFS_TESTS_DATABASE_RECORDS_STOP_C
#define CGTFS_TESTS_DATABASE_RECORDS_STOP_C

#include "greatest/greatest.h"
#include "database/records/stop.h"

TEST db_stop_store(void) {
    feed_db_t db;
    feed_db_status_t res;

    stop_t record = {
        .id = "s0",
        .code = "stop_zero",
        .name = "Stop Zero",
        .desc = "pretty self-explanatory",
        .lat = 41.008738999999998,
        .lon = -75.476448000000005,
        .zone_id = "some_zone",
        .url = "https://example.com",
        .location_type = LT_STATION,
        .parent_station = "abcd",
        .timezone = "efgh",
        .wheelchair_boarding = WB_NOT_POSSIBLE,
        .level_id = "LVL01",
        .platform_code = "A"
    };

    init_feed_db(&db, "tests_tdw0.db", 1);
    setup_feed_db(&db, 1);

    res = store_stop_db(&record, &db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    free_feed_db(&db);

    PASS();
}

SUITE(CGTFS_DatabaseStop) {
    RUN_TEST(db_stop_store);
}


#endif