/*
 * Author: Daniel Richardson
 * Date: 24th November 2015
 * Purpose: Linked List Driver file, used to create and show how library files
 * interfaces with driver files in order to put it together.
 */
 
#include "linked_list.h"
#include <stdlib.h>

int main()
{
	linked_list list;		// A list that will contain our data.
	
	linked_list_init(&list);	// Initialise the list.
	
	// Used for connivance to populate the list with values. 
	for (int i = 0; i < 20; i++)
	{
		add_element(&list, i);
	}
	
	// Print values to the console.
	traverse(list);
	
	return EXIT_SUCCESS;
}