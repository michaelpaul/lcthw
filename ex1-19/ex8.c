#include <stdio.h>

int main (int argc, char * argv[]) {
    int i = 0;
    if (argc == 1) {
        printf("Sem argumentos...\n");
    } else if (argc == 2) {
        printf("Need Help? \n");
    } else if (argc > 2 && argc < 5) {
        printf("Agora dava pra analisar esses caras...\n");
        printf("%s %s %s\n", argv[1], argv[2], argv[3]);
    } else if (argc == 5) {
        printf("High five!\n");
    } else {
        printf("Listando tudo: \n");
        for(i = 0; i < argc; i++) {
            printf("arg: %d, value: %s \n", i, argv[i]);
        }
        printf("\n");
    }
    return 0;
}
