/**
 * @file
 * @brief    File names and paths handling utilities.
 */

#ifndef CGTFS_FILENAMES_H
#define CGTFS_FILENAMES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @def        FILENAME_SEPARATOR
 * @brief      OS-dependent filepath separator (`\` for Windows, `/` for UNIX-based OSs).
 *
 * @ingroup    Helpers
 */
#ifdef _WIN32
    #define FILENAME_SEPARATOR "\\"
#else
    #define FILENAME_SEPARATOR "/"
#endif

/**
 * @def        FILENAME_MAX_LENGTH
 * @brief      Max reasonable length of a file/directory name.
 *
 * Obviously, increase if needed.
 *
 * @ingroup    Helpers
 */
#define FILENAME_MAX_LENGTH 1000

/**
 * Concatenates a directory name with a file name,
 * removing or adding a trailing (back)slash in between them.
 *
 * Writes `NULL` into `out` if either of `dirname` or `filename` are NULLs.
 *
 * @param[out]    out         String pointer to write the resulting path into.
 * @param[in]     dirname     Directory name.
 * @param[in]     filename    File name.
 *
 * @ingroup       Helpers
 */
void make_filepath(char **out, const char *dirname, const char *filename);

#endif