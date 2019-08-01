/* Includes 	*/

#include 	<stdio.h>
#include	<math.h>
#include	"WordsExtractor.h"
#include	"FromBitToSign.h"
#include	"FromBitToSign.h"

/*  Defines		*/

#define		opcode						4
#define		operand						2

/* Prototypes 	*/

int			from_line_to_bmc			(line*, int, char*);
short int 	from_normal_line			(line*, char*);
int			create_operation_bmc		(line*);
int 		test_label					(line*, char*);
int			from_operation_to_bynary	(char*, operation);
int			to_decimal					(int);
int			from_operand_to_bynary		(char*, hash);




