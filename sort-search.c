// testando qsort e binsearch
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight) {
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);
    
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;
    
    return who;
}

void Person_destroy(struct Person *who) {
    assert(who != NULL);
    
    free(who->name);
    free(who);
}

void Person_print(struct Person *who) {
    assert (who != NULL);
    
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

// static int
// cmpstringp(const void *p1, const void *p2)
// {
   /* The actual arguments to this function are "pointers to
      pointers to char", but strcmp(3) arguments are "pointers
      to char", hence the following cast plus dereference */
//   return strcmp(* (char * const *) p1, * (char * const *) p2);
// }

int Person_compare(const void *a, const void *b) {
    // explicação no manual da qsort na função acima
    struct Person *p1 = *(struct Person **)a;
    struct Person *p2 = *(struct Person **)b;
    
    printf("Comparando: %s <=> %s \n", p1->name, p2->name);
    
    return strcmp(p1->name, p2->name);
}

int main(int argc, char **argv) {
    /* Sort some people */
    // struct Person *pessoas[5];
    struct Person *pessoas[] = {
        Person_create("Michael", 30, 190, 75),
        Person_create("Beti", 29, 155, 55),
        Person_create("Alice", 22, 150, 65),
        Person_create("Bob", 45, 176, 72)
    };
    
    /* Whatis */
    // (gdb) whatis pessoas
    // type = struct Person *[4]
    // (gdb) whatis &pessoas
    // type = struct Person *(*)[4]
    // (gdb) whatis *pessoas
    // type = struct Person *
    /* Examine */
    // (gdb) x pessoas
    // 0x7fffffffe100: 0x00603050
    // (gdb) x pessoas+0
    // 0x7fffffffe100: 0x00603050
    // (gdb) x pessoas[0]
    // 0x603050:       0x00603070
    // (gdb) x *(pessoas+0)
    // 0x603050:       0x00603070
    /* Print */
    // (gdb) p pessoas
    // $20 = {0x603050, 0x603010, 0x603090, 0x6030d0}
    // (gdb) p &pessoas
    // $12 = (struct Person *(*)[4]) 0x7fffffffe100
    // (gdb) p pessoas+0
    // $21 = (struct Person **) 0x7fffffffe100
    // (gdb) p pessoas[0]
    // $22 = (struct Person *) 0x603050
    // (gdb) p *(pessoas+0)
    // $23 = (struct Person *) 0x603050
    // (gdb) p **(pessoas+0)
    // $24 = {name = 0x603070 "Michael", age = 30, height = 190, weight = 75}
    // (gdb) p pessoas[0][0]
    // $25 = {name = 0x603070 "Michael", age = 30, height = 190, weight = 75}
    // (gdb) p pessoas[1][0]
    // $26 = {name = 0x603030 "Beti", age = 29, height = 155, weight = 55}
    // (gdb) p pessoas[0][1]
    // $27 = {name = 0x21 <error: Cannot access memory at address 0x21>, age = 1751345485, height = 7103841, weight = 7040609}
    /* . vs -> */    
    // (gdb) p &pessoas.name
    // $17 = (char **) 0x603050
    // (gdb) p &pessoas->name
    // $14 = (char **) 0x603050
    // (gdb) p (&pessoas).name
    // $16 = 0x603070 "Michael"
    // (gdb) p (&pessoas)->name
    // $15 = 0x603070 "Michael"
    // (gdb) p pessoas.name
    // $18 = 0x603070 "Michael"
    // (gdb) p pessoas->name
    // $19 = 0x603070 "Michael"
    
    size_t elm_size = sizeof(struct Person *);
    int count = sizeof(pessoas) / elm_size; 
    // como usar a compare: passar endereço do elemento
    printf("%i \n", Person_compare(&pessoas[0], &pessoas[1]));
    printf("%i \n", Person_compare(&*(pessoas + 1), &*pessoas));
    
    // https://stackoverflow.com/questions/23689687/sorting-an-array-of-struct-pointers-using-qsort
    qsort(pessoas, count, elm_size, Person_compare);
    
    int i;
    for (i = 0; i < count; i++) {
        Person_print(pessoas[i]);
    }
    /* @TODO Search someone */
    // struct Person *beti = Person_create("Beti", 29, 155, 55);
    
    // struct Person *found = bsearch(beti, pessoas, 
    //     sizeof(pessoas) / sizeof(struct Person), sizeof(struct Person), 
    //     Person_compare);
    
    // if (found == NULL) {
    //     printf("404 Person Not Found\n");
    // } else {
    //     printf("Achei você! \n");
    //     Person_print(found);
    // }
    
    for (i = 0; i < count; i++) {
        Person_destroy(pessoas[i]);
    }
    return 0;
}
