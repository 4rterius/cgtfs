#ifndef CGTFS_TESTS_DATABASE_RECORDS_FEED_INFO_C
#define CGTFS_TESTS_DATABASE_RECORDS_FEED_INFO_C

#include "greatest/greatest.h"
#include "database/records/feed_info.h"

TEST db_feed_info_store(void) {
    feed_db_t db;
    feed_db_status_t res;

    feed_info_t record = {
        .feed_publisher_name = "monroe-pa-us",
        .feed_publisher_url = "http://www.gomcta.com",
        .feed_lang = "en",
        .feed_start_date = "20190120",
        .feed_end_date = "20190629",
        .feed_version = "20190111",
        .feed_contact_email = "some@ema.il",
        .feed_contact_url = "http://some.url"
    };

    init_feed_db(&db, "tests_tdw0.db", 1);
    setup_feed_db(&db, 1);

    res = store_feed_info_db(&record, &db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    free_feed_db(&db);

    PASS();
}

SUITE(CGTFS_DatabaseFeedInfo) {
    RUN_TEST(db_feed_info_store);
}


#endif