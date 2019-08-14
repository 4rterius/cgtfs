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
 * Parses the base file name without extension from the path.
 *
 * @param[in]    src               Source string with file path.
 * @param[in]    path_separator    Path separator (e.g. '/' or '\\').
 *
 * Allocates memory for the new string, so the result must be freed after use.
 *
 * @returns      A new string with base file name without extension. NULL on error.
 *
 * @ingroup      Utilities__String
 */
char *get_filename_no_ext(char *src, char path_separator);

#endif