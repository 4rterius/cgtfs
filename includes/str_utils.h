/**
 * @file
 * @brief    String handling utilities.
 */

#ifndef CGTFS_STR_UTILS_H
#define CGTFS_STR_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Frees memory taken by a c-string array.
 *
 * @param[in,out]    arr    Array to free.
 * @param[in]        sz     Number of allocated strings.
 *
 * @ingroup          Utilities__Memory
 */
char *get_filename_no_ext(char *src, char path_separator);

#endif