#ifndef CGTFS_TESTS_DATABASE_RECORDS_ROUTE_C
#define CGTFS_TESTS_DATABASE_RECORDS_ROUTE_C

#include "greatest/greatest.h"
#include "database/records/route.h"

TEST db_route_store(void) {
    feed_db_t db;
    feed_db_status_t res;

    route_t record = {
        .id = "263",
        .agency_id = "Pocono Pony",
        .short_name = "203",
        .long_name = "Violet",
        .desc = "(none)",
        .type = RT_BUS,
        .url = "http://ponytracker.availtec.com/InfoPoint/203",
        .color = "BA55D3",
        .text_color = "FFFFFF",
        .sort_order = 6
    };

    init_feed_db(&db, "tests_tdw0.db", 1);
    setup_feed_db(&db, 1);

    res = store_route_db(&record, &db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    free_feed_db(&db);

    PASS();
}

SUITE(CGTFS_DatabaseRoute) {
    RUN_TEST(db_route_store);
}


#endif