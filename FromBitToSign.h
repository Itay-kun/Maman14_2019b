/* Includes 		*/

#include 	<stdio.h>
#include 	"FileGeneralOperations.h"

/* Definitions		*/

#define 	numOfActiveBites 							14 /* should be int he main.h!!!!!!!!!!!!!!*/
#define 	maxNumDecimalAddress 						1000
#define		char_to_asci								48

/* Prototypes 	*/

int	 		from_binary_machine_code_to_fourth_base 	(int short*, int);
char 		to_4_base									(char, char);
int			printSignToFile								(char*, FILE*);

