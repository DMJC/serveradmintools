GSList *global_options;

typedef struct _shared_network shared_network;
typedef struct _subnet subnet;
typedef struct _network network;
typedef struct _pool pool;
typedef struct _host host;

struct _network {

};

enum ddns_style {
	none,
	ad-hoc,
	interim,
	standard
};

int default-lease-time;
int max-lease-time;

int ddns_update_style;
bool authoritative;

char *log_facility[256];

struct _subnet {
	char *subnet[37];
	char *netmask[37];
	char *range1[37];
	char *range2[37];
	int bootp;
	GSList *options;

};

struct _host {
	char *name[2048];
	char *fixed_address[2048];
	int file_or_servername;
	char *filename[2048];
	char *server_name[2048];
};

struct _shared_network {
	char *name[2048];
	GSList *subnets;
	GSList *pools;
};

struct _pool {
	int allow_deny_members;
	;
	char range1[37];
	char range2[37];
};
