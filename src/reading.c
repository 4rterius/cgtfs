#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reading.h"

int read_agencies(FILE *fp, agency_t **agencies) {
    int agencies_count = 0;

    // Fetch & parse table header
    // so that `field_names` has a list of them.

    int field_count = 0;
    char **field_names = malloc(sizeof(char *));
    {
        char header[1000];
        char *field_name;

        fgets(header, 1000, fp);
        
        field_name = strtok(header, ",");
        while (field_name != NULL) {
            field_count++;
            field_names = realloc(field_names, field_count * sizeof(char *));
            field_names[field_count - 1] = field_name;
            field_name = strtok(NULL, ",");
        }

        free(field_name);
        free(field_names);
    }


    // Fetch every agency from the file line-by-line
    
    int agencies_count;
    agency_t *agencies = malloc(sizeof(agency_t));
    {
        char record[1000];
        char *record_field;
        int in_quotes = 0;  // to ignore commas in "dbl_quoted" field values

        fgets(record, 1000, fp);
        

    }

    return agencies_count;
}