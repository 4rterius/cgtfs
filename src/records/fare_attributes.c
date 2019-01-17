#include "records/fare_attributes.h"

payment_method_t parse_payment_method(const char *value) {
    if (strcmp(value, "0") == 0)
        return PM_ON_BOARD;
    else if (strcmp(value, "1") == 0)
        return PM_BEFOREHAND;
    else
        return PM_NOT_SET;
}

transfers_state_t parse_transfer_state(const char *value) {
    if (strcmp(value, "0") == 0)
        return TS_NOT_ALLOWED;
    else if (strcmp(value, "1") == 0)
        return TS_ONCE;
    else if (strcmp(value, "2") == 0)
        return TS_TWICE;
    else if (strcmp(value, "") == 0)
        return TS_UNLIMITED;
    else
        return TS_NOT_ALLOWED;
}

void init_fare_attributes(fare_attributes_t *record) {
    strcpy(record->fare_id, "");
    record->price = 0.0;
    strcpy(record->currency_type, "");
    record->payment_method = PM_NOT_SET;
    record->transfers = TS_NOT_SET;
    strcpy(record->agency_id, "");
    record->transfer_duration = 0.0;
    record->is_null = 1;
}

void read_fare_attributes(fare_attributes_t *record, int field_count, const char **field_names, const char **field_values) {
    init_fare_attributes(record);
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "fare_id") == 0) {
            strcpy(record->fare_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "price") == 0) {
            record->price = atof(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "currency_type") == 0) {
            strcpy(record->currency_type, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "payment_method") == 0) {
            record->payment_method = parse_payment_method(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "transfers") == 0) {
            record->transfers = parse_transfer_state(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_id") == 0) {
            strcpy(record->agency_id, field_values[i]);
            // assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "transfer_duration") == 0) {
            record->transfer_duration = strtod(field_values[i], NULL);
            // assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        record->is_null = 1;
    else
        record->is_null = 0;
}

int equal_fare_attributes(const fare_attributes_t *a, const fare_attributes_t *b) {
    return !(!strcmp(a->fare_id, b->fare_id) &&
             !strcmp(a->currency_type, b->currency_type) &&
             !strcmp(a->agency_id, b->agency_id) &&
             a->price == b->price &&
             a->payment_method == b->payment_method &&
             a->transfers == b->transfers &&
             a->transfer_duration == b->transfer_duration);
}