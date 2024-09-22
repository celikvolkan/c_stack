#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // memcpy, strlen
#include "stack1.h"

stack_t stack;

void push1(const char* new_str)
{
    if (stack.counter == STACK_SIZE || new_str == NULL) {
        return;
    }
    char* str = (char*)malloc(strlen(new_str) + 1);
    if (str == NULL) {
        return;
    }

    memcpy(str, new_str, strlen(new_str) + 1);;
    stack.string[stack.counter++] = str;
}

char* pop1(void)
{
    static char* pre_pop_str = NULL;
    
    if (pre_pop_str != NULL) {
        free(pre_pop_str);
        pre_pop_str = NULL;
    }

    if (stack.counter == 0) {
        return NULL;
    }
     
    
    pre_pop_str = stack.string[--stack.counter];

    return pre_pop_str;
}
