#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define DEBUG 1
//frontend
char *get_demon_lang();

//stack
typedef struct{
	char *stack;
	int size;
    int top;
    char *name;
} Stack;
Stack* init_stack(int size, char *name);
char pop(Stack *s);
char nopop(Stack *s);
void push_s(Stack *s, char* c);
void push_c(Stack *s, char c);
bool is_empty(Stack *s);
char *stack2str(Stack *s);

//backend
char *translate(char *input, int size);

//utils
#define panic(c) \
    printf("\033[1;31m" "panic: %s\n" "\033[0m", c); \
    exit(1);

#endif