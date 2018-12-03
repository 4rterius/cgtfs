#ifndef CGTFS_TESTS__ALL_C
#define CGTFS_TESTS__ALL_C

#include "test-haversine.c"
#include "test-make_functions.c"
#include "test-reading.c"
#include "test-reading_utils.c"

int main(int argc, char **argv) {
    test_haversine_correct();

    test_mf_agency();
    test_mf_calendar_dates();
    test_mf_calendar();

    test_reading_utils_read_header();
    test_reading_utils_read_record();
    return 0;
}

#endif
