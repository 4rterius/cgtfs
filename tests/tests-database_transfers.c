#ifndef CGTFS_TESTS_DATABASE_RECORDS_TRANSFERS_C
#define CGTFS_TESTS_DATABASE_RECORDS_TRANSFERS_C

#include "greatest/greatest.h"
#include "database/records/transfers.h"

TEST db_transfer_store(void) {
    feed_db_t db;
    feed_db_status_t res;

    transfer_t record = {
        .from_stop_id = "stopid123",
        .to_stop_id = "stopid321",
        .transfer_type = TT_TIME_REQUIRED,
        .min_transfer_time = 10
    };

    init_feed_db(&db, "tests_tdw0.db", 1);
    setup_feed_db(&db, 1);

    res = store_transfer_db(&record, &db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");

    free_feed_db(&db);

    PASS();
}

SUITE(CGTFS_DatabaseTransfers) {
    RUN_TEST(db_transfer_store);
}


#endif