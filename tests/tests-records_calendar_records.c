#ifndef CGTFS_TESTS_RECORDS_CALENDAR_RECORDS_C
#define CGTFS_TESTS_RECORDS_CALENDAR_RECORDS_C

#include "greatest/greatest.h"
#include "records/calendar.h"

TEST calendar_record_compare(void) {
    calendar_record_t a = {
        .service_id = "SOME_ID1",
        .start_date = "01012019",
        .end_date = "",
        .monday = SA_AVAILABLE,
        .tuesday = SA_AVAILABLE,
        .wednesday = SA_UNAVAILABLE,
        .thursday = SA_AVAILABLE,
        .friday = SA_NOT_SET,
        .saturday = SA_UNAVAILABLE,
        .sunday = SA_AVAILABLE
    };

    calendar_record_t b = {
        .service_id = "SOME_ID1",
        .start_date = "01012019",
        .end_date = "",
        .monday = SA_AVAILABLE,
        .tuesday = SA_AVAILABLE,
        .wednesday = SA_UNAVAILABLE,
        .thursday = SA_AVAILABLE,
        .friday = SA_NOT_SET,
        .saturday = SA_UNAVAILABLE,
        .sunday = SA_AVAILABLE
    };

    calendar_record_t c = {
        .service_id = "SOME_ID1",
        .start_date = "01012019",
        .end_date = "aa",
        .monday = SA_AVAILABLE,
        .tuesday = SA_AVAILABLE,
        .wednesday = SA_UNAVAILABLE,
        .thursday = SA_AVAILABLE,
        .friday = SA_NOT_SET,
        .saturday = SA_UNAVAILABLE,
        .sunday = SA_AVAILABLE
    };

    ASSERT_EQ(equal_calendar_record(&a, &b), 0);
    ASSERT_EQ(equal_calendar_record(&a, &c), 1);
    ASSERT_EQ(equal_calendar_record(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordCalendarRecord) {
    RUN_TEST(calendar_record_compare);
}

#endif