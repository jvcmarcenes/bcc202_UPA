all:
	gcc *.c -c -Wall
	gcc *.o -o upa

run:
	make all
	./upa < test.in

run_1:
	make all
	./upa < 1.in > out.out

test:
	make all
	./upa < test.in > result.out
	diff result.out test.out

clear:
	rm *.o upa out.out
