#include "readline.h"
#include <stdio.h>

#define MAX_PARTS 1000
#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0; /* number of parts currently stored */

int find_part(int number);

void insert(void);

void search(void);

void update(void);

void print(void);

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

int find_part(int number) {
    for (int i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}

void insert(void) {
    if (num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    int part_number;

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;

    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);

    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);

    num_parts++;
}

void search(void) {
    int number;
    printf("Enter part number: ");
    scanf("%d", &number);

    int idx = find_part(number);

    if (idx == -1) {
        printf("Part not found.\n");
        return;
    }

    printf("Part name: %s\n", inventory[idx].name);
    printf("Quantity on hand: %d\n", inventory[idx].on_hand);
}

void update(void) {
    int number;
    printf("Enter part number: ");
    scanf("%d", &number);

    int idx = find_part(number);

    if (idx == -1) {
        printf("Part not found.\n");
        return;
    }

    int change;
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);

    inventory[idx].on_hand += change;
}

void print(void) {
    for (int i = 0; i < num_parts - 1; i++) {
        int min = i;
        for (int j = i + 1; j < num_parts; j++) {
            if (inventory[j].number < inventory[min].number) {
                min = j;
            }
        }

        if (min != i) {
            int temp = inventory[i].number;
            inventory[i].number = inventory[min].number;
            inventory[min].number = temp;
        }
    }

    printf("Part Number     Part Name     Quantity on Hand\n");
    for (int i = 0; i < num_parts; i++)
        printf("%11d     %-9s     %16d\n", inventory[i].number, inventory[i].name,
               inventory[i].on_hand);
}
