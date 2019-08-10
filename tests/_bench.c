#ifndef CGTFS_TESTS__BENCH_C
#define CGTFS_TESTS__BENCH_C

#include "bench-feed.c"

int main(int argc, char **argv) {
    bench_feed_1();
    bench_db_1_semantic();
    return 0;
}

#endif