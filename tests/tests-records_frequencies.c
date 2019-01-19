#ifndef CGTFS_TESTS_RECORDS_FREQUENCIES_C
#define CGTFS_TESTS_RECORDS_FREQUENCIES_C

#include "greatest/greatest.h"
#include "records/frequency.h"

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
    RUN_TEST(frequency_compare);
}

#endif