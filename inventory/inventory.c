#include "readline.h"
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;

void insert(void);

void search(void);

void update(void);

void print(void);

struct part *find_part(int number);

int main(void) {
    for (;;) {
        char code;
        printf("Enter operation code: ");
        scanf(" %c", &code);

        while (getchar() != '\n'); /* skips to end of line */

        switch (code) {
            case 'i':
                insert();
                break;
            case 's':
                search();
                break;
            case 'u':
                update();
                break;
            case 'p':
                print();
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }
}

void insert(void) {
    struct part *curr, *prev, *new_node;

    new_node = malloc(sizeof(struct part));

    if (new_node == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (prev = NULL, curr = inventory;
         curr != NULL && new_node->number > curr->number;
         prev = curr, curr = curr->next);

    if (curr != NULL && new_node->number == curr->number) {
        printf("Part already exists.\n");
        free(new_node); // release the space to avoid memory leak
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);

    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = curr;

    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

void search(void) {
    int number;
    printf("Enter part number: ");
    scanf("%d", &number);

    struct part *p = find_part(number);

    if (p == NULL) {
        printf("Part not found.\n");
        return;
    }

    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
}

void update(void) {
    int number;
    printf("Enter part number: ");
    scanf("%d", &number);

    struct part *p = find_part(number);

    if (p == NULL) {
        printf("Part not found.\n");
        return;
    }

    int change;
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);

    p->on_hand += change;
}

void print(void) {
    printf("Part Number     Part Name     Quantity on Hand\n");
    for (struct part *p = inventory; p != NULL; p = p->next)
        printf("%11d     %-9s     %16d\n", p->number, p->name, p->on_hand);
}

struct part *find_part(int number) {
    struct part *p;

    for (p = inventory;
         p != NULL && number > p->number;
         p = p->next);

    if (p != NULL && number == p->number)
        return p;

    return NULL;
}
