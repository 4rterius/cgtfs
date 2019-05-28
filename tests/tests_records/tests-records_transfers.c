#ifndef CGTFS_TESTS_RECORDS_TRANSFERS_C
#define CGTFS_TESTS_RECORDS_TRANSFERS_C

#include "greatest/greatest.h"
#include "records/transfers.h"

TEST transfer_read(void) {
        
    #define FIELDS_NUM_12 4
    char *field_names[FIELDS_NUM_12] = {
        "from_stop_id", "to_stop_id", "transfer_type", "min_transfer_time"
    };
    char *field_values[FIELDS_NUM_12] = {
        "S180", "R360", "2", "120"
    };

    transfer_t t_1;
    read_transfer(&t_1, FIELDS_NUM_12, (const char **)field_names, (const char **)field_values);
    
    ASSERT_STR_EQ("S180", t_1.from_stop_id);
    ASSERT_STR_EQ("R360", t_1.to_stop_id);
    ASSERT_EQ(TT_TIME_REQUIRED, t_1.transfer_type);
    ASSERT_EQ(120, t_1.min_transfer_time);

    PASS();
}

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
    RUN_TEST(transfer_read);
    RUN_TEST(transfer_compare);
}

#endif