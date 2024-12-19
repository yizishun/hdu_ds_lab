#ifndef UTILS_H
#define UTILS_H
//#define DEBUG 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//utils
#define panic(c) \
    printf("\033[1;31m" "panic: %s\n" "\033[0m", c); \
    exit(1);

inline void panic_a(bool cond, char *c){
    if(cond){
        panic(c);
    }
}
#endif