/*
 * Author: Daniel Richardson.
 * Date & Version: 1 12 2015.
 * Purpose:
 *
 */

#include <stdbool.h>
#include "node.h"
#include "stack.h"

/* Represents our stack data type */
struct Stack
{
	node *top;
};

/*
 * Creates a new stack for use then returns it.
 *
 * Parameters:
 * no parameters.
 *
 * Return: newly created stack "new_stack".
 */
Stack create_stack()
{
    Stack new_stack = NULL;
    if ((new_stack = (Stack)malloc(sizeof(*new_stack))) == NULL) {
		perror("Could not allocate memory for new stack inside create_stack()");
		exit(EXIT_FAILURE);
	}
	new_stack->top = NULL;
	
	return new_stack;
}

/*
 * Check whether or not the stack has elements.
 *	
 * Parameters:
 * current_stack to check whether or not it is empty.
 *
 * Return: Return true if the stack is empty otherwise return false.
 */
bool is_stack_empty(Stack current_stack)
{
    bool is_empty = false;

	if (current_stack->top == NULL) {
		is_empty = true;
	}

	return is_empty;
}

/*
 * Push pushes an item onto the stack by creating a node and linking it to the previous
 * one and updating the stack's 'top_of_stack' each time.
 *
 * Parameters:
 * current_stack to push item on.
 * data is the item being pushed.
 *
 * Return: void	
 */
void push(Stack current_stack, void *data)
{
	node *new_node = create_node(data);
	
	/* General case, the stack is not empty */
	if (!is_stack_empty(current_stack)) {
		set_previous(&current_stack->top, &new_node);
	}
	current_stack->top = new_node;
}

/*
 * Get the value of the top of the stack.
 *
 * Parameters:
 * current_stack the stack to get the value of the top element.
 *
 * Return: return the char stored inside the top of the stack.
 */
void *top(Stack current_stack)
{
	return get_data(current_stack->top);
}

/*
 * Removes the top element from the stack and updates the top to become the previous element.
 *
 * Parameters:
 * current_stack is the stack to pop from.
 *
 * Returns: void.	
 */
void pop(Stack current_stack)
{
	node *top = current_stack->top;

	if (top != NULL) {
		current_stack->top = get_previous(top);
		destroy_node(top);
	}

}
