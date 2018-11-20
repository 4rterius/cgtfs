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