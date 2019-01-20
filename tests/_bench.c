#ifndef CGTFS_TESTS__BENCH_C
#define CGTFS_TESTS__BENCH_C

#include "bench-feed.c"

int main(int argc, char **argv) {
    bench_feed_1();
    bench_feed_2();
    return 0;
}

#endif