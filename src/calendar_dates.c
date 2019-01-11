#include "calendar_dates.h"

exception_type_t parse_exception_type(const char *value) {
    if (strcmp(value, "1") == 0)
        return ET_ADDED;
    else if (strcmp(value, "2") == 0)
        return ET_REMOVED;
    else
        return ET_NOT_SET;
}

calendar_date_t empty_calendar_date(void) {
    calendar_date_t calendar_date;
    strcpy(calendar_date.service_id, "");
    strcpy(calendar_date.date, "");
    calendar_date.exception_type = ET_NOT_SET;
    calendar_date.is_null = 1;
    return calendar_date;
}

calendar_date_t read_calendar_date(const int field_count, const char **field_names, const char **field_values) {
    calendar_date_t calendar_date = empty_calendar_date();
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "service_id") == 0) {
            strcpy(calendar_date.service_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "date") == 0) {
            strcpy(calendar_date.date, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "exception_type") == 0) {
            calendar_date.exception_type = parse_exception_type(field_values[i]);
            assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        calendar_date.is_null = 1;
    else
        calendar_date.is_null = 0;

    return calendar_date;
}