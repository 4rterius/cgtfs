#ifndef CGTFS_TESTS_READING_UTILS_C
#define CGTFS_TESTS_READING_UTILS_C

#include "greatest/greatest.h"
#include "reading_utils.h"


// read_header(..) tests
// ----------------------------------------------------------------------

TEST reading_utils_read_header_0(void) {
    FILE *fp = fopen("../tests/data/agency.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/agency.txt` test file");
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
        ASSERT_EQ_FMTm("Counted wrong number of fields in the header", (int)correct_field_count, field_count, "%zu");

        for (size_t i = 0; i < correct_field_count; i++)
            ASSERT_STR_EQ(correct_field_names[i], field_names[i]);

        for (size_t j = 0; j < field_count; j++)
            free(field_names[j]);
        free(field_names);

        fclose(fp);
        PASS();
    }
}

TEST reading_utils_read_header_1(void) {
    FILE *fp = fopen("../tests/data/routes.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/routes.txt` test file");
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
        ASSERT_EQ_FMTm("Counted wrong number of fields in the header", (int)correct_field_count, field_count, "%i");

        for (size_t i = 0; i < correct_field_count; i++)
            ASSERT_STR_EQ(correct_field_names[i], field_names[i]);

        for (size_t j = 0; j < field_count; j++)
            free(field_names[j]);
        free(field_names);

        fclose(fp);
        PASS();
    }
}

TEST reading_utils_read_header_2_empty(void) {
    FILE *fp = fopen("../tests/data/empty.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/empty.txt` test file");
    } else {
        char **field_names;
        int field_count = 0;

        field_count = read_header(fp, &field_names);
        ASSERT_EQ_FMTm("Counted some fields in the header where there are none", 0, field_count, "%i");

        for (size_t j = 0; j < field_count; j++)
            free(field_names[j]);
        free(field_names);

        fclose(fp);
        PASS();
    }
}

TEST reading_utils_read_header_3_badfile(void) {
    FILE *fp = fopen("../tests/data/doesntexist.txt", "r");
    
    char **field_names;
    int field_count = 0;

    field_count = read_header(fp, &field_names);
    ASSERT_EQ_FMTm("Somehow opened the file that doesn't exist", 0, field_count, "%i");

    for (size_t j = 0; j < field_count; j++)
        free(field_names[j]);
    free(field_names);

    if (fp != NULL)
        fclose(fp);

    PASS();
}



// read_record(..) tests
// ----------------------------------------------------------------------

TEST reading_utils_read_record_0(void) {
    FILE *fp = fopen("../tests/data/agency.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/agency.txt` test file");
    } else {
        char **field_names;
        int field_count = read_header(fp, &field_names);

        char **record_values;
        int record_count = 0;

        while (read_record(fp, field_count, &record_values) > 0) {
            switch(record_count) {
                case 0:
                    ASSERT_STR_EQ("1", record_values[0]);
                    ASSERT_STR_EQ("Lahden Seudun Liikenne", record_values[1]);
                    ASSERT_STR_EQ("http://www.lsl.fi", record_values[2]);
                    ASSERT_STR_EQ("Europe/Helsinki", record_values[3]);
                    ASSERT_STR_EQ("fi", record_values[4]);
                    ASSERT_STR_EQ("03 814 2355", record_values[5]);
                    break;
                case 2:
                    ASSERT_STR_EQ("3", record_values[0]);
                    ASSERT_STR_EQ("", record_values[1]);
                    ASSERT_STR_EQ("", record_values[2]);
                    ASSERT_STR_EQ("", record_values[3]);
                    ASSERT_STR_EQ("", record_values[4]);
                    ASSERT_STR_EQ("", record_values[5]);
                    break;
                case 3:
                    ASSERT_STR_EQ("4", record_values[0]);
                    ASSERT_STR_EQ("\"djghas\"ldföäånkl´+123sd\"", record_values[1]);
                    ASSERT_STR_EQ("http://www.lsl.fi", record_values[2]);
                    ASSERT_STR_EQ("blah \"HELLO\" blah", record_values[3]);
                    ASSERT_STR_EQ("fi", record_values[4]);
                    ASSERT_STR_EQ("03 814 2355", record_values[5]);
                    break;
            }
            record_count++;

            for (size_t j = 0; j < field_count; j++)
                free(record_values[j]);
            free(record_values);
        }


        for (size_t j = 0; j < field_count; j++)
            free(field_names[j]);
        free(field_names);

        for (size_t j = 0; j < field_count; j++)
            free(record_values[j]);
        free(record_values); // Free here, because read_record() allocates memory even on read failure.

        fclose(fp);
        PASS();
    }
}

