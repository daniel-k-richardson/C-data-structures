/*
 * Author: Daniel Richardson
 * Date: 24th of November 2015
 * Purpose: creates single nodes that linked_list_lib.c uses to create
 * its list with.
 */

#include "node.h"

/* A type node, which holds an int value and a pointer to the next node */
struct Node
{
    int value;
    Node next;
};

/* Create a new node, set the value of the node and set its next to NULL. */
void init_node(Node *self, int value)
{
    // Initialise and dynamically allocate memory for a new node.
    Node new_node = NULL;
    
    if ((new_node = malloc(sizeof(*new_node))) == NULL) {
        perror("Error: allocation of new node failed\n");
        exit(EXIT_FAILURE);
    }
    
    // Initialise the fields of the node.
    new_node->value = value;
    new_node->next = NULL;
    
    // Assign (or point) n to the new_node that has been initialised.
    (*self) = new_node;
}

/* Return the value of the node passed in as its argument. */
int get_node_value(Node n)
{
    return n->value;
}

/* Return the current node (passed in as an argument) and return its next. */
Node get_next_node(Node self)
{
    return self->next;
}

/* Point the current node's next field to the node "next". */
void set_next_node(Node current, Node next)
{
    current->next = next;
}

void free_node(Node self)
{
    self->next = NULL;
    free(self);
    self = NULL;
}