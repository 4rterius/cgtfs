#include "filenames.h"

void make_filepath(char **out, const char *dirname, const char *filename) {
    // TODO: null-checking here

    char *_dirname = strdup(dirname);

    *out = malloc((strlen(dirname) + strlen(filename) + 2) * sizeof(char));
    strcpy(*out, "");

    char last_dirname_char = '\0';
    if (strlen(_dirname) > 0)
        last_dirname_char = _dirname[strlen(_dirname) - 1];
    
    if (last_dirname_char == *FILENAME_SEPARATOR)
        _dirname[strlen(_dirname) - 1] = '\0';

    strncat(*out, _dirname, strlen(_dirname));
    strncat(*out, FILENAME_SEPARATOR, 1);
    strncat(*out, filename, strlen(filename));
}