#ifndef TYPES_H
#define TYPES_H
typedef struct _share share;
typedef struct _domain domain;

struct _domain {
		char *domain_name[1024];
		char wins_server[1024];
		char log_file_location[1024];
		char samba_crash_action[1024];
		char password_program[1024];
		char password_chat[1024];
		char map_to_guest[1024];
		int wins_support;
		int use_dns_proxy;
		int bind_interfaces_only;
		int maximum_log_size;
		int syslog_logging_level;
		int server_role;
		int passdb_backend;
		int obey_pam_restrictions;
		int sync_unix_passwords;
		int pam_password_change;
};


struct _share {
		GtkGrid *share_grid;
		char share_name[1024];
		char share_description[8192];
		char share_path[2048];
		int create_mask;
		int directory_mask;
		int guest_access;
		int browseable;
		int writeable;
		char valid_users[1024];
		char invalid_users[1024];
};

#endif
