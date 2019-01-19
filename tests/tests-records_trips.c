#ifndef CGTFS_TESTS_RECORDS_TRIPS_C
#define CGTFS_TESTS_RECORDS_TRIPS_C

#include "greatest/greatest.h"
#include "records/trip.h"

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