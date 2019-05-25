#ifndef CGTFS_TESTS_DATABASE_C
#define CGTFS_TESTS_DATABASE_C

#include "greatest/greatest.h"
#include "database/database.h"

TEST db_init_close_writable(void) {
    feed_db_t db;
    feed_db_status_t res;

    res = init_feed_db(&db, "tests_db_init_0.db", 1);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    res = setup_feed_db(&db, 1);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    res = free_feed_db(&db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    PASS();
}

TEST db_init_close_readable_error(void) {
    feed_db_t db;
    feed_db_status_t res;

    res = init_feed_db(&db, "tests_db_init_1.db", 0);
    ASSERT_EQ_FMT(FEED_DB_ERROR, res, "%i");

    res = free_feed_db(&db);
    ASSERT_EQ_FMT(FEED_DB_SUCCESS, res, "%i");

    PASS();
}

TEST db_init_close_readable_success(void) {

    // Preparation
    feed_db_t _db;
    ASSERT_EQ(FEED_DB_SUCCESS, init_feed_db(&_db, "tests_db_init_2.db", 1));
    ASSERT_EQ(FEED_DB_SUCCESS, setup_feed_db(&_db, 1));
    ASSERT_EQ(FEED_DB_SUCCESS, free_feed_db(&_db));
    // End

    feed_db_t db;
    feed_db_status_t res;

    res = init_feed_db(&db, "tests_db_init_2.db", 0);
    ASSERT_EQ_FMT(FEED_DB_SUCCESS, res, "%i");

    res = free_feed_db(&db);
    ASSERT_EQ_FMT(FEED_DB_SUCCESS, res, "%i");

    PASS();
}

SUITE(CGTFS_Database) {
    RUN_TEST(db_init_close_writable);
    RUN_TEST(db_init_close_readable_error);
    RUN_TEST(db_init_close_readable_success);
}


#endif