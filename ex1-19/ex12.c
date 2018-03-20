#include <stdio.h>

int main() {
    char full_name[] = { 
        'm', 'p', '\0', 
        'r', 'o', 's', 'a' 
    };
    int areas[] = {2*2, 3*3, 4*4, 5*5, 6*6};
    char name[] = "Mich\0ael";
        
    printf("The size of an int: %ld\n", sizeof(int));
    printf("The size of areas (int[]): %ld\n", sizeof(areas));
    printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
    printf("The first area is %d, the 2nd %d. \n", areas[0], areas[1]);

    printf("The size of char: %ld\n", sizeof(char));
    printf("The size of name (char[]): %ld\n", sizeof(name));
    printf("The number of chars: %ld\n", sizeof(name) / sizeof(char));
    
    printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
    printf("The number of chars: %ld\n", sizeof(full_name) / sizeof(char));
    
    printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);
    
    return 0;
}