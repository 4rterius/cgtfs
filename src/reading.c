#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reading.h"
#include "reading_utils.h"

int read_agencies(FILE *fp, agency_t **agencies) {

    char **field_names;
    int field_count = read_header(fp, &field_names);


    // Fetch every agency from the file line-by-line
    
    int agencies_count = 0;
    agency_t *agencies_list = malloc(sizeof(agency_t));
    {
        char record[1000];

        char record_field[1000];
        int record_field_length = 0;
        int record_field_pos = 0;

        char chr;
        int chr_pos = 0;

        int in_quotes = 0;  // to ignore commas in "dbl_quoted" field values

        memset(record_field, 0, 1000);

        while (fgets(record, 1000, fp)) {
            while (chr = record[++chr_pos - 1]) {
                if (chr == '"') {
                    in_quotes = (in_quotes == 1) ? 0 : 1;
                } else if ((chr == ',' || chr == '\n') && !in_quotes) {
                    memset(record_field, 0, 1000);
                    record_field_length = 0;
                    record_field_pos++;
                } else if (chr != '\n') {
                    record_field[++record_field_length - 1] = chr;
                }
            }
        }
    }

    return agencies_count;
}