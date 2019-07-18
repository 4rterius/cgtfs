CREATE TABLE agency (
	agency_id TEXT,
	agency_name TEXT PRIMARY KEY NOT NULL,
	agency_url TEXT NOT NULL,
	agency_timezone TEXT NOT NULL,
	agency_lang TEXT,
	agency_phone TEXT,
	agency_fare_url TEXT,
	agency_email TEXT
);

CREATE TABLE stops (
	stop_id TEXT PRIMARY KEY NOT NULL,
	stop_code TEXT,
	stop_name TEXT NOT NULL,
	stop_desc TEXT,
	stop_lat DOUBLE NOT NULL,
	stop_lon DOUBLE NOT NULL,
	zone_id TEXT,
	stop_url TEXT,
	location_type INT,
	parent_station TEXT,
	stop_timezone TEXT,
	wheelchair_boarding INT
);

CREATE TABLE routes (
	route_id TEXT PRIMARY KEY NOT NULL,
	agency_id TEXT,
	route_short_name TEXT,
	route_long_name TEXT,
	route_desc TEXT,
	route_type INT NOT NULL,
	route_url TEXT,
	route_color TEXT,
	route_text_color TEXT,
	route_sort_order INT
);

CREATE TABLE trips (
	route_id TEXT NOT NULL,
	service_id TEXT NOT NULL,
	trip_id TEXT PRIMARY KEY NOT NULL,
	trip_headsign TEXT,
	trip_short_name TEXT,
	direction_id INT,
	block_id TEXT,
	shape_id TEXT,
	wheelchair_accessible INT,
	bikes_allowed INT
);

CREATE TABLE stop_times (
	trip_id TEXT NOT NULL,
	arrival_time TEXT NOT NULL,
	departure_time TEXT NOT NULL,
	stop_id TEXT NOT NULL,
	stop_sequence INT NOT NULL,
	stop_headsign TEXT,
	pickup_type INT,
	drop_off_type INT,
	shape_dist_traveled REAL,
	timepoint INT
);

CREATE TABLE calendar (
	service_id TEXT PRIMARY KEY NOT NULL,
	monday INT NOT NULL,
	tuesday INT NOT NULL,
	wednesday INT NOT NULL,
	thursday INT NOT NULL,
	friday INT NOT NULL,
	saturday INT NOT NULL,
	sunday INT NOT NULL,
	start_date TEXT NOT NULL,
	end_date TEXT NOT NULL
);

CREATE TABLE calendar_dates (
	service_id TEXT NOT NULL,
	date TEXT NOT NULL,
	exception_type INT NOT NULL
);

CREATE TABLE fare_attributes (
	fare_id TEXT NOT NULL,
	price REAL NOT NULL,
	currency_type TEXT NOT NULL,
	payment_method INT NOT NULL,
	transfers INT NOT NULL,
	agency_id TEXT,
	transfer_duration REAL
);

CREATE TABLE fare_rules (
	fare_id TEXT NOT NULL,
	route_id TEXT,
	origin_id TEXT,
	destination_id TEXT,
	contains_id TEXT
);

CREATE TABLE shapes (
	shape_id TEXT PRIMARY KEY NOT NULL,
	shape_pt_lat DOUBLE NOT NULL,
	shape_pt_lon DOUBLE NOT NULL,
	shape_pt_sequence INT NOT NULL,
	shape_dist_traveled REAL
);

CREATE TABLE frequencies (
	trip_id TEXT NOT NULL,
	start_time TEXT NOT NULL,
	end_time TEXT NOT NULL,
	headway_secs INT NOT NULL,
	exact_times INT
);

CREATE TABLE transfers (
	from_stop_id TEXT NOT NULL,
	to_stop_id TEXT NOT NULL,
	transfer_type INT NOT NULL,
	min_transfer_time INT
);

CREATE TABLE feed_info (
	feed_publisher_name TEXT NOT NULL,
	feed_publisher_url TEXT NOT NULL,
	feed_lang TEXT NOT NULL,
	feed_start_date TEXT,
	feed_end_date TEXT,
	feed_version TEXT,
	feed_contact_email TEXT,
	feed_contact_url TEXT
);

CREATE TABLE levels (
	level_id TEXT NOT NULL,
	level_index DOUBLE NOT NULL,
	level_name TEXT
);

CREATE TABLE pathways (
	pathway_id TEXT NOT NULL,
	from_stop_id TEXT NOT NULL,
	to_stop_id TEXT NOT NULL,
	pathway_mode INT NOT NULL,
	is_bidirectional INT NOT NULL,
	length DOUBLE,
	traversal_time INT,
	stair_count INT,
	max_slope DOUBLE,
	min_width DOUBLE,
	signposted_as TEXT,
	reversed_signposted_as TEXT
);