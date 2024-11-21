#ifndef UTILS_H
#define UTILS_H

//utils
#define panic(c) \
    printf("\033[1;31m" "panic: %s\n" "\033[0m", c); \
    exit(1);
#endif