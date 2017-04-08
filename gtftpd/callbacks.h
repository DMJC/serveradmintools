#ifndef CALLBACKS_H
#define CALLBACKS_H
#include "gtftpd.h"

void inetd_checkbox_toggled_cb(void);

void timeout_entry_activate_cb(void);

void retry_timeout_entry_activate_cb(void);

void multicast_port_entry_activate_cb(void);

void multicast_address_entry_activate_cb(void);

void multicast_ttl_entry_activate_cb(void);

void max_thread_entry_activate_cb(void);

void verbose_entry_activate_cb(void);

void folder_entry_activate_cb(void);

void browse_button_activate_cb(void);

void save_button_activate_cb(void);

void quit_button_activate_cb(GtkWidget* widget,gpointer user_data);
#endif
