#include "gui.h"

void gui_main(int argc, char argv[]) {

        GtkBuilder      *builder;
        GtkWidget       *window;

        gtk_init(&argc, &argv);

        builder = gtk_builder_new();
        gtk_builder_add_from_file (builder, "gtftpd.gtkbuilder", NULL);

        window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window")); 

	timeout_entry = GTK_WIDGET(gtk_builder_get_object(builder, "timeout_entry"));
	retry_timeout_entry = GTK_WIDGET(gtk_builder_get_object(builder, "retry_timeout_entry"));
	multicast_port_entry = GTK_WIDGET(gtk_builder_get_object(builder, "multicast_port_entry"));
	multicast_address_entry = GTK_WIDGET(gtk_builder_get_object(builder, "multicast_address_entry"));
	multicast_ttl_entry = GTK_WIDGET(gtk_builder_get_object(builder, "multicast_ttl_entry"));
	max_thread_entry = GTK_WIDGET(gtk_builder_get_object(builder, "max_thread_entry"));
	verbose_entry = GTK_WIDGET(gtk_builder_get_object(builder, "verbose_entry"));
	folder_entry = GTK_WIDGET(gtk_builder_get_object(builder, "folder_entry"));
	file_location_label = GTK_WIDGET(gtk_builder_get_object(builder, "file_location_label"));

	char timeout_buffer[6];
	char retry_timeout_buffer[6];
	char multicast_port_buffer[6];
	char multicast_address_buffer[15];
	char multicast_ttl_buffer[6];
	char max_thread_buffer[6];
	char verbose_buffer[6];
	char folder_buffer[1024];
	char filename_buffer[1024];

	sprintf(timeout_buffer, "%d", timeout);
	sprintf(retry_timeout_buffer, "%d", retry_timeout);
	sprintf(multicast_port_buffer, "%d", multicast_port);
	sprintf(multicast_address_buffer, "%s", multicast_address);
	sprintf(multicast_ttl_buffer, "%d", multicast_ttl);
	sprintf(max_thread_buffer, "%d", max_thread);
	sprintf(verbose_buffer, "%d", verbose);
	sprintf(folder_buffer, "%s", folder);
	sprintf(filename_buffer, "%s", filename);

	gtk_entry_set_text (timeout_entry, timeout_buffer);
	gtk_entry_set_text (retry_timeout_entry, retry_timeout_buffer);
	gtk_entry_set_text (multicast_port_entry, multicast_port_buffer);
	gtk_entry_set_text (multicast_address_entry, multicast_address_buffer);
	gtk_entry_set_text (multicast_ttl_entry, multicast_ttl_buffer);
	gtk_entry_set_text (max_thread_entry, max_thread_buffer);
	gtk_entry_set_text (verbose_entry, verbose_buffer);
	gtk_entry_set_text (folder_entry, &folder_buffer);
	gtk_label_set_text (file_location_label, filename_buffer);

        gtk_builder_connect_signals(builder, NULL);

        g_object_unref(builder);

        gtk_widget_show(window);
        gtk_main();
}

