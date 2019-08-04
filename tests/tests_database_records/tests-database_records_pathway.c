#ifndef CGTFS_TESTS_DATABASE_RECORDS_PATHWAY_C
#define CGTFS_TESTS_DATABASE_RECORDS_PATHWAY_C

#include "greatest/greatest.h"
#include "database/records/pathway.h"

TEST db_pathway_store(void) {
    feed_db_t db;
    feed_db_status_t res;

    pathway_t record = {
        .id = "INDEX456_abc",
        .from_stop_id = "STOP_ID1",
        .to_stop_id = "STOP_ID2",
        .mode = PTMD_MOVING,
        .is_bidirectional = PD_BIDIRECTIONAL,
        .length = 123.4,
        .traversal_time = 3600,
        .stair_count = 12,
        .max_slope = -1.008,
        .min_width = 2.3,
        .signposted_as = "Something A",
        .reversed_signposted_as = "Something B"
    };

    if (FEED_DB_SUCCESS != init_feed_db(&db, "tests_tdw0.db", 1))
        FAILm(db.error_msg);

    setup_feed_db(&db);

    res = store_pathway_db(&record, &db);
    ASSERT_EQ_FMTm(db.error_msg, FEED_DB_SUCCESS, res, "%i");


    if (FEED_DB_SUCCESS != free_feed_db(&db))
        FAILm("Failed to free a feed_db_t instance");

    PASS();
}

SUITE(CGTFS_DatabasePathway) {
    RUN_TEST(db_pathway_store);
}


#endif