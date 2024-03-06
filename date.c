#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int day_of_year(Date date);

int compare_dates(Date d1, Date d2);

bool is_leap_year(int year);

int main() {
    Date d1 = {.day = 30, .month = 12, .year = 2024};
    Date d2 = {.day = 31, .month = 12, .year = 2024};

    printf("%d\n", day_of_year(d1));
    printf("%d\n", day_of_year(d2));
    printf("%d\n", compare_dates(d1, d2));
    return 0;
}

int compare_dates(Date d1, Date d2) {
    if (day_of_year(d1) < day_of_year(d2))
        return -1;
    if (day_of_year(d1) > day_of_year(d2))
        return 1;
    return 0;
}

int day_of_year(Date date) {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (is_leap_year(date.year)) {
        days_in_month[1] = 29;
    }

    int day_of_year = 0;

    for (int i = 0; i < date.month - 1; i++) {
        day_of_year += days_in_month[i];
    }

    day_of_year += date.day;

    return day_of_year;
}

bool is_leap_year(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
