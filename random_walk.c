#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 10

bool available_spot(char walks[][N], int random, int currentRow, int currentColumn);

bool out_of_boundaries(int random, int currentRow, int currentColumn);

bool is_game_lost(const bool attempts[]);

void next_move(int random, int *currentRow, int *currentColumn);

void init_walks(char walks[][N]);

void print_walks(const char walks[][N]);

int main() {
    char walks[N][N], letter = 'A';
    bool attempts[4];

    srand((unsigned) time(NULL));

    init_walks(walks);

    int currentRow = 0;
    int currentColumn = 0;

    for (;;) {
        walks[currentRow][currentColumn] = letter;
        print_walks(walks);

        if (letter == 'Z') {
            printf("Congratulation!\n");
            return 0;
        }

        for (int i = 0; i < 4; i++)
            attempts[i] = false;

        int random = rand() % 4;

        while (!available_spot(walks, random, currentRow, currentColumn)) {
            attempts[random] = true;

            if (is_game_lost(attempts)) {
                printf("You lost!\n");
                return 1;
            }

            random = rand() % 4;
        }

        next_move(random, &currentRow, &currentColumn);
        letter++;
    }
}


bool available_spot(char walks[][N], int random, int currentRow, int currentColumn) {
    if (out_of_boundaries(random, currentRow, currentColumn))
        return false;

    if (random == 0)
        return walks[--currentRow][currentColumn] == '.';
    if (random == 1)
        return walks[currentRow][++currentColumn] == '.';
    if (random == 2)
        return walks[++currentRow][currentColumn] == '.';
    return walks[currentRow][--currentColumn] == '.';
}

bool out_of_boundaries(int random, int currentRow, int currentColumn) {
    return random == 0 && currentRow == 0 ||
           random == 1 && currentColumn == N - 1 ||
           random == 2 && currentRow == N - 1 ||
           random == 3 && currentColumn == 0;
}

bool is_game_lost(const bool attempts[]) {
    int count = 0;

    for (int i = 0; i < 4; i++)
        if (attempts[i])
            count++;

    return count == 4;
}

void next_move(int random, int *currentRow, int *currentColumn) {
    if (random == 0)
        *currentRow = *currentRow - 1;
    else if (random == 1)
        *currentColumn = *currentColumn + 1;
    else if (random == 2)
        *currentRow = *currentRow + 1;
    else
        *currentColumn = *currentColumn - 1;
}

void init_walks(char walks[][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            walks[i][j] = '.';
}

void print_walks(const char walks[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", walks[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}
