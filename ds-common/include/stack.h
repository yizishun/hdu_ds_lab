#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
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


#endif