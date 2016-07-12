#include "bst.h"

struct bstNode
{
    long value;
    struct bstNode *left;
    struct bstNode *right;
};


/* find_min: Helper function to find the smallest largest value from the left
 * branch of the tree. This is only visiable from within this source file.
 *
 * Param: The parents right child in which to find the smallest value from.
 *
 * Returns: the BST node with the smallest value from the left branch.
 */
BST find_min(BST self)
{
    if (self == NULL) {
        return NULL;
    }
    if (self->left == NULL) {
        return self;
    }
    return find_min(self->left);
}

/* create_new_node: Create a new node with the value of 'student_id'. Sets the
 * children to NULL. This is a helper function only visiable to this source file.
 *
 * Param: the student's id number that is to be added to the BST node.
 *
 * Returns: the newly created node to the caller.
 */
BST create_new_node(long data)
{
    BST new_node = NULL;
    
    if ((new_node = malloc(sizeof(*new_node))) == NULL) {
        perror("Error: issue allocating memory for new_node\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = data;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
}

/* number_of_elements_in_BST: Count the number of nodes inside the binary search
 * tree. This is useful for summerizing how many students are enrolled in course.
 *
 * Param: root of the tree to count the number of nodes contained within.
 *
 * Returns: a count of all nodes inside a tree.
 */
int number_of_elements_in_BST(BST self)
{
    int count;
    if (self == NULL) {
        return 0;
    }
    count = 1 + number_of_elements_in_BST(self->left) +
    number_of_elements_in_BST(self->right);
    
    return count;
}

/* add_element_to_BST: Adds a student id to the binary tree creating new nodes
 * and linking them as necessary.
 *
 * Params: the BST and the student id to add to the BST.
 *
 * Returns: void.
 */
BST add_element_to_BST(BST self, long value)
{
    if (self == NULL) {
        return create_new_node(value);
    }
    
    if (value < self->value) {
        self->left = add_element_to_BST(self->left, value);
    } else {
        self->right = add_element_to_BST(self->right, value);
    }
    return self;
}

void free_node(BST *self_p)
{
    free(*self_p);
    *self_p = NULL;
}

/* delete_element_from_BST: Searches the BST for the target(student_id), if it
 * is found, then remove it from the BST. Returns the new BST back to the caller.
 * Params: the BST to delete an item from and target to search the BST for.
 * Returns: the BST once the delection is complete.
 */
BST delete_element_from_BST(BST self, long target)
{
    if (self == NULL) {
        return NULL;
    }
    if (target < self->value) {
        self->left = delete_element_from_BST(self->left, target);
    } else if (target > self->value) {
        self->right = delete_element_from_BST(self->right, target);
    } else {
        if (self->left == NULL) {
            BST temp = self->right;
            free_node(&self);
            return temp;
        } else if (self->right == NULL) {
            BST temp = self->left;
            free_node(&self);
            return temp;
        } else {
            BST temp = find_min(self->right);
            self->value = temp->value;
            self->right = delete_element_from_BST(self->right, temp->value);
        }
    }
    return self;
}

/* inorder: Prints an inorder list of all elements stored inside the BST
 *
 * Params: the BST in which to print all nodes inorder.
 *
 * Returns: void.
 */
void inorder(BST self)
{
    if (self != NULL) {
        inorder(self->left);
        printf("%lu\n", self->value);
        inorder(self->right);
    }
}

void postorder(BST self)
{
    if (self != NULL) {
        postorder(self->left);
        postorder(self->right);
        printf("%lu\n", self->value);
    }
}

void preorder(BST self)
{
    if (self != NULL) {
        printf("%lu\n", self->value);
        postorder(self->left);
        postorder(self->right);
    }
}


/* search: this searches an entire BST for a student.
 *
 * Params: the BST to search and the student_id to search for.
 *
 * Returns: true if the student_id has been found in the BST and false otherwise.
 */
bool search_BST(BST self, long target)
{
    if (self != NULL) {
        if (self->value == target) {
            return true;
        } else if (self->value > target) {
            return search_BST(self->left, target);
        } else {
            return search_BST(self->right, target);
        }
    }
    return false;
}

/* destroy_tree: Destroys an entire BST.
 *
 * Params: the BST to delete.
 *
 * Returns: void.
 */
void destroy_tree(BST *self)
{
    if (*self != NULL) {
        destroy_tree(&(*self)->left);
        destroy_tree(&(*self)->right);
        free_node(self);
    }
}