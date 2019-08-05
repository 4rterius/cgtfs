#ifndef CGTFS_TESTS_FILENAMES_C
#define CGTFS_TESTS_FILENAMES_C

#include "greatest/greatest.h"
#include "helpers/filenames.h"


static char *filename = "some.file";

#ifdef _WIN32
    static char *dirname_noslash = "D:\\some\\folder";
    static char *dirname_slash = "D:\\some\\folder\\";
    static char *expected = "D:\\some\\folder\\some.file";
#else
    static char *dirname_noslash = "/some/folder";
    static char *dirname_slash = "/some/folder/";
    static char *expected = "/some/folder/some.file";
#endif


TEST filenames_no_trailing_slash(void) {
    char *filepath;
    make_filepath(&filepath, dirname_noslash, filename);
    ASSERT_STR_EQ(expected, filepath);
    if (filepath)
        free(filepath);
    PASS();
}

TEST filenames_with_trailing_slash(void) {
    char *filepath;
    make_filepath(&filepath, dirname_slash, filename);
    ASSERT_STR_EQ(expected, filepath);
    if (filepath)
        free(filepath);
    PASS();
}

TEST filenames_passed_null(void) {
    char *filepath;
    char *filepath2;

    make_filepath(&filepath, NULL, "");
    make_filepath(&filepath2, "", NULL);

    ASSERT_FALSE(filepath);
    ASSERT_FALSE(filepath2);

    if (filepath)
        free(filepath);

    if (filepath2)
        free(filepath2);

    PASS();
}



SUITE(CGTFS_Filenames) {
    RUN_TEST(filenames_no_trailing_slash);
    RUN_TEST(filenames_with_trailing_slash);
    RUN_TEST(filenames_passed_null);
}

#endif