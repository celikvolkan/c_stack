#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // memcpy, strlen
#include "stack1.h"

stack_t stack;

void push1(const char* new_str)
{
	if (stack.counter == STACK_SIZE || new_str == NULL) {
		printf("Cannot push! Stack is full or null data\n");
		return;
	}
	printf("Pushing \"%s\"\n", new_str);
	char* pstr = (char*)malloc(strlen(new_str) + 1);
	if (pstr == NULL) {
		return;
	}
	memcpy(pstr, new_str, strlen(new_str) + 1);
	stack.string[stack.counter++] = pstr;
}

char* pop1(void)
{
	static char* return_str = NULL;
	if (return_str != NULL) {
		free(return_str);
		return_str = NULL;
	}
	if (stack.counter == 0) {
		printf("Error: Cannot pop! Empty stack\n");
		return NULL;
	}
	return_str = stack.string[--stack.counter];
	//printf("Popping \"%s\"\n", return_str);
	return return_str;
}