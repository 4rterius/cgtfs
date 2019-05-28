#ifndef CGTFS_TESTS_DATABASE_RECORDS_CALENDAR_C
#define CGTFS_TESTS_DATABASE_RECORDS_CALENDAR_C

#include "greatest/greatest.h"
#include "database/records/calendar.h"

TEST db_calendar_record_store(void) {
    feed_db_t db;
    feed_db_status_t res;

    calendar_record_t record = {
        .service_id = "FULLW",
        .monday = SA_AVAILABLE,
        .tuesday = SA_AVAILABLE,
        .wednesday = SA_AVAILABLE,
        .thursday = SA_AVAILABLE,
        .friday = SA_AVAILABLE,
        .saturday = SA_AVAILABLE,
        .sunday = SA_AVAILABLE,
        .start_date = "20070101",
        .end_date = "20101231"
    };

    init_feed_db(&db, "tests_tdw0.db", 1);
    setup_feed_db(&db, 1);

    res = store_calendar_record_db(&record, &db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    free_feed_db(&db);

    PASS();
}

SUITE(CGTFS_DatabaseCalendarRecords) {
    RUN_TEST(db_calendar_record_store);
}


#endif