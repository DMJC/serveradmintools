#ifndef GTFTPD_H
#define GTFTPD_H
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "input.h"
//#include "callbacks.h"

int timeout;
int retry_timeout;
int multicast_port;
char *multicast_address;
int multicast_ttl;
int max_thread;
int verbose;
char *folder;
int inetd;
char *filename;

GtkWidget       *inetd_checkbox;
GtkWidget       *timeout_entry;
GtkWidget       *retry_timeout_entry;
GtkWidget       *multicast_port_entry;
GtkWidget       *multicast_address_entry;
GtkWidget       *multicast_ttl_entry;
GtkWidget       *max_thread_entry;
GtkWidget       *verbose_entry;
GtkWidget       *folder_entry;
GtkWidget       *browse_button;
GtkWidget       *file_location_label;

#endif

