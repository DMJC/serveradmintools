#ifndef CALLBACKS_H
#define CALLBACKS_H

#include "gsamba.h"
#include "gui.h"
#include "types.h"

void new_domain_cb(void);
void add_new_share_cb(GtkGrid *share_grid);
void add_dummy_share(void);
void delete_share_cb(int **this_share);
void save_shares_cb(char filename[]);

#endif
