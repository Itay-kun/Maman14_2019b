//
// Created by avivk on 16/07/2019.
//

#include "main.h"

int main(char* argv[]){
    int counter=0;

    for(counter=0 ; counter<=argv.length() ; counter++)
    {
        if (is_valid_file(argv[counter]) == 1)
        {
            if (open_file(argv[counter]) != NULL)
            {
                start_extraction(argv[i]);
            }

        }
    }


    return 0;
}