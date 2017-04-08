#include "callbacks.h"

void inetd_checkbox_toggled_cb(){

}

void timeout_entry_activate_cb(){
	sprintf(timeout_entry, "%d",  timeout);
	gtk_entry_set_text(GTK_ENTRY (timeout_entry), timeout);
	printf("Timeout Entry Activated\n");
}

void retry_timeout_entry_activate_cb(){
	sprintf(retry_timeout_entry, "%d",  retry_timeout);
	gtk_entry_set_text(GTK_ENTRY (retry_timeout_entry), retry_timeout);
	printf("Retry Timeout Entry Activated\n");
}

void multicast_port_entry_activate_cb(){
	sprintf(multicast_port_entry, "%d",  multicast_port);
	gtk_entry_set_text(GTK_ENTRY (multicast_port_entry), multicast_port);
	printf("Folder Entry Activated\n");
}

void multicast_address_entry_activate_cb(){
	sprintf(multicast_address_entry, "%d",  multicast_address);
	gtk_entry_set_text(GTK_ENTRY (multicast_address_entry), multicast_address);
	printf("Folder Entry Activated\n");
}

void multicast_ttl_entry_activate_cb(){
	sprintf(multicast_ttl_entry, "%d",  multicast_ttl);
	gtk_entry_set_text(GTK_ENTRY (multicast_ttl_entry), multicast_ttl);
	printf("Folder Entry Activated\n");
}

void max_thread_entry_activate_cb(){
	sprintf(max_thread_entry, "%d",  max_thread);
	gtk_entry_set_text(GTK_ENTRY (max_thread_entry), max_thread);
	printf("Folder Entry Activated\n");
}

void verbose_entry_activate_cb(){
	sprintf(verbose_entry, "%d",  verbose);
	gtk_entry_set_text(GTK_ENTRY (verbose_entry), verbose);
	printf("Folder Entry Activated\n");
}

void folder_entry_activate_cb(){
	sprintf(folder_entry, "%d",  folder);
	gtk_entry_set_text(GTK_ENTRY (folder_entry), folder);
	printf("Folder Entry Activated\n");
}

void browse_button_activate_cb(){
	printf("Browse Button Activated\n");
}

void save_button_activate_cb(){
	printf("Save Activated\n");
	save();
}

void quit_button_activate_cb(GtkWidget* widget,gpointer user_data){
	printf("Quit Activated\n");
	gtk_main_quit();
}
