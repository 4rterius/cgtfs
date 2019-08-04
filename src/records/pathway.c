#include "records/pathway.h"

pathway_mode_t parse_pathway_mode(const char *value) {
    if (strcmp(value, "1") == 0)
        return PTMD_WALKWAY;
    else if (strcmp(value, "2") == 0)
        return PTMD_STAIRS;
    else if (strcmp(value, "3") == 0)
        return PTMD_MOVING;
    else if (strcmp(value, "4") == 0)
        return PTMD_ESCALATOR;
    else if (strcmp(value, "5") == 0)
        return PTMD_ELEVATOR;
    else if (strcmp(value, "6") == 0)
        return PTMD_PAYGATE;
    else if (strcmp(value, "7") == 0)
        return PTMD_EXITGATE;
    else
        return PTMD_NOT_SET;
}

pathway_directions_t parse_pathway_directions(const char *value) {
    if (strcmp(value, "0") == 0)
        return PD_UNIDIRECTIONAL;
    else if (strcmp(value, "1") == 0)
        return PD_BIDIRECTIONAL;
    else
        return PD_NOT_SET;
}

void init_pathway(pathway_t *record) {
    strcpy(record->id, "");
    strcpy(record->from_stop_id, "");
    strcpy(record->to_stop_id, "");
    record->mode = PTMD_NOT_SET,
    record->is_bidirectional = PD_NOT_SET,
    record->length = 0.0,
    record->traversal_time = 0,
    record->stair_count = 0,
    record->max_slope = 0.0,
    record->min_width = 0.0,
    strcpy(record->signposted_as, "");
    strcpy(record->reversed_signposted_as, "");
}

void read_pathway(pathway_t *record, int field_count, const char **field_names, const char **field_values) {
    init_pathway(record);

    for (int i = 0; i < field_count; i++) {
        if (strcmp(field_names[i], "pathway_id") == 0) {
            strcpy(record->id, field_values[i]);
            continue;
        }

        if (strcmp(field_names[i], "from_stop_id") == 0) {
            strcpy(record->from_stop_id, field_values[i]);
            continue;
        }

        if (strcmp(field_names[i], "to_stop_id") == 0) {
            strcpy(record->to_stop_id, field_values[i]);
            continue;
        }

        if (strcmp(field_names[i], "pathway_mode") == 0) {
            record->mode = parse_pathway_mode(field_values[i]);
            continue;
        }

        if (strcmp(field_names[i], "is_bidirectional") == 0) {
            record->is_bidirectional = parse_pathway_directions(field_values[i]);
            continue;
        }

        if (strcmp(field_names[i], "length") == 0) {
            record->length = strtod(field_values[i], NULL);
            continue;
        }

        if (strcmp(field_names[i], "traversal_time") == 0) {
            record->traversal_time = (int)strtol(field_values[i], NULL, 0);
            continue;
        }

        if (strcmp(field_names[i], "stair_count") == 0) {
            record->stair_count = (int)strtol(field_values[i], NULL, 0);
            continue;
        }

        if (strcmp(field_names[i], "max_slope") == 0) {
            record->max_slope = strtod(field_values[i], NULL);
            continue;
        }

        if (strcmp(field_names[i], "min_width") == 0) {
            record->min_width = strtod(field_values[i], NULL);
            continue;
        }

        if (strcmp(field_names[i], "signposted_as") == 0) {
            strcpy(record->signposted_as, field_values[i]);
            continue;
        }

        if (strcmp(field_names[i], "reversed_signposted_as") == 0) {
            strcpy(record->reversed_signposted_as, field_values[i]);
            continue;
        }
    }
}

/**
 * Compares two structures.
 *
 * @param[in]    a    First structure
 * @param[in]    b    Second structure
 *
 * @returns      0 if structures are equal, non-zero otherwise.
 *
 * @ingroup      Core__EntityFunctions Core__EntityList__Pathway
 */
int equal_pathway(const pathway_t *a, const pathway_t *b) {
    return (!strcmp(a->id, b->id) &&
             !strcmp(a->from_stop_id, b->from_stop_id) &&
             !strcmp(a->to_stop_id, b->to_stop_id) &&
             !strcmp(a->signposted_as, b->signposted_as) &&
             !strcmp(a->reversed_signposted_as, b->reversed_signposted_as) &&
             a->mode == b->mode &&
             a->is_bidirectional == b->is_bidirectional &&
             a->length == b->length &&
             a->traversal_time == b->traversal_time &&
             a->stair_count == b->stair_count &&
             a->max_slope == b->max_slope &&
             a->min_width == b->min_width);
}