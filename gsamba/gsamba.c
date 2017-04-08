#include "gsamba.h"

int main(int argc, char *argv[]){
	printf("Welcome to gsamba\n");
	domain *new_domain = malloc (sizeof(domain));
	char filename[20] = {'/','e','t','c','/','s','a','m','b','a','/','s','m','b','.','c','o','n','f','\0'};
	GSList *samba_share_list = NULL;
	add_dummy_share();
        printf("There are now %d shares in the list\n", (g_slist_length (samba_share_list)));
	load_defaults(new_domain);
	if (load_smb_conf("/etc/samba/smb.conf") != 0){
		printf("Failed to load Samba Configuration File");
		*filename = NULL;
	}else{
	char filename[20] = {'/','e','t','c','/','s','a','m','b','a','/','s','m','b','.','c','o','n','f','\0'};
	};
	gui(argc, argv, new_domain);
return 0;
}
