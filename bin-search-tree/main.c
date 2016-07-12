//
//  main.c
//  bintree
//
//  Created by Daniel Richardson on 4/01/2016.
//  This is my first attemp at creating a binary search tree.
//  I created all the functions that could be done on a bin searh tree.
//  This is not perfect, I will be making improvements as I learn more.
//  This is for a personal reference.

#include "bst.h"

int main(void)
{
    // create the root node for the tree and a starting value.
    BST tree = NULL;
    int r;
    
    for (int i = 0; i < 40; i++) {
        r = rand() % 100 + 1;
        tree = add_element_to_BST(tree, r);
    }
    preorder(tree);
    destroy_tree(&tree);
    printf("....................destroy...................\n");
    inorder(tree);
    
    return EXIT_SUCCESS;
}
