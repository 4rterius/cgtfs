#ifndef CGTFS_TESTS__ALL_C
#define CGTFS_TESTS__ALL_C

#include "greatest/greatest.h"

#include "tests-feed.c"

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();

    RUN_SUITE(CGTFS_Feed);

    GREATEST_MAIN_END();
}

#endif