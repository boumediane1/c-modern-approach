#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node *next;
};

struct node *delete_node(struct node *list, int value);

struct node *add_to_list(struct node *list, int value);

struct node *search_list2(struct node *list, int value);

struct node *search_list(struct node *list, int value);

struct node *read_numbers(void);

int main() {
    return 0;
}

struct node *delete_node(struct node *list, int value) {
    struct node *curr, *prev;

    for (curr = list, prev = NULL;
         curr != NULL && curr->value != value;
         prev = curr, curr = curr->next);

    if (curr == NULL)
        return list;             /* n was not found */

    if (prev == NULL)
        list = list->next;       /* n is in the first node */
    else
        prev->next = curr->next; /* n is in some other node */

    free(curr);

    return list;
}

struct node *search_list2(struct node *list, int value) {
    while (list != NULL && list->value != value)
        list = list->next;

    return list;
}

struct node *search_list(struct node *list, int value) {
    for (struct node *p = list; p != NULL; p = p->next)
        if (p->value == value)
            return p;

    return NULL;
}

struct node *add_to_list(struct node *list, int value) {
    struct node *new_node = malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = value;
    new_node->next = list;

    return new_node;
}

struct node *read_numbers(void) {
    struct node *first = NULL;
    int value;

    printf("Enter a series of integers (0 to terminate): ");

    for (;;) {
        scanf("%d", &value);

        if (value == 0)
            return first;

        first = add_to_list(first, value);
    }
}
