all: Maman14

Maman14: FromBitToSign.o FileGeneralOperations.o main.o WordsExtractor.o
	gcc -ansi -Wall -pedantic -o Maman14 FromBitToSign.o 			FileGeneralOperations.o main.o WordsExtractor.o

FromBitToSign.o: FromBitToSign.c FromBitToSign.h FileGeneralOperations.h
	gcc -ansi -Wall -pedantic -c FromBitToSign.c
 
FileGeneralOperations.o: FileGeneralOperations.c FileGeneralOperations.h
	gcc -ansi -Wall -pedantic -c FileGeneralOperations.c

main.o: main.c main.h
	gcc -ansi -Wall -pedantic -c main.c

WordsExtractor.o: WordsExtractor.c WordsExtractor.h
	gcc -ansi -Wall -pedantic -c WordsExtractor.c

clean:
	rm *.o *~Maman14
