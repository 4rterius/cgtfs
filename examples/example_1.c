#include <stdio.h>

#include "helpers/filenames.h"
#include "reading.h"

void do_stuff_with_stop(stop_t *stop);

/**
 * Example 1: read all bus stops into memory
 */
void another_function(void) {
    int stops_count = 0;
    stop_t *stops;

    // It's 100% up to the developer to ensure
    // that the correct file is passed
    // to the parsing functions.
    FILE *fp = fopen("../tests/data/google_sample/stops.txt", "r");
    if (fp) {
        // The function allocates all the required memory.
        stops_count = read_all_stops(fp, &stops);
        fclose(fp);
    }

    for (int i = 0; i < stops_count; i++)
        do_stuff_with_stop(&(stops[i]));

    if (stops_count > 0)
        free(stops);
}

void do_stuff_with_stop(stop_t *stop) {
        printf("<stop %s>\n", stop->id);
        printf("  Name:       %s\n", stop->name);
        printf("  Latitude:   %Lf\n", stop->lat);
        printf("  Longitude:  %Lf\n\n", stop->lon);
}

int main() {
    another_function();
    return 0;
}