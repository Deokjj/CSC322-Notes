#    Makefile for the Modular program

Modular:	Modular.o Person.o
	gcc -o Modular Modular.o Person.o

Modular.o:	Modular.c Person.h CString.h PrettyPrint.h
	gcc -c Modular.c

Person.o:	Person.c Person.h CString.h
	gcc -c Person.c
