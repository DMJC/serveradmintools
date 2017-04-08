#include "output.h"

void output_shares(share *share/*, char filename[1024]*/){
	if(share->share_name != NULL){
		printf("[%s]\n", share->share_name);
	if(share->share_description != NULL){
		printf("comment = %s\n", share->share_description);
	}if(share->share_path != NULL){
		printf("path = %s\n", share->share_path);
	}if(share->create_mask != NULL){
		printf("create mask = %s\n", share->create_mask);
	}if(share->directory_mask != NULL){
		printf("directory mask = %s\n", share->directory_mask);
	}if (share->guest_access == 1){
		printf("guest ok = yes\n");
	}else{
		printf("guest ok = no\n");
	}
	if (share->browseable == 1){
		printf("browseable = yes\n");
	}else{
		printf("browseable = no\n");
	}
	if (share->writeable == 1){
		printf("writeable = yes\n");
	}else{
		printf("writeable = no\n");
	}
	printf("valid users = %s\n", share->valid_users);
	printf("invalid users = %s\n\n", share->invalid_users);
	}else{
		printf("Invalid share Name, you must specify a proper name.\n");
	}
}
