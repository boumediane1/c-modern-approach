#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int red;
    int green;
    int blue;
} Color;

Color darken(Color color);

Color brighter(Color color);

bool equal_color(Color color1, Color color2);

int get_red(Color color);

Color make_color(int red, int green, int blue);

int main() {
    const Color magenta = {255, 0, 255};
    printf("%d\n", magenta.red);
    return 0;
}

Color darken(Color color) {
    color.red = (int) (color.red * 0.7);
    color.green = (int) (color.green * 0.7);
    color.red = (int) (color.red * 0.7);

    return color;
}

Color brighter(Color color) {
    if (color.red == 0 && color.green == 0 && color.blue == 0)
        return (Color) {3, 3, 3};

    if (color.red > 0 && color.red < 3)
        color.red = 3;

    if (color.green > 0 && color.green < 3)
        color.green = 3;

    if (color.blue > 0 && color.blue < 3)
        color.blue = 3;

    color.red = (int) (color.red / 0.7) > 255 ? 255 : (int) (color.red / 0.7);
    color.green = (int) (color.green / 0.7) ? 255 : (int) (color.green / 0.7);
    color.blue = (int) (color.blue / 0.7) ? 255 : (int) (color.blue / 0.7);

    return color;
}

bool equal_color(Color color1, Color color2) {
    return color1.red == color2.red && color1.green == color2.green && color1.blue == color2.blue;
}

int get_red(Color color) {
    return color.red;
}

Color make_color(int red, int green, int blue) {
    if (red < 0)
        red = 0;
    else if (red > 255)
        red = 255;

    if (green < 0)
        green = 0;
    else if (green > 255)
        green = 255;

    if (blue < 0)
        blue = 0;
    else if (blue > 255)
        blue = 255;

    return (Color) {red, green, blue};
}
