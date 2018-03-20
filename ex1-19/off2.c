#include <stdio.h>

// strtolower
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: vc precisa de um argumento \n");
        return 1;
    }
    int i = 0;
    for (i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];
        // upper 65 - 90
        // lower 97 - 122
        if (letter >= 65 && letter <= 90) {
            letter += 32;
        }
        printf("%d %c\n", letter, letter);
    }
    return 0;
}
