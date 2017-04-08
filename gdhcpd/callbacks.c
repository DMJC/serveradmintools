#include "callbacks.h"




void save_dhcp_config_cb(void){
	printf("Writing DHCP Configuration to File\n");
	g_slist_foreach (samba_share_list, output_shares, NULL);
}

