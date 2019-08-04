#ifndef CGTFS_TESTS_DATABASE_RECORDS_TRIP_C
#define CGTFS_TESTS_DATABASE_RECORDS_TRIP_C

#include "greatest/greatest.h"
#include "database/records/trip.h"

TEST db_trip_store(void) {
    feed_db_t db;
    feed_db_status_t res;

    trip_t record = {
        .route_id = "245",
        .service_id = "12",
        .id = "t254-sl12-pAF-r120",
        .headsign = "Eagle Valley",
        .short_name = "lOrEM IpsuM",
        .direction_id = 1,
        .block_id = "1012",
        .shape_id = "175_shp",
        .wheelchair_accessible = WA_POSSIBLE,
        .bikes_allowed = BA_POSSIBLE
    };

    init_feed_db(&db, "tests_tdw0.db", 1);
    setup_feed_db(&db);

    res = store_trip_db(&record, &db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    free_feed_db(&db);

    PASS();
}

SUITE(CGTFS_DatabaseTrip) {
    RUN_TEST(db_trip_store);
}


#endif