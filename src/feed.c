#include "feed.h"

void init_feed(feed_t *feed) {
    feed->agencies = NULL;
    feed->agency_count = 0;
    feed->calendar_dates = NULL;
    feed->calendar_dates_count = 0;
    feed->calendar_records = NULL;
    feed->calendar_records_count = 0;
    feed->fare_attributes = NULL;
    feed->fare_attributes_count = 0;
    feed->fare_rules = NULL;
    feed->fare_rules_count = 0;
    feed->feed_info = NULL;
    feed->feed_info_count = 0;
    feed->frequencies = NULL;
    feed->frequencies_count = 0;
    feed->routes = NULL;
    feed->routes_count = 0;
    feed->shapes = NULL;
    feed->shapes_count = 0;
    feed->stop_times = NULL;
    feed->stop_times_count = 0;
    feed->stops = NULL;
    feed->stops_count = 0;
    feed->transfers = NULL;
    feed->transfers_count = 0;
    feed->trips = NULL;
    feed->trips_count = 0;
}

int read_feed(feed_t *instance, const char *feed_directory_path) {
    char *agencies_fname;
    char *calendar_dates_fname;
    char *calendar_records_fname;
    char *fare_attributes_fname;
    char *fare_rules_fname;
    char *feed_info_fname;
    char *frequencies_fname;
    char *routes_fname;
    char *shapes_fname;
    char *stop_times_fname;
    char *stops_fname;
    char *transfers_fname;
    char *trips_fname;

    make_filepath(&agencies_fname, feed_directory_path, "agency.txt");
    make_filepath(&calendar_dates_fname, feed_directory_path, "calendar_dates.txt");
    make_filepath(&calendar_records_fname, feed_directory_path, "calendar.txt");
    make_filepath(&fare_attributes_fname, feed_directory_path, "fare_attributes.txt");
    make_filepath(&fare_rules_fname, feed_directory_path, "fare_rules.txt");
    make_filepath(&feed_info_fname, feed_directory_path, "feed_info.txt");
    make_filepath(&frequencies_fname, feed_directory_path, "frequencies.txt");
    make_filepath(&routes_fname, feed_directory_path, "routes.txt");
    make_filepath(&shapes_fname, feed_directory_path, "shapes.txt");
    make_filepath(&stop_times_fname, feed_directory_path, "stop_times.txt");
    make_filepath(&stops_fname, feed_directory_path, "stops.txt");
    make_filepath(&transfers_fname, feed_directory_path, "transfers.txt");
    make_filepath(&trips_fname, feed_directory_path, "trips.txt");

    FILE *fp_agencies = fopen(agencies_fname, "r");
    if (fp_agencies) {
        instance->agency_count = read_all_agencies(fp_agencies, &(instance->agencies));
        fclose(fp_agencies);
    } else {
        instance->agency_count = -1;
    }

    FILE *fp_calendar_dates = fopen(calendar_dates_fname, "r");
    if (fp_calendar_dates) {
        instance->calendar_dates_count = read_all_calendar_dates(fp_calendar_dates, &(instance->calendar_dates));
        fclose(fp_calendar_dates);
    } else {
        instance->calendar_dates_count = -1;
    }

    FILE *fp_calendar_records = fopen(calendar_records_fname, "r");
    if (fp_calendar_records) {
        instance->calendar_records_count = read_all_calendar_records(fp_calendar_records, &(instance->calendar_records));
        fclose(fp_calendar_records);
    } else {
        instance->calendar_records_count = -1;
    }

    FILE *fp_fare_attributes = fopen(fare_attributes_fname, "r");
    if (fp_fare_attributes) {
        instance->fare_attributes_count = read_all_fare_attributes(fp_fare_attributes, &(instance->fare_attributes));
        fclose(fp_fare_attributes);
    } else {
        instance->fare_attributes_count = -1;
    }

    FILE *fp_fare_rules = fopen(fare_rules_fname, "r");
    if (fp_fare_rules) {
        instance->fare_rules_count = read_all_fare_rules(fp_fare_rules, &(instance->fare_rules));
        fclose(fp_fare_rules);
    } else {
        instance->fare_rules_count = -1;
    }

    FILE *fp_feed_info = fopen(feed_info_fname, "r");
    if (fp_feed_info) {
        instance->feed_info_count = read_all_feed_info(fp_feed_info, &(instance->feed_info));
        fclose(fp_feed_info);
    } else {
        instance->feed_info_count = -1;
    }

    FILE *fp_frequencies = fopen(frequencies_fname, "r");
    if (fp_frequencies) {
        instance->frequencies_count = read_all_frequencies(fp_frequencies, &(instance->frequencies));
        fclose(fp_frequencies);
    } else {
        instance->frequencies_count = -1;
    }

    FILE *fp_routes = fopen(routes_fname, "r");
    if (fp_routes) {
        instance->routes_count = read_all_routes(fp_routes, &(instance->routes));
        fclose(fp_routes);
    } else {
        instance->routes_count = -1;
    }

    FILE *fp_shapes = fopen(shapes_fname, "r");
    if (fp_shapes) {
        instance->shapes_count = read_all_shapes(fp_shapes, &(instance->shapes));
        fclose(fp_shapes);
    } else {
        instance->shapes_count = -1;
    }

    FILE *fp_stop_times = fopen(stop_times_fname, "r");
    if (fp_stop_times) {
        instance->stop_times_count = read_all_stop_times(fp_stop_times, &(instance->stop_times));
        fclose(fp_stop_times);
    } else {
        instance->stop_times_count = -1;
    }

    FILE *fp_stops = fopen(stops_fname, "r");
    if (fp_stops) {
        instance->stops_count = read_all_stops(fp_stops, &(instance->stops));
        fclose(fp_stops);
    } else {
        instance->stops_count = -1;
    }

    FILE *fp_transfers = fopen(transfers_fname, "r");
    if (fp_transfers) {
        instance->transfers_count = read_all_transfers(fp_transfers, &(instance->transfers));
        fclose(fp_transfers);
    } else {
        instance->transfers_count = -1;
    }

    FILE *fp_trips = fopen(trips_fname, "r");
    if (fp_trips) {
        instance->trips_count = read_all_trips(fp_trips, &(instance->trips));
        fclose(fp_trips);
    } else {
        instance->trips_count = -1;
    }
    

    free(agencies_fname);
    free(calendar_dates_fname);
    free(calendar_records_fname);
    free(fare_attributes_fname);
    free(fare_rules_fname);
    free(feed_info_fname);
    free(frequencies_fname);
    free(routes_fname);
    free(shapes_fname);
    free(stop_times_fname);
    free(stops_fname);
    free(transfers_fname);
    free(trips_fname);

    return 0;
}

void free_feed(feed_t *feed) {
    if (feed->agency_count > 0) {
        free(feed->agencies);
    }
    if (feed->calendar_dates_count > 0) {
        free(feed->calendar_dates);
    }
    if (feed->calendar_records_count > 0) {
        free(feed->calendar_records);
    }
    if (feed->fare_attributes_count > 0) {
        free(feed->fare_attributes);
    }
    if (feed->fare_rules_count > 0) {
        free(feed->fare_rules);
    }
    if (feed->feed_info_count > 0) {
        free(feed->feed_info);
    }
    if (feed->frequencies_count > 0) {
        free(feed->frequencies);
    }
    if (feed->routes_count > 0) {
        free(feed->routes);
    }
    if (feed->shapes_count > 0) {
        free(feed->shapes);
    }
    if (feed->stop_times_count > 0) {
        free(feed->stop_times);
    }
    if (feed->stops_count > 0) {
        free(feed->stops);
    }
    if (feed->transfers_count > 0) {
        free(feed->transfers);
    }
    if (feed->trips_count > 0) {
        free(feed->trips);
    }
}