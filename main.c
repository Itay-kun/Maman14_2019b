//
// Created by avivk on 16/07/2019.
//

#include "main.h"

int main(char* argv[]){
    int counter=0;
    FILE* inputFilePointer = NULL;

    for(counter=0 ; counter<=argv.length() ; counter++)
    {
        add_extention_to_file()
        if (open_or_create_file(inputFilePointer, argv[counter]) != -1)
        {
            start_extraction(argv[i]);
        }
    }
    return 0;
}