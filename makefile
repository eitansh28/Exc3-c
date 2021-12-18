all: runlib stringProg

runlib: libEx3.a
libEx3.a: StringFunc.o
	ar -rcs libEx3.a StringFunc.o

StringFunc.o: StringFunc.c StringFunc.h
	gcc -Wall -g -c StringFunc.c

main.o: main.c StringFunc.h
	gcc -Wall -g -c main.c

stringProg:main.o libEx3.a
	gcc -Wall -o stringProg main.o libEx3.a

.PHONY: clean all

clean:
	rm -f *.o *.a stringProg
