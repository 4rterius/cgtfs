#ifndef CGTFS_TESTS__UTILS_C
#define CGTFS_TESTS__UTILS_C

#include <assert.h>
#include <time.h>
#include <stdio.h>

int in_i(int num, int lb, int rb) {
    assert(lb <= rb);
    if (num < lb) return -1;
    if (num > rb) return 1;
    return 0;
}

int in_f(float num, float lb, float rb) {
    assert(lb <= rb);
    if (num < lb) return -1;
    if (num > rb) return 1;
    return 0;
}

int in_ld(long double num, long double lb, long double rb) {
    assert(lb <= rb);
    if (num < lb) return -1;
    if (num > rb) return 1;
    return 0;
}


typedef struct {
    double iter1;
    double iter10;
    double iter100;
    double iter1000;
} bm_results_t;

bm_results_t bm_init_results(void) {
    bm_results_t res;
    res.iter1 = -1.0;
    res.iter10 = -1.0;
    res.iter100 = -1.0;
    res.iter1000 = -1.0;
    return res;
}

double bm_run_n(unsigned n, void (*test_fn)()) {
    clock_t bgn;
    bgn = clock();

    for (unsigned i = 0; i < n; i++)
        test_fn();

    return (clock() - bgn) / CLOCKS_PER_SEC;
}

void bm_run_1(bm_results_t *results, void (*test_fn)()) {
    results->iter1 = bm_run_n(1, test_fn);
    return;
}

void bm_run_10(bm_results_t *results, void (*test_fn)()) {
    results->iter10 = bm_run_n(10, test_fn);
    return;
}

void bm_run_100(bm_results_t *results, void (*test_fn)()) {
    results->iter100 = bm_run_n(100, test_fn);
    return;
}

void bm_run_1000(bm_results_t *results, void (*test_fn)()) {
    results->iter1000 = bm_run_n(1000, test_fn);
    return;
}

void bm_display_results(const bm_results_t *results, const char *msg) {
    printf("\n");
    printf("Benchmark results for %s:\n", msg);

    if (results->iter1 >= 0)
        printf(" -> 1     iteration:    %lf sec./iter.\n", results->iter1);

    if (results->iter10 >= 0)
        printf(" -> 10    iterations:   %lf sec./iter.\n", results->iter10 / (double)10);
    
    if (results->iter100 >= 0)
        printf(" -> 100   iterations:   %lf sec./iter.\n", results->iter100 / (double)100);

    if (results->iter1000 >= 0)    
        printf(" -> 1000  iterations:   %lf sec./iter.\n", results->iter1000 / (double)1000.0);

    printf("---------\n");
}

#endif
