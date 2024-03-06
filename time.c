#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
    int seconds;
} Time;

Time split_time(long total_seconds);

int main() {
    Time time = split_time(93630);
    printf("%.2d:%.2d:%.2d\n", time.hours, time.minutes, time.seconds);
    return 0;
}

Time split_time(long total_seconds) {
    Time time;
    time.hours = (int) (total_seconds / 3600 % 24);
    time.minutes = (int) (total_seconds / 60 % 60);
    time.seconds = (int) total_seconds % 60;

    return time;
}
