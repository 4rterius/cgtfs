#include <stdio.h>
#include "feed.h"

/**
 * Example 0: read all feed data into memory
 */
void some_function(void) {
    // Feed initialization.
    //
    // As with all entity structs (records, feed,
    // db connection, etc.), init_T(T *) function must be called.
    //
    // Every such struct has to be eventually freed by free_T(T *),
    // with the notable exception of all record entities
    // (a unified approach to struct handling is still WIP).
    feed_t amazing_feed;
    init_feed(&amazing_feed);

    // Feed reading.
    //
    // This function is a convenience wrapper for calling
    // file-scope reading functions, which read the entire
    // *.txt files into arrays. This function passes pointers
    // to feed_t fields, and after reading stores the counts
    // of each parsed record type into _count fields.
    //
    // Obviously, takes **a lot** of memory.
    read_feed(&amazing_feed, "../tests/data/google_sample");

    // If a *.txt file does not exist or cannot be opened,
    // -1 is assigned to the corresponding _count field.
    // If the file can be opened but has no records, 0 is assigned.
    // Otherwise, the field gets the number of records read from the file.
    if (amazing_feed.agency_count > 0)
        printf("The agency's name is: %s \n", amazing_feed.agencies[0].name);
    else
        perror("Failed to open agency.txt or the file has no records");

    // Don't forget to call this function.
    // No, really :|
    free_feed(&amazing_feed);
}

int main() {
    some_function();
    return 0;
}