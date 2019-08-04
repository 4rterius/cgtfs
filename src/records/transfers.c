#include "records/transfers.h"

transfer_type_t parse_transfer_type(const char *value) {
    if (strcmp(value, "0") == 0 || strcmp(value, "") == 0)
        return TT_RECOMMENDED;
    else if (strcmp(value, "1") == 0)
        return TT_TIMED;
    else if (strcmp(value, "2") == 0)
        return TT_TIME_REQUIRED;
    else if (strcmp(value, "3") == 0)
        return TT_NOT_POSSIBLE;
    else
        return TT_NOT_SET;
}

void init_transfer(transfer_t *record) {
    strcpy(record->from_stop_id, "");
    strcpy(record->to_stop_id, "");
    record->transfer_type = TT_RECOMMENDED;
    record->min_transfer_time = 0;
}

void read_transfer(transfer_t *record, int field_count, const char **field_names, const char **field_values) {
    init_transfer(record);

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "from_stop_id") == 0) {
            strcpy(record->from_stop_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "to_stop_id") == 0) {
            strcpy(record->to_stop_id, field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "transfer_type") == 0) {
            record->transfer_type = parse_transfer_type(field_values[i]);
            continue;
        }
        if (strcmp(field_names[i], "min_transfer_time") == 0) {
            record->min_transfer_time = (unsigned int)strtoul(field_values[i], NULL, 0);
            continue;
        }
    }
}

int equal_transfer(const transfer_t *a, const transfer_t *b) {
    return !(!strcmp(a->from_stop_id, b->from_stop_id) &&
             !strcmp(a->to_stop_id, b->to_stop_id) &&
             a->transfer_type == b->transfer_type &&
             a->min_transfer_time == b->min_transfer_time);
}