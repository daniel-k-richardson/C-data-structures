/*
 * Author: Daniel Richardson.
 * Date & Version: 1 12 2015.
 * Purpose:
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
 
struct Node;
typedef struct Node node;
 
node *create_node(void *data);
void set_previous(node **current, node **new_node);
node *get_previous(node *current);
void *get_data(node *current);
void destroy_node(node *node_to_destroy);