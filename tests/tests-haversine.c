#ifndef CGTFS_TESTS_HAVERSINE_C
#define CGTFS_TESTS_HAVERSINE_C

#include "greatest/greatest.h"
#include "helpers/haversine.h"

TEST haversine_approx(void) {
    geo_location_t a = {.latitude = 41.8903, .longitude = 12.4924};
    geo_location_t b = {.latitude = 41.88526, .longitude = 12.48712};

    ASSERT_IN_RANGE(710, haversine_distance(a, b), 5.0);
    PASS();
}

TEST haversine_precise(void) {
    geo_location_t c = {.latitude = 60.98390, .longitude = 25.65733};
    geo_location_t d = {.latitude = 60.98395, .longitude = 25.65694};

    ASSERT_IN_RANGE(21.7, haversine_distance(c, d), 0.5);
    PASS();
}

SUITE(CGTFS_Haversine) {
    RUN_TEST(haversine_approx);
    RUN_TEST(haversine_precise);
}

#endif