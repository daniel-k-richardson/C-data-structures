//
//  main.c
//  bintree
//
//  Created by Daniel Richardson on 4/01/2016.
//  This is my first attemp at creating a binary search tree.
//  I created all the functions that could be done on a bin searh tree.
//  This is not perfect, I will be making improvements as I learn more.
//  This is a personal reference for myself.

#include <stdio.h>
#include <stdlib.h>

typedef struct Bin_Search_Tree
{
    int data;
    struct Bin_Search_Tree *left_child, *right_child;
} node;

// function prototypes.
node *get_node(int);
void insert(node *, int);
void inorder(node *);
void preorders(node *);
void postorders(node *);
node *search(node *, int);
node *remove_node(node *, int);
node *find_min(node *);
void destory_tree(node *);

int main(void)
{
    // create the root node for the tree and a starting value.
    node *bin_tree = get_node(6);
    
    // insert values into the tree.
    insert(bin_tree, 2);
    insert(bin_tree, 20);
    insert(bin_tree, 9);
    insert(bin_tree, 3);
    
    // search the tree for a value
    search(bin_tree, 3);
    
    // the three different traversals for displaying the content of the tree.
    inorder(bin_tree);
    printf("\n");
    preorders(bin_tree);
    printf("\n");
    postorders(bin_tree);
    printf("\n");
    
    // remove an item from the tree.
    remove_node(bin_tree, 6);
    
    // display the tree after an item has been removed.
    inorder(bin_tree);
    printf("\n");
    
    // destory the tree once finished/free up memory.
    destory_tree(bin_tree);
    
    return EXIT_SUCCESS;
}

/*
 Get new Node
 */
node *get_node(int val)
{
    node *temp;
    temp = malloc(sizeof(*temp));
    temp->data = val;
    temp->left_child = NULL;
    temp->right_child = NULL;
    
    return temp;
}

/*
 Create binary tree.
 */
void insert(node *root, int val)
{
    node *new_node;
    
    if (val  > root->data)
    {
        if (!root->right_child)
        {
            new_node = get_node(val);
            root->right_child = new_node;
        }
        else
        {
            insert(root->right_child, val);
        }
    }
    if (val < root->data)
    {
        if (!root->left_child)
        {
            new_node = get_node(val);
            root->left_child = new_node;
        }
        else
        {
            insert(root->left_child, val);
        }
    }
}

/*
 Search the bin tree for an item.
 */
node *search(node *root, int key)
{
    node *temp;
    temp = root;
    
    if (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("The %d element is Pressent\n", temp->data);
            return temp;
        }
    }
    if (temp->data > key)
    {
        search(temp->left_child, key);
    }
    else
    {
        search(temp->right_child, key);
    }
    return NULL;
}

/*
 Display the tree inorder.
 */
void inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left_child);
        printf("%d\t", temp->data);
        inorder(temp->right_child);
    }
}

/*
 This function displays thr tree in preorder.
 */
void preorders(node *temp)
{
    if (temp)
    {
        printf("%d\t", temp->data);
        preorders(temp->left_child);
        preorders(temp->right_child);
    }
}

/*
 displays the tree in postorder fashion
 */
void postorders(node *temp)
{
    if (temp)
    {
        postorders(temp->left_child);
        postorders(temp->right_child);
        printf("%d\t", temp->data);
    }
}

node *remove_node(node *root, int key)
{
    
    if (root == NULL)
    {
        return root;
    }
    
    /*  Check which branch of the tree to go down based on if the key
        is less than or greater than the current nodes value */
    if (key < root->data)
    {
        root->left_child = remove_node(root->left_child, key);
    }
    else if (key > (root)->data)
    {
        root->right_child = remove_node(root->right_child, key);
    }
    else
    {
        
        /*  Note to self: case 1: case one has been skipped. Case 1 refers to a parent
            that has no children. However, after much consideration, case 1 achieves
            the same result as case 2. For example: the target is '4'.
            
                case 2:     4          After        3
                           / \                    /   \
                          3  null               null  null
         
                case 1:     4          After       null
                           / \                     /  \
                        null null                null null
         
         
            case 2: check if the tree has a left-child, if it doesn't
            free the node to be removed from memory and link right_child
            to parent node. */
        if (root->left_child == NULL)
        {
            node *temp = root->right_child;
            free(root);
            root = NULL;
            return temp;
        }
        /*  case 2: check if right child is NULL, do the same as case 1
            but link left_child to parent instead */
        else if (root->right_child == NULL)
        {
            node *temp = root->left_child;
            free(root);
            root = NULL;
            return temp;
        }
        
        /*  case 3: node has a left and right child. Find the smallest of the
            right branch. Return and set the smallest largest value to the node
            that is to be removed and instead delete the leaf node (the smallest
            largest value). */
        node *temp = find_min(root->right_child);
        
        root->data = temp->data;
        
        root->right_child = remove_node(root->right_child, temp->data);
    }
    return root;
}

/* find the smallest value of the currnt left child */
node *find_min(node *temp)
{
    if (temp == NULL)
    {
        return NULL;
    }
    if (temp->left_child == NULL)
    {
        return temp;
    }
    return find_min(temp->left_child);
}

/* destory the entire tree, feeing up all memory */
void destory_tree(node *root)
{
    if (root)
    {
        destory_tree(root->left_child);
        destory_tree(root->right_child);
        free(root);
    }
}