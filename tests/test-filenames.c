#ifndef CGTFS_TESTS_FILENAMES_C
#define CGTFS_TESTS_FILENAMES_C

#include "filenames.h"

int test_filenames_no_endslash(void) {

    #ifdef _WIN32
        char *dirname = "D:\\some\\folder";
        char *filename = "some.file";
        char *expected = "D:\\some\\folder\\some.file";
    #else
        char *dirname = "/some/folder";
        char *filename = "some.file";
        char *expected = "/some/folder/some.file";
    #endif

    char *filepath;
    make_filepath(&filepath, dirname, filename);

    if (strcmp(filepath, expected) != 0) {
        printf("Failed to concatenate directory %s with filename %s:\n   %s", dirname, filename, filepath);
    }

    free(filepath);
}

int test_filenames_with_endslash(void) {

    #ifdef _WIN32
        char *dirname = "D:\\some\\folder\\";
        char *filename = "some.file";
        char *expected = "D:\\some\\folder\\some.file";
    #else
        char *dirname = "/some/folder/";
        char *filename = "some.file";
        char *expected = "/some/folder/some.file";
    #endif

    char *filepath;
    make_filepath(&filepath, dirname, filename);

    if (strcmp(filepath, expected) != 0) {
        printf("Failed to concatenate directory %s with filename %s:\n   %s", dirname, filename, filepath);
    }

    free(filepath);
}

#endif