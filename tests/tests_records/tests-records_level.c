#ifndef CGTFS_TESTS_RECORDS_LEVEL_C
#define CGTFS_TESTS_RECORDS_LEVEL_C

#include "greatest/greatest.h"
#include "records/level.h"

TEST level_read(void) {
    #define FIELDS_NUM_14 3
    char *field_names[FIELDS_NUM_14] = {
        "level_id", "level_index", "level_name"
    };
    char *field_values[FIELDS_NUM_14] = {
        "INDEX123_abc", "0.435", "Another damn level"
    };

    level_t lvl_1;
    read_level(&lvl_1, FIELDS_NUM_14, (const char **)field_names, (const char **)field_values);

    ASSERT_STR_EQ("INDEX123_abc", lvl_1.id);
    ASSERT_STR_EQ("Another damn level", lvl_1.name);
    ASSERT_EQ_FMT(0.435, lvl_1.index, "%f");

    PASS();
}

TEST level_compare(void) {
    level_t a = {
        .id = "SOMEID123",
        .name = "a b c d e f",
        .index = -123.9
    };

    level_t b = {
        .id = "SOMEID123",
        .name = "a b c d e f",
        .index = -123.9
    };

    level_t c = {
        .id = "SOMEID456",
        .name = "a b c d e f",
        .index = -123.9
    };

    level_t d = {
        .id = "SOMEID123",
        .name = "a b c d e f ",
        .index = -123.9
    };

    level_t e = {
        .id = "SOMEID123",
        .name = "a b c d e f",
        .index = 0.0
    };

    ASSERT_EQ(1, equal_level(&a, &b));
    ASSERT_EQ(0, equal_level(&a, &c));
    ASSERT_EQ(0, equal_level(&b, &c));
    ASSERT_EQ(0, equal_level(&b, &d));
    ASSERT_EQ(0, equal_level(&b, &e));

    PASS();
}

SUITE(CGTFS_RecordLevel) {
    RUN_TEST(level_read);
    RUN_TEST(level_compare);
}

#endif