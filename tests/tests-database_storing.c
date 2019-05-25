#ifndef CGTFS_TESTS_DATABASE_STORING_C
#define CGTFS_TESTS_DATABASE_STORING_C

#include "greatest/greatest.h"
#include "database/storing.h"
#include "reading.h"

TEST db_all_agencies_store(void) {
    FILE *fp = fopen("../tests/data/google_sample/agency.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/google_sample/agency.txt` test file");
    } else {
        
        feed_db_t db;
        feed_db_status_t res;

        agency_t *records;

        ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, init_feed_db(&db, "tests_store_agencies0.db", 1), "%i");
        ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, setup_feed_db(&db, 1), "%i");

        int stored_count = store_all_agencies_db(fp, &db);

        /**
         * Replace this code with fetch_all_agencies_db(&db, &records)
         * when it's coded...
        
        rewind(fp);
        int record_count = read_all_agencies(fp, &records);

        agency_t expected[1] = {
            {
                .id = "DTA",
                .name = "Demo Transit Authority",
                .url = "http://google.com",
                .timezone = "America/Los_Angeles"
            }
        };

        ASSERT_EQ(1, record_count);
        ASSERT(!equal_agency(&(expected[0]), &(records[0])));
        if (record_count > 0) free(records);
         */

        ASSERT_EQ(1, stored_count);

        ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, free_feed_db(&db), "%i");
        if (fp) fclose(fp);
    }
    PASS();
}

SUITE(CGTFS_DatabaseStoring) {
    RUN_TEST(db_all_agencies_store);
}

#endif