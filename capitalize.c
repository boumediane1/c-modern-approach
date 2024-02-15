#include <ctype.h>

void capitalize(char s[]);
void capitalize_ptr(char *s);

int main() {
    char s[] = "CLion";
    capitalize_ptr(s);
    return 0;
}

void capitalize(char s[]) {
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = (char) toupper(s[i]);
}


void capitalize_ptr(char *s) {
    while (*s) {
        *s = (char) toupper(*s);
        s++;
    }
}
