#include <stdlib.h>
#include <stdio.h>

void closest_flight(const int daily_flights[][2], int desired_time, int *departure_time, int *arrival_time);

void show_daily_flights(const int daily_flights[][2]);

void format_time(int minutes, char *time);

int from_time(int hours, int minutes);

int main() {
    int daily_flights[8][2] = {
            {from_time(8, 0),   from_time(10, 16)},
            {from_time(9, 43),  from_time(11, 52)},
            {from_time(11, 19), from_time(1, 31)},
            {from_time(12, 47), from_time(15, 0)},
            {from_time(14, 0),  from_time(16, 8)},
            {from_time(15, 45), from_time(17, 55)},
            {from_time(19, 0),  from_time(21, 20)},
            {from_time(21, 45), from_time(23, 58)}
    };

    int hour, second, departure_time, arrival_time;

    show_daily_flights(daily_flights);

    printf("\nEnter a 24 hour time: ");
    scanf("%d:%d", &hour, &second);

    int desired_time = from_time(hour, second);

    closest_flight(daily_flights, desired_time, &departure_time, &arrival_time);

    char formatted_departure_time[6], formatted_arrival_time[6];
    format_time(departure_time, formatted_departure_time);
    format_time(arrival_time, formatted_arrival_time);

    printf("Closest departure time is %s, arriving at %s", formatted_departure_time, formatted_arrival_time);

    return 0;
}

void closest_flight(const int daily_flights[][2], int desired_time, int *departure_time, int *arrival_time) {
    *departure_time = daily_flights[0][0];
    *arrival_time = daily_flights[0][1];

    int smallest_diff = abs(desired_time - *departure_time);

    for (int i = 1; i < 8; i++) {
        int diff = abs(desired_time - daily_flights[i][0]);

        if (diff < smallest_diff) {
            smallest_diff = diff;
            *departure_time = daily_flights[i][0];
            *arrival_time = daily_flights[i][1];
        }
    }
}

void show_daily_flights(const int daily_flights[8][2]) {
    printf("departure time\tarrival time\n");
    for (int i = 0; i < 8; i++) {
        char departure_time[6], arrival_time[6];
        format_time(daily_flights[i][0], departure_time);
        format_time(daily_flights[i][1], arrival_time);
        printf("%s\t%s\n", departure_time, arrival_time);
    }
}

void format_time(int minutes, char *time) {
    sprintf(time, "%02d:%02d", minutes / 60, minutes % 60);
}

int from_time(int hours, int minutes) {
    return hours * 60 + minutes;
}
