/* Do binary movements and send 00 or 01 or 10 or 11 to the "to_4_base" function. Reutrns 0 if all good. */

int 	from_binary_machine_code_to_fourth_base 	(short *binaryCode, int decimalAddressCounter) 
{
	int 		counter 		= 0;
	char 		number 			= '\0';
	File		*pf				= null;
	
	if (check_if_file_exists(psLocation) == -1)
	{
		create_file(psLocation, 'ps.ob');
	}
	
	fp = open_file(psLocation);
		
		if (fp == null)
		{
			return -1;
		}
	
	if (decimalAddressCounter < maxNumDecimalAddress)
	{
		putchar('0', fp);
	}
	
	fprintf(fp, "%d", decimalAddressCounter);
	
	putchar('\t', fp);
	
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
				to_4_base(number, '1', fp);
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
				to_4_base(number, '0', fp);
				number = '\0';
			}
		}
		
		counter++;
		
		*binaryCode<<= 2;
	}
	
	putchar('\n', fp);
	
	fclose(fp);
	
	free(fp);
	
	return 0;
}

/* check if the file exists, if yes puts * or # or % or !. If does not exists create the file and than put the correct sign. Reutrns 0 if all good.*/

int 		to_4_base					(char firstBitBit, char secondBit, file *fp)
{
	secondBit = secondBit * 2;
	
	switch(secondBit + firstBit)
	{
		case 0:
				/* write * to the file*/
				putchar('*', fp);
				
				break;
			
		case 1:
				/* write # to the file*/
				putchar('#', fp);
				
				break;
		
		case 2:
				/* write % to the file*/
				putchar('%', fp);
				
				break;
				
		case 3:
				/* write ! to the file*/
				putchar('!', fp);
				
				break; 
		
		default:
				/* write error*/
				write_error("There is a problem with the translation to 4 base");			
				return -1;
				
				break;
	}
	
	return 0;
}

int 			main					(void) 
{
	short aaa = 127;
	from_binary_machine_code_to_fourth_base(&aaa);
	
	return 0;
}
