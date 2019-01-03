#ifndef CGTFS_FILENAMES_H
#define CGTFS_FILENAMES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define FILENAME_SEPARATOR "\\"
#else
    #define FILENAME_SEPARATOR "/"
#endif

#define FILENAME_MAX_LENGTH 1000

void make_filepath(char **out, const char *dirname, const char *filename);

#endif