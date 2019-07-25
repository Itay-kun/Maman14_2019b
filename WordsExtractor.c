#include "WordsExtractor.h"


void start_extraction(FILE* inputFilePointer){
    char *lineWithoutNewline = "";
    /*TODO: scan the line with fgets till \n or 80 char, whatever comes first*/

    fgets(lineWithoutNewline, LINE_MAX_BUFFER, inputFilePointer);
    while (lineWithoutNewline != NULL)
    {
        if (extract_by_whitespaces(lineWithoutNewline) != NULL)
        {
            fprintf(stdout,"The initial extraction was done successfully");
        }
    }

}

char* extract_by_whitespaces(char *lineWithoutNewline){
    char* wordsToken = "";
    char whitespaceDelimiters[]="\t\v\f\r";

    wordsToken = strtok(lineWithoutNewline,whitespaceDelimiters);

    return wordsToken;
}
