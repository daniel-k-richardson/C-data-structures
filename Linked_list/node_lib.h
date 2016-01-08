/* Author: Daniel Richardson
 * Date: 24th November 2015
 *
 *	Purpose: these two libraries are going to be used through the program, 
 *	so include them here and just include "node_lib.h" to all other 
 *	source files for connivance.	
 */
#include <stdio.h>
#include <stdlib.h>

// forward declaration of struct node_int so we can use it in future code.
struct node_int;

// a convenient way to avoid adding 'struct node_init *' every time. 
typedef struct node_int *node;

// function declarations we want to be able to use.
void init_node(node *n, int value);
int get_node_value(node n);
node get_next_node(node n);
void set_next_node(node current, node next);