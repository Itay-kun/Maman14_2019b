#include 	"CreateBMC.h"

int			from_line_to_bmc			(line* nextLine, int decimalAdderess, labelTable* table)
{		
	if (nextLine->label != NULL)
	{		
		if (nextLine->desoperand != NULL && nextLine->srcoperand != NULL)
		{	
			from_binary_machine_code_to_fourth_base(from_normal_line(nextLine, table), decimalAdderess);
		}
	}
	return 0;
}

short int 	from_normal_line			(line* nextLine, labelTable* table)
{
	if (test_label (nextLine, table) == -1)
	{
		return -1;
	}
	
	return create_operation_bmc(nextLine);
}

short int	create_operation_bmc		(line *nextLine)
{
	int 		i				= numOfActiveBites - 5; /* Unsed bits */
	int 		j				= 0;
	short int	counter			= 0;
	char		op[opcode]		= "";
	char		opr[operand]	= "";
	
	from_operation_to_bynary (op, nextLine->ope);
	
	for ( j = (opcode - 1) ; j >= 0 ; j--)
	{				
		counter += ((int)(op[j] - char_to_asci) * to_decimal(i));
		
		i--;
	}
	
	from_operand_to_bynary (opr, nextLine->srctype);
	
	for ( j = 0 ; j <= (operand - 1) ; j++)
	{				
		counter += ((int)(opr[j] - char_to_asci) * to_decimal(i));
		
		i--;
	}
	
	from_operand_to_bynary (opr, nextLine->destype);
	
	for ( j = 0 ; j <= (operand - 1) ; j++)
	{		
		counter += ((int)(opr[j] - char_to_asci) * to_decimal(i));
		
		i--;
	}
	
	return counter;
}

int			from_operation_to_bynary	(char op[], operation ope) /* change ope to pointer ?*/
{
	int			i, j;
	
	i							= opcode;
	j							= 8; /* TODO define ? */
	
	while ( i != 0)
	{		
		if (ope > j)
		{		
			op[opcode - i] = '1';
		
			ope -= j;
		}
	
		else
		{
			op[opcode - i] = '0';
		}
		
		i--;
		
		j /= 2;
	}
	
	return 0;
}

int 		test_label					(line* nextLine, labelTable* table)
{
	int 	i 				= 0;
	
	if (table == NULL)
	{
		return 0;
	}
	
	while (i < (sizeof(table) - 1)) /*TODO check whatsapp from Aviv*/
	{
		if (strcmp (nextLine->label, *table[i].label) == 0)
		{
				break;
		}
		
		i++;
	}
	
	if (i == (sizeof(table) - 1))
	{
		fprintf(stderr,"The label %s is not exist in the file. \n", nextLine->label); /*TODO: write functions that deal properly with errors (such as write_error)*/
		
		return -1;
	}
	
	return i;
}

int			to_decimal					(int power)
{
	int			i, j;
	
	for ( j = 2, i = 1 ; i < power ; i++)
	{
		j*= 2;
	}
	
	return j;
}

int			from_operand_to_bynary		(char opr[], hash oprtype)
{
	int			i, j;
		
	i							= operand;
	j							= operand;
	
	while ( i != 0)
	{
		if (oprtype >= j)
		{
			opr[operand - i] = '1';
		
			oprtype -= j;
		}
	
		else
		{
			opr[operand - i] = '0';
		}
		
		i--;
		
		j /= 2;
	}
	
	return 0;
}

/*int			get_local_are				(line* nextLine)
{
	if (nextLine->srctype == immediateAddress)
	{
		return 0;
	}
}*/
