#include <stdio.h>
#include <cs50.h>

int main() {
    while (true) {
        int height = get_int("Height: \n");
        if (height <= 0 || height > 8) {
            continue;
        }
        else {
            for (int i = height; i > 0; i--) {
                for (int j = 1; j < i; j++) {
                    printf(" ");
                }
                for (int k = 0; k < (height - i + 1); k++) {
                    printf("#");
                }
                printf("\n");
            }
            break;
        }
    }
}
