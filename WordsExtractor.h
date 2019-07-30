#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINE_MAX_BUFFER 80 /*max size is 80 characters at most. It is NOT including '\n', but it includes '\0'*/
#define NEW_LINE_CHAR_COUNT 1


void start_extraction(FILE*);

char* extract_by_whitespaces(char*);

char* extract_by_colon(char*);
