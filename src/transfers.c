#include "transfers.h"

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

transfer_t empty_transfer(void) {
    transfer_t transfer;
    strcpy(transfer.from_stop_id, "");
    strcpy(transfer.to_stop_id, "");
    transfer.transfer_type = TT_RECOMMENDED;
    transfer.min_transfer_time = 0;
    transfer.is_null = 1;
    return transfer;
}

transfer_t read_transfer(int field_count, const char **field_names, const char **field_values) {
    transfer_t transfer = empty_transfer();
    int assignment_counter = 0;

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "from_stop_id") == 0) {
            strcpy(transfer.from_stop_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "to_stop_id") == 0) {
            strcpy(transfer.to_stop_id, field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "transfer_type") == 0) {
            transfer.transfer_type = parse_transfer_type(field_values[i]);
            assignment_counter++;
            continue;
        }
        if (strcmp(field_names[i], "min_transfer_time") == 0) {
            transfer.min_transfer_time = (unsigned int)strtoul(field_values[i], NULL, 0);
            // assignment_counter++;
            continue;
        }
    }

    if (assignment_counter == 0)
        transfer.is_null = 1;
    else
        transfer.is_null = 0;
    
    return transfer;
}