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
}

void read_calendar_date(calendar_date_t *record, int field_count, const char **field_names, const char **field_values) {
    init_calendar_date(record);

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "service_id") == 0) {
            strcpy(record->service_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "date") == 0) {
            strcpy(record->date, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "exception_type") == 0) {
            record->exception_type = parse_exception_type(field_values[i]);
            continue;
        }
    }
}

int equal_calendar_date(const calendar_date_t *a, const calendar_date_t *b) {
    return (!strcmp(a->service_id, b->service_id) &&
             !strcmp(a->date, b->date) &&
             a->exception_type == b->exception_type);
}