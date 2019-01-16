#ifndef CGTFS_TESTS__ALL_C
#define CGTFS_TESTS__ALL_C

#include "greatest/greatest.h"

#include "tests-enum_parsing.c"
#include "tests-feed.c"
#include "tests-filenames.c"
#include "tests-haversine.c"
#include "tests-reading.c"

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();

    RUN_SUITE(CGTFS_EnumParsing);
    RUN_SUITE(CGTFS_Feed);
    RUN_SUITE(CGTFS_Filenames);
    RUN_SUITE(CGTFS_Haversine);
    
    RUN_SUITE(CGTFS_ReadingAgency);
    RUN_SUITE(CGTFS_ReadingCalendarDate);
    RUN_SUITE(CGTFS_ReadingCalendarRecord);

    GREATEST_MAIN_END();
}

#endif