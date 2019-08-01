/* Includes 		*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Definitions		*/

#define 	__FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define MAX_FILE_LENGTH 256
#define FILE_EXTENSION_LENGTH 3

/* Prototypes 	*/

int is_valid_file(char*);

int check_if_file_exists(char*);

int add_extension_to_file(char*);

int open_or_create_file(FILE**, char*);

