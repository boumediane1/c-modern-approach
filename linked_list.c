#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node *next;
};

void add_to_list(struct node **list, int value);

void delete_node(struct node **list, int value);

void delete_all_nodes(struct node **list);

struct node *search_list(struct node *list, int value);

struct node *search_list2(struct node *list, int value);

struct node *read_numbers(void);

int main() {
    struct node *first = read_numbers();
    delete_all_nodes(&first);
    return 0;
}

void add_to_list(struct node **list, int value) {
    struct node *new_node = malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = value;
    new_node->next = *list;

    *list = new_node;
}

void delete_node(struct node **list, int value) {
    struct node *curr = *list;

    /* n was not found */
    if (curr == NULL)
        return;

    /* n is in the first node */
    if (curr->value == value) {
        *list = (*list)->next;
        return;
    }

    for (; curr->next != NULL && curr->next->value != value;
           curr = curr->next);

    /* n was not found */
    if (curr->next == NULL)
        return;

    /* n is in some other node */
    curr->next = curr->next->next;
}

void delete_all_nodes(struct node **list) {
    struct node *p = *list;
    struct node *next_node;

    while (p != NULL) {
        next_node = p->next;
        free(p);
        p = next_node;
    }
}

struct node *search_list(struct node *list, int value) {
    for (struct node *p = list; p != NULL; p = p->next)
        if (p->value == value)
            return p;

    return NULL;
}

struct node *search_list2(struct node *list, int value) {
    while (list != NULL && list->value != value)
        list = list->next;

    return list;
}

struct node *read_numbers(void) {
    struct node *first = NULL;
    int value;

    printf("Enter a series of integers (0 to terminate): ");

    for (;;) {
        scanf("%d", &value);

        if (value == 0)
            return first;

        add_to_list(&first, value);
    }
}
