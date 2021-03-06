#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bstNode *BST;

int number_of_elements_in_BST(BST self);
BST add_element_to_BST(BST self, long student_id);
BST delete_element_from_BST(BST self, long target);
void inorder(BST self);
void postorder(BST self);
void preorder(BST self);
bool search_BST(BST self, long student_id);
void destroy_tree(BST *self);

#endif