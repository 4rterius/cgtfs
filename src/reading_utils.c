#include "reading_utils.h"

int read_header(FILE *fp, char ***field_names) {
    int field_count = 0;
    char header[1000];
    char *field_token;

    *field_names = malloc(sizeof(char *));

    if (fgets(header, 1000, fp)) {
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

int read_records(FILE *fp, char ****record_values) {
    int records_count = 0;

    char record[1000];
    char record_field[1000];

    int record_field_length = 0;
    int record_field_pos = 0;

    char chr;
    int chr_pos = 0;

    int in_quotes = 0;  // to ignore commas in "dbl_quoted" field values

    *record_values = malloc(sizeof(char **));
    memset(record_field, 0, 1000);

    while (fgets(record, 1000, fp)) {
        *record_values = realloc(*record_values, (records_count + 1) * sizeof(char **));
        (*record_values)[records_count] = malloc(sizeof(char **));
        while (chr = record[++chr_pos - 1]) {
            if (chr == '"') {
                in_quotes = (in_quotes == 1) ? 0 : 1;
            } else if ((chr == ',' || chr == '\n') && !in_quotes) {
                (*record_values)[records_count] = realloc((*record_values)[records_count], (record_field_pos + 1) * sizeof(char *));
                (*record_values)[records_count][record_field_pos] = record_field;
                
                printf("\n!!!REALLY DOESN'T WORK ATM: %s:%i\n\n", __FILE__, __LINE__);
                exit(-1);
                printf("%i . %i . %s\n", records_count, record_field_pos, (*record_values)[records_count][record_field_pos]);
                
                memset(record_field, 0, 1000);
                record_field_length = 0;
                record_field_pos++;
            } else if (chr != '\n') {
                record_field[++record_field_length - 1] = chr;
            }
        }
        records_count++;
    }

    printf("\n\n%s\n\n", (*record_values)[0][0]);

    return records_count;
}
