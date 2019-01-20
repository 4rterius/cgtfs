#include "helpers/filenames.h"

void make_filepath(char **out, const char *dirname, const char *filename) {
    
    if (dirname == NULL || filename == NULL) {
        *out = NULL;
        return;
    }

    char *_dirname = strdup(dirname);
    const int res_len = strlen(dirname) + strlen(filename) + 2;

    *out = malloc(res_len * sizeof(char));
    strcpy(*out, "");

    char last_dirname_char = '\0';
    if (strlen(_dirname) > 0)
        last_dirname_char = _dirname[strlen(_dirname) - 1];
    
    if (last_dirname_char == *FILENAME_SEPARATOR)
        _dirname[strlen(_dirname) - 1] = '\0';
    
    snprintf(*out, res_len, "%s%s%s", _dirname, FILENAME_SEPARATOR, filename);

    free(_dirname);
}