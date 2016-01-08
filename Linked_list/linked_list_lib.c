/*
 * Author: Daniel Richardson
 * Date: 24th November 2015
 * Purpose: A linked list implementation for a youtube tutorial.
 */

#include "linked_list_lib.h"

/* A new linked_list_int type that will represent a linked list */
struct linked_list_int
{
	node first;
};

/* Create and initialise a linked list. */
void linked_list_init(linked_list *l)
{
	// Initialise and dynamically create a new list in memory.
	linked_list new_list = (linked_list)malloc(sizeof(struct linked_list_int));
	new_list->first = NULL;
}

/* Check whether or not the list is empty. */
bool is_empty(linked_list l)
{
	if (l->first == NULL)
	{
		return true;
	}
	return false;
}

/*
 * Create a new node, assign the new node the value passed in as a value,
 * check for singleton or general case i.e is the new node created the first
 * or not. If it is the singleton then assign current and the list's first
 * to point to the new node. Otherwise, set it to currents next, then update
 * current to point to the new node in the linked list.
 *	
 * in other words, link the new node to the list.
 */
void add_element(linked_list *l, int value)
{
	// NOTE the static keyword keeps the last updated value assigned to it.
	static node current = NULL;
	node new_node = NULL;
	node first = (*l)->first;
	
	init_node(&new_node, value);
	
	// Singleton case, there are no elements in our linked list.
	if (is_empty((*l)))
	{
		current = new_node;
		first = new_node;
		(*l)->first = new_node;
	}
	else
	{
		// General case, add the new node to the end of the list.
		set_next_node(current, new_node);
		current = get_next_node(current);
	}
}

/* 
 * Does what it says on the tin - traverses through all the nodes in the list
 * and prints those values out to the console.
 */	
void traverse(linked_list l)
{
	node current = l->first;
	
	while (current != NULL)
	{
		printf("The value inside the node is \"%d\"\n", get_node_value(current));
		current = get_next_node(current);
	}
}