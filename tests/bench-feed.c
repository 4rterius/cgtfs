#ifndef CGTFS_BENCH_FEED_C
#define CGTFS_BENCH_FEED_C

#define CGTFS_STORING_BATCH_TRANSACTIONS_OFF

#include "_utils.c"
#include "feed.h"
#include "database/database.h"

int _bm_db_1_run = 0;

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

void _bm_db_1() {
    feed_db_t db;
    feed_db_status_t res;

    char db_name[26];

    snprintf(db_name, 26, "tests_bench_db_%i.db", _bm_db_1_run++);
    
    res = init_feed_db(&db, db_name, 1);
    if (res != FEED_DB_SUCCESS)
        perror("BENCHMARK #3 failed @ init\n");

    res = setup_feed_db(&db, 1);
    if (res != FEED_DB_SUCCESS)
        perror("BENCHMARK #3 failed @ setup\n");

    res = store_feed_db("../tests/data/stupid_gtfs", &db);  // ../tests/data/stupid_gtfs
    if (res != FEED_DB_SUCCESS)
        perror("BENCHMARK #3 failed @ store\n");

    free_feed_db(&db);
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

void bench_db_1(void) {
    bm_results_t res = bm_init_results();
    
    bm_run_1(&res, _bm_db_1);
    bm_run_10(&res, _bm_db_1);
    // bm_run_100(&res, _bm_db_1);
    // bm_run_1000(&res, _bm_feed_2);

    bm_display_results(&res, "StupidGTFS feed dir -> db parsing");
}

#endif