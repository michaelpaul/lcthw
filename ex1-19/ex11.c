#include <stdio.h>
#include <string.h>

int main() {
    int numbers[4] = { 0 };
    char name[5] = { 'a' };
    
    printf("numbers: %d %d %d %d \n", 
        numbers[0], numbers[1], numbers[2], numbers[3]);
    printf("name each: %c %c %c %c \n", 
        name[0], name[1], name[2], name[3]);
    printf("name: %s \n", name);
    
    numbers[0] = 'B';
    numbers[1] = 'e';
    numbers[2] = 't';
    numbers[3] = 'i';
    
    name[0] = 66;
    name[1] = 101;
    name[2] = 116;
    name[3] = 105;
    name[4] = '\0';
    
    printf("numbers: %d %d %d %d \n", 
        numbers[0], numbers[1], numbers[2], numbers[3]);
    printf("name each: %c %c %c %c \n", 
        name[0], name[1], name[2], name[3]);
    printf("name: %s \n", name);
    
    char * another = "Beti";
    
    printf("another: %s \n", another);
    printf("another each: %c %c %c %c \n", 
        another[0], another[1], another[2], another[3]);

    char bet[3];
    memcpy(bet, another, 2);
    bet[2] = '\0';
    printf("be: %s \n", bet);
    
    // extra credit!
    char *fit = "Fit";
    int intChars;
    memcpy(&intChars, fit, 3);
    printf("intChars: 0x%x \n", intChars);
    // %s percorre um array de char's e precisa de um \0 no final do array
    // mas ainda funciona com esse hack!
    printf("intChars string: %s \n", (char *)&intChars);
    printf("intChars each: %c %c %c \n", 
        0xFF & intChars, 
        0xFF & (intChars >> 8),
        0xFF & (intChars >> 16)
    );
    
    return 0;
}