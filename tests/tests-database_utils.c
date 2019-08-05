#ifndef CGTFS_TESTS_DATABASE_UTILS_C
#define CGTFS_TESTS_DATABASE_UTILS_C

#include "greatest/greatest.h"
#include "database/database_utils.h"

TEST db_count_rows_success(void) {

    feed_db_t db;
    // feed_db_status_t res;

    /* res = */ init_feed_db(&db, "../tests/db/count_rows.db", 1);

    ASSERT_EQ_FMT(6, count_rows_db(&db, "some_table"), "%i");
    ASSERT_EQ_FMT(4, count_rows_db(&db, "other_table"), "%i");

    free_feed_db(&db);
    PASS();
}

TEST db_count_rows_error_bad_table(void) {

    feed_db_t db;
    // feed_db_status_t res;

    /* res = */ init_feed_db(&db, "../tests/db/count_rows.db", 1);

    ASSERT_EQ_FMT(-1, count_rows_db(&db, "bad_table"), "%i");

    free_feed_db(&db);
    PASS();
}

SUITE(CGTFS_DatabaseUtils) {
    RUN_TEST(db_count_rows_success);
    RUN_TEST(db_count_rows_error_bad_table);
}

#endif