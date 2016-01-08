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
	node *top_of_stack;
};

/*
 * Creates a new stack for use then returns it.
 *
 * Parameters:
 * no parameters.
 *
 * Return: newly created stack "new_stack".
 */
stack *create_stack()
{
	stack *new_stack = (stack *)malloc(sizeof(stack));
	
	if (new_stack == NULL)
	{
		fprintf(stderr, "Could not allocate memory for new stack inside create_stack()");
		exit(1);
	}
	new_stack->top_of_stack = NULL;
	
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
bool is_stack_empty(stack *current_stack)
{
	bool is_empty;

	if (current_stack->top_of_stack == NULL)
	{
		is_empty = true;
	}
	else
	{
		is_empty = false;
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
void push(stack *current_stack, void *data)
{
	node *new_node = create_node(data);
	
	/* General case, the stack is not empty */
	if (!is_stack_empty(current_stack))
	{
		set_previous(&current_stack->top_of_stack, &new_node);
	}
	current_stack->top_of_stack = new_node;
}

/*
 * Get the value of the top of the stack.
 *
 * Parameters:
 * current_stack the stack to get the value of the top element.
 *
 * Return: return the char stored inside the top of the stack.
 */
void *top(stack *current_stack)
{
	return get_data(current_stack->top_of_stack);
}

/*
 * Removes the top element from the stack and updates the top to become the previous element.
 *
 * Parameters:
 * current_stack is the stack to pop from.
 *
 * Returns: void.	
 */
void pop(stack *current_stack)
{
	node *top = current_stack->top_of_stack;

	if (top != NULL)
	{
		current_stack->top_of_stack = get_previous(top);
		destroy_node(top);
	}

}
