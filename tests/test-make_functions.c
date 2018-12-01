#ifndef CGTFS_TESTS_MAKE_FUNCTIONS_C
#define CGTFS_TESTS_MAKE_FUNCTIONS_C

#include "calendar_dates.h"

int test_mf_calendar_dates(void) {
    // Case 1
    {
        #define FIELDS_NUM_1 3
        char *field_names[FIELDS_NUM_1] = {
            "service_id", "date", "exception_type"
        };
        char *field_values[FIELDS_NUM_1] = {
            "1000", "20000101", "2"
        };

        calendar_date_t cd_1 = make_calendar_date(FIELDS_NUM_1, field_names, field_values);
        
        if (!(
            !strcmp(cd_1.service_id, "1000") &&
            !strcmp(cd_1.date, "20000101") &&
            cd_1.exception_type == ET_REMOVED
        )) {
            printf("Parsed calendar date 1 incorrectly!");
        }
    }
}

#endif