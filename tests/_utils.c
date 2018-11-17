#ifndef CGTFS_TESTS__UTILS_C
#define CGTFS_TESTS__UTILS_C

#include <assert.h>

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

#endif
