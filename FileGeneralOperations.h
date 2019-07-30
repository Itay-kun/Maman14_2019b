#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define 	__FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

int is_valid_file(char*);

int check_if_file_exists(char*);

int add_extension_to_file(char*);

int open_or_create_file(FILE**, char*);

