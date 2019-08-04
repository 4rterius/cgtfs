#ifndef CGTFS_TESTS_RECORDS_CALENDAR_RECORDS_C
#define CGTFS_TESTS_RECORDS_CALENDAR_RECORDS_C

#include "greatest/greatest.h"
#include "records/calendar.h"

TEST calendar_record_read(void) {

    #define FIELDS_NUM_3 10
    char *field_names[FIELDS_NUM_3] = {
        "service_id", "monday", "tuesday", "wednesday", "thursday",
        "friday", "saturday", "sunday", "start_date", "end_date"
    };
    char *field_values[FIELDS_NUM_3] = {
        "1001", "1", "1", "1", "1", "1", "0", "0", "20000101", "20201231"
    };

    calendar_record_t cr_1;
    read_calendar_record(&cr_1, FIELDS_NUM_3, (const char **)field_names, (const char **)field_values);

    ASSERT_STR_EQ("1001", cr_1.service_id);
    ASSERT_STR_EQ("20000101", cr_1.start_date);
    ASSERT_STR_EQ("20201231", cr_1.end_date);
    ASSERT_EQ(SA_AVAILABLE, cr_1.monday);
    ASSERT_EQ(SA_AVAILABLE, cr_1.tuesday);
    ASSERT_EQ(SA_AVAILABLE, cr_1.wednesday);
    ASSERT_EQ(SA_AVAILABLE, cr_1.thursday);
    ASSERT_EQ(SA_AVAILABLE, cr_1.friday);
    ASSERT_EQ(SA_UNAVAILABLE, cr_1.saturday);
    ASSERT_EQ(SA_UNAVAILABLE, cr_1.sunday);

    PASS();
}

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

    ASSERT_EQ(1, equal_calendar_record(&a, &b));
    ASSERT_EQ(0, equal_calendar_record(&a, &c));
    ASSERT_EQ(0, equal_calendar_record(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordCalendarRecord) {
    RUN_TEST(calendar_record_read);
    RUN_TEST(calendar_record_compare);
}

#endif