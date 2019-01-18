#ifndef CGTFS_TESTS__ALL_C
#define CGTFS_TESTS__ALL_C

#include "greatest/greatest.h"

#include "tests-enum_parsing.c"
#include "tests-feed.c"
#include "tests-file_reading.c"
#include "tests-filenames.c"
#include "tests-haversine.c"
#include "tests-reading_utils.c"
#include "tests-reading.c"

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();

    RUN_SUITE(CGTFS_EnumParsing);
    RUN_SUITE(CGTFS_Feed);
    RUN_SUITE(CGTFS_Filenames);
    RUN_SUITE(CGTFS_Haversine);

    RUN_SUITE(CGTFS_ReadingUtils);
    
    RUN_SUITE(CGTFS_ReadingAgency);
    RUN_SUITE(CGTFS_ReadingCalendarDate);
    RUN_SUITE(CGTFS_ReadingCalendarRecord);
    RUN_SUITE(CGTFS_ReadingFareAttributes);
    RUN_SUITE(CGTFS_ReadingFareRule);
    RUN_SUITE(CGTFS_ReadingFeedInfo);
    RUN_SUITE(CGTFS_ReadingFrequency);
    RUN_SUITE(CGTFS_ReadingRoute);
    RUN_SUITE(CGTFS_ReadingShape);
    RUN_SUITE(CGTFS_ReadingStopTime);
    RUN_SUITE(CGTFS_ReadingStop);
    RUN_SUITE(CGTFS_ReadingTransfer);
    RUN_SUITE(CGTFS_ReadingTrip);

    RUN_SUITE(CGTFS_FileReading);

    GREATEST_MAIN_END();
}

#endif