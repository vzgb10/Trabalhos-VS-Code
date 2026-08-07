#include <stdio.h>

int main() {
    int x = 0;
    int y;
    while(x <= 20) {
        y = (x-5) * (x-10);
        printf("\nx = %2d   y = %3d", x, y);
        x++;
    }
}