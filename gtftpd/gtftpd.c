#include "gtftpd.h"
//#include "callbacks.h"

FILE *output_file;

int timeout = 300;
int retry_timeout = 300;
int multicast_port = 1758;
char *multicast_address = "239.239.239.0-255";
int multicast_ttl = 1;
int max_thread = 100;
int verbose = 5;
char *folder = "/var/sftp";
int inetd = 0;
char *filename = "/etc/default/atftpd";

GtkWidget	*inetd_checkbox;
GtkWidget	*timeout_entry;
GtkWidget	*retry_timeout_entry;
GtkWidget	*multicast_port_entry;
GtkWidget	*multicast_address_entry;
GtkWidget	*multicast_ttl_entry;
GtkWidget	*max_thread_entry;
GtkWidget	*verbose_entry;
GtkWidget	*folder_entry;
GtkWidget	*browse_button;
GtkWidget	*file_location_label;

int main(int argc, char *argv[]){
	printf("Welcome to gftpd\n");
	if(geteuid() != 0)
	{
		printf("Run gtftpd again as root.\n");
		return 0;
	}
	int load_attempt = 0;
	if (load_attempt == load(filename)){
		printf("load succeeded\n");
	}else{
		printf("load failed, using defaults\n");
	}
	gui_main(argc, argv);
return 0;
}

void inetd_checkbox_toggled_cb(){
	printf("Inetd Toggled\n");
}

void timeout_entry_activate_cb(){
	timeout_entry = g_strdup_printf( "%d",  timeout);
	printf("Timeout Entry Activated\n");
	printf("Timeout entry contents: %s\n", timeout_entry );
}

void retry_timeout_entry_activate_cb(){
	retry_timeout_entry = g_strdup_printf( "%d",  retry_timeout);
	printf("Retry Timeout Entry Activated\n");
}

void multicast_port_entry_activate_cb(){
	multicast_port_entry = g_strdup_printf( "%d",  multicast_port);
	printf("Multicast Port Entry Activated\n");
}

void multicast_address_entry_activate_cb(){
	multicast_address_entry = g_strdup_printf( "%d",  multicast_address);
	printf("Multicast Address Entry Activated\n");
}

void multicast_ttl_entry_activate_cb(){
	multicast_ttl_entry = g_strdup_printf( "%d",  multicast_ttl);
	printf("Multicast TTL Entry Activated\n");
}

void max_thread_entry_activate_cb(){
	max_thread_entry = g_strdup_printf( "%d",  max_thread);
	printf("Max Thread Entry Activated\n");
}

void verbose_entry_activate_cb(){
	verbose_entry = g_strdup_printf( "%d",  verbose);
	printf("Verbose Entry Activated\n");
}

void folder_entry_activate_cb(){
	printf("Folder Entry Activated\n");
	sprintf(folder_entry, "%s",  folder);
	gtk_entry_set_text(GTK_ENTRY (folder_entry), folder);
}

void browse_button_activate_cb(){
	printf("Browse Button Activated\n");
}

/*   char startup[20];
   strcpy( startup, "service atftpd start" );
   char shutdown[20];
   strcpy( shutdown, "service atftpd stop" );*/

void start_server_cb(){
	system("service atftpd start");
	printf("Service Started\n");
}

void stop_server_cb(){
	system("service atftpd stop");
	printf("Service Stopped\n");
}

void save_button_activate_cb(){
	printf("Save Activated\n");
	void save();
}

void quit_button_activate_cb(GtkWidget* widget,gpointer user_data){
	printf("Quit Activated\n");
	gtk_main_quit();
}

