all:
	gcc *.c -c -Wall
	gcc *.o -o upa

run:
	make all
	./upa < test.in

test:
	make all
	./upa < test.in > result.out
	diff result.out test.out

clear:
	rm *.o upa
