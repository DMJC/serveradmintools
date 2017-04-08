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

void delete_share_cb(int **this_share){
	printf("deleting share\n");
	printf("List length %d\n",g_slist_length (samba_share_list));
	printf("This share is the %dth share\n", g_slist_nth (samba_share_list, this_share));
	printf("this share = %x\n", **this_share);
	gtk_grid_remove_row(new_share_storage_grid, this_share -1);
	g_slist_remove (samba_share_list, g_slist_nth (samba_share_list, this_share));
	g_slist_free_1 (samba_share_list);
//	free(&*this_share);
	printf("List length after deletion: %d\n",g_slist_length (samba_share_list));
	gtk_widget_show_all(new_share_storage_grid);
}

void add_new_share_cb(GtkGrid *share_grid_holder){

	printf("Making New Samba Share\n");
	share *new_share = malloc (sizeof (share));

	new_share->share_grid = GTK_GRID(gtk_grid_new());

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
	GtkWidget *share_valid_users_label;
	GtkWidget *share_valid_users_entry;
	GtkWidget *share_invalid_users_label;
	GtkWidget *share_invalid_users_entry;
	GtkWidget *share_delete_button;
	GtkWidget *share_separator;

	share_name_label = gtk_label_new("Share Name:");
	share_name_entry = gtk_entry_new();
	share_description_label = gtk_label_new("Share Description:");
	share_description_entry = gtk_entry_new();
	share_path_label = gtk_label_new("Share Path:");
	share_path_entry = gtk_entry_new();
	share_guest_ok_checkbox = gtk_check_button_new_with_label("Guest OK:");
	share_browseable_checkbox = gtk_check_button_new_with_label("Browseable");
	share_create_mask_label = gtk_label_new("Create Mask:");
	share_create_mask_entry = gtk_entry_new();
	share_directory_mask_label = gtk_label_new("Directory Mask:");
	share_directory_mask_entry = gtk_entry_new();
	share_read_only_checkbox = gtk_check_button_new_with_label("Read Only");
	share_valid_users_label = gtk_label_new("Valid Users:");
	share_valid_users_entry = gtk_entry_new();
	share_invalid_users_label = gtk_label_new("Invalid Users:");
	share_invalid_users_entry = gtk_entry_new();

	share_delete_button = gtk_button_new_with_label("Delete Share");
	share_separator = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_widget_set_margin_top (share_separator, 8);

	gtk_grid_attach (new_share->share_grid, share_name_label, 0, 0, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_name_entry, 1, 0, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_description_label, 0, 1, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_description_entry, 1, 1, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_path_label, 0, 2, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_path_entry, 1, 2, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_guest_ok_checkbox, 1, 3, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_browseable_checkbox, 1, 4, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_create_mask_label, 0, 5, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_create_mask_entry, 1, 5, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_directory_mask_label, 0, 6, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_directory_mask_entry, 1, 6, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_valid_users_label, 0, 7, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_valid_users_entry, 1, 7, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_invalid_users_label, 0, 8, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_invalid_users_entry, 1, 8, 1, 1);

	gtk_grid_attach (new_share->share_grid, share_delete_button, 1, 9, 1, 1);
	gtk_grid_attach (new_share->share_grid, share_separator, 0, 10, 2, 1);

	if(prev_share == NULL || 0){
		printf("Previous Share is null, binding undernearth the Add Share Button\n");
		gtk_grid_attach (GTK_GRID(new_share_storage_grid), GTK_WIDGET(new_share->share_grid), 0, 0, 1, 1);
	} else {
		printf("Previous Share Exists, binding underneath previous share.\n");
		gtk_grid_attach (GTK_GRID(new_share_storage_grid), GTK_WIDGET(new_share->share_grid), 0, (g_slist_length (samba_share_list)), 1, 1);
	}
	samba_share_list = g_slist_append (samba_share_list, new_share);
	prev_share = new_share;

	printf("New Share Address: %p\n", *&new_share);
	printf("New Share Address: %p\n", &new_share);
	printf("New Share Address: %p\n", new_share);

	int* this_share = malloc(sizeof(int));
	this_share = g_slist_index (samba_share_list, new_share)+1;


	g_signal_connect (share_delete_button, "clicked", delete_share_cb, &this_share);
	printf("This Share = %p\n", this_share);
	printf("This Share = %x\n", this_share);
	printf("This Share = %d\n", this_share);


	printf("Postgrid\n");
        gtk_widget_show_all(new_share_storage_grid);
	printf("There are %d shares in the list\n", (g_slist_length (samba_share_list)));
	if ( 1 == g_slist_length (samba_share_list)){
		printf("This share is the %dst share in the list\n\n", (g_slist_index (samba_share_list, new_share)+1));
	}
	if ( 2 == g_slist_length (samba_share_list)){
		printf("This share is the %dnd share in the list\n\n", (g_slist_index (samba_share_list, new_share)+1));
	}
	if ( 3 == g_slist_length (samba_share_list)){
		printf("This share is the %drd share in the list\n\n", (g_slist_index (samba_share_list, new_share)+1));
	}
	if ( 4 <= g_slist_length (samba_share_list)){
		printf("This share is the %dth share in the list\n\n", (g_slist_index (samba_share_list, new_share)+1));
	}
}

void add_dummy_share(void){
	printf("Adding Dummy Share\n");
	share *new_share = malloc (sizeof (share));
	samba_share_list = g_slist_append (samba_share_list, new_share);	
}

void save_shares_cb(char filename[1024]){
	if (filename == NULL){
		printf("No Save File, Please select a file to save in\n");
	}
	printf("Writing Shares Out to File\n");
	int list_length = g_slist_length(samba_share_list);
	if ( list_length > 0 ){
		g_slist_foreach (samba_share_list, output_shares, NULL);
	}
}
