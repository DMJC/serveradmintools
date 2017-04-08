#ifndef INPUT_H
#define INPUT_H
#include "gsamba.h"
#include "types.h"

int load_smb_conf(char filename[]);
int load_defaults(domain *new_domain);

#endif
