#ifndef CGTFS_MEM_UTILS_H
#define CGTFS_MEM_UTILS_H

#include <stdlib.h>

/**
 * Frees memory taken by a c-string array,
 * @param[in,out] arr Array to free.
 * @param[in]     sz  Number of allocated strings.
 */
inline void free_cstr_arr(char **arr, size_t sz) {
    for (size_t i = 0; i < sz; i++)
        free(arr[i]);
    free(arr);
}

#endif