#ifndef CGTFS_TESTS_DATABASE_C
#define CGTFS_TESTS_DATABASE_C

#include "greatest/greatest.h"
#include "database/database.h"

TEST db_init_close_writable(void) {
    feed_db_t db;
    feed_db_status_t res;

    res = init_feed_db(&db, "tests_db_init_0.db", 1);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    res = setup_feed_db(&db);
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
    ASSERT_EQ(FEED_DB_SUCCESS, setup_feed_db(&_db));
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

TEST db_import(void) {
    feed_db_t db;
    feed_db_status_t res;

    res = init_feed_db(&db, "tests_feed_import.db", 1);
    res = import_feed_db("../tests/data/stupid_gtfs", &db);

    res = import_csv_file_db("../tests/data/stupid_gtfs/stop_times.txt", "stop_times", &db);

    ASSERT_EQm(db.error_msg, FEED_DB_SUCCESS, res);

    free_feed_db(&db);
    PASS();
}

TEST db_store_no_counter(void) {

    feed_db_t db;
    feed_db_status_t res;

    res = init_feed_db(&db, "tests_feed_1_no_counter.db", 1);
    if (res != FEED_DB_SUCCESS)
        FAILm("Failed to initialize a database `tests_feed_1_no_counter.db` (writable)");

    res = setup_feed_db(&db);
    if (res != FEED_DB_SUCCESS)
        FAILm("Failed to create a table layout at `tests_feed_1_no_counter.db` (writable)");

    res = store_feed_db("../tests/data/stupid_gtfs", &db, NULL);

    ASSERT_EQ(FEED_DB_SUCCESS, res);

    free_feed_db(&db);
    PASS();
}

TEST db_store_partial(void) {

    feed_db_t db;
    feed_db_status_t res;

    res = init_feed_db(&db, "tests_feed_3_partial.db", 1);
    if (res != FEED_DB_SUCCESS)
        FAILm("Failed to initialize a database `tests_feed_3_partial.db` (writable)");

    res = setup_feed_db(&db);
    if (res != FEED_DB_SUCCESS)
        FAILm("Failed to create a table layout at `tests_feed_3_partial.db` (writable)");

    res = store_feed_db("../tests/data/google_sample", &db, NULL);

    ASSERT_EQ(FEED_DB_PARTIAL, res);

    free_feed_db(&db);
    PASS();
}

TEST db_store_counter(void) {

    feed_db_t db;
    feed_db_status_t res;

    feed_t counter;

    res = init_feed_db(&db, "tests_feed_2_counter.db", 1);
    if (res != FEED_DB_SUCCESS)
        FAILm("Failed to initialize a database `tests_feed_2_counter.db` (writable)");

    res = setup_feed_db(&db);
    if (res != FEED_DB_SUCCESS)
        FAILm("Failed to create a table layout at `tests_feed_2_counter.db` (writable)");

    res = store_feed_db("../tests/data/stupid_gtfs", &db, &counter);

    ASSERT_EQ(FEED_DB_SUCCESS, res);
    ASSERT_EQ_FMT(4, counter.agency_count, "%i");
    ASSERT_EQ_FMT(4, counter.calendar_records_count, "%i");
    ASSERT_EQ_FMT(9, counter.calendar_dates_count, "%i");
    ASSERT_EQ_FMT(2, counter.fare_attributes_count, "%i");
    ASSERT_EQ_FMT(4, counter.fare_rules_count, "%i");
    ASSERT_EQ_FMT(1, counter.feed_info_count, "%i");
    ASSERT_EQ_FMT(11, counter.frequencies_count, "%i");
    ASSERT_EQ_FMT(4, counter.levels_count, "%i");
    ASSERT_EQ_FMT(2, counter.pathways_count, "%i");
    ASSERT_EQ_FMT(8, counter.routes_count, "%i");
    ASSERT_EQ_FMT(10, counter.shapes_count, "%i");
    ASSERT_EQ_FMT(28, counter.stop_times_count, "%i");
    ASSERT_EQ_FMT(6, counter.stops_count, "%i");
    ASSERT_EQ_FMT(4, counter.transfers_count, "%i");
    ASSERT_EQ_FMT(4, counter.trips_count, "%i");

    free_feed_db(&db);
    PASS();
}

TEST db_fetch(void) {

    feed_t feed;
    feed_db_t db;
    feed_db_status_t res;

    init_feed(&feed);

    res = init_feed_db(&db, "tests_feed_2_counter.db", 0);
    if (res != FEED_DB_SUCCESS)
        FAILm("Failed to initialize a database `tests_feed_2_counter.db` (non-writable)");

    fetch_feed_db(&db, &feed);

    ASSERT_EQ_FMT(4, feed.agency_count, "%i");
    ASSERT_EQ_FMT(4, feed.calendar_records_count, "%i");
    ASSERT_EQ_FMT(9, feed.calendar_dates_count, "%i");
    ASSERT_EQ_FMT(2, feed.fare_attributes_count, "%i");
    ASSERT_EQ_FMT(4, feed.fare_rules_count, "%i");
    ASSERT_EQ_FMT(1, feed.feed_info_count, "%i");
    ASSERT_EQ_FMT(11, feed.frequencies_count, "%i");
    ASSERT_EQ_FMT(4, feed.levels_count, "%i");
    ASSERT_EQ_FMT(2, feed.pathways_count, "%i");
    ASSERT_EQ_FMT(8, feed.routes_count, "%i");
    ASSERT_EQ_FMT(10, feed.shapes_count, "%i");
    ASSERT_EQ_FMT(28, feed.stop_times_count, "%i");
    ASSERT_EQ_FMT(6, feed.stops_count, "%i");
    ASSERT_EQ_FMT(4, feed.transfers_count, "%i");
    ASSERT_EQ_FMT(4, feed.trips_count, "%i");

    free_feed_db(&db);
    free_feed(&feed);

    PASS();
}


SUITE(CGTFS_Database) {
    RUN_TEST(db_init_close_writable);
    RUN_TEST(db_init_close_readable_error);
    RUN_TEST(db_init_close_readable_success);
    RUN_TEST(db_import);
    RUN_TEST(db_store_no_counter);
    RUN_TEST(db_store_partial);
    RUN_TEST(db_store_counter); // These two tests must come together AND in this order
    RUN_TEST(db_fetch);         // as db_fetch() uses the db file created by db_store_counter.
}


#endif