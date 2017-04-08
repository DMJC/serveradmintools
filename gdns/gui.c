#include "gui.h"

GtkBuilder *builder;

void gui(int argc, char *argv[], domain *new_domain){
	GtkWidget	*domain_entry;
	GtkWidget	*log_file_entry;
	GtkWidget	*log_size_entry;
	GtkWidget	*wins_server_entry;
	GtkWidget	*panic_action_entry;
	GtkWidget	*syslog_level_entry;

	prev_share = NULL;
	printf("Making Gui\n");
        gtk_init(&argc, &argv);

	builder = gtk_builder_new_from_file("gsamba.gtkbuilder");
	gtk_builder_add_from_file (builder, "gsamba.gtkbuilder", NULL);

        domain_entry = gtk_builder_get_object(builder, "domain_entry");
        wins_server_entry = gtk_builder_get_object(builder, "wins_server_entry");
        log_file_entry = gtk_builder_get_object(builder, "log_file_entry");
        panic_action_entry = gtk_builder_get_object(builder, "panic_action_entry");
        syslog_level_entry = gtk_builder_get_object(builder, "syslog_level_entry");
        main_window = gtk_builder_get_object(builder, "main_window");
	share_grid = gtk_builder_get_object(builder, "share_grid");
	share_button_grid = gtk_builder_get_object(builder, "share_button_grid");

	gtk_entry_set_text (domain_entry, new_domain->domain_name);
	gtk_entry_set_text (wins_server_entry, new_domain->wins_server);
	gtk_entry_set_text (log_file_entry, new_domain->log_file_location);
	gtk_entry_set_text (panic_action_entry, new_domain->samba_crash_action);
	gtk_entry_set_text (syslog_level_entry, new_domain->syslog_logging_level);

        gtk_builder_connect_signals(builder, NULL);
//        g_object_unref(builder);

        gtk_widget_show(main_window);
        gtk_main();
}

void gui_create_new_domain(){
        GtkBuilder      *builder;
        GtkWidget       *new_domain_window;

	printf("Making Provisioning Gui\n");
        builder = gtk_builder_new();
        gtk_builder_add_from_file (builder, "gsamba.gtkbuilder", NULL);

        new_domain_window = gtk_builder_get_object(builder, "domain_provision_window"); 

        gtk_builder_connect_signals(builder, NULL);

        g_object_unref(builder);

        gtk_widget_show(new_domain_window);
}
