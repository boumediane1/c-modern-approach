#include <string.h>

void remove_filename(char *url);

int main() {
    char url[] = "http://www.knking.com/index.html";
    remove_filename(url);
    return 0;
}


void remove_filename(char *url) {
    char *end = url + strlen(url) - 1;

    while (*end != '/')
        end--;

    *end = '\0';
}
