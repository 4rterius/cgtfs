#include "reading_utils.h"

int read_header(FILE *fp, char ***field_names) {
    int field_count = 0;
    char header[LINE_MAX_LEN];
    char *field_token;

    *field_names = malloc(sizeof(char *));

    if (fgets(header, LINE_MAX_LEN, fp)) {
        if (!(field_token = strtok(header, ",")))
            return -1;

        for(;;) {
            field_count++;
            *field_names = realloc(*field_names, field_count * sizeof(char *));
            (*field_names)[field_count - 1] = field_token;

            if (!(field_token = strtok(NULL, ",")))
                break;

            if (field_token[strlen(field_token) - 1] == '\n')
                field_token[strlen(field_token) - 1] = '\0';
        }
    } else {
        return -1;
    }

    free(field_token);
    return field_count;
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
