/*
 * Author: Daniel Richardson
 * Date: 24th November 2015
 * Purpose: A linked list implementation for a youtube tutorial.
 */

#include "linked_list.h"
#include "node.h"

/* A new linked_list_int type that will represent a linked list */
struct linked_list_int
{
    Node head;
    Node tail;
};

/* Create and initialise a linked list. */
void linked_list_init(linked_list *l)
{
    // Initialise and dynamically create a new list in memory.
    linked_list new_list = NULL;
    
    if ((new_list = malloc(sizeof(*new_list))) == NULL ) {
        perror("Error: could not allocate memory for list\n");
        exit(EXIT_FAILURE);
    }
    new_list->head = NULL;
    new_list->tail = NULL;
}

/* Check whether or not the list is empty. */
bool is_empty(linked_list self)
{
    if (self->head == NULL)
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
void add_element(linked_list *self, int value)
{
    Node current = NULL;
    Node new_node = NULL;
    
    current = (*self)->head;
    init_node(&new_node, value);
    
    if (is_empty((*self))) {
        (*self)->head = new_node;
        (*self)->tail = (*self)->head;
    } else {
        set_next_node((*self)->tail, new_node);
        (*self)->tail = get_next_node((*self)->tail);
        
    }
}

linked_list delete_item(linked_list self, int target)
{
    Node current = self->head;
    Node previous = NULL;
    
    while (current != NULL) {
        if (get_node_value(current) == target) {
            if (current == self->head) {
                self->head = get_next_node(current);
                free_node(current);
            } else if (current == self->tail) {
                self->tail = previous;
                free_node(previous);
            } else {
                set_next_node(get_next_node(previous), get_next_node(current));
                free_node(current);
            }
        }
        previous = current;
        current = get_next_node(current);
    }
    return self;
}

/*
 * Does what it says on the tin - traverses through all the nodes in the list
 * and prints those values out to the console.
 */
void traverse(linked_list self)
{
    Node current = self->head;
    
    while (current != NULL) {
        printf("The value inside the node is \"%d\"\n", get_node_value(current));
        current = get_next_node(current);
    }
}