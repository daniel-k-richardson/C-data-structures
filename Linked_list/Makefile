driver: node.o linked_list.o driver.o
	gcc node.o linked_list.o driver.o -o driver

driver.o: driver.c
	gcc -c driver.c

node.o: node.c node.h
	gcc -c node.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

clean:
	rm *.o driver
