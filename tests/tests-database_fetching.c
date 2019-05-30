#ifndef CGTFS_TESTS_DATABASE_FETCHING_C
#define CGTFS_TESTS_DATABASE_FETCHING_C

#include "greatest/greatest.h"
#include "database/fetching.h"


/** 
 * IMPORTANT: CGTFS_DatabaseStoring suite MUST be run first...
 * This suite checks that the previous suite did everything correctly...
 */
TEST db_all_agencies_fetch(void) {

    feed_db_t db;
    // feed_db_status_t res;

    agency_t *records;

    /* res = */ init_feed_db(&db, "tests_storing.db", 1);
    /* res = */ setup_feed_db(&db, 1);

    int retrieved_count = fetch_all_agencies_db(&db, &records);

    // printf("\nRetrieved: %i...\n", retrieved_count);
    // for (int i = 0; i < retrieved_count; i++) {
    //     printf("\n      agency #%i: {.id = %s, .name = %s}\n\n", i, records[i].id, records[i].name);
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
        },
        {
            .id = "4",
            .name = "\"djghas\"ldföäånkl´+123sd\"",
            .url = "http://www.lsl.fi",
            .timezone = "blah \"HELLO\" blah",
            .lang = "fi",
            .phone = "03 814 2355"
        }
    };

    ASSERT_EQ_FMT(4, retrieved_count, "%i");
    ASSERT(!equal_agency(&(expected[0]), &(records[0])));
    ASSERT(!equal_agency(&(expected[1]), &(records[1])));
    ASSERT(!equal_agency(&(expected[2]), &(records[2])));
    ASSERT(!equal_agency(&(expected[3]), &(records[3])));
    

    free_feed_db(&db);
    if (retrieved_count > 0) free(records);
    PASS();
}

SUITE(CGTFS_DatabaseFetching) {
    RUN_TEST(db_all_agencies_fetch);
}

#endif