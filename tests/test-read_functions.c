#ifndef CGTFS_TESTS_MAKE_FUNCTIONS_C
#define CGTFS_TESTS_MAKE_FUNCTIONS_C

#include "agency.h"
#include "calendar_dates.h"
#include "calendar.h"
#include "fare_attributes.h"
#include "fare_rule.h"
#include "feed_info.h"
#include "frequency.h"
#include "route.h"
#include "shape.h"
#include "stop_time.h"
#include "stop.h"
#include "transfers.h"
#include "trip.h"

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

        agency_t a_1 = read_agency(FIELDS_NUM_1, (const char **)field_names, (const char **)field_values);

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

        calendar_date_t cd_1 = read_calendar_date(FIELDS_NUM_2, (const char **)field_names, (const char **)field_values);
        
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

        calendar_record_t cr_1 = read_calendar_record(FIELDS_NUM_3, (const char **)field_names, (const char **)field_values);
        
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

        fare_attributes_t fa_1 = read_fare_attributes(FIELDS_NUM_4, (const char **)field_names, (const char **)field_values);

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

        fare_rule_t fa_1 = read_fare_rule(FIELDS_NUM_5, (const char **)field_names, (const char **)field_values);

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

        feed_info_t fi_1 = read_feed_info(FIELDS_NUM_6, (const char **)field_names, (const char **)field_values);

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

        frequency_t freq_1 = read_frequency(FIELDS_NUM_7, (const char **)field_names, (const char **)field_values);

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

int test_rf_route(void) {
    // Case 1
    {
        #define FIELDS_NUM_8 10
        char *field_names[FIELDS_NUM_8] = {
            "route_id", "agency_id", "route_short_name", "route_long_name", "route_desc",
            "route_type", "route_url", "route_color", "route_text_color", "route_sort_order"
        };
        char *field_values[FIELDS_NUM_8] = {
            "A", "2", "17", "Mission", "Amazing desc",
            "3", "http://some.url", "cccccc", "ff0000", "175"
        };

        route_t r_1 = read_route(FIELDS_NUM_8, (const char **)field_names, (const char **)field_values);

        if (!(
            !strcmp(r_1.id, "A") &&
            !strcmp(r_1.agency_id, "2") &&
            !strcmp(r_1.short_name, "17") &&
            !strcmp(r_1.long_name, "Mission") &&
            !strcmp(r_1.desc, "Amazing desc") &&
            r_1.type == RT_BUS &&
            !strcmp(r_1.url, "http://some.url") &&
            !strcmp(r_1.color, "cccccc") &&
            !strcmp(r_1.text_color, "ff0000") &&
            r_1.sort_order == 175
        )) {
            printf("Parsed route 1 incorrectly!");
        }
    }
    return 0;
}

int test_rf_shape(void) {
    // Case 1
    {
        #define FIELDS_NUM_9 5
        char *field_names[FIELDS_NUM_9] = {
            "shape_id", "shape_pt_lat", "shape_pt_lon", "shape_pt_sequence", "shape_dist_traveled"
        };
        char *field_values[FIELDS_NUM_9] = {
            "A_shp", "37.64430", "-122.41070", "0", "6.8310"
        };

        shape_t s_1 = read_shape(FIELDS_NUM_9, (const char **)field_names, (const char **)field_values);   // TODO: find out why works on Win but not on Linux

        if (!(
            !strcmp(s_1.id, "A_shp") &&
            s_1.pt_lat == 37.64430 &&
            s_1.pt_lon == -122.41070 &&
            s_1.pt_sequence == 0 &&
            s_1.dist_traveled == 6.8310
        )) {
            printf("Parsed shape 1 incorrectly!");
        }
    }
    return 0;
}

int test_rf_stop_time(void) {
    // Case 1
    {
        #define FIELDS_NUM_10 10
        char *field_names[FIELDS_NUM_10] = {
            "trip_id", "arrival_time", "departure_time", "stop_id", "stop_sequence",
            "stop_headsign", "pickup_type", "drop_off_type", "shape_dist_traveled", "timepoint"
        };
        char *field_values[FIELDS_NUM_10] = {
            "AWE1", "00:06:00", "00:06:30", "ST_666", "1",
            "Argent D'Nur", "1", "2", "6.8315", ""
        };

        stop_time_t st_1 = read_stop_time(FIELDS_NUM_10, (const char **)field_names, (const char **)field_values);

        if (!(
            !strcmp(st_1.trip_id, "AWE1") &&
            !strcmp(st_1.arrival_time, "00:06:00") &&
            !strcmp(st_1.departure_time, "00:06:30") &&
            !strcmp(st_1.stop_id, "ST_666") &&
            st_1.stop_sequence == 1 &&
            !strcmp(st_1.stop_headsign, "Argent D'Nur") &&
            st_1.pickup_type == ST_NOT_AVAILABLE &&
            st_1.dropoff_type == ST_CONTACT_AGENCY &&
            st_1.shape_dist_traveled == 6.8315 &&
            st_1.timepoint == TP_EXACT
        )) {
            printf("Parsed stop time 1 incorrectly!");
        }
    }
    return 0;
}

