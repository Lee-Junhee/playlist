ifeq ($(DEBUG), true)
	(CC) = gcc -g
else
	(CC) = gcc
endif

all: main.o songs.o
	$(CC) -o songfxns main.o songs.o

main.o: main.c headers.h
	$(CC) -c main.c

songs.o: songs.c headers.h
	$(CC) -c songs.c

run:
	./listfxns

clean:
	touch main.o
	touch a.out
	rm *.o
	rm a.out
