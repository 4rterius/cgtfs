#ifndef CGTFS_TESTS__ALL_C
#define CGTFS_TESTS__ALL_C

#include "test-haversine.c"

int main(int argc, char **argv) {
    test_haversine_correct();
    return 0;
}

#endif
