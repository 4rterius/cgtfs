#ifndef CGTFS_TESTS_RECORDS_STOPS_C
#define CGTFS_TESTS_RECORDS_STOPS_C

#include "greatest/greatest.h"
#include "records/stop.h"

TEST stop_read(void) {

    #define FIELDS_NUM_11 14
    char *field_names[FIELDS_NUM_11] = {
        "stop_id", "stop_code", "stop_name",
        "stop_desc", "stop_lat", "stop_lon",
        "zone_id", "stop_url", "location_type",
        "parent_station", "stop_timezone", "wheelchair_boarding",
        "level_id", "platform_code"
    };
    char *field_values[FIELDS_NUM_11] = {
        "S1", "SOMECODE", "Mission St, Silver Ave.",
        "The stop is located at the southwest corner of the intersection.", "37.728631", "-122.431282",
        "1", "http://example.com", "0",
        "ST0", "Europe/Helsinki", "2",
        "LVLID", "SOMECODE"
    };

    stop_t stp_1;
    read_stop(&stp_1, FIELDS_NUM_11, (const char **)field_names, (const char **)field_values);

    ASSERT_STR_EQ("S1", stp_1.id);
    ASSERT_STR_EQ("SOMECODE", stp_1.code);
    ASSERT_STR_EQ("Mission St, Silver Ave.", stp_1.name);
    ASSERT_STR_EQ("The stop is located at the southwest corner of the intersection.", stp_1.desc);
    ASSERT_STR_EQ("1", stp_1.zone_id);
    ASSERT_STR_EQ("http://example.com", stp_1.url);
    ASSERT_STR_EQ("ST0", stp_1.parent_station);
    ASSERT_STR_EQ("Europe/Helsinki", stp_1.timezone);
    ASSERT_EQ(37.728631, stp_1.lat);
    ASSERT_EQ(-122.431282, stp_1.lon);
    ASSERT_EQ(LT_STOP, stp_1.location_type);
    ASSERT_EQ(WB_NOT_POSSIBLE, stp_1.wheelchair_boarding);
    ASSERT_STR_EQ("LVLID", stp_1.level_id);
    ASSERT_STR_EQ("SOMECODE", stp_1.platform_code);

    PASS();
}

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
        .wheelchair_boarding = WB_NOT_SET,
        .level_id = "LVL01",
        .platform_code = "A"
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
        .wheelchair_boarding = WB_NOT_SET,
        .level_id = "LVL01",
        .platform_code = "A"
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
        .wheelchair_boarding = WB_NOT_SET,
        .level_id = "LVL00",
        .platform_code = "B"
    };

    ASSERT_EQ(1, equal_stop(&a, &b));
    ASSERT_EQ(0, equal_stop(&a, &c));
    ASSERT_EQ(0, equal_stop(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordStop) {
    RUN_TEST(stop_read);
    RUN_TEST(stop_compare);
}

#endif