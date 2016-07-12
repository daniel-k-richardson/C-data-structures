/*
 * Author: Daniel Richardson.
 * Date & Version: 1 12 2015.
 * Purpose: Testbed for the stack.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

int main()
{
	// Declare and initialise a stack 
	Stack new_stack = create_stack();
	
	// Elements to push onto the stack.
	char *name1 = "Daniel";
	char *name2 = "david";
	char *name3 = "Paul";
	char *name4 = "Peter";
	
	// Push items into stack
	push(new_stack, (void *) name1);
	push(new_stack, (void *) name2);
	push(new_stack, (void *) name3);
	push(new_stack, (void *) name4);

	// Example of getting the top of the stack, popping the top element
	// and showing the new item at the top of the stack.
	printf("The top of the stack is \"%s\"\n", (char *) top(new_stack));
	
	pop(new_stack);
	printf("The new top of the stack after pop is  \"%s\"\n", (char *) top(new_stack));

	pop(new_stack);
	printf("The new top of the stack after pop is  \"%s\"\n", (char *) top(new_stack));

	pop(new_stack);
	printf("The new top of the stack after pop is  \"%s\"\n", (char *) top(new_stack));
	
	return EXIT_SUCCESS;
}