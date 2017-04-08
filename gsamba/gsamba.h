#ifndef GSAMBA_H
#define GSAMBA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "manipulate.h"
#include "input.h"
#include "output.h"
#include "gui.h"
#include "types.h"

GSList *samba_share_list;

int main(int argc, char *argv[]);

typedef struct _domain domain;

#endif

