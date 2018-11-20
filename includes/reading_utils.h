#ifndef CGTFS_READING_UTILS_H
#define CGTFS_READING_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_header(FILE *fp, char ***field_names);
char*** read_records(FILE *fp, int validate_field_num, int min_fields);

#endif
