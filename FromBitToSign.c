#include "FromBitToSign.h"

/*Do binary movements and send 00 or 01 or 10 or 11 to the "to_4_base" function. Reutrns 0 if all good else returns -1.*/

int 	from_binary_machine_code_to_fourth_base 	(int short *binaryCode, int decimalAddressCounter)
{
	int 	counter 						= 0;
	char 	number 							= '\0';
	FILE	*pf								= NULL;
	char	bmcsign[numOfActiveBites/2]		= "";
	
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
	
	while (counter < (numOfActiveBites / 2))
	{
		if (*binaryCode % 2 == 1)
		{

			if (number == '\0')
			{
				number = '1';
			}
			
			else
			{				
				bmcsign[counter] = to_4_base(number, '1');
				
				if (bmcsign[counter] == '0')
				{
					return -1;
				}
				
				number = '\0';
				
				counter++;
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
				bmcsign[counter] = to_4_base(number, '0');
				
				if (bmcsign[counter] == '0')
				{
					return -1;
				}
				
				number = '\0';
				
				counter++;
			}
		}
		
		*binaryCode>>= 1;
	}
	
	printSignToFile(bmcsign, pf);
	
	fputc('\n', pf);
	
	fclose(pf); /*TODO: write functions that deal properly with files cleanup (such as clean_output_files)*/
	
	return 0;
}

/*Returns * or # or % or ! to the array. Reutrns 0 if all good.*/

char			to_4_base					(char firstBit, char secondBit)
{	
	secondBit 	= (secondBit - char_to_asci) * 2;
	firstBit	= (firstBit - char_to_asci);
		
	switch(secondBit + firstBit)
	{
		case 0:
				/* return * to the array*/
				return '*';
				
				break;
			
		case 1:
				/* return # to the array*/
				return '#';
				
				break;
		
		case 2:
				/* return % to the array*/
				return '%';
				
				break;
				
		case 3:
				/* return ! to the array*/
				return '!';
				
				break; 
		
		default:
				/* write error*/
				fprintf(stderr,"There is a problem with the translation to 4 base \n"); /*TODO: write functions that deal properly with errors (such as write_error)*/
				return '0';
				
				break;
	}
	
	return '0';
}

/*Prints the array in the opposite way to the file. Returns 0 if all good, else returns -1.*/

int			printSignToFile					(char *bmcsign, FILE* fp)
{
	int i;
	
	for (i = (numOfActiveBites/2 - 1) ; i >= 0 ; i--)
	{
		if(bmcsign[i] != '0')
		{			
			fputc(bmcsign[i], fp);
		}
		
		else
		{
			return -1;
		}
	}
	
	return 0;
}
