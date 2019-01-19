#ifndef CGTFS_TESTS_RECORDS_CALENDAR_DATES_C
#define CGTFS_TESTS_RECORDS_CALENDAR_DATES_C

#include "greatest/greatest.h"
#include "records/calendar_dates.h"

TEST calendar_date_read(void) {

    #define FIELDS_NUM 3
    char *field_names[FIELDS_NUM] = {
        "service_id", "date", "exception_type"
    };
    char *field_values[FIELDS_NUM] = {
        "1000", "20000101", "2"
    };

    calendar_date_t cd_1;
    read_calendar_date(&cd_1, FIELDS_NUM, (const char **)field_names, (const char **)field_values);

    ASSERT_STR_EQ("1000", cd_1.service_id);
    ASSERT_STR_EQ("20000101", cd_1.date);
    ASSERT_EQ(ET_REMOVED, cd_1.exception_type);

    PASS();
}

TEST calendar_date_compare(void) {
    calendar_date_t a = {
        .service_id = "SOME_ID1",
        .date = "01012019",
        .exception_type = ET_ADDED
    };

    calendar_date_t b = {
        .service_id = "SOME_ID1",
        .date = "01012019",
        .exception_type = ET_ADDED
    };

    calendar_date_t c = {
        .service_id = "SOME_ID2",
        .date = "01012019",
        .exception_type = ET_REMOVED
    };

    ASSERT_EQ(0, equal_calendar_date(&a, &b));
    ASSERT_EQ(1, equal_calendar_date(&a, &c));
    ASSERT_EQ(1, equal_calendar_date(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordCalendarDate) {
    RUN_TEST(calendar_date_read);
    RUN_TEST(calendar_date_compare);
}

#endif