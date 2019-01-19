#ifndef CGTFS_TESTS_RECORDS_SHAPES_C
#define CGTFS_TESTS_RECORDS_SHAPES_C

#include "greatest/greatest.h"
#include "records/shape.h"

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

    ASSERT_EQ(0, equal_shape(&a, &b));
    ASSERT_EQ(1, equal_shape(&a, &c));
    ASSERT_EQ(1, equal_shape(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordShape) {
    RUN_TEST(shape_compare);
}

#endif