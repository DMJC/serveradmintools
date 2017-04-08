#include "gui.h"
void gui(int argc, char *argv[]){
        GtkBuilder      *builder;
        GtkWidget       *window;

	printf("Making Gui\n");
        gtk_init(&argc, &argv);

        builder = gtk_builder_new();
        gtk_builder_add_from_file (builder, "gsshd.gtkbuilder", NULL);

        window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window")); 

        gtk_builder_connect_signals(builder, NULL);

        g_object_unref(builder);

        gtk_widget_show(window);
        gtk_main();
}
