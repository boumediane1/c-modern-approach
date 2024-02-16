#include <stdio.h>
#include <string.h>

int main() {
    char word[21], smallest_word[21], largest_word[21];

    for (;;) {
        printf("Enter a word: ");
        scanf("%s", word);

        if (strlen(word) == 4)
            break;

        if (strcmp(word, smallest_word) < 0) {
            strcpy(smallest_word, word);
        } else if (strcmp(word, largest_word) > 0) {
            strcpy(smallest_word, largest_word);
            strcpy(largest_word, word);
        }
    }

    printf("smallest word: %s\n", smallest_word);
    printf("largest word: %s\n", largest_word);

    return 0;
}