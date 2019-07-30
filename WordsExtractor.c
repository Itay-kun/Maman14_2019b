#include "WordsExtractor.h"


void start_extraction(FILE* inputFilePointer)
{
    char *lineWithoutNewline = "";
    char *lineExtractedByWhitespace = "";
    char* lineExtractedByWhitespaceAndColon = "";
    /*TODO: scan the line with fgets till \n or 80 char, whatever comes first*/

    fgets(lineWithoutNewline, LINE_MAX_BUFFER + NEW_LINE_CHAR_COUNT, inputFilePointer);
    while (lineWithoutNewline != NULL)
    {
        lineExtractedByWhitespace = extract_by_whitespaces(lineWithoutNewline);
        if (lineExtractedByWhitespace != NULL)
        {
            fprintf(stderr,"The initial extraction (by whitespaces) was done successfully");
            lineExtractedByWhitespaceAndColon = extract_by_colon(lineExtractedByWhitespace);
            if (lineExtractedByWhitespaceAndColon != NULL)
            {
                /*fprintf(stderr,"The extraction by colon was done successfully");*/
            }
            else
            {
                /*fprintf(stderr,"The extraction by colon failed");*/
            }
        }
        else
        {
            /*fprintf(stderr,"The initial extraction failed");*/
        }
    }

}

char* extract_by_whitespaces(char *lineWithoutNewline)
{
    char* wordsToken = "";
    char whitespaceDelimiters[]="\t\v\f\r";

    wordsToken = strtok(lineWithoutNewline,whitespaceDelimiters);

    /*return wordsToken;*/
    return "";
}

char* extract_by_colon(char* lineExtractedByWhitespace)
{
    return "";
}