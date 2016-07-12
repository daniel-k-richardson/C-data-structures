/*
 * Author: Daniel Richardson.
 * Date & Version: 1 12 2015.
 * Purpose:
 *
 */

#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Node;

Node create_node(void *data);
void set_next(Node current, Node new_node);
Node get_next(Node self);
void *get_data(Node self);
void destroy_node(Node node_to_destroy);

#endif