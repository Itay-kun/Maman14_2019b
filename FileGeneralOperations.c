#include "FileGeneralOperations.h"

int is_valid_file(char *file_name)
{

}

int check_if_file_exists(char *fullDirectory)
{
	if( access( fname, F_OK ) != -1 )
	{
		return 0;
	}
	
	else
	{
		return -1;
	}
}

int add_extention_to_file (char *FilePath)
{
	FilePath = strcat(FilePath, '.as');
	
	return 0;
}

int open_or_create_file (file *pf, char *FilePath)
{
	if (check_if_file_exists(FilePath) == -1)
	{
		pf = fopen(FilePath, 'w+');
	}
	
	else
	{
		pf = fopen(FilePath, 'r+');
	}
		
	if (pf == null)
	{
		return -1;
	}
	
	return 0;
}