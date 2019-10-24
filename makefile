all: main.o list.o
	gcc -o listfxns main.o list.o

main.o: main.c headers.h
	gcc -c main.c

list.o: list.c headers.h
	gcc -c list.c

run:
	./listfxns

clean:
	rm *.o
	rm *.swp
