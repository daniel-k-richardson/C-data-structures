/*
 * Author: Daniel Richardson
 * Date: 24th of November 2015
 * Purpose: creates single nodes that linked_list_lib.c uses to create
 * its list with.
 */

#include "node_lib.h"

/* A type node, which holds an int value and a pointer to the next node */
struct node_int
{
	int value;
	node next;
};

/* Create a new node, set the value of the node and set its next to NULL. */
void init_node(node *n, int value)
{
	// Initialise and dynamically allocate memory for a new node. 
	node new_node = (node)malloc(sizeof(struct node_int));
	
	// Initialise the fields of the node.
	new_node->value = value;
	new_node->next = NULL;
	
	// Assign (or point) n to the new_node that has been initialised.
	(*n) = new_node;
}

/* Return the value of the node passed in as its argument. */
int get_node_value(node n)
{
	return n->value;
}

/* Return the current node (passed in as an argument) and return its next. */
node get_next_node(node n)
{
	return n->next;
}

/* Point the current node's next field to the node "next". */
void set_next_node(node current, node next)
{
	current->next = next;
}