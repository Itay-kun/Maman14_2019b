/* Includes 		*/

#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<string.h>
#include 	<unistd.h>

/* Definitions		*/

#define 	LINE_MAX_BUFFER 				80 /*max size is 80 characters at most. It is NOT including '\n', but it includes '\0'*/
#define 	NEW_LINE_CHAR_COUNT 			1
#define 	max_Label 						31
#define		max_operand						25
#define 	MAX_WORDS_COUNT_IN_SENTENCE		5

/* Prototypes 		*/

void 		start_extraction		(FILE*);
void 		extract_by_whitespaces	(char*);
char* 		extract_by_colon		(char*);

/* Structures 		*/

  typedef enum
  {
	  immediateAddress,
	  directAddress,
	  indexAddress,
	  storageAddress
  } hash;

  typedef enum
  {
	  mov,
	  cmp,
	  add,
	  sub,
	  not,
	  clr,
	  lea,
	  inc,
	  dec,
	  jmp,
	  bne,
	  red,
	  prn,
	  jsr,
	  rts,
	  stop
  } operation;
  
    typedef struct
  {
	  operation 	ope;
	  char			binaryCode;
	  hash			source;
	  hash			destination;
  } oper;
  
    typedef struct
  {
	  char 			label[max_Label];
	  operation		ope;
	  char			srcoperand[max_operand];
	  char			desoperand[max_operand];
	  hash			srctype;
	  hash			destype;
  } line;

    typedef struct
    {
    	char* 		label[max_Label];
    	int 		value;
    } labelTable;
