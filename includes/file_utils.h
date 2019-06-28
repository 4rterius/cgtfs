/**
 * @file
 * @brief    File I/O utilities.
 */

#ifndef CGTFS_READING_UTILS_H
#define CGTFS_READING_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @def      LINE_MAX_LEN
 * @brief    Max reasonable length of a line or a record (!).
 * @note     Obviously, increase/decrease if needed.
 */
#define LINE_MAX_LEN 10000

/**
 * Reads the next line of the file as a set of comma-separated values (partial CSV)
 * into the given string array.
 * 
 * @param[in]     fp             Opened file connection to read from.
 * @param[out]    field_names    Pointer to the string array to read field names into.
 * 
 * @returns 0 on file reading error, number of fields on success.
 */
int read_header(FILE *fp, char ***field_names);

/**
 * Reads the next line of the file as a set of comma-separated values.
 * 
 * Essentially, a CSV parser, but supports CSV only in the capacity that GTFS defines.
 * @see https://developers.google.com/transit/gtfs/reference/#file_requirements
 * 
 * @param[in]     fp               Opened file connection to read from.
 * @param[in]     fields_number    Number of fields to expect.
 * @param[out]    record_values    Pointer to the string array to read record values into.
 * 
 * @returns       -1 on the file reading error, 1 on success.
 */
int read_record(FILE *fp, const int fields_number, char ***record_values);

/**
 * Counts the number of lines in the given file,
 * preserving the position in the file stream.
 * 
 * @param[in]    fp    Opened file connection to count line in.
 * 
 * @returns      -1 on the file reading error, number of lines on success.
 */
int count_lines(FILE *fp);

#endif
