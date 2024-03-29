/* Includes 	*/

#include 	<stdio.h>
#include	"WordsExtractor.h"
#include	"FromBitToSign.h"
#include	"FromBitToSign.h"

/*  Defines		*/

#define		opcode						4
#define		storageOperand				3
#define		operand						2

/* Prototypes 	*/

int			from_line_to_bmc			(line*, int, labelTable*);
short int  	from_normal_line			(line*, labelTable*);
short int	create_operation_bmc		(line*);
int 		test_label					(line*, labelTable*);
int			from_operation_to_binary	(char [], operation);
int			to_decimal					(int);
int			from_operand_to_binary		(char [], hash);
short int	src_des_storage				(line*);
int			from_storage_to_binary		(char [], int);
/*void		printArray					(char []);*/


