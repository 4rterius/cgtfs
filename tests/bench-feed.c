#ifndef CGTFS_BENCH_FEED_C
#define CGTFS_BENCH_FEED_C

#include "_utils.c"
#include "feed.h"

void _bm_feed_1() {
    feed_t f;
    init_feed(&f);
    read_feed(&f, "../tests/data/google_sample");
    free_feed(&f);
}

void _bm_feed_2() {
    feed_t f;
    init_feed(&f);
    read_feed(&f, "../tests/data/pocono_pony");
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

void bench_feed_2(void) {
    bm_results_t res = bm_init_results();
    
    bm_run_1(&res, _bm_feed_2);
    bm_run_10(&res, _bm_feed_2);
    // bm_run_100(&res, _bm_feed_2);
    // bm_run_1000(&res, _bm_feed_2);

    bm_display_results(&res, "Pocono Pony feed parsing");
}

#endif