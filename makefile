ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o songnode.o songlib.o
	$(CC) -o songfxns main.o songnode.o songlib.o

main.o: main.c songnode.h
	$(CC) -c main.c

songlib.o: songlib.c songlib.h songnode.c songnode.h
	$(CC) -c songlib.c songnode.c

songnode.o: songnode.c songnode.h
	$(CC) -c songnode.c

run:
	./songfxns

clean:
	touch main.o
	touch a.out
	rm *.o
	rm a.out
