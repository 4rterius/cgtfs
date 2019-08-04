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
    feed->levels = NULL;
    feed->levels_count = 0;
    feed->pathways = NULL;
    feed->pathways_count = 0;
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
    char *levels_fname;
    char *pathways_fname;
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
    make_filepath(&levels_fname, feed_directory_path, "levels.txt");
    make_filepath(&pathways_fname, feed_directory_path, "pathways.txt");
    make_filepath(&routes_fname, feed_directory_path, "routes.txt");
    make_filepath(&shapes_fname, feed_directory_path, "shapes.txt");
    make_filepath(&stop_times_fname, feed_directory_path, "stop_times.txt");
    make_filepath(&stops_fname, feed_directory_path, "stops.txt");
    make_filepath(&transfers_fname, feed_directory_path, "transfers.txt");
    make_filepath(&trips_fname, feed_directory_path, "trips.txt");

    init_feed(instance);

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

    FILE *fp_levels = fopen(levels_fname, "r");
    if (fp_levels) {
        instance->levels_count = read_all_levels(fp_levels, &(instance->levels));
        fclose(fp_levels);
    } else {
        instance->levels_count = -1;
    }

    FILE *fp_pathways = fopen(pathways_fname, "r");
    if (fp_pathways) {
        instance->pathways_count = read_all_pathways(fp_pathways, &(instance->pathways));
        fclose(fp_pathways);
    } else {
        instance->pathways_count = -1;
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
    free(levels_fname);
    free(pathways_fname);
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
    if (feed->levels_count > 0) {
        free(feed->levels);
    }
    if (feed->pathways_count > 0) {
        free(feed->pathways);
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

int equal_feeds(const feed_t *a, const feed_t *b) {
    if (a->agency_count != b->agency_count)
        return 0;

    if (a->calendar_dates_count != b->calendar_dates_count)
        return 0;

    if (a->calendar_records_count != b->calendar_records_count)
        return 0;

    if (a->fare_attributes_count != b->fare_attributes_count)
        return 0;

    if (a->fare_rules_count != b->fare_rules_count)
        return 0;

    if (a->feed_info_count != b->feed_info_count)
        return 0;

    if (a->frequencies_count != b->frequencies_count)
        return 0;

    if (a->levels_count != b->levels_count)
        return 0;

    if (a->pathways_count != b->pathways_count)
        return 0;

    if (a->routes_count != b->routes_count)
        return 0;

    if (a->shapes_count != b->shapes_count)
        return 0;

    if (a->stop_times_count != b->stop_times_count)
        return 0;

    if (a->stops_count != b->stops_count)
        return 0;

    if (a->transfers_count != b->transfers_count)
        return 0;

    if (a->trips_count != b->trips_count)
        return 0;


    for (int i = 0; i < a->agency_count; i++)
        if (!equal_agency(&(a->agencies[i]), &(b->agencies[i])))
            return 0;

    for (int i = 0; i < a->calendar_dates_count; i++)
        if (!equal_calendar_date(&(a->calendar_dates[i]), &(b->calendar_dates[i])))
            return 0;

    for (int i = 0; i < a->calendar_records_count; i++)
        if (!equal_calendar_record(&(a->calendar_records[i]), &(b->calendar_records[i])))
            return 0;

    for (int i = 0; i < a->fare_attributes_count; i++)
        if (!equal_fare_attributes(&(a->fare_attributes[i]), &(b->fare_attributes[i])))
            return 0;

    for (int i = 0; i < a->fare_rules_count; i++)
        if (!equal_fare_rule(&(a->fare_rules[i]), &(b->fare_rules[i])))
            return 0;

    for (int i = 0; i < a->feed_info_count; i++)
        if (!equal_feed_info(&(a->feed_info[i]), &(b->feed_info[i])))
            return 0;

    for (int i = 0; i < a->frequencies_count; i++)
        if (!equal_frequency(&(a->frequencies[i]), &(b->frequencies[i])))
            return 0;

    for (int i = 0; i < a->levels_count; i++)
        if (!equal_level(&(a->levels[i]), &(b->levels[i])))
            return 0;

    for (int i = 0; i < a->pathways_count; i++)
        if (!equal_pathway(&(a->pathways[i]), &(b->pathways[i])))
            return 0;

    for (int i = 0; i < a->routes_count; i++)
        if (!equal_route(&(a->routes[i]), &(b->routes[i])))
            return 0;

    for (int i = 0; i < a->shapes_count; i++)
        if (!equal_shape(&(a->shapes[i]), &(b->shapes[i])))
            return 0;

    for (int i = 0; i < a->stop_times_count; i++)
        if (!equal_stop_time(&(a->stop_times[i]), &(b->stop_times[i])))
            return 0;

    for (int i = 0; i < a->stops_count; i++)
        if (!equal_stop(&(a->stops[i]), &(b->stops[i])))
            return 0;

    for (int i = 0; i < a->transfers_count; i++)
        if (!equal_transfer(&(a->transfers[i]), &(b->transfers[i])))
            return 0;

    for (int i = 0; i < a->trips_count; i++)
        if (!equal_trip(&(a->trips[i]), &(b->trips[i])))
            return 0;

    return 1;
}