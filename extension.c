#include <stdio.h>
#include <string.h>

void get_extension(const char *file_name, char *extension);

int main() {
    char extension[255];
    get_extension("something.txt", extension);

    printf("%s", extension);
    return 0;
}


void get_extension(const char *file_name, char *extension) {
    size_t len = strlen(file_name);
    const char *temp = file_name + len - 1;

    while (*temp != '.')
        temp--;

    strcpy(extension, temp + 1);
}
