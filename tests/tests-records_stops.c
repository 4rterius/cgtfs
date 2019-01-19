#ifndef CGTFS_TESTS_RECORDS_STOPS_C
#define CGTFS_TESTS_RECORDS_STOPS_C

#include "greatest/greatest.h"
#include "records/stop.h"

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

    ASSERT_EQ(0, equal_stop(&a, &b));
    ASSERT_EQ(1, equal_stop(&a, &c));
    ASSERT_EQ(1, equal_stop(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordStop) {
    RUN_TEST(stop_compare);
}

#endif