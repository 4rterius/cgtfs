#ifndef CGTFS_TESTS_RECORDS_FREQUENCIES_C
#define CGTFS_TESTS_RECORDS_FREQUENCIES_C

#include "greatest/greatest.h"
#include "records/frequency.h"

TEST frequency_read(void) {
    #define FIELDS_NUM 5
    char *field_names[FIELDS_NUM] = {
        "trip_id", "start_time", "end_time", "headway_secs", "exact_times"
    };
    char *field_values[FIELDS_NUM] = {
        "0xC0FFEE", "05:00:00", "07:00:00", "1200", ""
    };

    frequency_t freq_1;
    read_frequency(&freq_1, FIELDS_NUM, (const char **)field_names, (const char **)field_values);

    ASSERT_STR_EQ("0xC0FFEE", freq_1.trip_id);
    ASSERT_STR_EQ("05:00:00", freq_1.start_time);
    ASSERT_STR_EQ("07:00:00", freq_1.end_time);
    ASSERT_EQ(1200, freq_1.headway_secs);
    ASSERT_EQ(TE_NOT_EXACT, freq_1.exact_times);

    PASS();
}

TEST frequency_compare(void) {
    frequency_t a = {
        .trip_id = "EXAMPLEtrip",
        .start_time = "110000",
        .end_time = "220000",
        .headway_secs = 600,
        .exact_times = TE_NOT_EXACT
    };

    frequency_t b = {
        .trip_id = "EXAMPLEtrip",
        .start_time = "110000",
        .end_time = "220000",
        .headway_secs = 600,
        .exact_times = TE_NOT_EXACT
    };

    frequency_t c = {
        .trip_id = "EXAMPLEtrip",
        .start_time = "110000",
        .end_time = "220000",
        .headway_secs = 600,
        .exact_times = TE_EXACT
    };

    ASSERT_EQ(0, equal_frequency(&a, &b));
    ASSERT_EQ(1, equal_frequency(&a, &c));
    ASSERT_EQ(1, equal_frequency(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordFrequency) {
    RUN_TEST(frequency_read);
    RUN_TEST(frequency_compare);
}

#endif