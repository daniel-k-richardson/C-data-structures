
/* 
 * Author: Daniel Richardson
 * Date: 24th November 2015
 * Purpose: API for the 'linked_listDriver.c'
*/

#include "node_lib.h"
#include <stdbool.h>

struct linked_list_int;
typedef struct linked_list_int *linked_list;

void linked_list_init(linked_list *l);
void add_element(linked_list *l, int value);
void traverse(linked_list l);