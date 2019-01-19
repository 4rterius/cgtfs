#ifndef CGTFS_TESTS_RECORDS_ROUTES_C
#define CGTFS_TESTS_RECORDS_ROUTES_C

#include "greatest/greatest.h"
#include "records/route.h"

TEST route_read(void) {
    #define FIELDS_NUM 10
    char *field_names[FIELDS_NUM] = {
        "route_id", "agency_id", "route_short_name", "route_long_name", "route_desc",
        "route_type", "route_url", "route_color", "route_text_color", "route_sort_order"
    };
    char *field_values[FIELDS_NUM] = {
        "A", "2", "17", "Mission", "Amazing desc",
        "3", "http://some.url", "cccccc", "ff0000", "175"
    };

    route_t r_1;
    read_route(&r_1, FIELDS_NUM, (const char **)field_names, (const char **)field_values);

    ASSERT_STR_EQ("A", r_1.id);
    ASSERT_STR_EQ("2", r_1.agency_id);
    ASSERT_STR_EQ("17", r_1.short_name);
    ASSERT_STR_EQ("Mission", r_1.long_name);
    ASSERT_STR_EQ("Amazing desc", r_1.desc);
    ASSERT_STR_EQ("http://some.url", r_1.url);
    ASSERT_STR_EQ("cccccc", r_1.color);
    ASSERT_STR_EQ("ff0000", r_1.text_color);
    ASSERT_EQ(RT_BUS, r_1.type);
    ASSERT_EQ(175, r_1.sort_order);
    
    PASS();
}

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

    ASSERT_EQ(0, equal_route(&a, &b));
    ASSERT_EQ(1, equal_route(&a, &c));
    ASSERT_EQ(1, equal_route(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordRoute) {
    RUN_TEST(route_read);
    RUN_TEST(route_compare);
}

#endif