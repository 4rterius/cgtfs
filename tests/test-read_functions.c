#ifndef CGTFS_TESTS_MAKE_FUNCTIONS_C
#define CGTFS_TESTS_MAKE_FUNCTIONS_C

#include "agency.h"
#include "calendar_dates.h"
#include "calendar.h"
#include "fare_attributes.h"
#include "fare_rule.h"
#include "feed_info.h"
#include "frequency.h"

int test_rf_agency(void) {
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

        agency_t a_1 = read_agency(FIELDS_NUM_1, field_names, field_values);

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

int test_rf_calendar_dates(void) {
    // Case 1
    {
        #define FIELDS_NUM_2 3
        char *field_names[FIELDS_NUM_2] = {
            "service_id", "date", "exception_type"
        };
        char *field_values[FIELDS_NUM_2] = {
            "1000", "20000101", "2"
        };

        calendar_date_t cd_1 = read_calendar_date(FIELDS_NUM_2, field_names, field_values);
        
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

int test_rf_calendar(void) {
    // Case 1
    {
        #define FIELDS_NUM_3 10
        char *field_names[FIELDS_NUM_3] = {
            "service_id", "monday", "tuesday", "wednesday", "thursday",
            "friday", "saturday", "sunday", "start_date", "end_date"
        };
        char *field_values[FIELDS_NUM_3] = {
            "1001", "1", "1", "1", "1", "1", "0", "0", "20000101", "20201231"
        };

        calendar_record_t cr_1 = read_calendar_record(FIELDS_NUM_3, field_names, field_values);
        
        if (!(
            !strcmp(cr_1.service_id, "1001") &&
            !strcmp(cr_1.start_date, "20000101") &&
            !strcmp(cr_1.end_date, "20201231") &&
            cr_1.monday == SA_AVAILABLE &&
            cr_1.tuesday == SA_AVAILABLE &&
            cr_1.wednesday == SA_AVAILABLE &&
            cr_1.thursday == SA_AVAILABLE &&
            cr_1.friday == SA_AVAILABLE &&
            cr_1.saturday == SA_UNAVAILABLE &&
            cr_1.sunday == SA_UNAVAILABLE
        )) {
            printf("Parsed calendar record 1 incorrectly!");
        }
    }
    return 0;
}

int test_rf_fare_attributes(void) {
    // Case 1
    {
        #define FIELDS_NUM_4 7
        char *field_names[FIELDS_NUM_4] = {
            "fare_id", "price", "currency_type", "payment_method",
            "transfers", "agency_id", "transfer_duration"
        };
        char *field_values[FIELDS_NUM_4] = {
            "17", "2.85", "EUR", "0", "", "1", "6000"
        };

        fare_attributes_t fa_1 = read_fare_attributes(FIELDS_NUM_4, field_names, field_values);

        if (!(
            !strcmp(fa_1.fare_id, "17") &&
            fa_1.price == 2.85 &&
            !strcmp(fa_1.currency_type, "EUR") &&
            fa_1.payment_method == PM_ON_BOARD &&
            fa_1.transfers == TS_UNLIMITED &&
            !strcmp(fa_1.agency_id, "1") &&
            fa_1.transfer_duration == 6000
        )) {
            printf("Parsed fare attributes record 1 incorrectly!");
        }
    }
    return 0;
}

int test_rf_fare_rule(void) {
    // Case 1
    {
        #define FIELDS_NUM_5 5
        char *field_names[FIELDS_NUM_5] = {
            "fare_id", "route_id", "origin_id", "destination_id", "contains_id"
        };
        char *field_values[FIELDS_NUM_5] = {
            "b", "TSW", "2", "8", "6"
        };

        fare_rule_t fa_1 = read_fare_rule(FIELDS_NUM_5, field_names, field_values);

        if (!(
            !strcmp(fa_1.fare_id, "b") &&
            !strcmp(fa_1.route_id, "TSW") &&
            !strcmp(fa_1.origin_id, "2") &&
            !strcmp(fa_1.destination_id, "8") &&
            !strcmp(fa_1.contains_id, "6")
        )) {
            printf("Parsed fare rules record 1 incorrectly!");
        }
    }
    return 0;
}

int test_rf_feed_info(void) {
    // Case 1
    {
        #define FIELDS_NUM_6 8
        char *field_names[FIELDS_NUM_6] = {
            "feed_publisher_name", "feed_publisher_url", "feed_lang", "feed_start_date",
            "feed_end_date", "feed_version", "feed_contact_email", "feed_contact_url"
        };
        char *field_values[FIELDS_NUM_6] = {
            "Vasilij Terkin", "protocol://domain.zone", "somelang", "18970527",
            "30000101", "0.1.0", "some@example.com", "http://example.com"
        };

        feed_info_t fi_1 = read_feed_info(FIELDS_NUM_6, field_names, field_values);

        if (!(
            !strcmp(fi_1.feed_publisher_name, "Vasilij Terkin") &&
            !strcmp(fi_1.feed_publisher_url, "protocol://domain.zone") &&
            !strcmp(fi_1.feed_lang, "somelang") &&
            !strcmp(fi_1.feed_start_date, "18970527") &&
            !strcmp(fi_1.feed_end_date, "30000101") &&
            !strcmp(fi_1.feed_version, "0.1.0") &&
            !strcmp(fi_1.feed_contact_email, "some@example.com") &&
            !strcmp(fi_1.feed_contact_url, "http://example.com")
        )) {
            printf("Parsed feed info incorrectly!");
        }
    }
    return 0;
}

int test_rf_frequency(void) {
    // Case 1
    {
        #define FIELDS_NUM_7 5
        char *field_names[FIELDS_NUM_7] = {
            "trip_id", "start_time", "end_time", "headway_secs", "exact_times"
        };
        char *field_values[FIELDS_NUM_7] = {
            "0xC0FFEE", "05:00:00", "07:00:00", "1200", ""
        };

        frequency_t freq_1 = read_frequency(FIELDS_NUM_7, field_names, field_values);

        if (!(
            !strcmp(freq_1.trip_id, "0xC0FFEE") &&
            !strcmp(freq_1.start_time, "05:00:00") &&
            !strcmp(freq_1.end_time, "07:00:00") && 
            freq_1.headway_secs == 1200 &&
            freq_1.exact_times == TE_NOT_EXACT
        )) {
            printf("Parsed frequency 1 incorrectly!");
        }
    }
    return 0;
}

#endif