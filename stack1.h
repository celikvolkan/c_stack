#pragma once

#define STACK_SIZE	(5)

typedef struct {
	char* string[STACK_SIZE];
	unsigned int counter;
}stack_t;

extern stack_t stack;

void push(const char* new_str);
char* pop(void);
