#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 0;
    
    argv[1] = "na mao";
    
    for (; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);    
    }
    
    char *states[] = {
        "Paraná", "Rio de Janeiro",
        NULL, "São Paulo", "Bahia"
    };
    states[2] = argv[1];
    for (i=0; i < 4; i++) {
        printf("state %d: %s\n", i, states[i]);    
    }
    
    return 0;
}