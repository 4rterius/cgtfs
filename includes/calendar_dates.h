#ifndef CGTFS_CALENDAR_DATES_H
#define CGTFS_CALENDAR_DATES_H

typedef enum {
    ET_ADDED = 1,
    ET_REMOVED = 2
} exception_type_t;

typedef struct {
    char service_id[64];
    char date[8];
    exception_type_t exception_type;
} calendar_date_t;

#endif
