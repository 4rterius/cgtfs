#ifndef CGTFS_TESTS_FEED_C
#define CGTFS_TESTS_FEED_C

#include "feed.h"

int test_feed_good(void) {
    feed_t feed = empty_feed();
    read_feed("..\\tests\\data\\google_sample", &feed);
    
    return 0;
}

#endif