int test_rf_stop(void) {
    // Case 1
    {
        #define FIELDS_NUM_11 12
        char *field_names[FIELDS_NUM_11] = {
            "stop_id", "stop_code", "stop_name",
            "stop_desc", "stop_lat", "stop_lon",
            "zone_id", "stop_url", "location_type",
            "parent_station", "stop_timezone", "wheelchair_boarding"
        };
        char *field_values[FIELDS_NUM_11] = {
            "S1", "SOMECODE", "Mission St, Silver Ave.",
            "The stop is located at the southwest corner of the intersection.", "37.728631", "-122.431282",
            "1", "http://example.com", "0",
            "ST0", "Europe/Helsinki", "2"
        };

        stop_t stp_1 = read_stop(FIELDS_NUM_11, (const char **)field_names, (const char **)field_values);

        if (!(
            !strcmp(stp_1.id, "S1") &&
            !strcmp(stp_1.code, "SOMECODE") &&
            !strcmp(stp_1.name, "Mission St, Silver Ave.") &&
            !strcmp(stp_1.desc, "The stop is located at the southwest corner of the intersection.") &&
            stp_1.lat == 37.728631 &&
            stp_1.lon == -122.431282 &&
            !strcmp(stp_1.zone_id, "1") &&
            !strcmp(stp_1.url, "http://example.com") &&
            stp_1.location_type == LT_STOP &&
            !strcmp(stp_1.parent_station, "ST0") &&
            !strcmp(stp_1.timezone, "Europe/Helsinki") &&
            stp_1.wheelchair_boarding == WB_NOT_POSSIBLE
        )) {
            printf("Parsed stop 1 incorrectly!");
        }
    }
    return 0;
}

int test_rf_transfer(void) {
    // Case 1
    {
        #define FIELDS_NUM_12 4
        char *field_names[FIELDS_NUM_12] = {
            "from_stop_id", "to_stop_id", "transfer_type", "min_transfer_time"
        };
        char *field_values[FIELDS_NUM_12] = {
            "S180", "R360", "2", "120"
        };

        transfer_t t_1 = read_transfer(FIELDS_NUM_12, (const char **)field_names, (const char **)field_values);

        if (!(
            !strcmp(t_1.from_stop_id, "S180") &&
            !strcmp(t_1.to_stop_id, "R360") &&
            t_1.transfer_type == TT_TIME_REQUIRED &&
            t_1.min_transfer_time == 120
        )) {
            printf("Parsed transfer 1 incorrectly!");
        }
    }
    return 0;
}

int test_rf_trip(void) {
    // Case 1
    {
        #define FIELDS_NUM_13 10
        char *field_names[FIELDS_NUM_13] = {
            "route_id", "service_id", "trip_id", "trip_headsign", "trip_short_name",
            "direction_id", "block_id", "shape_id", "wheelchair_accessible", "bikes_allowed"
        };
        char *field_values[FIELDS_NUM_13] = {
            "A", "WE", "AWE1", "Downtown", "Some short name",
            "", "11", "8", "1", "2"
        };

        trip_t tr_1 = read_trip(FIELDS_NUM_13, (const char **)field_names, (const char **)field_values);

        if (!(
            !strcmp(tr_1.route_id, "A") &&
            !strcmp(tr_1.service_id, "WE") &&
            !strcmp(tr_1.trip_id, "AWE1") &&
            !strcmp(tr_1.headsign, "Downtown") &&
            !strcmp(tr_1.short_name, "Some short name") &&
            tr_1.direction_id == 0 &&
            !strcmp(tr_1.block_id, "11") &&
            !strcmp(tr_1.shape_id, "8") &&
            tr_1.wheelchair_accessible == WA_POSSIBLE &&
            tr_1.bikes_allowed == BA_NOT_POSSIBLE
        )) {
            printf("Parsed trip 1 incorrectly!");
        }
    }
    return 0;
}

#endif