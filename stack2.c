#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // memcpy, strlen
#include "stack1.h"
#include "stack2.h"

void push2(const char* new_str)
{

}

char* pop2(void)
{    
    if (stack.counter == 0) {
        printf("Error: Cannot pop! Empty stack\n");
        return NULL;
    }
    return stack.string[--stack.counter];    
}
