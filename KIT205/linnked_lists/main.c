/*
 *	Author: Daniel Richardson. Note, some of the code froms from kit205 lecture slides.
 *	Date: 29/2/2016
 *	Purpose: Mostly just reference material and practice for kit205. This is a linked-list
 * 	complete with different operations that can be done to linked lists.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* linked list data type */
typedef struct Node {
	int data;
	struct Node *next;
} *List;

/* function prototypes for the program */
void insert(List *, int);
void traverse(List);
void insert_in_order(List *, int);
List reverse(List);
void destroy(List *);
void merge(List *, List *);
void delete_item(List *, int);

int main()
{
	int number[] = {20, 4, 8, 12, 16, 5, 9, 0, 30, 55};	// used to fill merge_list1
	int number2[] = {21, 9, 49, 70, 1, 9, 3, 2, 80, 200};	// used to fill merge_list2
	
	/* two lists, used to test functions */
	List merge_list1 = NULL;	// used to test merge() with merge_list2
	List merge_list2 = NULL;	// used to test merge() with merge_list1
	List reverse_list = NULL;	// store the new reversed linked-list from reverse()
	
	/* just a convenient way to fill both linked-lists in one loop */
	for (int i = 0; i < 10; i++)
	{
		insert_in_order(&merge_list1, number[i]);
		insert_in_order(&merge_list2, number2[i]);
	}
	
	// test that merge() works and print it to console.
	merge(&merge_list1, &merge_list2);
	traverse(merge_list1);
	
	// test that reverse() works and print it to console.
	printf("\nReversed list\n\n");
	reverse_list = reverse(merge_list1);
	traverse(reverse_list);
	
	//test that delete_item() works.
	delete_item(&reverse_list, 12);
	delete_item(&reverse_list, 11);
	
	
	return EXIT_SUCCESS;
}

/* Inserts data (int values) into a link-list in order it receives them */
void insert(List *self, int data)
{
	List new_node = malloc(sizeof(*new_node));
	
	/* check to ensure memory has successfully been allocated */
	if (!new_node)
	{
		fprintf(stderr, "Error allocating memory\n");
		exit(EXIT_FAILURE);
	}
	new_node->data = data;
	new_node->next = *self;
	*self = new_node;
}

/* searches the linked-list for the node with the target's value. if found
 * remove that node from the list. */
void delete_item(List *self, int target)
{
	List current = *self;
	List previous = NULL;
	bool has_found_target = false;	// flag variable, display appropriate message.
	
	while (current)
	{
		/* element to remove found */
		if (current->data == data)
		{
			/* If previous is NULL then remove the first node */
			if (!previous)
			{
				*self = current->next;
				free(current);
				current = *self;
				has_found_target = true;
			}
			/* otherwise, general case: just link previous's next to current's next
			 * and free current */
			else
			{
				previous->next = current->next;
				free(current);
				current = previous->next;
				has_found_target = true;
			}
		}
		/* traverse through the rest of the list if not found */
		else
		{
			previous = current;
			current = current->next;
		}
	}
	
	if (has_found_target)
	{
		printf("Target %d found and removed\n", data);
	}
	else
	{
		printf("Target %d not found.\n", data);
	}
}

/* prints out the data (int values) from each node in the linked-list */
void traverse(List self)
{
	List current = self;
	
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}

/* This function inserts values in order from lowest to highest values */
void insert_in_order(List *self, int data)
{
	List current = *self;
	List previous = NULL;
	
	List new_node = malloc(sizeof(*new_node));
	
	/* check that memory has been successfully allocated */
	if (!new_node)
	{
		fprintf(stderr, "Issue allocating memory\n");
		exit(EXIT_FAILURE);
	}
	new_node->data = data;
	new_node->next = NULL;
	
	/* checks if the current node's data value is smaller than the data's value, if the data 
	 * is less than the current nodes data value, keep traversing until the node's data is
	 * greater than or equal to data's value */
	while (current && current->data < data)
	{
		previous = current;
		current = current->next;
	}
	
	/* check if the new data should be entered at the start of the list, either because
	 * it's the first data value being entered, or the data's value is smaller than the 
	 * list's first data */
	if (current == *self)
	{
		new_node->next = current;
		*self = new_node;
	}
	/* Otherwise, it's the general case just (just add it to the end) until it has to be
	 * moved. */
	else
	{
		new_node->next = current;
		previous->next = new_node;
	}
}

/* reverses a list, by taking a list and adding all nodes to the front. Then returns the
 * new list back to the caller */
List reverse(List self)
{
	List new_list = NULL;
	List new_current = NULL;
	
	List current = self;
	
	while (current)
	{
		new_current = malloc(sizeof(*new_current));
		
		/* error checking */
		if (!new_current)
		{
			fprintf(stderr, "Issue allocating memory\n");
			exit(EXIT_FAILURE);
		}
		new_current->data = current->data;
		new_current->next = NULL;
		
		/* if the first item being added to the list if the first. */
		if (!new_list)
		{
			new_list = new_current;
		}
		/* Otherwise, general case: just keep adding to the front and link the new node
		 * to the current node's next and update the new_list to point to the new current
		 * node. */
		else
		{
			new_current->next = new_list;
			new_list = new_current;
		}
		current = current->next;
	}
	
	return new_list;
}

/* merge two lists and deletes the 'other' list */
void merge(List *self, List *other)
{
	List current = *other;
	
	while(current)
	{
		insert_in_order(self, current->data);
		current = current->next;
	}
	
	destroy(other);
}

/* completely destroy a linked-list, traversing and freeing each node from memory */
void destroy(List *self)
{
	List current = *self;
	List previous = NULL;
	
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
	*self = NULL;
}
