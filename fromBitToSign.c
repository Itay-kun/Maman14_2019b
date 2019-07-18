/* Do binary movements and send 00 or 01 or 10 or 11 to the "to_4_base" function. Reutrns 0 if all good. */
#include "FromBitToSign.h"
#include "main.h"


int 	from_binary_machine_code_to_fourth_base 	(short *binaryCode, int decimalAddressCounter) 
{
	int 		counter 		= 0;
	char 		number 			= '\0';
	FILE		*pf				= NULL;
	
	if (open_or_create_file(pf, __FILENAME__) == -1)
	{
		return -1;
	}
	
	if (decimalAddressCounter < maxNumDecimalAddress)
	{
		fputc('0', pf);
	}
	
	fprintf(pf, "%d", decimalAddressCounter);
	
	fputc('\t', pf);
	
	while (counter < numOfActiveBites)
	{
		if (*binaryCode % 2 == 1)
		{
			if (number == '\0')
			{
				number = '1';
			}
			
			else
			{
				to_4_base(number, '1', pf);
				number = '\0';
			}
		}
		
		else
		{
			if (number == '\0')
			{
				number = '0';
			}
			
			else
			{
				to_4_base(number, '0', pf);
				number = '\0';
			}
		}
		
		counter++;
		
		*binaryCode<<= 2;
	}
	
	fputc('\n', pf);
	
	clean_output_files(pf);
	
	return 0;
}

/* check if the file exists, if yes puts * or # or % or !. If does not exists create the file and than put the correct sign. Reutrns 0 if all good.*/

int 		to_4_base					(char firstBit, char secondBit, FILE* fp)
{
	secondBit = secondBit * 2;
	
	switch(secondBit + firstBit)
	{
		case 0:
				/* write * to the file*/
				fputc('*', fp);
				
				break;
			
		case 1:
				/* write # to the file*/
				fputc('#', fp);
				
				break;
		
		case 2:
				/* write % to the file*/
				fputc('%', fp);
				
				break;
				
		case 3:
				/* write ! to the file*/
				fputc('!', fp);
				
				break; 
		
		default:
				/* write error*/
				write_error("There is a problem with the translation to 4 base");			
				return -1;
				
				break;
	}
	
	return 0;
}
