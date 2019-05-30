#ifndef CGTFS_TESTS_DATABASE_FETCHING_C
#define CGTFS_TESTS_DATABASE_FETCHING_C

#include "greatest/greatest.h"

#include "reading.h"
#include "database/fetching.h"


/** 
 * IMPORTANT: CGTFS_DatabaseStoring suite MUST be run first...
 * This suite checks that the previous suite did everything correctly...
 */
TEST db_all_agencies_fetch(void) {

    FILE *fp = fopen("../tests/data/stupid_gtfs/agency.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/agency.txt` test file");
    } else {
        agency_t *expected;
        int expected_count = read_all_agencies(fp, &expected);

        ASSERT_EQ_FMT(4, expected_count, "%i");


        feed_db_t db;
        agency_t *records;

        init_feed_db(&db, "tests_storing.db", 1);
        setup_feed_db(&db, 1);

        int retrieved_count = fetch_all_agencies_db(&db, &records);
        
        ASSERT_EQ_FMT(expected_count, retrieved_count, "%i");
        for (int i = 0; i < retrieved_count; i++)
            ASSERT(!equal_agency(&(expected[i]), &(records[i])));


        free_feed_db(&db);
        if (retrieved_count > 0) free(records);
        if (expected_count > 0) free(expected);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_calendar_dates_fetch(void) {

    FILE *fp = fopen("../tests/data/stupid_gtfs/calendar_dates.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/calendar_dates.txt` test file");
    } else {
        calendar_date_t *expected;
        int expected_count = read_all_calendar_dates(fp, &expected);

        ASSERT_EQ_FMT(9, expected_count, "%i");


        feed_db_t db;
        calendar_date_t *records;

        init_feed_db(&db, "tests_storing.db", 1);
        setup_feed_db(&db, 1);

        int retrieved_count = fetch_all_calendar_dates_db(&db, &records);
        
        ASSERT_EQ_FMT(expected_count, retrieved_count, "%i");
        for (int i = 0; i < retrieved_count; i++)
            ASSERT(!equal_calendar_date(&(expected[i]), &(records[i])));


        free_feed_db(&db);
        if (retrieved_count > 0) free(records);
        if (expected_count > 0) free(expected);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_calendar_records_fetch(void) {

    FILE *fp = fopen("../tests/data/stupid_gtfs/calendar.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/calendar.txt` test file");
    } else {
        calendar_record_t *expected;
        int expected_count = read_all_calendar_records(fp, &expected);

        ASSERT_EQ_FMT(4, expected_count, "%i");


        feed_db_t db;
        calendar_record_t *records;

        init_feed_db(&db, "tests_storing.db", 1);
        setup_feed_db(&db, 1);

        int retrieved_count = fetch_all_calendar_records_db(&db, &records);
        
        ASSERT_EQ_FMT(expected_count, retrieved_count, "%i");
        for (int i = 0; i < retrieved_count; i++)
            ASSERT(!equal_calendar_record(&(expected[i]), &(records[i])));


        free_feed_db(&db);
        if (retrieved_count > 0) free(records);
        if (expected_count > 0) free(expected);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_fare_attributes_fetch(void) {

    FILE *fp = fopen("../tests/data/stupid_gtfs/fare_attributes.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/fare_attributes.txt` test file");
    } else {
        fare_attributes_t *expected;
        int expected_count = read_all_fare_attributes(fp, &expected);

        ASSERT_EQ_FMT(2, expected_count, "%i");


        feed_db_t db;
        fare_attributes_t *records;

        init_feed_db(&db, "tests_storing.db", 1);
        setup_feed_db(&db, 1);

        int retrieved_count = fetch_all_fare_attributes_db(&db, &records);
        
        ASSERT_EQ_FMT(expected_count, retrieved_count, "%i");
        for (int i = 0; i < retrieved_count; i++)
            ASSERT(!equal_fare_attributes(&(expected[i]), &(records[i])));


        free_feed_db(&db);
        if (retrieved_count > 0) free(records);
        if (expected_count > 0) free(expected);
        if (fp) fclose(fp);
    }
    PASS();
}


SUITE(CGTFS_DatabaseFetching) {
    RUN_TEST(db_all_agencies_fetch);
    RUN_TEST(db_all_calendar_dates_fetch);
    RUN_TEST(db_all_calendar_records_fetch);
    RUN_TEST(db_all_fare_attributes_fetch);
}

#endif