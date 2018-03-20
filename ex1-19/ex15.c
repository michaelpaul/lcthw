#include <stdio.h>

void separator() {
    printf("-----\n");
}

void first_way(int count, char *line, char **names, int *ages) {
    int i = 0;
    // first way using indexing
    for(i = 0; i < count; i++) {
        printf(line, names[i], ages[i]);
    }
    separator();
    // reverse
    for(i = count - 1; i >= 0; i--) {
        printf("  ");
        printf(line, names[i], ages[i]);
    }
    separator();
}

void second_way(int count, char **names, int *ages) {
    int i = 0;
    char *line = "%s is %d years old.\n";
    // second way using pointers
    for (i = 0; i < count; i++) {
        printf(line, *(names + i), *(ages + i));
    }
    printf("-----\n");
    // second way reverve
    for (i = count - 1; i >= 0; i--) {
        printf("  ");
        printf(line, *(names + i), *(ages + i));
    }
    printf("-----\n");
}

void third_way(int count, char **name, int *age) {
    first_way(count, "%s is %d years old again.\n", name, age);
}

void fourth_way(int count, char ** cur_name, char **names, int *cur_age, int *ages) {
    char * line = "%s lived %d years so far.\n";
    // fourth way with pointers in a stupid complex way 
    for (cur_name = names, cur_age = ages; 
        (cur_age - ages) < count; cur_name++, cur_age++) {
        printf(line, *cur_name, *cur_age);
    }
    printf("-----\n");
    // fourth way reverse, stupid  
    for (cur_name = names + (count - 1), cur_age = ages + (count - 1); 
        cur_age >= ages; 
        cur_name--, cur_age--) {
        printf("  ");
        printf(line, *cur_name, *cur_age);
    }
}

int main(int argc, char *argv[]) {
    // create two arrays we carre about
    int ages[] = { 
        23, 43, 
        12, 89, 2 
    };
    char *names[] = {
        "Alan", "Frank", 
        "Mary", "John", "Lisa"
    };
    
    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    // int count = sizeof(names) / sizeof(char *); // the same using names
    int i = 0;
    
    first_way(count, "%s has %d years alive.\n", names, ages);
    
    // setup pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;
    
    second_way(count, cur_name, cur_age);
    third_way(count, cur_name, cur_age);
    fourth_way(count, cur_name, names, cur_age, ages);
    
    for (i = 0; i < count; i++) {
        printf("where name: %p\tage: %p\n", cur_name + i, cur_age + i);
    }
    return 0;
}