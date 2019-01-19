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

    ASSERT_EQ(0, equal_transfer(&a, &b));
    ASSERT_EQ(1, equal_transfer(&a, &c));
    ASSERT_EQ(1, equal_transfer(&b, &c));

    PASS();
}

SUITE(CGTFS_RecordTransfer) {
    RUN_TEST(transfer_compare);
}

#endif