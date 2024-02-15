void censor(char s[]);

int main() {
    char s[] = "food fool";
    censor(s);
    return 0;
}

void censor(char s[]) {
    while (*(s + 2)) {
        if (*s == 'f' && *(s + 1) == 'o' && *(s + 2) == 'o') {
            *s = *(s + 1) = *(s + 2) = 'x';
        }

        s++;
    }
}
