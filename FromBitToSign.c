/* Do binary movements and send 00 or 01 or 10 or 11 to the "to_4_base" function. Reutrns 0 if all good. */
#include "main.h"

int 	from_binary_machine_code_to_fourth_base 	(int short *binaryCode, int decimalAddressCounter)
{
	int 	counter 						= 0;
	char 	number 							= '\0';
	FILE	*pf								= NULL;
	
	if (open_or_create_file(&pf, "ps.ob") == -1)
	{
		return -1;
	}
	
	if (decimalAddressCounter < maxNumDecimalAddress)
	{		
		fputc('0', pf); /*puts 0 befor the IC number if it is less then 1000*/
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
				if (to_4_base(number, '1', pf) != 0)
				{
					return -1;
				}
				
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
				if (to_4_base(number, '0', pf) != 0)
				{
					return -1;
				}
				
				number = '\0';
			}
		}
		
		counter++;
		
		*binaryCode>>= 1;
	}
	
	fputc('\n', pf);
	
	fclose(pf); /*TODO: write functions that deal properly with files cleanup (such as clean_output_files)*/
	
	return 0;
}

/* check if the file exists, if yes puts * or # or % or !. If does not exists create the file and than put the correct sign. Reutrns 0 if all good.*/

int			to_4_base					(char firstBit, char secondBit, FILE* fp)
{
	secondBit 	= (secondBit - char_to_asci) * 2;
	firstBit	= (firstBit - char_to_asci);
		
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
				fprintf(stderr,"There is a problem with the translation to 4 base \n"); /*TODO: write functions that deal properly with errors (such as write_error)*/
				return -1;
				
				break;
	}
	
	return 0;
}
