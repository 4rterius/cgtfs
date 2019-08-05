#ifndef CGTFS_TESTS_RECORDS_STOP_TIMES_C
#define CGTFS_TESTS_RECORDS_STOP_TIMES_C

#include "greatest/greatest.h"
#include "records/stop_time.h"

TEST stop_time_read(void) {

    #define FIELDS_NUM_10 10
    char *field_names[FIELDS_NUM_10] = {
        "trip_id", "arrival_time", "departure_time", "stop_id", "stop_sequence",
        "stop_headsign", "pickup_type", "drop_off_type", "shape_dist_traveled", "timepoint"
    };
    char *field_values[FIELDS_NUM_10] = {
        "AWE1", "00:06:00", "00:06:30", "ST_666", "1",
        "Argent D'Nur", "1", "2", "6.8315", ""
    };

    stop_time_t st_1;
    read_stop_time(&st_1, FIELDS_NUM_10, (const char **)field_names, (const char **)field_values);

    ASSERT_STR_EQ("AWE1", st_1.trip_id);
    ASSERT_STR_EQ("00:06:00", st_1.arrival_time);
    ASSERT_STR_EQ("00:06:30", st_1.departure_time);
    ASSERT_STR_EQ("ST_666", st_1.stop_id);
    ASSERT_STR_EQ("Argent D'Nur", st_1.stop_headsign);
    ASSERT_EQ(1, st_1.stop_sequence);
    ASSERT_EQ(ST_NOT_AVAILABLE, st_1.pickup_type);
    ASSERT_EQ(ST_CONTACT_AGENCY, st_1.dropoff_type);
    ASSERT_EQ(6.8315, st_1.shape_dist_traveled);
    ASSERT_EQ(TP_EXACT, st_1.timepoint);

    PASS();
}

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

    ASSERT_EQ(1, equal_stop_time(&a, &b));
    ASSERT_EQ(0, equal_stop_time(&a, &c));
    ASSERT_EQ(0, equal_stop_time(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordStopTime) {
    RUN_TEST(stop_time_read);
    RUN_TEST(stop_time_compare);
}

#endif