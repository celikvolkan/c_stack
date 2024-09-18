#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // memcpy, strlen

/* 
push("car");
push("pc");
push("tomato");
pop --> tomato;
pop --> pc;
*/

#define STACK_SIZE	(5)

typedef struct {
	const char* string[STACK_SIZE];
	unsigned int counter;
}stack_t;

static stack_t stack;

void push(const char* new_str)
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
	memcpy(pstr, new_str, strlen(new_str)+1);
	stack.string[stack.counter++] = pstr;	
}

const char* pop(void)
{
	static char* return_str = NULL;
	if (return_str != NULL) {
		free(return_str);
		return_str = NULL;
	}
	if (stack.counter == 0) {
		printf("Cannot pop! Empty stack\n");
		return NULL;
	}	
	return_str = stack.string[--stack.counter];
	//printf("Popping \"%s\"\n", return_str);
	return return_str;
}

void print_stack(void)
{
	printf("\nStack\n");
	printf("---------\n");
	if (stack.counter == 0) {
		printf("Empty stack!\n");
	}
	else {
		for (int i = stack.counter-1; i >=0; --i) {
			printf("%d: [%s]\n", i, stack.string[i]);
		}
	}
	printf("---------\n\n");
}

int main(void)
{
	print_stack();

	push("car");
	push("bee");
	push("book");
	print_stack();
	
	printf("Popping \"%s\"\n", pop());
	print_stack();

	push("plane");
	push("ship");
	print_stack();

	printf("Popping \"%s\"\n", pop());
	print_stack();

	printf("Popping \"%s\"\n", pop());
	printf("Popping \"%s\"\n", pop());
	printf("Popping \"%s\"\n", pop());
	print_stack();

	printf("Popping \"%s\"\n", pop());
	printf("Popping \"%s\"\n", pop());
	printf("Popping \"%s\"\n", pop());
	print_stack();

	push(NULL);
	push("pen");
	push("color");
	push("pc");
	push("student");
	push("worker");
	push("dentist");
	print_stack();

	return 0;
}
