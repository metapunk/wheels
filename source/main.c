#include "log.h"

int main() {

	log_file* lf = log_open("test.log");
	log_print( lf, "Hello World." );
	log_print( lf, "Hello to you, sir!" );
	log_close( lf );

	return 0;
}
