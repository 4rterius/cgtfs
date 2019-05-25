#ifndef CGTFS_TESTS__ALL_C
#define CGTFS_TESTS__ALL_C

#include "greatest/greatest.h"

#include "tests-database.c"
#include "tests-database_agency.c"
#include "tests-database_storing.c"
#include "tests-enum_parsing.c"
#include "tests-feed.c"
#include "tests-file_reading.c"
#include "tests-filenames.c"
#include "tests-haversine.c"
#include "tests-file_utils.c"
#include "tests-records.c"

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();

    RUN_SUITE(CGTFS_Database);
    RUN_SUITE(CGTFS_DatabaseStoring);
    
    RUN_SUITE(CGTFS_DatabaseAgency);

    RUN_SUITE(CGTFS_EnumParsing);
    RUN_SUITE(CGTFS_Feed);
    RUN_SUITE(CGTFS_Filenames);
    RUN_SUITE(CGTFS_Haversine);

    RUN_SUITE(CGTFS_FileUtils);
    
    RUN_SUITE(CGTFS_RecordAgency);
    RUN_SUITE(CGTFS_RecordCalendarDate);
    RUN_SUITE(CGTFS_RecordCalendarRecord);
    RUN_SUITE(CGTFS_RecordFareAttributes);
    RUN_SUITE(CGTFS_RecordFareRule);
    RUN_SUITE(CGTFS_RecordFeedInfo);
    RUN_SUITE(CGTFS_RecordFrequency);
    RUN_SUITE(CGTFS_RecordRoute);
    RUN_SUITE(CGTFS_RecordShape);
    RUN_SUITE(CGTFS_RecordStopTime);
    RUN_SUITE(CGTFS_RecordStop);
    RUN_SUITE(CGTFS_RecordTransfer);
    RUN_SUITE(CGTFS_RecordTrip);

    RUN_SUITE(CGTFS_FileReading);

    GREATEST_MAIN_END();
}

#endif