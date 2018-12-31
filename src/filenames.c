#include "filenames.h"

void make_filepath(char **out, char *dirname, char *filename) {
    *out = malloc((strlen(dirname) + strlen(filename) + 2) * sizeof(char));
    strcpy(*out, "");

    strncat(*out, dirname, strlen(dirname));
    strncat(*out, FILENAME_SEPARATOR, 1);
    strncat(*out, filename, strlen(filename));
}