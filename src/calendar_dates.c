#include "records/calendar_dates.h"

exception_type_t parse_exception_type(const char *value) {
    if (strcmp(value, "1") == 0)
        return ET_ADDED;
    else if (strcmp(value, "2") == 0)
        return ET_REMOVED;
    else
        return ET_NOT_SET;
}

void init_calendar_date(calendar_date_t *record) {
    strcpy(record->service_id, "");
    strcpy(record->date, "");
    record->exception_type = ET_NOT_SET;
    record->is_null = 1;
}

void read_calendar_date(calendar_date_t *record, int field_count, const char **field_names, const char **field_values) {
    init_calendar_date(record);
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "service_id") == 0) {
            strcpy(record->service_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "date") == 0) {
            strcpy(record->date, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "exception_type") == 0) {
            record->exception_type = parse_exception_type(field_values[i]);
            assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        record->is_null = 1;
    else
        record->is_null = 0;
}