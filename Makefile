all:
	gcc *.c -c -Wall
	gcc *.o -o upa

run:
	make all
	./upa