TEST reading_utils_read_record_1_empty(void) {
    FILE *fp = fopen("../tests/data/empty.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/empty.txt` test file");
    } else {
        char **field_names;
        int field_count = read_header(fp, &field_names);

        char **record_values;
        ASSERT_EQ_FMTm("Somehow read a record that doesn't exist", -1, read_record(fp, field_count, &record_values), "%i");

        for (size_t j = 0; j < field_count; j++)
            free(field_names[j]);
        free(field_names);

        for (size_t j = 0; j < field_count; j++)
            free(record_values[j]);
        free(record_values); // Free here, because read_record() allocates memory even on read failure.

        fclose(fp);
        PASS();
    }
}

TEST reading_utils_read_record_2_badfile(void) {
    FILE *fp = fopen("../tests/data/doesntexist.txt", "r");

    char **field_names;
    int field_count = read_header(fp, &field_names);

    char **record_values;
    ASSERT_EQ_FMTm("Somehow read a record from a file that doesn't exist", -1, read_record(fp, field_count, &record_values), "%i");

    for (size_t j = 0; j < field_count; j++)
        free(field_names[j]);
    free(field_names);

    for (size_t j = 0; j < field_count; j++)
        free(record_values[j]);
    free(record_values); // Free here, because read_record() allocates memory even on read failure.

    if (fp != NULL)
        fclose(fp);

    PASS();
}



// count_lines(..) tests
// ----------------------------------------------------------------------

TEST reading_utils_count_lines_0(void) {
    FILE *fp = fopen("../tests/data/agency.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/agency.txt` test file");
    } else {
        ASSERT_EQ(5, count_lines(fp));
        fclose(fp);
        PASS();
    }
}

TEST reading_utils_count_lines_1(void) {
    FILE *fp = fopen("../tests/data/empty.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/empty.txt` test file");
    } else {
        ASSERT_EQ(0, count_lines(fp));
        fclose(fp);
        PASS();
    }
}

TEST reading_utils_count_lines_2(void) {
    FILE *fp = fopen("../tests/data/only_nl.txt", "r");
    if (fp == NULL) {
        FAILm("Couldn't open `data/only_nl.txt` test file");
    } else {
        ASSERT_EQ(2, count_lines(fp));
        fclose(fp);
        PASS();
    }
}

TEST reading_utils_count_lines_3_badfile(void) {
    FILE *fp = fopen("../tests/data/doesntexist.txt", "r");
    ASSERT_EQ(-1, count_lines(fp));

    if (fp != NULL)
        fclose(fp);
    PASS();
}



SUITE(CGTFS_ReadingUtils) {
    RUN_TEST(reading_utils_read_header_0);
    RUN_TEST(reading_utils_read_header_1);
    RUN_TEST(reading_utils_read_header_2_empty);
    RUN_TEST(reading_utils_read_header_3_badfile);

    RUN_TEST(reading_utils_read_record_0);
    RUN_TEST(reading_utils_read_record_1_empty);
    RUN_TEST(reading_utils_read_record_2_badfile);

    RUN_TEST(reading_utils_count_lines_0);
    RUN_TEST(reading_utils_count_lines_1);
    RUN_TEST(reading_utils_count_lines_2);
    RUN_TEST(reading_utils_count_lines_3_badfile);
}

#endif