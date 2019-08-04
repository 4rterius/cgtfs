#ifndef CGTFS_TESTS_RECORDS_SHAPES_C
#define CGTFS_TESTS_RECORDS_SHAPES_C

#include "greatest/greatest.h"
#include "records/shape.h"

TEST shape_read(void) {
    #define FIELDS_NUM_9 5
    char *field_names[FIELDS_NUM_9] = {
        "shape_id", "shape_pt_lat", "shape_pt_lon", "shape_pt_sequence", "shape_dist_traveled"
    };
    char *field_values[FIELDS_NUM_9] = {
        "A_shp", "37.64430", "-122.41070", "0", "6.8310"
    };

    shape_t s_1;
    read_shape(&s_1, FIELDS_NUM_9, (const char **)field_names, (const char **)field_values);

    ASSERT_STR_EQ("A_shp", s_1.id);
    ASSERT_EQ(37.64430, s_1.pt_lat);
    ASSERT_EQ(-122.41070, s_1.pt_lon);
    ASSERT_EQ(0, s_1.pt_sequence);
    ASSERT_EQ(6.8310, s_1.dist_traveled);

    PASS();
}

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

    ASSERT_EQ(1, equal_shape(&a, &b));
    ASSERT_EQ(0, equal_shape(&a, &c));
    ASSERT_EQ(0, equal_shape(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordShape) {
    RUN_TEST(shape_read);
    RUN_TEST(shape_compare);
}

#endif