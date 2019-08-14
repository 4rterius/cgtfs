#ifndef CGTFS_TESTS_STR_UTILS_C
#define CGTFS_TESTS_STR_UTILS_C

#include "greatest/greatest.h"
#include "str_utils.h"


TEST str_utils_filename_no_ext(void) {
    char *got;

    got = get_filename_no_ext("hello", '/');
    ASSERT_STR_EQ("hello", got);
    free(got);

    got = get_filename_no_ext("hello.there", '/');
    ASSERT_STR_EQ("hello", got);
    free(got);

    got = get_filename_no_ext("/path/to/hello.there", '/');
    ASSERT_STR_EQ("hello", got);
    free(got);

    got = get_filename_no_ext("/pa.th/to/hello", '/');
    ASSERT_STR_EQ("hello", got);
    free(got);

    got = get_filename_no_ext("/pa.th/to/hello.there", '/');
    ASSERT_STR_EQ("hello", got);
    free(got);

    got = get_filename_no_ext("/pa.th/to/hello.the.re", '/');
    ASSERT_STR_EQ("hello.the", got);
    free(got);



    got = get_filename_no_ext("hello", '\\');
    ASSERT_STR_EQ("hello", got);
    free(got);

    got = get_filename_no_ext("hello.there", '\\');
    ASSERT_STR_EQ("hello", got);
    free(got);

    got = get_filename_no_ext("C:\\path\\to\\hello.there", '\\');
    ASSERT_STR_EQ("hello", got);
    free(got);

    got = get_filename_no_ext("D:\\pa.th\\to\\hello", '\\');
    ASSERT_STR_EQ("hello", got);
    free(got);

    got = get_filename_no_ext("E:\\pa.th\\to\\hello.there", '\\');
    ASSERT_STR_EQ("hello", got);
    free(got);

    got = get_filename_no_ext("F:\\pa.th\\to\\hello.the.re", '\\');
    ASSERT_STR_EQ("hello.the", got);
    free(got);

    PASS();
}


SUITE(CGTFS_StrUtils) {
    RUN_TEST(str_utils_filename_no_ext);
}

#endif