#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // memcpy, strlen
#include "stack1.h"

#define INPUT_SIZE	(100)

/* API */
void push(const char* new_str)
{
    push1(new_str);
}

char* pop(void)
{
    return pop1();
}

const char menu_string[] =  "**********************  MENU  **************************\n" \
                            "'+' Push string\n'-' Pop string\n'*' Print the stack\n'/' Exit from the program\n'm' See this menu\n" \
                            "********************************************************\n";

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
	char input[INPUT_SIZE] = { 0 };
	char ch = 0;
	
	printf("%s", menu_string);
	
	do {		
		printf("\nMenu command: ");
		gets_s(input, INPUT_SIZE);
		ch = input[0];
		switch (ch) {
			case'+': {
				printf("Enter string to push to stack: ");
				gets_s(input, INPUT_SIZE);
				push(input);
				break;
			}
			case'-': {
				printf("Popping string: '%s'\n", (const char *)pop());
				break;
			}
			case'*': {
				print_stack();
				break;
			}
			case'/': {
				printf("\nGOOD BYE!..\n\n");
				break;
			}
			case'm': {
				printf("%s", menu_string);
				break;
			}
			default: {
				printf("Undefined input!\n");
				break;
			}
		}
	} while (ch != '/');	

	return 0;
}
