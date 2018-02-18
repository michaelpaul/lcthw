#include <stdio.h>

int main(int argc, char *argv[])
{
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'P';
    char first_name[] = "Michael";
    char last_name[] = "Rosa";

    printf("You are %d miles away\n", distance);
    printf("Um %f float\n", power);
    printf("Meu super poder %f \n", super_power);
    printf("Um unico char: %c \n", initial);
    printf("Primeiro nome %s \n", first_name);
    printf("Segundo nome %s \n", last_name);
    printf("Nome completo %s %c. %s \n", first_name, initial, last_name);

    int bugs = 100;
    double bug_rate = 1.2;

    printf("Vc tem %d bugs na fila, aumentando a uma taxa de %f \n", bugs, bug_rate);

    long universe_of_defects = 1L * 1024L * 1024L * 1024L;
    printf("O universo inteiro de bugs %ld \n", universe_of_defects);

    double expected_bugs = bugs * bug_rate;
    printf("Deve ainda vai ver uns %f bugs \n", expected_bugs);

    double part_universe = expected_bugs / universe_of_defects;
    // %e scientific notation 
    printf("Uma parte dos bugs %e \n", part_universe);

    // algo sem sentido
    char nul_byte = '\0';
    int care_percentage = bugs * nul_byte;
    printf("O quanto vc deve se importar: %d%% \n", care_percentage);

    return 0;
}
