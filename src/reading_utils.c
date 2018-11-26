#include "reading_utils.h"

int read_header(FILE *fp, char ***field_names) {
    char header[LINE_MAX_LEN];
    char h_field[LINE_MAX_LEN];
    char h_field_index = 0;
    int h_field_len = 0;

    if (!fgets(header, LINE_MAX_LEN, fp))
        return -1;

    char chr;
    int chr_pos = 0;

    *field_names = malloc(sizeof(char *));
    memset(h_field, 0, LINE_MAX_LEN);
    
    while (chr = header[++chr_pos - 1]) {
        if (chr == ',' || chr == '\n') {
            *field_names = realloc(*field_names, (h_field_index + 1) * sizeof(char *));
            (*field_names)[h_field_index] = strdup(h_field);

            memset(h_field, 0, LINE_MAX_LEN);
            h_field_len = 0;
            h_field_index++;
        } else if (chr != '\n') {
            h_field[++h_field_len - 1] = chr;
        }
    }
    
    return h_field_index;
}

int read_one_record(FILE *fp, int fields_number, char ***record_values) {
    char record[LINE_MAX_LEN];
    char r_field[LINE_MAX_LEN];
    char r_field_index = 0;
    int r_field_len = 0;
    int in_quotes = 0;  // to ignore commas in "dbl_quoted" field values

    if (!fgets(record, LINE_MAX_LEN, fp))
        return -1;

    char chr;
    int chr_pos = 0;

    *record_values = malloc(fields_number * sizeof(char *));
    memset(r_field, 0, LINE_MAX_LEN);
    
    while (chr = record[++chr_pos - 1]) {
        if (chr == '"') {
            in_quotes = (in_quotes == 1) ? 0 : 1;
        } else if ((chr == ',' || chr == '\n') && !in_quotes) {
            (*record_values)[r_field_index] = strdup(r_field);

            memset(r_field, 0, LINE_MAX_LEN);
            r_field_len = 0;
            r_field_index++;
        } else if (chr != '\n') {
            r_field[++r_field_len - 1] = chr;
        }
    }
    return 1;
}

int for_each_record(FILE *fp, int fields_number, int (*cb)(int, int, char **)) {
    char **record_values;
    int line_num = 0;

    while (read_one_record(fp, fields_number, &record_values) > 0)
        if (cb(line_num++, fields_number, record_values) < 0)
            return -1;

    free(record_values);
    return line_num;
}
