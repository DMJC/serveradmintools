#include "input.h"

int load(char *filename) {

	FILE *input_file = fopen(filename, "r");

	if (inetd == 0){
		fprintf(input_file, "USE_INETD=true");
	}else{
		fprintf(input_file, "USE_INETD=false");
	}

	fprintf(input_file, "OPTIONS=\"--tftpd-timeout %d --retry-timeout %d --mcast-port %d --mcast-addr %s --mcast-ttl %d --maxthread %d --verbose=%d %s\"", timeout, retry_timeout, multicast_port, multicast_address, multicast_ttl, max_thread, verbose, folder);
	fclose(input_file);
	return 0;
}
