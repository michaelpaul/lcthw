#include <stdio.h>

int main(int argc, char * argv[]) {
    int i = 0;
    while (i < 25) {
        printf("%d ", i);
        i++;
    }
    unsigned int b = i;
    while (b > 0) {
        printf("%u ", b);
        // b-- on 0 sets b to the max positive int
        b--;
    }
    printf("%u ", b);
    printf("\n");
    return 0;
}
