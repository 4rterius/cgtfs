#ifndef CGTFS_TESTS__UTILS_C
#define CGTFS_TESTS__UTILS_C

#include <assert.h>
#include <time.h>
#include <stdio.h>


typedef struct {
    long double iter1;
    long double iter10;
    long double iter100;
    long double iter1000;
    long double iter10000;
    long double iter100000;
    long double iter1000000;
} bm_results_t;

bm_results_t bm_init_results(void) {
    bm_results_t res;
    res.iter1 = -1.0;
    res.iter10 = -1.0;
    res.iter100 = -1.0;
    res.iter1000 = -1.0;
    res.iter10000 = -1.0;
    res.iter100000 = -1.0;
    res.iter1000000 = -1.0;
    return res;
}

long double bm_run_n(unsigned n, void (*test_fn)()) {
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

void bm_run_10000(bm_results_t *results, void (*test_fn)()) {
    results->iter10000 = bm_run_n(10000, test_fn);
    return;
}

void bm_run_100000(bm_results_t *results, void (*test_fn)()) {
    results->iter100000 = bm_run_n(100000, test_fn);
    return;
}

void bm_run_1000000(bm_results_t *results, void (*test_fn)()) {
    results->iter1000000 = bm_run_n(1000000, test_fn);
    return;
}

void bm_display_results(const bm_results_t *results, const char *msg) {
    printf("\n");
    printf("Benchmark results for %s:\n", msg);

    if (results->iter1 >= 0)
        printf(" -> 1        iteration:    %Lf sec. / %i iter. = %Lf\n", results->iter1, 1, results->iter1);

    if (results->iter10 >= 0)
        printf(" -> 10       iterations:   %Lf sec. / %i iter. = %Lf\n", results->iter10, 10, results->iter10 / (long double)10);
    
    if (results->iter100 >= 0)
        printf(" -> 100      iterations:   %Lf sec. / %i iter. = %Lf\n", results->iter100, 100, results->iter100 / (long double)100);

    if (results->iter1000 >= 0)    
        printf(" -> 1000     iterations:   %Lf sec. / %i iter. = %Lf\n", results->iter1000, 1000, results->iter1000 / (long double)1000.0);

    if (results->iter10000 >= 0)
        printf(" -> 10000    iterations:   %Lf sec. / %i iter. = %Lf\n", results->iter10000, 10000, results->iter10000 / (long double)10000.0);
    
    if (results->iter100000 >= 0)
        printf(" -> 100000   iterations:   %Lf sec. / %i iter. = %Lf\n", results->iter100000, 100000, results->iter100000 / (long double)100000.0);

    if (results->iter1000000 >= 0)    
        printf(" -> 1000000  iterations:   %Lf sec. / %i iter. = %Lf\n", results->iter1000000, 1000000, results->iter1000000 / (long double)1000000.0);

    printf("---------\n");
}

#endif
