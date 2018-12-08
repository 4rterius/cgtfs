#ifndef CGTFS_TESTS__ALL_C
#define CGTFS_TESTS__ALL_C

#include "test-haversine.c"
#include "test-read_functions.c"
#include "test-reading.c"
#include "test-reading_utils.c"

int main(int argc, char **argv) {
    test_haversine_correct();

    test_rf_agency();
    test_rf_calendar_dates();
    test_rf_calendar();
    test_rf_fare_attributes();
    test_rf_fare_rule();
    test_rf_feed_info();
    test_rf_frequency();

    test_reading_utils_read_header();
    test_reading_utils_read_record();
    return 0;
}

#endif
