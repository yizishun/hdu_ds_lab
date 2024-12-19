#ifndef COMMON_H
#define COMMON_H
#include <common.h>
#include <stack.h>
#include <utils.h>
#include <string.h>
#include <assert.h>
#define DEBUG 1
//frontend
char *get_demon_lang();

//backend
char *translate(char *input, int size);


#endif