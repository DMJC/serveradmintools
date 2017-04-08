#include "input.h"
int load_defaults(domain *new_domain){
	strcpy(new_domain->domain_name, "WORKGROUP");
	strcpy(new_domain->wins_server, "0.0.0.0");
	strcpy(new_domain->log_file_location, "/var/log/samba/log.%m");
	strcpy(new_domain->samba_crash_action, "/usr/share/samba/panicdomain-action %d");
	strcpy(new_domain->password_program, "/usr/bin/passwd %u");
	strcpy(new_domain->password_chat, "*Enter\\snew\\s*\\spassword:* %n\\n *Retype\\snew\\s*\\spassword:* %n\n *password\supdated\ssuccessfully* .");
	strcpy(new_domain->map_to_guest, "bad user");
	new_domain->wins_support = 0;
	new_domain->use_dns_proxy = 0;
	new_domain->bind_interfaces_only = 0;
	new_domain->maximum_log_size = 1000;
	new_domain->syslog_logging_level = 0;
	new_domain->server_role = 0;
	new_domain->passdb_backend = 0;
	new_domain->obey_pam_restrictions = 1;
	new_domain->sync_unix_passwords = 1;
	new_domain->pam_password_change = 1;
}

int load_smb_conf(char filename[]){
	printf("Configuration Filename is: %s\n", filename);

	FILE *conf_file;
	conf_file = fopen(filename, "r");

	int size;
	fseek(conf_file, 0L, SEEK_END);
	size = ftell(conf_file);

	char buffer[size];
	if( fgets (buffer, size, conf_file)!=NULL)
	   {
	      /* writing content to stdout */
	      puts(buffer);
	   }

/*	for (; ;){
	struct share *new_share;

	g_slist_append (shares_list, new_share);
	}*/
	fclose(conf_file);
	return 0;
}
