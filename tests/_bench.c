#ifndef CGTFS_TESTS__BENCH_C
#define CGTFS_TESTS__BENCH_C

#include "bench-feed.c"

int main(int argc, char **argv) {
    bench_feed_2();
    bench_db_1();
    return 0;
}

#endif