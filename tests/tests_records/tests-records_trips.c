#ifndef CGTFS_TESTS_RECORDS_TRIPS_C
#define CGTFS_TESTS_RECORDS_TRIPS_C

#include "greatest/greatest.h"
#include "records/trip.h"

TEST trip_read(void) {

    #define FIELDS_NUM_13 10
    char *field_names[FIELDS_NUM_13] = {
        "route_id", "service_id", "trip_id", "trip_headsign", "trip_short_name",
        "direction_id", "block_id", "shape_id", "wheelchair_accessible", "bikes_allowed"
    };
    char *field_values[FIELDS_NUM_13] = {
        "A", "WE", "AWE1", "Downtown", "Some short name",
        "", "11", "8", "1", "2"
    };

    trip_t tr_1;
    read_trip(&tr_1, FIELDS_NUM_13, (const char **)field_names, (const char **)field_values);

    ASSERT_STR_EQ("A", tr_1.route_id);
    ASSERT_STR_EQ("WE", tr_1.service_id);
    ASSERT_STR_EQ("AWE1", tr_1.id);
    ASSERT_STR_EQ("Downtown", tr_1.headsign);
    ASSERT_STR_EQ("Some short name", tr_1.short_name);
    ASSERT_STR_EQ("11", tr_1.block_id);
    ASSERT_STR_EQ("8", tr_1.shape_id);
    ASSERT_EQ(0, tr_1.direction_id);
    ASSERT_EQ(WA_POSSIBLE, tr_1.wheelchair_accessible);
    ASSERT_EQ(BA_NOT_POSSIBLE, tr_1.bikes_allowed);

    PASS();
}

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

    ASSERT_EQ(1, equal_trip(&a, &b));
    ASSERT_EQ(0, equal_trip(&a, &c));
    ASSERT_EQ(0, equal_trip(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordTrip) {
    RUN_TEST(trip_read);
    RUN_TEST(trip_compare);
}

#endif