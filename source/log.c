/* Copyright 2014 Richard Slater. Open Source under the MIT License */

#include "log.h"
#include "mutex.h"
#include "stdio.h"
#include "stdlib.h"

log_file* log_open(const char* a_file_name) {
	log_file* lf;
	lf = malloc(sizeof(*lf));
	lf->attached_file = fopen(a_file_name, "w");
	mutex* mut = mutex_create();
	lf->attached_mutex = mut;
	return lf;
}

void log_close(log_file* a_log_file) {
	fclose(a_log_file->attached_file);
	mutex_destroy(a_log_file->attached_mutex);
}

void log_print(log_file* a_log_file, const char* a_msg) {
	mutex_lock(a_log_file->attached_mutex);
	fprintf(a_log_file->attached_file, "%s", a_msg);
	fprintf(a_log_file->attached_file, "\n");
	mutex_unlock(a_log_file->attached_mutex);
}
