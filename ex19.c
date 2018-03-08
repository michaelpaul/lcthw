#include "dbg.h"

#include <stdlib.h>
#include <stdio.h>

void test_debug() 
{
    debug("no need for newline");
    debug("can have %d arguments", 999);
}

void test_log_err()
{
    log_err("something broken");
    log_err("HTTP/%.1f %d %s", 1.1, 404, "Not Found");
}

void test_log_warn()
{
    log_warn("sit back and relax");
    log_warn("there is no such a thing as %s", "aliens");
}

void test_log_info()
{
    log_info("i=0");
    log_info("floats work too: %f", 1.3f);
}

int test_check(char *file_name) 
{
    FILE *input = NULL;
    char *block = NULL;

    block = malloc(100);
    check_mem(block); // should work

    input = fopen(file_name, "r");
    check(input, "Failed to open: %s", file_name);

    free(block);
    fclose(input);
    return 0;

error:
    if (block) free(block);
    if (input) fclose(input);
    return -1;
}

int test_sentinel(int code) 
{
    char *temp = malloc(100);
    check_mem(temp);

    switch(code) {
        case 1:
            log_info("It worked.");
            break;
        default:
            sentinel("Code not implemented yet");
    }

    free(temp);
    return 0;

error:
    if (temp) free(temp);
    return -1;
} 

int test_check_mem()
{
    char *test = NULL;
    check_mem(test);

    free(test);
    return 1;

error:
    return -1;
}

int test_check_debug()
{
    int i = 0;
    check_debug(i != 0, "I was 0.");

    return 0;
error:
    return -1;
}

int main(int argc, char *argv[])
{
    check(argc == 2, "Need an argument");

    test_debug();
    test_log_err();
    test_log_warn();
    test_log_info();

    check(test_check("ex19.c") == 0, "failed with ex19.c");
    check(test_check(argv[1]) == -1, "failed with argv");
    check(test_sentinel(1) == 0, "test_sentinel failed");
    check(test_sentinel(100) == -1, "test_sentinel failed");
    check(test_check_mem() == -1, "test_check_mem failed");
    check(test_check_debug() == -1, "test_check_debug failed");

    return 0;

error:
    return -1;
}
