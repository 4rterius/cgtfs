#ifndef CGTFS_TESTS_DATABASE_RECORDS_CALENDAR_DATES_C
#define CGTFS_TESTS_DATABASE_RECORDS_CALENDAR_DATES_C

#include "greatest/greatest.h"
#include "database/records/calendar_dates.h"

TEST db_calendar_dates_store(void) {
    feed_db_t db;
    feed_db_status_t res;

    calendar_date_t record = {
        .service_id = "FULLW",
        .date = "20070604",
        .exception_type = ET_REMOVED
    };

    init_feed_db(&db, "tests_tdw0.db", 1);
    setup_feed_db(&db);

    res = store_calendar_dates_db(&record, &db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    free_feed_db(&db);

    PASS();
}

SUITE(CGTFS_DatabaseCalendarDates) {
    RUN_TEST(db_calendar_dates_store);
}


#endif