#ifndef CGTFS_TESTS_READING_UTILS_C
#define CGTFS_TESTS_READING_UTILS_C

#include "reading_utils.h"

int test_reading_utils_read_header() {
    
    // Case 1
    {
        FILE *fp = fopen("../tests/data/agency.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/agency.txt` file");
        } else {
            char **field_names;
            int field_count = 0;

            size_t correct_field_count = 6;
            char *correct_field_names[] = {
                "agency_id",
                "agency_name",
                "agency_url",
                "agency_timezone",
                "agency_lang",
                "agency_phone"
            };

            field_count = read_header(fp, &field_names);

            if (field_count != correct_field_count)
                printf("Number of header fields (e.g. columns) parsed incorrectly: %i, not %i", field_count, correct_field_count);

            for (size_t i = 0; i < correct_field_count; i++) {
                if (strcmp(correct_field_names[i], field_names[i]) != 0) {
                    printf("Incorrect field %i name: %s instead of %s", i, field_names[i], correct_field_names[i]);
                }
            }

        }
    }

    // Case 2
    {
        FILE *fp = fopen("../tests/data/routes.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/routes.txt` file");
        } else {
            char **field_names;
            int field_count = 0;

            size_t correct_field_count = 7;
            char *correct_field_names[] = {
                "route_id",
                "agency_id",
                "route_short_name",
                "route_long_name",
                "route_type",
                "route_color",
                "route_text_color"
            };

            field_count = read_header(fp, &field_names);

            if (field_count != correct_field_count)
                printf("Number of header fields (e.g. columns) parsed incorrectly: %i, not %i", field_count, correct_field_count);

            for (size_t i = 0; i < correct_field_count; i++) {
                if (strcmp(correct_field_names[i], field_names[i]) != 0) {
                    printf("Incorrect field %i name: %s instead of %s", i, field_names[i], correct_field_names[i]);
                }
            }
        }
    }

    // Case 3
    {
        FILE *fp = fopen("../tests/data/empty.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/empty.txt` file");
        } else {
            char **field_names;
            int field_count = 0;

            field_count = read_header(fp, &field_names);

            if (field_count != -1) {
                printf("read_header() somehow didn't signal the error when reading what it could not read");
            }
        }
    }
    return 0;
}

int test_reading_utils_read_record() {

    // Case 1
    {
        FILE *fp = fopen("../tests/data/agency.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/agency.txt` file");
        } else {
            char **field_names;
            int field_count = read_header(fp, &field_names);

            char **record_values;
            int record_count = 0;
            
            while (read_record(fp, field_count, &record_values) > 0) {
                switch(record_count) {
                    case 0:
                        if (!(
                            !strcmp(record_values[0], "1") &&
                            !strcmp(record_values[1], "Lahden Seudun Liikenne") &&
                            !strcmp(record_values[2], "http://www.lsl.fi") &&
                            !strcmp(record_values[3], "Europe/Helsinki") &&
                            !strcmp(record_values[4], "fi") &&
                            !strcmp(record_values[5], "03 814 2355")
                        )) {
                            printf("Agency 1 parsed incorrectly.");
                        }
                        break;
                    case 2:
                        if (!(
                            !strcmp(record_values[0], "3") &&
                            !strcmp(record_values[1], "") &&
                            !strcmp(record_values[2], "") &&
                            !strcmp(record_values[3], "") &&
                            !strcmp(record_values[4], "") &&
                            !strcmp(record_values[5], "")
                        )) {
                            printf("Agency 3 (empty) parsed incorrectly.");
                        }
                        break;
                    case 3:
                        if (!(
                            !strcmp(record_values[0], "4") &&
                            !strcmp(record_values[1], "\"djghas\"ldföäånkl´+123sd\"") &&
                            !strcmp(record_values[2], "http://www.lsl.fi") &&
                            !strcmp(record_values[3], "blah \"HELLO\" blah") &&
                            !strcmp(record_values[4], "fi") &&
                            !strcmp(record_values[5], "03 814 2355")
                        )) {
                            printf("Agency 4 parsed incorrectly.");
                        }
                        break;
                }
                record_count++;
            }

            free(field_names);
            free(record_values);
        }
        fclose(fp);
    }
    return 0;
}

int test_reading_utils_count_lines(void) {
    // Case 1
    {
        FILE *fp = fopen("../tests/data/agency.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/agency.txt` file");
        } else {
            int lc = count_lines(fp);
            if (lc != 5) {
                printf("Counted line count in `data/agency.txt` incorrectly.");
            }
            fclose(fp);
        }
    }

    // Case 2
    {
        FILE *fp = fopen("../tests/data/empty.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/empty.txt` file");
        } else {
            int lc = count_lines(fp);
            if (lc != 0) {
                printf("Counted line count in `data/empty.txt` incorrectly.");
            }
            fclose(fp);
        }
    }

    // Case 3
    {
        FILE *fp = fopen("../tests/data/only_nl.txt", "r");
        if (fp == NULL) {
            perror("Couldn't open `data/only_nl.txt` file");
        } else {
            int lc = count_lines(fp);
            if (lc != 2) {
                printf("Counted line count in `data/only_nl.txt` incorrectly.");
            }
            fclose(fp);
        }
    }
    return 0;
}

#endif