/*
 * Author: Daniel Richardson.
 * Date & Version: 1 12 2015.
 * Purpose:
 *
 */

#ifndef STACK_H
#define STACK_H

typedef struct Stack *Stack;

Stack create_stack();
void push(Stack current_stack, void *data);
void *top(Stack current_stack);
void pop(Stack current_stack);

#endif