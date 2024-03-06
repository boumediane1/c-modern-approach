#include <math.h>

enum shape_kind {
    RECTANGLE,
    CIRCLE
};

struct point {
    int x, y;
};

struct shape {
    enum shape_kind shape_kind;
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;

        struct {
            int radius;
        } circle;
    } u;
} s;

int shape_area(struct shape s);
struct shape move_shape(struct shape s, int x, int y);
struct shape scale_shape(struct shape s, double c);

int main() {

    return 0;
}

int shape_area(struct shape shape) {
    if (shape.shape_kind == RECTANGLE)
        return shape.u.rectangle.height * shape.u.rectangle.width;
    else if (shape.shape_kind == CIRCLE)
        return M_PI * pow(shape.u.circle.radius, 2);
    return 0;
}

struct shape move_shape(struct shape shape, int x, int y) {
    shape.center.x += x;
    shape.center.y += y;
    return shape;
}

struct shape scale_shape(struct shape shape, double c) {
    if (shape.shape_kind == RECTANGLE) {
        shape.u.rectangle.height *= c;
        shape.u.rectangle.width *= c;
    } else if (shape.shape_kind == CIRCLE) {
        shape.u.circle.radius *= c;
    }
    return shape;
}
