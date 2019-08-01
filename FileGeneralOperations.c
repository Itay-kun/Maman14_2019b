#include "FileGeneralOperations.h"

int is_valid_file(char *file_name)
{
	return 0;
}

int check_if_file_exists(char *fullDirectory)
{
	if( access (fullDirectory, F_OK ) != -1 )
	{
		return 0;
	}
	
	else
	{
		return -1;
	}
}

int add_extension_to_file (char *filePath)
{
	/*
	char* filePathWithExtension;
	char* mvCommand;
	char* mvVariables;
	mvVariables = "";
	filePathWithExtension = (char*)malloc(MAX_FILE_LENGTH + FILE_EXTENSION_LENGTH);
	mvCommand = (char*)malloc(MAX_FILE_LENGTH*2 + FILE_EXTENSION_LENGTH + 3);
	strcpy(filePath,filePathWithExtension);
	strcat(filePathWithExtension,".as");
	strcat(mvVariables,filePath);
	strcat(mvVariables," ");
	strcat(mvVariables, filePathWithExtension);
	sprintf(mvCommand, "mv %s",mvVariables);
	free(filePathWithExtension);
	if (system(mvCommand) == -1)
	{
		fprintf(stdout,"The rename operation ended with errors");
		free(mvCommand);
		return -1;
	}
	else
	{
		free(mvCommand);
		return 0;
	}
	*/
	return 0;

}

int open_or_create_file (FILE **pf, char *FilePath)
{
	if (check_if_file_exists(FilePath) == -1)
	{
		*pf = fopen(FilePath, "w+");
	}
	
	else
	{
		*pf = fopen(FilePath, "r+");
	}
		
	if (*pf == NULL)
	{
		return -1;
	}

	return 0;
}
