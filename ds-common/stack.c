#include "./include/common.h"
#include "./include/utils.h"
#include "./include/stack.h"
bool is_empty(Stack *s){ return s->top == -1; }
static inline bool is_full(Stack *s){ return s->top == s->size - 1; }

Stack* init_stack(int size, char *name){
    Stack *s = malloc(sizeof(Stack));
	s->stack = malloc(size);
	s->size = size;
	s->top = -1;
    s->name = name;
    #ifdef DEBUG
    printf("Stack %s created with size %d\n", s->name, s->size);
    #endif
    return s;
}

void push_c(Stack *s, char c){
    if(is_full(s)){
        panic("Stack overflow");
    }
    #ifdef DEBUG
    printf("PUSH: %c [%s]\n", c, s->name);
    #endif
    s->stack[++s->top] = c;
}
void push_internal(Stack *s, char c){
    if(is_full(s)){
        panic("Stack overflow");
    }
    s->stack[++s->top] = c;
}
void push_s(Stack *s, char* c){
    if(c == NULL) return;
    #ifdef DEBUG
    printf("PUSH: %s [%s]\n", c, s->name);
    #endif
    for(int i = 0; c[i] != '\0'; i++)
        push_internal(s, c[i]);
}

char pop(Stack *s){
    if(is_empty(s)){
        return -1;
    }
    #ifdef DEBUG
    printf("POP : %c [%s]\n", s->stack[s->top], s->name);
    #endif
    return s->stack[s->top--];
}

char nopop(Stack *s){
    if(is_empty(s)){
        panic("Stack underflow");
    }
    return s->stack[s->top];
}


char *stack2str(Stack *s){
    char *str = malloc(s->size);
    push_c(s, '\0');
    strcpy(str, s->stack);
    pop(s);
    return str;
}