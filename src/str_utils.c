#include "str_utils.h"

char *get_filename_no_ext(char *src, char path_separator) {
    char *opstr, *retstr;
    char *lastdot;
    char *lastsep;

    if (src == NULL)
         return NULL;

    if ((opstr = malloc(strlen(src) + 1)) == NULL)
        return NULL;

    strcpy(opstr, src);

    lastdot = strrchr(opstr, '.');
    lastsep = strrchr(opstr, path_separator);

    if (lastdot && lastsep) {
        if (lastsep < lastdot) {
            *lastdot = '\0';
            opstr = lastsep + 1;
        }
    }

    if (lastdot && !lastsep) {
        *lastdot = '\0';
    }

    if (!lastdot && lastsep) {
         opstr = lastsep + 1;
    }

    if (!lastdot && !lastsep) {

    }

    // printf("\nallocated: %li byte(s), freed: %li byte(s)\n", strlen(src) + 1, strlen(opstr) + 1);

    return opstr;
}