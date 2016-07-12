stack: node.o stack.o stack_driver.o
	gcc node.o stack.o stack_driver.o -o stack

stack_driver.o: stack_driver.c
	gcc -c stack_driver.c

node.o: node.c node.h
	gcc -c node.c

stack.o: stack.c stack.h
	gcc -c stack.c

clean:
	rm *.o stack
