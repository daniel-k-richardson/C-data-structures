/*
 * Author: Daniel Richardson.
 * Date & Version: 1 12 2015.
 * Purpose:
 *
 */

struct Stack;
typedef struct Stack stack;

stack *create_stack();
void push(stack *current_stack, void *data);
void *top(stack *current_stack);
void pop(stack *current_stack);