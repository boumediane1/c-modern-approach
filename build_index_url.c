#include <stdio.h>
#include <string.h>

void build_index_url(const char *domain, char *index_url);

int main() {
    char index_url[255];
    build_index_url("knking.com", index_url);
    return 0;
}

void build_index_url(const char *domain, char *index_url) {
    strcpy(index_url, "http://www.");
    strcat(index_url, domain);
    strcat(index_url, "/index.html");
}
