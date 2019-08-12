#include "str_utils.h"

char *get_filename_no_ext(char *src, char path_separator) {
    char *retstr, *retstr2;
    char *lastdot;
    char *lastsep;

    if (src == NULL)
         return NULL;

    if ((retstr = malloc(strlen(src) + 1)) == NULL)
        return NULL;

    strcpy(retstr, src);

    lastdot = strrchr(retstr, '.');
    lastsep = strrchr(retstr, path_separator);

    if (lastdot) {
        if (lastsep) {
            if (lastsep < lastdot) {
                *lastdot = '\0';
            }
        } else {
            *lastdot = '\0';
        }
    }

    if (lastsep) {
        retstr = lastsep + 1;
    }


    return retstr;
}