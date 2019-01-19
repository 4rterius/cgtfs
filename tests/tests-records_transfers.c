#ifndef CGTFS_TESTS_RECORDS_TRANSFERS_C
#define CGTFS_TESTS_RECORDS_TRANSFERS_C

#include "greatest/greatest.h"
#include "records/transfers.h"

TEST transfer_compare(void) {
    transfer_t a = {
        .from_stop_id = "0STP8",
        .to_stop_id = "7STP9",
        .transfer_type = TT_TIMED,
        .min_transfer_time = 800
    };

    transfer_t b = {
        .from_stop_id = "0STP8",
        .to_stop_id = "7STP9",
        .transfer_type = TT_TIMED,
        .min_transfer_time = 800
    };

    transfer_t c = {
        .from_stop_id = "0STP8",
        .to_stop_id = "7STP9",
        .transfer_type = TT_TIME_REQUIRED,
        .min_transfer_time = 800
    };

    ASSERT_EQ(equal_transfer(&a, &b), 0);
    ASSERT_EQ(equal_transfer(&a, &c), 1);
    ASSERT_EQ(equal_transfer(&b, &c), 1);

    PASS();
}

SUITE(CGTFS_RecordTransfer) {
    RUN_TEST(transfer_compare);
}

#endif