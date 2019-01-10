#ifndef CGTFS_BENCH_FEED_C
#define CGTFS_BENCH_FEED_C

#include "_utils.c"
#include "feed.h"

void _bm_feed_1() {
    feed_t f = empty_feed();
    read_feed("../tests/data/google_sample", &f);
    free_feed(&f);
}

void bench_feed_1(void) {
    bm_results_t res = bm_init_results();
    
    bm_run_1(&res, _bm_feed_1);
    bm_run_10(&res, _bm_feed_1);
    bm_run_100(&res, _bm_feed_1);
    bm_run_1000(&res, _bm_feed_1);

    bm_display_results(&res, "Google sample feed parsing");
}

#endif