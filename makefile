all: main.o list.o
	gcc -o listfxns main.o list.o

main.o: main.c headers.h
	gcc -c main.c

list.o: list.c headers.h
	gcc -c list.c

run:
	./listfxns

clean:
	touch main.o
	touch a.out
	rm *.o
	rm a.out

debug: main.c list.c headers.h
	gcc -g main.c list.c

gdb: a.out
	gdb a.out

valgrind: a.out
	valgrind --leak-check=yes ./a.out
