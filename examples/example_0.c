#include <stdio.h>
#include "feed.h"

// Example 0: read all feed data into memory
void some_function(void) {
    feed_t amazing_feed;
    init_feed(&amazing_feed);
    read_feed(&amazing_feed, "../tests/data/google_sample");

    if (amazing_feed.agency_count > 0)
        printf("The agency's name is: %s \n", amazing_feed.agencies[0].name);
    else
        perror("Failed to open agency.txt or the file has no records");
    
    free_feed(&amazing_feed);
}

int main() {
    some_function();
    return 0;
}