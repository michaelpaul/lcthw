#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// typedef creates a fake type, in this case for a function pointer
typedef int (*compare_cb)(const void *a, const void *b);
// sort function
typedef int *(*sort_fn)(int *numbers, int count, compare_cb cmp);

// from ex17
void die(const char *message) 
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}

// stdlib qsort
int *ordena_rapido(int *numbers, int count, compare_cb cmp) 
{
    int *target = malloc(count * sizeof(int));

    if (!target)
        die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));
    qsort(target, count, sizeof(int), cmp);

    return target;
}

// classic BB
int *bubble_sort(int *numbers, int count, compare_cb cmp) 
{
    int temp = 0;
    int i = 0;
    int j = 0;

    int *target = malloc(count * sizeof(int));

    if (!target)
        die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    for (i = 0; i < count; i++) {
        for (j = 0; j < count - 1; j++) {
            if (cmp(&target[j], &target[j + 1]) > 0) {
                temp = target[j + 1];
                target[j + 1] = target[j];
                target[j] = temp;
            }
        }
    }
    
    return target;
}

// compare functions 

int sorted_order(const void *a, const void *b) 
{
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    
    return arg1 - arg2;
}

int reverse_order(const void *a, const void *b) 
{
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    
    return arg2 - arg1;
}

int strange_order(const void *a, const void *b)
{
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    
    if (arg1 == 0 || arg2 == 0) {
        return 0;
    } else {
        return arg1 % arg2;
    }
}

// test sort and print results
void test_sorting(int *numbers, int count, sort_fn sort, compare_cb cmp) 
{
    int i = 0;
    int *sorted = sort(numbers, count, cmp);

    if (!sorted) {
        die("Failed to sort as requested");
    }

    for (i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }

    printf("\n");
    free(sorted);
} 

// read memory from a function pointer, ie. read its compiled code
void read_cb(compare_cb cmp) 
{
    unsigned char *data = (unsigned char *)cmp;

    for(int i = 0; i < 25; i++)  {
        // data[i] = 1; // code is readonly in memory
        printf("%02x:", data[i]);
    }

    printf("\n");
}

int main(int argc, char *argv[]) 
{
    if (argc < 2) die("Usage: ex18 <numbers>");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if (!numbers) die("Memory error");

    for (i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, bubble_sort, sorted_order);
    test_sorting(numbers, count, ordena_rapido, sorted_order);
    printf("\n");

    test_sorting(numbers, count, bubble_sort, reverse_order);
    test_sorting(numbers, count, ordena_rapido, reverse_order);
    printf("\n");

    test_sorting(numbers, count, bubble_sort, strange_order);
    test_sorting(numbers, count, ordena_rapido, strange_order);
    printf("\n");

    free(numbers);

    printf("SORTED: ");
    read_cb(sorted_order);

    printf("REVERSE: ");
    read_cb(reverse_order);

    return 0;
} 
