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
        // printf("\n lastdot = %li; lastsep = %li; lastdot-lastsep = %li \n", lastdot - opstr, lastsep - opstr, lastdot - lastsep);
        if (lastsep < lastdot) {
            if ((retstr = malloc(lastdot - lastsep)) == NULL) {
                free(opstr);
                return NULL;
            }
            strncpy(retstr, lastsep + 1, lastdot - lastsep - 1);
            retstr[lastdot - lastsep - 1] = '\0';
            free(opstr);
        } else {
            if ((retstr = malloc(opstr + strlen(opstr) - lastsep)) == NULL) {
                free(opstr);
                return NULL;
            }

            strncpy(retstr, lastsep + 1, opstr + strlen(opstr) - lastsep);
            free(opstr);
        }
    }

    if (lastdot && !lastsep) {
        if ((retstr = malloc(lastdot - opstr + 1)) == NULL) {
            free(opstr);
            return NULL;
        }

        strncpy(retstr, opstr, lastdot - opstr);
        retstr[lastdot - opstr] = '\0';
        free(opstr);
    }

    if (!lastdot && lastsep) {
        if ((retstr = malloc(opstr + strlen(opstr) - lastsep)) == NULL) {
            free(opstr);
            return NULL;
        }

        strncpy(retstr, lastsep + 1, opstr + strlen(opstr) - lastsep);
        free(opstr);
    }

    if (!lastdot && !lastsep) {
        return opstr;
    }

    return retstr;
}