#pragma once

#include <stdint.h>

#define STACK_SIZE	(5)

typedef struct {
    char* string[STACK_SIZE];
    uint16_t counter;
}stack_t;

extern stack_t stack;

void push1(const char* new_str);
char* pop1(void);
