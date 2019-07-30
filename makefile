all: assembler

assembler: FromBitToSign.o FileGeneralOperations.o main.o WordsExtractor.o CreateBMC.o
	gcc -ansi -Wall -pedantic -o assembler FromBitToSign.o FileGeneralOperations.o main.o WordsExtractor.o CreateBMC.o
	rm *.o

main.o: main.c main.h
	gcc -ansi -Wall -pedantic -c main.c

FromBitToSign.o: FromBitToSign.c FromBitToSign.h FileGeneralOperations.h
	gcc -ansi -Wall -pedantic -c FromBitToSign.c
 
FileGeneralOperations.o: FileGeneralOperations.c FileGeneralOperations.h
	gcc -ansi -Wall -pedantic -c FileGeneralOperations.c

WordsExtractor.o: WordsExtractor.c WordsExtractor.h
	gcc -ansi -Wall -pedantic -c WordsExtractor.c

CreateBMC.o: CreateBMC.c CreateBMC.h main.h
	gcc -ansi -Wall -pedantic -c CreateBMC.c

clean:
	rm *.o assembler*
