#ifndef CGTFS_TESTS_DATABASE_STORING_C
#define CGTFS_TESTS_DATABASE_STORING_C

#include "greatest/greatest.h"
#include "database/storing.h"


TEST db_all_agencies_store(void) {
    FILE *fp = fopen("../tests/data/agency.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/agency.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_store_agencies0.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_agencies_db(fp, &db);
        ASSERT_EQ(4, stored_count);

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_calendar_dates_store(void) {
    FILE *fp = fopen("../tests/data/pocono_pony/calendar_dates.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/pocono_pony/calendar_dates.txt` test file");
    } else {
        
        feed_db_t db;
        // feed_db_status_t res;

        /* res = */ init_feed_db(&db, "tests_store_agencies0.db", 1);
        /* res = */ setup_feed_db(&db, 1);

        int stored_count = store_all_calendar_dates_db(fp, &db);
        ASSERT_EQ_FMT(138, stored_count, "%i");

        free_feed_db(&db);
        if (fp) fclose(fp);
    }
    PASS();
}

SUITE(CGTFS_DatabaseStoring) {
    RUN_TEST(db_all_agencies_store);
    RUN_TEST(db_all_calendar_dates_store);
}

#endif