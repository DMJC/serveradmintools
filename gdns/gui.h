#ifndef GUI_H
#define GUI_H

#include "gdns.h"
#include "types.h"

GtkBuilder *builder;
GtkWidget *main_window;
GtkWidget *share_entry_page;
GtkWidget *share_grid;
GtkWidget *share_button_grid;
struct share *prev_share;
void gui (int argc, char *argv[], domain *new_domain);

#endif
