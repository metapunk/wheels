/* Copyright 2014 Richard Slater */

#ifndef __log_h_included__
#define __log_h_included__

#include "stdbool.h"

typedef struct {
	char* file_name;
	void* attached_mutex;
	void* attached_file;
	bool is_timestamp_enabled;
} log_file;

log_file* log_open(const char* a_file_name);
void log_close(log_file* a_log_file);
void log_print(log_file* a_log_file, const char* a_msg);

#endif
