#ifndef CGTFS_TESTS_RECORDS_ROUTES_C
#define CGTFS_TESTS_RECORDS_ROUTES_C

#include "greatest/greatest.h"
#include "records/route.h"

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
    RUN_TEST(route_compare);
}

#endif