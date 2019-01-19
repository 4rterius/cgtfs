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

    ASSERT_EQ(0, equal_calendar_record(&a, &b));
    ASSERT_EQ(1, equal_calendar_record(&a, &c));
    ASSERT_EQ(1, equal_calendar_record(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordCalendarRecord) {
    RUN_TEST(calendar_record_compare);
}

#endif