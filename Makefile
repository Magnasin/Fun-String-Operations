fancy_replace: main.o fancy_replace.o
	gcc main.o fancy_replace.o -o a

main.o: main.c
	gcc -c main.c -o main.o

fancy_replace.o: fancy_replace.c fancy_replace.h
	gcc -c fancy_replace.c -o fancy_replace.o

clean:
	rm -f main.o fancy_replace.o a*
