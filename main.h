#include 	"WordsExtractor.h"
#define 	max_Label 			31
#define		max_operand			25

  typedef enum
  {
	  immediate,
	  direct,
	  index,
	  storage
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
	  char 			label[max_Label];
	  operation		ope;
	  char			srcoperand[max_operand];
	  char			desoperand[max_operand];
	  hash			srctype;
	  hash			destype;
  } line;
  
  typedef struct
  {
	  operation 	ope;
	  char			binaryCode;
	  hash			source;
	  hash			destination;
  } oper;