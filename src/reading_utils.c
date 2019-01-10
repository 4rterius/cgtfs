#include "reading_utils.h"

int read_header(FILE *fp, char ***field_names) {
    char header[LINE_MAX_LEN];
    char h_field[LINE_MAX_LEN];
    char h_field_index = 0;
    int h_field_len = 0;

    *field_names = malloc(sizeof(char *));
    memset(h_field, 0, LINE_MAX_LEN);

    if (fp == NULL)
        return 0;

    if (!fgets(header, LINE_MAX_LEN, fp))
        return 0;

    char chr;
    int chr_pos = 0;

    while (chr = header[++chr_pos - 1]) {
        if (chr == ',' || chr == '\n') {
            *field_names = realloc(*field_names, (h_field_index + 1) * sizeof(char *));
            (*field_names)[h_field_index] = strdup(h_field);

            memset(h_field, 0, LINE_MAX_LEN);
            h_field_len = 0;
            h_field_index++;
        } else if (chr != '\n' && chr != '\r') {
            h_field[++h_field_len - 1] = chr;
        }
    }
    
    return h_field_index;
}

int read_record(FILE *fp, int fields_number, char ***record_values) {
    char record[LINE_MAX_LEN];
    char r_field[LINE_MAX_LEN];
    char r_field_index = 0;
    int r_field_len = 0;
    int in_quotes = 0;  // to ignore commas in "dbl_quoted" field values

    memset(r_field, 0, LINE_MAX_LEN);
    
    *record_values = malloc(fields_number * sizeof(char *));
    for (unsigned i = 0; i < fields_number; i++)
        (*record_values)[i] = strdup("");

    if (fp == NULL)
        return -1;

    if (!fgets(record, LINE_MAX_LEN, fp))
        return -1;

    char chr;
    int chr_pos = 0;
    int record_len = strlen(record);  // In theory, is guaranteed to have null-terminator, as
                                      // fgets() automatically applies one.
                                      // If not, pls PR or drop maintainer(s) a line.

    strcat(record, "\n");  // fixes the error that happens when the last record isn't followed by a newline
                           // (then the last record field fails to be parsed)
    
    while (chr = record[++chr_pos - 1]) {
        if (chr == '"') {
            if (in_quotes == 0) {
                in_quotes = 1;
            } else {
                if (chr_pos < record_len && record[chr_pos] == '"') {
                    r_field[++r_field_len - 1] = '"';
                    chr_pos++;
                } else {
                    in_quotes = 0;
                }
            }
        } else if ((chr == ',' || chr == '\n') && !in_quotes && r_field_index < fields_number) {
            free((*record_values)[r_field_index]);
            (*record_values)[r_field_index] = strdup(r_field);

            memset(r_field, 0, LINE_MAX_LEN);
            r_field_len = 0;
            r_field_index++;
        } else if (chr != '\n' && chr != '\r') {
            r_field[++r_field_len - 1] = chr;
        }
    }
    return 1;
}

int count_lines(FILE *fp) {
    int lines = 0;
    int ch_count = -1;
    int ch;

    if (fp == NULL)
        return -1;

    rewind(fp);
    do {
        ch = fgetc(fp);
        ch_count++;
        if (ch == '\n')
            lines++;
    } while (ch != EOF);

    if (ch != '\n' && ch_count > 0)
        lines++;

    if (ferror(fp) != 0)
        return -1;

    return lines;
}