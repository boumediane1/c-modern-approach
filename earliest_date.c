#include <stdio.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int compare_dates(Date d1, Date d2);

void format_date(Date date, char *formatted_date);

int main() {
    Date first, second;

    printf("Enter first date: (mm/dd/yy): ");
    scanf("%d/%d/%d", &first.month, &first.day, &first.year);

    printf("Enter second date: (mm/dd/yy): ");
    scanf("%d/%d/%d", &second.month, &second.day, &second.year);

    char earliest[9], latest[9];

    int compare = compare_dates(first, second);

    if (compare < 0) {
        format_date(first, earliest);
        format_date(second, latest);
    } else if (compare > 0) {
        format_date(first, latest);
        format_date(second, earliest);
    }

    if (compare) {
        printf("\n%s is earlier than %s\n", earliest, latest);
    }

    return 0;
}

int compare_dates(Date d1, Date d2) {
    if (d1.year - d2.year)
        return d1.year - d2.year;

    if (d1.month - d2.month)
        return d1.month - d2.month;

    if (d1.day - d2.day)
        return d1.day - d2.day;

    return 0;
}

void format_date(Date date, char *formatted_date) {
    sprintf(formatted_date, "%.2d/%.2d/%.2d", date.month, date.day, date.year);
}
