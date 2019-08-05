#ifndef CGTFS_TESTS_RECORDS_PATHWAY_C
#define CGTFS_TESTS_RECORDS_PATHWAY_C

#include "greatest/greatest.h"
#include "records/level.h"
#include "records/pathway.h"

TEST pathway_read(void) {
    #define FIELDS_NUM_15 12
    char *field_names[FIELDS_NUM_15] = {
        "pathway_id", "from_stop_id", "to_stop_id", "pathway_mode", "is_bidirectional", "length",
        "traversal_time", "stair_count", "max_slope", "min_width", "signposted_as", "reversed_signposted_as"
    };
    char *field_values[FIELDS_NUM_15] = {
        "INDEX456_abc", "STOP_ID1", "STOP_ID2", "3", "1", "123.4",
        "3600", "12", "-1.008", "2.3", "Something A", "Something B"
    };

    pathway_t pw_1;
    read_pathway(&pw_1, FIELDS_NUM_15, (const char **)field_names, (const char **)field_values);

    ASSERT_STR_EQ("INDEX456_abc", pw_1.id);
    ASSERT_STR_EQ("STOP_ID1", pw_1.from_stop_id);
    ASSERT_STR_EQ("STOP_ID2", pw_1.to_stop_id);
    ASSERT_EQ(PTMD_MOVING, pw_1.mode);
    ASSERT_EQ(PD_BIDIRECTIONAL, pw_1.is_bidirectional);
    ASSERT_EQ(123.4, pw_1.length);
    ASSERT_EQ(3600, pw_1.traversal_time);
    ASSERT_EQ(12, pw_1.stair_count);
    ASSERT_EQ(-1.008, pw_1.max_slope);
    ASSERT_EQ(2.3, pw_1.min_width);
    ASSERT_STR_EQ("Something A", pw_1.signposted_as);
    ASSERT_STR_EQ("Something B", pw_1.reversed_signposted_as);

    PASS();
}

TEST pathway_compare(void) {
    pathway_t a = {
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

    pathway_t b = {
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

    pathway_t c = {
        .id = "INDEX457_abc",
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

    pathway_t d = {
        .id = "INDEX456_abc",
        .from_stop_id = "STOP_ID",
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

    pathway_t e = {
        .id = "INDEX456_abc",
        .from_stop_id = "STOP_ID1",
        .to_stop_id = "STOP_ID23",
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

    pathway_t f = {
        .id = "INDEX456_abc",
        .from_stop_id = "STOP_ID1",
        .to_stop_id = "STOP_ID2",
        .mode = PTMD_EXITGATE,
        .is_bidirectional = PD_BIDIRECTIONAL,
        .length = 123.4,
        .traversal_time = 3600,
        .stair_count = 12,
        .max_slope = -1.008,
        .min_width = 2.3,
        .signposted_as = "Something A",
        .reversed_signposted_as = "Something B"
    };

    pathway_t g = {
        .id = "INDEX456_abc",
        .from_stop_id = "STOP_ID1",
        .to_stop_id = "STOP_ID2",
        .mode = PTMD_MOVING,
        .is_bidirectional = PD_UNIDIRECTIONAL,
        .length = 123.4,
        .traversal_time = 3600,
        .stair_count = 12,
        .max_slope = -1.008,
        .min_width = 2.3,
        .signposted_as = "Something A",
        .reversed_signposted_as = "Something B"
    };

    pathway_t h = {
        .id = "INDEX456_abc",
        .from_stop_id = "STOP_ID1",
        .to_stop_id = "STOP_ID2",
        .mode = PTMD_MOVING,
        .is_bidirectional = PD_BIDIRECTIONAL,
        .length = 123.0,
        .traversal_time = 3600,
        .stair_count = 12,
        .max_slope = -1.008,
        .min_width = 2.3,
        .signposted_as = "Something A",
        .reversed_signposted_as = "Something B"
    };

    pathway_t i = {
        .id = "INDEX456_abc",
        .from_stop_id = "STOP_ID1",
        .to_stop_id = "STOP_ID2",
        .mode = PTMD_MOVING,
        .is_bidirectional = PD_BIDIRECTIONAL,
        .length = 123.4,
        .traversal_time = 0,
        .stair_count = 12,
        .max_slope = -1.008,
        .min_width = 2.3,
        .signposted_as = "Something A",
        .reversed_signposted_as = "Something B"
    };

    pathway_t j = {
        .id = "INDEX456_abc",
        .from_stop_id = "STOP_ID1",
        .to_stop_id = "STOP_ID2",
        .mode = PTMD_MOVING,
        .is_bidirectional = PD_BIDIRECTIONAL,
        .length = 123.4,
        .traversal_time = 3600,
        .stair_count = 1,
        .max_slope = -1.008,
        .min_width = 2.3,
        .signposted_as = "Something A",
        .reversed_signposted_as = "Something B"
    };

    pathway_t k = {
        .id = "INDEX456_abc",
        .from_stop_id = "STOP_ID1",
        .to_stop_id = "STOP_ID2",
        .mode = PTMD_MOVING,
        .is_bidirectional = PD_BIDIRECTIONAL,
        .length = 123.4,
        .traversal_time = 3600,
        .stair_count = 12,
        .max_slope = -1,
        .min_width = 2.3,
        .signposted_as = "Something A",
        .reversed_signposted_as = "Something B"
    };

    pathway_t l = {
        .id = "INDEX456_abc",
        .from_stop_id = "STOP_ID1",
        .to_stop_id = "STOP_ID2",
        .mode = PTMD_MOVING,
        .is_bidirectional = PD_BIDIRECTIONAL,
        .length = 123.4,
        .traversal_time = 3600,
        .stair_count = 12,
        .max_slope = -1.008,
        .min_width = 0.4,
        .signposted_as = "Something A",
        .reversed_signposted_as = "Something B"
    };

    pathway_t m = {
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
        .signposted_as = "Something XY",
        .reversed_signposted_as = "Something B"
    };

    pathway_t n = {
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
        .reversed_signposted_as = "Something YZ"
    };

    ASSERT_EQ(1, equal_pathway(&a, &b));
    ASSERT_EQ(0, equal_pathway(&a, &c));
    ASSERT_EQ(0, equal_pathway(&b, &c));
    ASSERT_EQ(0, equal_pathway(&b, &d));
    ASSERT_EQ(0, equal_pathway(&b, &e));
    ASSERT_EQ(0, equal_pathway(&b, &f));
    ASSERT_EQ(0, equal_pathway(&b, &g));
    ASSERT_EQ(0, equal_pathway(&b, &h));
    ASSERT_EQ(0, equal_pathway(&b, &i));
    ASSERT_EQ(0, equal_pathway(&b, &j));
    ASSERT_EQ(0, equal_pathway(&b, &k));
    ASSERT_EQ(0, equal_pathway(&b, &l));
    ASSERT_EQ(0, equal_pathway(&b, &m));
    ASSERT_EQ(0, equal_pathway(&b, &n));

    PASS();
}

SUITE(CGTFS_RecordPathway) {
    RUN_TEST(pathway_read);
    RUN_TEST(pathway_compare);
}

#endif