#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINE_MAX_BUFFER 79

void start_extraction(FILE*);

char* extract_by_whitespaces(char*);

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

  typedef enum
  {
	  immediateAddress,
	  directAddress,
	  indexAddress,
	  storageAddress
  } hash;
