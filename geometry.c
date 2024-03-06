#include <stdbool.h>

typedef struct point {
    int x;
    int y;
} Point;

typedef struct rectangle {
    Point upper_left;
    Point lower_right;
} Rectangle;

Point rectangle_center(Rectangle r);

int rectangle_area(Rectangle r);

Rectangle move_rectangle(Rectangle r, int x, int y);

bool within_rectangle(Rectangle r, Point p);

int main() {
    Rectangle r = {0, 0, 1, 1};
    move_rectangle(r, 1, 1);
    return 0;
}

bool within_rectangle(Rectangle r, Point p) {
    return p.x >= r.upper_left.x
        && p.x <= r.lower_right.x
        && p.y >= r.upper_left.y
        && p.y <= r.lower_right.y;
}

Rectangle move_rectangle(Rectangle r, int x, int y) {
    r.upper_left.x += x;
    r.upper_left.y += y;
    r.lower_right.x += x;
    r.lower_right.y += y;
    return r;
}

Point rectangle_center(Rectangle r) {
    Point center;
    center.x = (r.lower_right.x - r.upper_left.x) / 2;
    center.y = (r.lower_right.y - r.upper_left.y) / 2;
    return center;
}

int rectangle_area(Rectangle r) {
    return (r.lower_right.x - r.upper_left.x) * (r.lower_right.y - r.upper_left.y);
}
