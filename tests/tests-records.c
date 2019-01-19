#ifndef CGTFS_TESTS_RECORDS_C
#define CGTFS_TESTS_RECORDS_C

#include "greatest/greatest.h"

#include "records/agency.h"
#include "records/calendar_dates.h"
#include "records/calendar.h"
#include "records/fare_attributes.h"
#include "records/fare_rule.h"
#include "records/feed_info.h"
#include "records/frequency.h"
#include "records/route.h"
#include "records/shape.h"
#include "records/stop_time.h"
#include "records/stop.h"
#include "records/transfers.h"
#include "records/trip.h"


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

SUITE(CGTFS_RecordAgency) {
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

SUITE(CGTFS_RecordCalendarDate) {
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

SUITE(CGTFS_RecordCalendarRecord) {
    RUN_TEST(calendar_record_compare);
}



// fare_attributes_t tests
// ----------------------------------------------------------------------

TEST fare_attributes_compare(void) {
    fare_attributes_t a = {
        .fare_id = "SOME_ID1",
        .currency_type = "EUR",
        .price = 10.0,
        .payment_method = PM_NOT_SET,
        .transfers = TS_UNLIMITED,
        .transfer_duration = 60.0
    };

    fare_attributes_t b = {
        .fare_id = "SOME_ID1",
        .currency_type = "EUR",
        .price = 10.0,
        .payment_method = PM_NOT_SET,
        .transfers = TS_UNLIMITED,
        .transfer_duration = 60.0
    };

    fare_attributes_t c = {
        .fare_id = "SOME_ID1",
        .currency_type = "EUR",
        .agency_id = "ANOTHER_ID",
        .price = 9.0,
        .payment_method = PM_NOT_SET,
        .transfers = TS_UNLIMITED,
        .transfer_duration = 60.0
    };

    ASSERT_EQ(equal_fare_attributes(&a, &b), 0);
    ASSERT_EQ(equal_fare_attributes(&a, &c), 1);
    ASSERT_EQ(equal_fare_attributes(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordFareAttributes) {
    RUN_TEST(fare_attributes_compare);
}



// fare_rule_t tests
// ----------------------------------------------------------------------

TEST fare_rule_compare(void) {
    fare_rule_t a = {
        .fare_id = "SOME_ID1",
        .route_id = "SUM_ROUT",
        .origin_id = "BS1",
        .destination_id = "BS117",
        .contains_id = ""
    };

    fare_rule_t b = {
        .fare_id = "SOME_ID1",
        .route_id = "SUM_ROUT",
        .origin_id = "BS1",
        .destination_id = "BS117",
        .contains_id = ""
    };

    fare_rule_t c = {
        .fare_id = "SOME_ID2",
        .route_id = "SUM_ROUT",
        .origin_id = "BS1",
        .destination_id = "BS117",
        .contains_id = ""
    };

    ASSERT_EQ(equal_fare_rule(&a, &b), 0);
    ASSERT_EQ(equal_fare_rule(&a, &c), 1);
    ASSERT_EQ(equal_fare_rule(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordFareRule) {
    RUN_TEST(fare_rule_compare);
}



// feed_info_t tests
// ----------------------------------------------------------------------

TEST feed_info_compare(void) {
    feed_info_t a = {
        .feed_publisher_name = "EXAMPLE",
        .feed_publisher_url = "https://example.com",
        .feed_lang = "EN",
        .feed_start_date = "01012019",
        .feed_end_date = "02012019",
        .feed_version = "",
        .feed_contact_email = "example@some.url",
        .feed_contact_url = "https://some.url/"
    };

    feed_info_t b = {
        .feed_publisher_name = "EXAMPLE",
        .feed_publisher_url = "https://example.com",
        .feed_lang = "EN",
        .feed_start_date = "01012019",
        .feed_end_date = "02012019",
        .feed_version = "",
        .feed_contact_email = "example@some.url",
        .feed_contact_url = "https://some.url/"
    };

    feed_info_t c = {
        .feed_publisher_name = "EXAMPLE2",
        .feed_publisher_url = "https://example.c0m",
        .feed_lang = "",
        .feed_start_date = "01012019",
        .feed_end_date = "02012019",
        .feed_version = "2",
        .feed_contact_email = "example@some.url",
        .feed_contact_url = "https://some.url/"
    };

    ASSERT_EQ(equal_feed_info(&a, &b), 0);
    ASSERT_EQ(equal_feed_info(&a, &c), 1);
    ASSERT_EQ(equal_feed_info(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordFeedInfo) {
    RUN_TEST(feed_info_compare);
}



// frequency_t tests
// ----------------------------------------------------------------------

TEST frequency_compare(void) {
    frequency_t a = {
        .trip_id = "EXAMPLEtrip",
        .start_time = "110000",
        .end_time = "220000",
        .headway_secs = 600,
        .exact_times = TE_NOT_EXACT
    };

    frequency_t b = {
        .trip_id = "EXAMPLEtrip",
        .start_time = "110000",
        .end_time = "220000",
        .headway_secs = 600,
        .exact_times = TE_NOT_EXACT
    };

    frequency_t c = {
        .trip_id = "EXAMPLEtrip",
        .start_time = "110000",
        .end_time = "220000",
        .headway_secs = 600,
        .exact_times = TE_EXACT
    };

    ASSERT_EQ(equal_frequency(&a, &b), 0);
    ASSERT_EQ(equal_frequency(&a, &c), 1);
    ASSERT_EQ(equal_frequency(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordFrequency) {
    RUN_TEST(frequency_compare);
}



// route_t tests
// ----------------------------------------------------------------------

TEST route_compare(void) {
    route_t a = {
        .id = "route0",
        .agency_id = "SOMEAGENCY",
        .short_name = "0",
        .long_name = "Null-route",
        .desc = "Highway to Hell",
        .type = RT_BUS,
        .url = "https://some.url/",
        .color = "ff3333",
        .text_color = "eeeeee",
        .sort_order = 0
    };

    route_t b = {
        .id = "route0",
        .agency_id = "SOMEAGENCY",
        .short_name = "0",
        .long_name = "Null-route",
        .desc = "Highway to Hell",
        .type = RT_BUS,
        .url = "https://some.url/",
        .color = "ff3333",
        .text_color = "eeeeee",
        .sort_order = 0
    };

    route_t c = {
        .id = "route1",
        .agency_id = "SOMEAGENCY",
        .short_name = "1",
        .long_name = "Not-null-route",
        .desc = "...and back",
        .type = RT_CABLE_CAR,
        .url = "https://some.url/",
        .color = "ff3333",
        .text_color = "eeeeee",
        .sort_order = 1
    };

    ASSERT_EQ(equal_route(&a, &b), 0);
    ASSERT_EQ(equal_route(&a, &c), 1);
    ASSERT_EQ(equal_route(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordRoute) {
    RUN_TEST(route_compare);
}



// shape_t tests
// ----------------------------------------------------------------------

TEST shape_compare(void) {
    shape_t a = {
        .id = "SHAPE_ID",
        .pt_lat = 123.0,
        .pt_lon = 0.3,
        .pt_sequence = 2,
        .dist_traveled = 2.7
    };

    shape_t b = {
        .id = "SHAPE_ID",
        .pt_lat = 123.0,
        .pt_lon = 0.3,
        .pt_sequence = 2,
        .dist_traveled = 2.7
    };

    shape_t c = {
        .id = "SHAPE_ID",
        .pt_lat = 123.1,
        .pt_lon = 0.3,
        .pt_sequence = 0,
        .dist_traveled = 2.6
    };

    ASSERT_EQ(equal_shape(&a, &b), 0);
    ASSERT_EQ(equal_shape(&a, &c), 1);
    ASSERT_EQ(equal_shape(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordShape) {
    RUN_TEST(shape_compare);
}



// stop_time_t tests
// ----------------------------------------------------------------------

TEST stop_time_compare(void) {
    stop_time_t a = {
        .trip_id = "trip 0",
        .arrival_time = "12:13:14",
        .departure_time = "12:13:14",
        .stop_id = "some stop",
        .stop_sequence = 11,
        .stop_headsign = "THE STOP",
        .pickup_type = ST_REGULAR,
        .dropoff_type = ST_CONTACT_DRIVER,
        .shape_dist_traveled = 2.7,
        .timepoint = TP_NOT_SET
    };

    stop_time_t b = {
        .trip_id = "trip 0",
        .arrival_time = "12:13:14",
        .departure_time = "12:13:14",
        .stop_id = "some stop",
        .stop_sequence = 11,
        .stop_headsign = "THE STOP",
        .pickup_type = ST_REGULAR,
        .dropoff_type = ST_CONTACT_DRIVER,
        .shape_dist_traveled = 2.7,
        .timepoint = TP_NOT_SET
    };

    stop_time_t c = {
        .trip_id = "trip 1",
        .arrival_time = "12:13:14",
        .departure_time = "12:13:14",
        .stop_id = "some stop",
        .stop_sequence = 11,
        .stop_headsign = "THE STOP",
        .pickup_type = ST_REGULAR,
        .dropoff_type = ST_CONTACT_DRIVER,
        .shape_dist_traveled = 2.6,
        .timepoint = TP_NOT_SET
    };

    ASSERT_EQ(equal_stop_time(&a, &b), 0);
    ASSERT_EQ(equal_stop_time(&a, &c), 1);
    ASSERT_EQ(equal_stop_time(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordStopTime) {
    RUN_TEST(stop_time_compare);
}



// stop_t tests
// ----------------------------------------------------------------------

TEST stop_compare(void) {
    stop_t a = {
        .id = "STP1",
        .code = "S1",
        .name = "stop",
        .desc = "some stop",
        .lat = 0.9,
        .lon = 9.0,
        .zone_id = "Zone 51",
        .url = "none",
        .location_type = LT_STOP,
        .parent_station = "",
        .timezone = "Europe/Helsinki",
        .wheelchair_boarding = WB_NOT_SET
    };

    stop_t b = {
        .id = "STP1",
        .code = "S1",
        .name = "stop",
        .desc = "some stop",
        .lat = 0.9,
        .lon = 9.0,
        .zone_id = "Zone 51",
        .url = "none",
        .location_type = LT_STOP,
        .parent_station = "",
        .timezone = "Europe/Helsinki",
        .wheelchair_boarding = WB_NOT_SET
    };

    stop_t c = {
        .id = "STP0",
        .code = "S1",
        .name = "stop",
        .desc = "some stop",
        .lat = 0.9,
        .lon = 9.0,
        .zone_id = "Zone 51",
        .url = "none",
        .location_type = LT_STOP,
        .parent_station = "",
        .timezone = "Europe/Helsinki",
        .wheelchair_boarding = WB_NOT_SET
    };

    ASSERT_EQ(equal_stop(&a, &b), 0);
    ASSERT_EQ(equal_stop(&a, &c), 1);
    ASSERT_EQ(equal_stop(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordStop) {
    RUN_TEST(stop_compare);
}



// transfer_t tests
// ----------------------------------------------------------------------

TEST transfer_compare(void) {
    transfer_t a = {
        .from_stop_id = "0STP8",
        .to_stop_id = "7STP9",
        .transfer_type = TT_TIMED,
        .min_transfer_time = 800
    };

    transfer_t b = {
        .from_stop_id = "0STP8",
        .to_stop_id = "7STP9",
        .transfer_type = TT_TIMED,
        .min_transfer_time = 800
    };

    transfer_t c = {
        .from_stop_id = "0STP8",
        .to_stop_id = "7STP9",
        .transfer_type = TT_TIME_REQUIRED,
        .min_transfer_time = 800
    };

    ASSERT_EQ(equal_transfer(&a, &b), 0);
    ASSERT_EQ(equal_transfer(&a, &c), 1);
    ASSERT_EQ(equal_transfer(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordTransfer) {
    RUN_TEST(transfer_compare);
}



// trip_t tests
// ----------------------------------------------------------------------

TEST trip_compare(void) {
    trip_t a = {
        .route_id = "RT1",
        .service_id = "123",
        .id = "RT1_888",
        .headsign = "The Grand Tour",
        .short_name = "TGT",
        .direction_id = 1,
        .block_id = "lbkc",
        .shape_id = "shpe",
        .wheelchair_accessible = WA_UNKNOWN,
        .bikes_allowed = BA_POSSIBLE
    };

    trip_t b = {
        .route_id = "RT1",
        .service_id = "123",
        .id = "RT1_888",
        .headsign = "The Grand Tour",
        .short_name = "TGT",
        .direction_id = 1,
        .block_id = "lbkc",
        .shape_id = "shpe",
        .wheelchair_accessible = WA_UNKNOWN,
        .bikes_allowed = BA_POSSIBLE
    };

    trip_t c = {
        .route_id = "RT2",
        .service_id = "123",
        .id = "RT2_888",
        .headsign = "The Grand Tour",
        .short_name = "TGT",
        .direction_id = 0,
        .block_id = "lbskc",
        .shape_id = "shpe",
        .wheelchair_accessible = WA_UNKNOWN,
        .bikes_allowed = BA_POSSIBLE
    };

    ASSERT_EQ(equal_trip(&a, &b), 0);
    ASSERT_EQ(equal_trip(&a, &c), 1);
    ASSERT_EQ(equal_trip(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordTrip) {
    RUN_TEST(trip_compare);
}

#endif