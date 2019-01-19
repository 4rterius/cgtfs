#ifndef CGTFS_TESTS_RECORDS_STOP_TIMES_C
#define CGTFS_TESTS_RECORDS_STOP_TIMES_C

#include "greatest/greatest.h"
#include "records/stop_time.h"

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

#endif