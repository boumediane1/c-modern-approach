#include <stdio.h>
#include <string.h>

#define N 100

void reverse_wording(const char *sentence, char *reversed);

int main() {
    char sentence[N + 1], reversed[N + 1];
    int ch = getchar(), count = 0;

    while (ch != '.' && ch != '?' && ch != '!') {
        sentence[count++] = (char) ch;
        ch = getchar();
    }

    sentence[count] = '\0';

    reverse_wording(sentence, reversed);

    reversed[count] = (char) ch;

    printf("%s\n", reversed);

    return 0;
}

void reverse_wording(const char *sentence, char *reversed) {
    int count = 0;
    size_t len = strlen(sentence);
    size_t start, end = len;

    for (size_t i = len; i-- > 0;) {
        if (sentence[i] == ' ' || i == 0) {
            start = i > 0 ? i + 1 : i;
            for (size_t j = start; j < end; j++)
                reversed[count++] = sentence[j];
            end = i;

            if (i > 0)
                reversed[count++] = ' ';
            else
                reversed[count] = '\0';
        }
    }
}
