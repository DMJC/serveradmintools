#include "callbacks.h"

void new_domain_cb(void){
	printf("New Domain Callback Fired\n");
	void gui_create_new_domain();
}

void provision_domain_cb(void){
	printf("Provisioning New Samba Domain\n");

/*	char *command[];
	command = ""

	popen(command, "r");*/
}

void add_new_share_cb(GtkWidget *share_grid){
//	GtkBuilder *builder;
//	GtkWidget *

//	builder = gtk_builder_new_from_file("gsamba.gtkbuilder");
	printf("Making New Samba Share\n");

	struct share *new_share = malloc (sizeof (struct share));

	new_share->share_grid = gtk_grid_new();

	GtkWidget *share_name_label;
	GtkWidget *share_name_entry;
	GtkWidget *share_description_label;
	GtkWidget *share_description_entry;
	GtkWidget *share_path_label;
	GtkWidget *share_path_entry;
	GtkWidget *share_guest_ok_checkbox;
	GtkWidget *share_browseable_checkbox;
	GtkWidget *share_create_mask_label;
	GtkWidget *share_create_mask_entry;
	GtkWidget *share_directory_mask_label;
	GtkWidget *share_directory_mask_entry;
	GtkWidget *share_read_only_checkbox;

	share_name_label = gtk_label_new("Share Name");
	share_name_entry = gtk_entry_new();
	share_description_label = gtk_label_new("Share Description");
	share_description_entry = gtk_entry_new();
	share_path_label = gtk_label_new("Share Path");
	share_path_entry = gtk_entry_new();
	share_guest_ok_checkbox = gtk_check_button_new_with_label("Guest OK");
	share_browseable_checkbox = gtk_check_button_new_with_label("Browseable");
	share_create_mask_label = gtk_label_new("Create Mask");
	share_create_mask_entry = gtk_entry_new();
	share_directory_mask_label = gtk_label_new("Directory Mask");
	share_directory_mask_entry = gtk_entry_new();
	share_read_only_checkbox = gtk_check_button_new_with_label("Read Only");

	gtk_grid_attach (GTK_GRID(new_share->share_grid), share_name_label, 0, 0, 1, 1);
	gtk_grid_attach (GTK_GRID(new_share->share_grid), share_name_entry, 1, 0, 1, 1);
	gtk_grid_attach (GTK_GRID(new_share->share_grid), share_description_label, 0, 1, 1, 1);
	gtk_grid_attach (GTK_GRID(new_share->share_grid), share_description_entry, 1, 1, 1, 1);
	gtk_grid_attach (GTK_GRID(new_share->share_grid), share_path_label, 0, 2, 1, 1);
	gtk_grid_attach (GTK_GRID(new_share->share_grid), share_path_entry, 1, 2, 1, 1);
	gtk_grid_attach (GTK_GRID(new_share->share_grid), share_guest_ok_checkbox, 0, 3, 1, 1);
	gtk_grid_attach (GTK_GRID(new_share->share_grid), share_browseable_checkbox, 0, 4, 1, 1);
	gtk_grid_attach (GTK_GRID(new_share->share_grid), share_create_mask_label, 0, 5, 1, 1);
	gtk_grid_attach (GTK_GRID(new_share->share_grid), share_create_mask_entry, 1, 5, 1, 1);
	gtk_grid_attach (GTK_GRID(new_share->share_grid), share_directory_mask_label, 0, 6, 1, 1);
	gtk_grid_attach (GTK_GRID(new_share->share_grid), share_directory_mask_entry, 1, 6, 1, 1);

/*	new_share->share_grid = GTK_WIDGET(gtk_builder_get_object(builder, "share_add_window"));
	new_share->share_grid = GTK_WIDGET(gtk_builder_get_object(builder, "share_entry_page"));
	new_share->share_grid = gtk_builder_get_object(builder, "share_entry_page");

	printf("Signals\n");
        gtk_builder_connect_signals(builder, NULL);

	printf("Unref Signals\n");
        g_object_unref(builder);*/

	printf("Grid\n");
	if(prev_share == NULL){
		printf("Previous Share is null, binding undernearth the Add Share Button\n");
		gtk_grid_attach (GTK_GRID(share_grid), GTK_WIDGET(new_share->share_grid), 1, 1, 1, 1);
	} else {
		printf("Previous Share Exists, binding underneath previous share.\n");
		gtk_grid_attach (GTK_GRID(share_grid), GTK_WIDGET(new_share->share_grid), 0, (g_slist_length (samba_share_list)), 1, 1);
	}
	samba_share_list = g_slist_append (samba_share_list, new_share);
	prev_share = new_share;

	printf("Postgrid\n");
        gtk_widget_show(new_share->share_grid);
        gtk_widget_show(main_window);
	printf("There are %d shares in the list\n", (g_slist_length (samba_share_list)));
}

void save_new_share_cb(void){

}
