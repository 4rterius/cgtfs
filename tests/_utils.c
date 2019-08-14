#ifndef CGTFS_TESTS__UTILS_C
#define CGTFS_TESTS__UTILS_C

#include <assert.h>
#include <time.h>
#include <stdio.h>


typedef struct {
    long long iter1;
    long long iter10;
    long long iter100;
    long long iter1000;
    long long iter10000;
    int run1;
    int run10;
    int run100;
    int run1000;
    int run10000;
} bm_results_t;

bm_results_t bm_init_results(void) {
    bm_results_t res;
    res.iter1 = 0;
    res.iter10 = 0;
    res.iter100 = 0;
    res.iter1000 = 0;
    res.iter10000 = 0;
    res.run1 = 0;
    res.run10 = 0;
    res.run100 = 0;
    res.run1000 = 0;
    res.run10000 = 0;
    return res;
}

long long bm_run_n(unsigned n, void (*test_fn)()) {
    struct timespec ts_begin;
    timespec_get(&ts_begin, TIME_UTC);

    for (unsigned i = 0; i < n; i++)
        test_fn();

    struct timespec ts_end;
    timespec_get(&ts_end, TIME_UTC);

    return (ts_end.tv_sec * 1000000000 + ts_end.tv_nsec) - (ts_begin.tv_sec * 1000000000 + ts_begin.tv_nsec);
}

void bm_run_1(bm_results_t *results, void (*test_fn)()) {
    results->run1 = 1;
    results->iter1 = bm_run_n(1, test_fn);
    return;
}

void bm_run_10(bm_results_t *results, void (*test_fn)()) {
    results->run10 = 1;
    results->iter10 = bm_run_n(10, test_fn);
    return;
}

void bm_run_100(bm_results_t *results, void (*test_fn)()) {
    results->run100 = 1;
    results->iter100 = bm_run_n(100, test_fn);
    return;
}

void bm_run_1000(bm_results_t *results, void (*test_fn)()) {
    results->run1000 = 1;
    results->iter1000 = bm_run_n(1000, test_fn);
    return;
}

void bm_run_10000(bm_results_t *results, void (*test_fn)()) {
    results->run10000 = 1;
    results->iter10000 = bm_run_n(10000, test_fn);
    return;
}

void bm_display_results(const bm_results_t *results, const char *msg) {
    printf("\n");
    printf("Benchmark results for %s:\n", msg);

    if (results->run1 > 0)
        printf(" -> 1        iteration:    %lli ns. / %i iter. => %Lf ms.\n", results->iter1, 1, (long double)results->iter1 / 1000000);

    if (results->run10 > 0)
        printf(" -> 10       iterations:   %lli ns. / %i iter. => %Lf ms.\n", results->iter10, 10, (long double)results->iter10 / 10 / 1000000);

    if (results->run100 > 0)
        printf(" -> 100      iterations:   %lli ns. / %i iter. => %Lf ms.\n", results->iter100, 100, (long double)results->iter100 / 100 / 1000000);

    if (results->run1000 > 0)
        printf(" -> 1000     iterations:   %lli ns. / %i iter. => %Lf ms.\n", results->iter1000, 1000, (long double)results->iter1000 / 1000 / 1000000);

    if (results->run10000 > 0)
        printf(" -> 10000     iterations:   %lli ns. / %i iter. => %Lf ms.\n", results->iter10000, 10000, (long double)results->iter10000 / 10000 / 1000000);

    printf("---------\n");
}

#endif
