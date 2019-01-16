#ifndef CGTFS_TESTS_READING_C
#define CGTFS_TESTS_READING_C

#include "greatest/greatest.h"

#include "records/agency.h"
#include "records/calendar_dates.h"


// agency_t tests
// ----------------------------------------------------------------------

TEST agency_compare(void) {
    agency_t a = {
        .id = "SOME_ID1",
        .name = "amazing name",
        .url = "",
        .timezone = "dfghjkl244124 qwe",
        .lang = "fi",
        .phone = "000111222",
        .fare_url = "https://example.com",
        .email = "no-reply@example.com"
    };

    agency_t b = {
        .id = "SOME_ID1",
        .name = "amazing name",
        .url = "",
        .timezone = "dfghjkl244124 qwe",
        .lang = "fi",
        .phone = "000111222",
        .fare_url = "https://example.com",
        .email = "no-reply@example.com"
    };

    agency_t c = {
        .id = "SOME_ID0",
        .name = "amazing name",
        .url = " ",
        .timezone = "dfghjkl244124 qwe",
        .lang = "fi",
        .phone = "0001112223",
        .email = "no-reply@example.com"
    };

    ASSERT_EQ(equal_agency(&a, &b), 0);
    ASSERT_EQ(equal_agency(&a, &c), 1);
    ASSERT_EQ(equal_agency(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_ReadingAgency) {
    RUN_TEST(agency_compare);
}



// calendar_date_t tests
// ----------------------------------------------------------------------

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

    ASSERT_EQ(equal_calendar_date(&a, &b), 0);
    ASSERT_EQ(equal_calendar_date(&a, &c), 1);
    ASSERT_EQ(equal_calendar_date(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_ReadingCalendarDate) {
    RUN_TEST(calendar_date_compare);
}



// calendar_record_t tests
// ----------------------------------------------------------------------

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

SUITE(CGTFS_ReadingCalendarRecord) {
    RUN_TEST(calendar_record_compare);
}

#endif