#include <stdio.h>
#include "feed.h"

// Example 0: read all feed data into memory
// (!) be careful, as reading ~12mb feed will take ~200mb of RAM.
void some_function(void) {
    feed_t amazing_feed = empty_feed();
    read_feed("../tests/data/google_sample", &amazing_feed);

    if (amazing_feed.agency_count > 0)
        printf("The agency's name is: %s \n", amazing_feed.agencies[0].name);
    else
        perror("Failed to open agency.txt or the file has no records");
}

int main() {
    some_function();
    return 0;
}