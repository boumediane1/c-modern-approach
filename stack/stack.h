#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct node {
    int value;
    struct node *next;
};

extern struct node *top;

bool push(int value);

struct node* pop(void);

void make_empty(void);

bool is_empty(void);

bool is_full(void);
#endif