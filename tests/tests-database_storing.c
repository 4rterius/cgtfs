#ifndef CGTFS_TESTS_DATABASE_STORING_C
#define CGTFS_TESTS_DATABASE_STORING_C

#include "greatest/greatest.h"
#include "database/storing.h"
#include "database/fetching.h"
#include "reading.h"

TEST db_all_agencies_store(void) {
    FILE *fp = fopen("../tests/data/agency.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/agency.txt` test file");
    } else {
        
        feed_db_t db;
        feed_db_status_t res;

        agency_t *records;

        ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, init_feed_db(&db, "tests_store_agencies0.db", 1), "%i");
        ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, setup_feed_db(&db, 1), "%i");

        int stored_count = store_all_agencies_db(fp, &db);
        ASSERT_EQ(4, stored_count);

        ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, free_feed_db(&db), "%i");
        if (fp) fclose(fp);
    }
    PASS();
}

TEST db_all_agencies_fetch(void) {

    feed_db_t db;
    feed_db_status_t res;

    agency_t *records;

    res = init_feed_db(&db, "tests_store_agencies0.db", 1);
    res = setup_feed_db(&db, 1);

    int retrieved_count = fetch_all_agencies_db(&db, &records);

    // printf("\n");
    // for (int i = 0; i < retrieved_count; i++) {
    //     printf("      agency #%i: {.id = %s, .name = %s}\n", i, records[i].id, records[i].name);
    // }

    agency_t expected[4] = {
        {
            .id = "1",
            .name = "Lahden Seudun Liikenne",
            .url = "http://www.lsl.fi",
            .timezone = "Europe/Helsinki",
            .lang = "fi",
            .phone = "03 814 2355"
        },
        {
            .id = "2",
            .name = "Jyväskylä",
            .url = "http://www.lsl.fi",
            .timezone = "blah, blah",
            .lang = "fi",
            .phone = "03 814 2355"
        },
        {
            .id = "3",
            .name = "",
            .url = "",
            .timezone = "",
            .lang = "",
            .phone = ""
        }
    };

    ASSERT_EQ_FMT(4, retrieved_count, "%i");
    ASSERT(!equal_agency(&(expected[0]), &(records[0])));
    ASSERT(!equal_agency(&(expected[1]), &(records[1])));
    ASSERT(!equal_agency(&(expected[2]), &(records[2])));
    // TODO: 4th assertion
    

    free_feed_db(&db);
    if (retrieved_count > 0) free(records);
    PASS();
}

SUITE(CGTFS_DatabaseStoring) {
    RUN_TEST(db_all_agencies_store);
    RUN_TEST(db_all_agencies_fetch);
}

#endif