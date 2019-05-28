#ifndef CGTFS_TESTS_DATABASE_RECORDS_STOP_TIME_C
#define CGTFS_TESTS_DATABASE_RECORDS_STOP_TIME_C

#include "greatest/greatest.h"
#include "database/records/stop_time.h"

TEST db_stop_time_store(void) {
    feed_db_t db;
    feed_db_status_t res;

    stop_time_t record = {
        .trip_id = "t13D-sl12-pB6-r120",
        .arrival_time = "06:06:15",
        .departure_time = "06:06:15",
        .stop_id = "209",
        .stop_sequence = 75,
        .stop_headsign = "SOMETHING",
        .pickup_type = ST_CONTACT_AGENCY,
        .dropoff_type = ST_CONTACT_DRIVER,
        .shape_dist_traveled = 7078.6209849999996,
        .timepoint = TP_EXACT
    };

    init_feed_db(&db, "tests_tdw0.db", 1);
    setup_feed_db(&db, 1);

    res = store_stop_time_db(&record, &db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    free_feed_db(&db);

    PASS();
}

SUITE(CGTFS_DatabaseStopTime) {
    RUN_TEST(db_stop_time_store);
}


#endif