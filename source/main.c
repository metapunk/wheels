/* Copyright 2014 Richard Slater. Open Source under the MIT License */

#include "mutex.h"
#include "log.h"

void run_mutex_tests() {
	mutex* mut = mutex_create();
	mutex_lock(mut);
	mutex_unlock(mut);
	mutex_destroy(mut);
}

void run_log_tests() {
	log_file* lf = log_open("test.log");
	log_print(lf, "Gentlemen. You can't fight in here. This is the war room!");
	log_print(lf, "End of line, man.");
	log_close(lf);
}

int main() {
	run_mutex_tests();
	run_log_tests();
	return 0;
}
