#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: manda pelo menos um argumento ai \n");
        return 1;
    }

    char *cmd = strndup(argv[0], 4);
    cmd[0] = ',';
    cmd[1] = ' ';
    printf("This is going to%splode your mind! \n", cmd);

    for (int j = 1; j < argc; j++) {
        int i = 0;
        for (i = 0; argv[j][i] != '\0'; i++) {
            char letter = argv[j][i];
            switch(letter) {
                case 'a':
                case 'A':
                    printf("%d: 'A'\n", i);
                    break;
                case 'e':
                case 'E':
                    printf("%d: 'E' \n", i);
                    break;
                case 'i':
                case 'I':
                    printf("%d: 'I' \n", i);
                    break;
                case 'o':
                case 'O':
                    printf("%d: 'O' \n", i);
                    break;
                case 'u':
                case 'U':
                    printf("%d: 'U' \n", i);
                    break;
                case 'y':
                case 'Y':
                    if (i > 2) {
                        // it's only sometimes Y
                        printf("%d: 'Y' \n", i);
                    }
                    break;
                default:
                    printf("%d: %c is not a vowel\n", i, letter);
            }
        }
    }

    return 0;
}
