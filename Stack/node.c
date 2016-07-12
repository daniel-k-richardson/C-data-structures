/*
 * Author: Daniel Richardson.
 * Date & Version: 1/12/2015 version 1.
 * Purpose: To create nodes and getters and setters for those nodes,
 * For the implementation of linked lists and stacks.
 */

#include "node.h"

/* A node type that stores a single char that will be used with our stack */
struct Node
{
    void *data;
    Node next;
};

/*
 * Create a new node assign the node's data with the data passed in as parameters
 * and set node's previous to NULL.
 *
 * Parameters:
 * data is used to set the node's data field.
 *
 * Returns: The new node.
 */
Node create_node(void *data)
{
    Node new_node = NULL;
    
    if ((new_node = malloc(sizeof(*new_node))) == NULL) {
        perror("Issue occurred durring memory allocation in create_node()\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    
    return new_node;
}

/*
 * Add new_node to the current node's previous field.
 *
 * Parameters:
 * current is the node that new_node is to connect to.
 * new_node is the node that connects to the current node.
 *
 * Returns: void.
 */
void set_next(Node current, Node new_node)
{
    new_node->next = (current);
}

/*
 * Gets the current node's previous node and returns it.
 *
 * Parameters:
 * current is the node to retrive the previous node from.
 *
 * Return: return the current node's previous.
 */
Node get_next(Node self)
{
    return self->next;
}

/*
 * Get the letter from the current node's field.
 *
 * Parameters:
 * current node to retrive letter from.
 *
 * Return: current node's letter.
 */
void *get_data(Node self)
{
    return self->data;
}

/*
 * Destroy and free up the memory address of node_to_destroy.
 *
 * Parameters:
 * node_to_destroy is the target.
 *
 * Return: void.
 */
void destroy_node(Node node_to_destroy)
{
    free(node_to_destroy);
    node_to_destroy = NULL;
    
}