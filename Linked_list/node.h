/* Author: Daniel Richardson
 * Date: 24th November 2015
 *
 *	Purpose: these two libraries are going to be used through the program,
 *	so include them here and just include "node_lib.h" to all other
 *	source files for connivance.
 */
#include <stdio.h>
#include <stdlib.h>

// a convenient way to avoid adding 'struct node_init *' every time.
typedef struct Node *Node;

// function declarations we want to be able to use.
void init_node(Node *self, int value);
int get_node_value(Node self);
Node get_next_node(Node self);
void set_next_node(Node current, Node next);
void free_node(Node self);