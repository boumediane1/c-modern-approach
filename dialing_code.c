#include <stdio.h>

#define CODES_LEN 33

struct dialing_code {
    char *country;
    int code;
};

const struct dialing_code country_codes[] = {
        {"Argentina",           54},
        {"Bangladesh",          880},
        {"Brazil",              55},
        {"Burma (Myanmar)",     95},
        {"China",               86},
        {"Colombia",            57},
        {"Congo, Dem. Rep. of", 243},
        {"Egypt",               20},
        {"Ethiopia",            251},
        {"France",              33},
        {"Germany",             49},
        {"India",               91},
        {"Indian",              91},
        {"Indonesia",           62},
        {"Italy",               39},
        {"Mexico",              52},
        {"Pakistan",            92},
        {"Poland",              48},
        {"South Africa",        27},
        {"Spain",               34},
        {"Thailand",            66},
        {"Ukraine",             380},
        {"United States",       1},
        {"Iran",                98},
        {"Japan",               81},
        {"Nigeria",             234},
        {"Philippines",         63},
        {"Russia",              7},
        {"South Korea",         82},
        {"Sudan",               249},
        {"Turkey",              90},
        {"United Kingdom",      44},
        {"Vietnam",             84}
};

int main() {
    int code;
    printf("Enter international dialing code: ");
    scanf("%d", &code);

    for (int i = 0; i < CODES_LEN; i++) {
        if (code == country_codes[i].code)
            printf("%s", country_codes[i].country);
        else
            printf("No country found!");
    }

    return 0;
}