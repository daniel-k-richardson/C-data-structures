bst_driver: bst.o main.o
	gcc bst.o main.o -o bst_driver

bst.o: bst.c bst.h
	gcc -c bst.c

main.o: main.c
	gcc -c main.c

clean:
	rm *.o bst_driver
