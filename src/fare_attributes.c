#include "fare_attributes.h"

payment_method_t parse_payment_method(char *value) {
    if (strcmp(value, "0") == 0)
        return PM_ON_BOARD;
    else if (strcmp(value, "1") == 0)
        return PM_BEFOREHAND;
    else
        return PM_NOT_SET;
}

transfers_state_t parse_transfer_state(char *value) {
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

fare_attributes_t empty_fare_attributes(void) {
    fare_attributes_t fare_attributes;
    strcpy(fare_attributes.fare_id, "");
    fare_attributes.price = 0.0;
    strcpy(fare_attributes.currency_type, "");
    fare_attributes.payment_method = PM_NOT_SET;
    fare_attributes.transfers = TS_NOT_SET;
    strcpy(fare_attributes.agency_id, "");
    fare_attributes.transfer_duration = 0.0;
    fare_attributes.is_null = 1;
    return fare_attributes;
}

fare_attributes_t read_fare_attributes(int field_count, char **field_names, char **field_values) {
    fare_attributes_t fare_attributes = empty_fare_attributes();
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "fare_id") == 0) {
            strcpy(fare_attributes.fare_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "price") == 0) {
            fare_attributes.price = atof(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "currency_type") == 0) {
            strcpy(fare_attributes.currency_type, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "payment_method") == 0) {
            fare_attributes.payment_method = parse_payment_method(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "transfers") == 0) {
            fare_attributes.transfers = parse_transfer_state(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "agency_id") == 0) {
            strcpy(fare_attributes.agency_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "transfer_duration") == 0) {
            fare_attributes.transfer_duration = atof(field_values[i]);
            assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        fare_attributes.is_null = 1;
    else
        fare_attributes.is_null = 0;
    
    return fare_attributes;
}