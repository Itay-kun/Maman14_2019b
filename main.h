#include 	"WordsExtractor.h"
#include 	"FromBitToSign.h"
#include 	"FileGeneralOperations.h"

#define 	max_Label 			31
#define		max_operand			25
#define		char_to_asci		48
#define 	__FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
/*TODO: Write it as a regular condition structure*/

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
	  char 			label[max_Label];
	  operation		ope;
	  char			srcoperand[max_operand];
	  char			desoperand[max_operand];
	  hash			srctype;
	  hash			destype;
	  /*Add a value of - is it dc? and the value of the dc*/
  } line;
  
  typedef struct
  {
	  operation 	ope;
	  char			binaryCode;
	  hash			source;
	  hash			destination;
  } oper;
