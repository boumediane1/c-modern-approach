#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

struct node *top = NULL;

int main() {
    push(5);
    push(3);
    push(7);
    pop();
    push(8);

    while (top != NULL) {
        printf("%d\n", top->value);
        top = top->next;
    }

    return 0;
}

void make_empty(void) {
    struct node *temp;

    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

bool is_empty(void) {
    return top == NULL;
}

bool push(int value) {
    struct node *new_node = malloc(sizeof(struct node));

    if (new_node == NULL)
        return false;

    new_node->value = value;
    new_node->next = top;

    top = new_node;

    return true;
}


struct node *pop(void) {
    struct node *temp;

    if (is_empty())
        return NULL;

    temp = top;

    top = top->next;

    temp->next = NULL;

    return temp;
}
