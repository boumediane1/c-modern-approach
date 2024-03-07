#include "readline.h"
#include <stdio.h>

#define MAX_PARTS 1000
#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    double price;
};

void insert(struct part *inventory, int *num_parts);

void search(const struct part *inventory, int num_parts);

void update(struct part *inventory, int num_parts);

void change_price(struct part *inventory, int num_parts);

void print(const struct part *inventory, int num_parts);

int find_part(const struct part *inventory, int num_parts, int number);

void sort_by_number(struct part *inventory, int num_parts);

int main(void) {
    struct part inventory[MAX_PARTS];
    int num_parts = 0; /* number of parts currently stored */

    for (;;) {
        char code;
        printf("Enter operation code: ");
        scanf(" %c", &code);

        while (getchar() != '\n'); /* skips to end of line */

        switch (code) {
            case 'i':
                insert(inventory, &num_parts);
                break;
            case 's':
                search(inventory, num_parts);
                break;
            case 'u':
                update(inventory, num_parts);
                break;
            case 'c':
                change_price(inventory, num_parts);
                break;
            case 'p':
                sort_by_number(inventory, num_parts);
                print(inventory, num_parts);
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }
}

void insert(struct part *inventory, int *num_parts) {
    if (*num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    int part_number;

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(inventory, *num_parts, part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[*num_parts].number = part_number;

    printf("Enter part name: ");
    read_line(inventory[*num_parts].name, NAME_LEN);

    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[*num_parts].on_hand);

    printf("Enter price: ");
    scanf("%lf", &inventory[*num_parts].price);

    (*num_parts)++;
}

void search(const struct part *inventory, int num_parts) {
    int number;
    printf("Enter part number: ");
    scanf("%d", &number);

    int idx = find_part(inventory, num_parts, number);

    if (idx == -1) {
        printf("Part not found.\n");
        return;
    }

    printf("Part name: %s\n", inventory[idx].name);
    printf("Quantity on hand: %d\n", inventory[idx].on_hand);
    printf("Price: %g\n", inventory[idx].price);
}

void update(struct part *inventory, int num_parts) {
    int number;
    printf("Enter part number: ");
    scanf("%d", &number);

    int idx = find_part(inventory, num_parts, number);

    if (idx == -1) {
        printf("Part not found.\n");
        return;
    }

    int change;
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);

    inventory[idx].on_hand += change;
}

void change_price(struct part *inventory, int num_parts) {
    int number;
    printf("Enter part number: ");
    scanf("%d", &number);

    int idx = find_part(inventory, num_parts, number);

    if (idx == -1) {
        printf("Part not found.\n");
        return;
    }

    double price;
    printf("Enter new price: ");
    scanf("%lf", &price);

    inventory[idx].price = price;
}

void print(const struct part *inventory, int num_parts) {
    printf("Part Number     Part Name     Quantity on Hand     Price\n");
    for (int i = 0; i < num_parts; i++)
        printf("%11d     %-9s     %16d     %5g\n", inventory[i].number, inventory[i].name, inventory[i].on_hand, inventory[i].price);
}

int find_part(const struct part *inventory, int num_parts, int number) {
    for (int i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}

void sort_by_number(struct part *inventory, int num_parts) {
    for (int i = 0; i < num_parts - 1; i++) {
        int min = i;
        for (int j = i + 1; j < num_parts; j++) {
            if (inventory[j].number < inventory[min].number) {
                min = j;
            }
        }

        if (min != i) {
            struct part temp = inventory[i];
            inventory[i] = inventory[min];
            inventory[min] = temp;
        }
    }
}
