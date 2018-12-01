#ifndef CGTFS_CALENDAR_DATES_H
#define CGTFS_CALENDAR_DATES_H

#include <stdio.h>
#include <string.h>


typedef enum {
    ET_NOT_SET = 0,
    ET_ADDED = 1,
    ET_REMOVED = 2
} exception_type_t;

typedef struct {
    char service_id[65];
    char date[9];
    exception_type_t exception_type;
    int is_null;
} calendar_date_t;


exception_type_t parse_exception_type(char *value);

calendar_date_t empty_calendar_date(void);
calendar_date_t make_calendar_date(int field_count, char **field_names, char **field_values);

#endif
