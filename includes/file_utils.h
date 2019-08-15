/**
 * @file
 * @brief    File I/O utilities.
 */

#ifndef CGTFS_READING_UTILS_H
#define CGTFS_READING_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __unix__
#include <dirent.h>
#endif
#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#pragma comment(lib, "User32.lib")
#endif

#include "mem_utils.h"

/**
 * @def        LINE_MAX_LEN
 * @brief      Max reasonable length of a line or a record (!).
 * @note       Obviously, increase/decrease if needed.
 *
 * @ingroup    Utilities__File
 */
#define LINE_MAX_LEN 10000

/**
 * Reads the next line of the file as a set of comma-separated values (partial CSV)
 * into the given string array.
 *
 * Array passed as the last argument is initialized and allocated by the function.
 * Once the function has returned, if field_names != NULL, the variable must be freed.
 *
 * @param[in]     fp             Opened file connection to read from.
 * @param[out]    field_names    Pointer to the string array to read field names into.
 *
 * @returns       Number of fields on success.
 *                On error, returns -1 and sets field_names to NULL.
 *
 * @ingroup       Utilities__File
 */
int read_header(FILE *fp, char ***field_names);

/**
 * Reads the next line of the file as a set of comma-separated values.
 *
 * Essentially, a CSV parser, but supports CSV only in the capacity that GTFS defines.
 * @see https://developers.google.com/transit/gtfs/reference/#file_requirements
 *
 * Array passed as the last argument is initialized and allocated by the function.
 * Once the function has returned, if record_values != NULL, the variable must be freed.
 *
 * @param[in]     fp               Opened file connection to read from.
 * @param[in]     fields_number    Number of fields to expect.
 * @param[out]    record_values    Pointer to the string array to read record values into.
 *
 * @returns       1 on success.
 *                On error, returns -1 and sets record_values to NULL.
 *
 * @ingroup       Utilities__File
 */
int read_record(FILE *fp, const int fields_number, char ***record_values);

/**
 * Counts the number of lines in the given file,
 * preserving the position in the file stream.
 *
 * @param[in]    fp    Opened file connection to count line in.
 *
 * @returns      -1 on the file reading error, number of lines on success.
 *
 * @ingroup       Utilities__File
 */
int count_lines(FILE *fp);

/**
 * Lists all *.txt files in the given directory.
 *
 * @param[in]     dir_path Path to directory to look in.
 * @param[out]    file_names C-string array of file names.
 *
 * Works on Windows and Linux,
 * facading a call to a corresponding function.
 * Always returns an error if the system is not supported.
 *
 * Array passed as the last argument is initialized and allocated by the function.
 * Unless the function sets it to NULL, it must be freed.
 *
 * @returns       Number of files found on success.
 *                On error, returns -1 and sets file_names to NULL.
 *
 * @ingroup       Utilities__File
 */
int list_txt_files(const char *dir_path, char ***file_names);

int __list_txt_files__unix(const char *dir_path, char ***file_names);
int __list_txt_files__win(const char *dir_path, char ***file_names);

#endif
