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

TEST db_all_fare_rules_fetch(void) {

    FILE *fp = fopen("../tests/data/stupid_gtfs/fare_rules.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/fare_rules.txt` test file");
    } else {
        fare_rule_t *expected;
        int expected_count = read_all_fare_rules(fp, &expected);

        ASSERT_EQ_FMT(4, expected_count, "%i");


        feed_db_t db;
        fare_rule_t *records;

        init_feed_db(&db, "tests_storing.db", 1);
        setup_feed_db(&db, 1);

        int retrieved_count = fetch_all_fare_rules_db(&db, &records);
        
        ASSERT_EQ_FMT(expected_count, retrieved_count, "%i");
        for (int i = 0; i < retrieved_count; i++)
            ASSERT(!equal_fare_rule(&(expected[i]), &(records[i])));


        free_feed_db(&db);
        if (retrieved_count > 0) free(records);
        if (expected_count > 0) free(expected);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_feed_info_fetch(void) {

    FILE *fp = fopen("../tests/data/stupid_gtfs/feed_info.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/feed_info.txt` test file");
    } else {
        feed_info_t *expected;
        int expected_count = read_all_feed_info(fp, &expected);

        ASSERT_EQ_FMT(1, expected_count, "%i");


        feed_db_t db;
        feed_info_t *records;

        init_feed_db(&db, "tests_storing.db", 1);
        setup_feed_db(&db, 1);

        int retrieved_count = fetch_all_feed_info_db(&db, &records);
        
        ASSERT_EQ_FMT(expected_count, retrieved_count, "%i");
        for (int i = 0; i < retrieved_count; i++)
            ASSERT(!equal_feed_info(&(expected[i]), &(records[i])));


        free_feed_db(&db);
        if (retrieved_count > 0) free(records);
        if (expected_count > 0) free(expected);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_frequencies_fetch(void) {

    FILE *fp = fopen("../tests/data/stupid_gtfs/frequencies.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/stupid_gtfs/frequencies.txt` test file");
    } else {
        frequency_t *expected;
        int expected_count = read_all_frequencies(fp, &expected);

        ASSERT_EQ_FMT(11, expected_count, "%i");


        feed_db_t db;
        frequency_t *records;

        init_feed_db(&db, "tests_storing.db", 1);
        setup_feed_db(&db, 1);

        int retrieved_count = fetch_all_frequencies_db(&db, &records);
        
        ASSERT_EQ_FMT(expected_count, retrieved_count, "%i");
        for (int i = 0; i < retrieved_count; i++)
            ASSERT(!equal_frequency(&(expected[i]), &(records[i])));


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
    RUN_TEST(db_all_fare_rules_fetch);
    RUN_TEST(db_all_feed_info_fetch);
    RUN_TEST(db_all_frequencies_fetch);
}

#endif