#include "main.h"

int 		main		(int argc, char* argv[])
{
    /*int 			counter					= 0;
    FILE* 			inputFilePointer 		= NULL;*/
	line			newLine;
	labelTable*		table					= NULL;
	
	strcpy (newLine.label, "Main");
	strcpy (newLine.srcoperand, "r3");
	strcpy (newLine.desoperand, "LIST[sz]");
	newLine.ope							= mov;
	newLine.srctype						= storageAddress;
	newLine.destype						= indexAddress;
	
	from_line_to_bmc(&newLine, 100, table);
	
    /*TODO: The counter is starting from 1 since in previous executions it added '.as' to the actual assembler file.
     * In this case, the extension will be added only to the input file. */
    /*for(counter=1 ; counter<=argc ; counter++)
    {
        if (add_extension_to_file(argv[counter]) == 0)
        {
            if (open_or_create_file(&inputFilePointer, argv[counter]) == 0)
            {
                start_extraction(inputFilePointer);
            }
        }
    }*/

    return 0;
}
