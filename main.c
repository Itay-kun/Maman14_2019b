//
// Created by avivk on 16/07/2019.
//

#include "main.h"

int main(int argc,char* argv[]){
    int counter=0;
    FILE* inputFilePointer = NULL;

    for(counter=0 ; counter<=argc ; counter++)
    {
        if (add_extension_to_file(argv[counter]) == 0)
        {
            if (open_or_create_file(inputFilePointer, argv[counter]) == 0)
            {
                start_extraction(inputFilePointer);
            }
        }

        short aaa = 127;
        int decimalAddressCounter = 0;
        from_binary_machine_code_to_fourth_base(&aaa, decimalAddressCounter);
    }
    return 0;
}