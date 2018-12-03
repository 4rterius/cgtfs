#ifndef CGTFS_TESTS_MAKE_FUNCTIONS_C
#define CGTFS_TESTS_MAKE_FUNCTIONS_C

#include "agency.h"
#include "calendar_dates.h"

int test_mf_agency(void) {
    // Case 1
    {
        #define FIELDS_NUM_1 8
        char *field_names[FIELDS_NUM_1] = {
            "agency_id", "agency_name", "agency_url", "agency_timezone",
            "agency_lang", "agency_phone", "agency_fare_url", "agency_email"
        };
        char *field_values[FIELDS_NUM_1] = {
            "1", "blahblah", "http://example.com/", "Europe/Moscow",
            "en", "0 000 000 00 00", "http://cash.me/outside", "ex@amp.le"
        };

        agency_t a_1 = make_agency(FIELDS_NUM_1, field_names, field_values);

        if (!(
            !strcmp(a_1.id, "1") &&
            !strcmp(a_1.name, "blahblah") &&
            !strcmp(a_1.url, "http://example.com/") &&
            !strcmp(a_1.timezone, "Europe/Moscow") &&
            !strcmp(a_1.lang, "en") &&
            !strcmp(a_1.phone, "0 000 000 00 00") &&
            !strcmp(a_1.fare_url, "http://cash.me/outside") &&
            !strcmp(a_1.email, "ex@amp.le")
        )) {
            printf("Parsed agency 1 incorrectly!");
        }

    }

    return 0;
}

int test_mf_calendar_dates(void) {
    // Case 1
    {
        #define FIELDS_NUM_2 3
        char *field_names[FIELDS_NUM_2] = {
            "service_id", "date", "exception_type"
        };
        char *field_values[FIELDS_NUM_2] = {
            "1000", "20000101", "2"
        };

        calendar_date_t cd_1 = make_calendar_date(FIELDS_NUM_2, field_names, field_values);
        
        if (!(
            !strcmp(cd_1.service_id, "1000") &&
            !strcmp(cd_1.date, "20000101") &&
            cd_1.exception_type == ET_REMOVED
        )) {
            printf("Parsed calendar date 1 incorrectly!");
        }
    }

    return 0;
}

#endif