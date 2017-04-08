#include "output.h"

void save(void) {

	FILE *output_file = fopen(filename, "w");

	if (inetd == 0){
		fprintf(output_file, "USE_INETD=true");
	}else{
		fprintf(output_file, "USE_INETD=false");
	}

	fprintf(output_file, "OPTIONS=\"--tftpd-timeout %d --retry-timeout %d --mcast-port %d --mcast-addr %s --mcast-ttl %d --maxthread %d --verbose=%d %s\"", timeout, retry_timeout, multicast_port, multicast_address, multicast_ttl, max_thread, verbose, folder);
	fclose(output_file);
}
