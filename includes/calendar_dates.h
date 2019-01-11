#ifndef CGTFS_CALENDAR_DATES_H
#define CGTFS_CALENDAR_DATES_H

#include <stdio.h>
#include <string.h>


typedef enum {
    ET_ADDED = 1,
    ET_REMOVED = 2,
    ET_NOT_SET
} exception_type_t;

typedef struct {
    char service_id[65];
    char date[9];
    exception_type_t exception_type;
    int is_null;
} calendar_date_t;


exception_type_t parse_exception_type(const char *value);

void init_calendar_date(calendar_date_t *record);
void read_calendar_date(calendar_date_t *record, int field_count, const char **field_names, const char **field_values);

#endif
