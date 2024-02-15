#include <string.h>
#include <stdbool.h>

bool test_extension(const char *file_name, const char *extension);

int main() {
    test_extension("script.sh", "sh");
    return 0;
}

bool test_extension(const char *file_name, const char *extension) {
    const char *f = file_name + strlen(file_name) - 1;
    const char *e = extension + strlen(extension) - 1;

    while (*f != '.') {
        if (*f-- != *e--)
            return false;
    }

    return true;
}
