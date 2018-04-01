#include <stdio.h>
#include <string.h>
#include "../dbg.h"

#define BSIZE 1000

int normal_copy(char * from, char *to, int count) 
{
    int i = 0;

    for (i = 0; i < count; i++) {
        to[i] = from[i];
    }

    return i;
}

int duffs_device(char *from, char *to, int count)
{
    {
        int n = (count + 7) / 8;
        log_info("blocks: %d count: %d mod: %d", n, count, count % 8);

        switch (count % 8) {
            case 0:
                do {
                    *to++ = *from++;
                    case 7:
                    *to++ = *from++;
                    case 6:
                    *to++ = *from++;
                    case 5:
                    *to++ = *from++;
                    case 4:
                    *to++ = *from++;
                    case 3:
                    *to++ = *from++;
                    case 2:
                    *to++ = *from++;
                    case 1:
                    *to++ = *from++;
                } while (--n > 0);
        }
    }
    return count;
}

int zeds_device(char *from, char *to, int count)
{
    int n = (count + 7) / 8;

    switch (count % 8) {
        case 0:
again:  *to++ = *from++;
        case 7:
        *to++ = *from++;
        case 6:
        *to++ = *from++;
        case 5:
        *to++ = *from++;
        case 4:
        *to++ = *from++;
        case 3:
        *to++ = *from++;
        case 2:
        *to++ = *from++;
        case 1:
        *to++ = *from++;
        if (--n > 0)
            goto again;
    }

    return count;
}

int valid_copy(char *data, int count, char expects) 
{
    int i = 0;
    for (i = 0; i < count; i++) {
        if (data[i] != expects) {
            log_err("[%d] %c != %c", i, data[i], expects);
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    char from[BSIZE] = { 'a' };
    char to[BSIZE] = { 'c' };
    int rc = 0;

    // set up the from to have some stuff
    memset(from, 'x', BSIZE);
    // set it to a failure mode
    memset(to, 'y', BSIZE);
    check(valid_copy(to, BSIZE, 'y'), "Not initialized right");

    // use normal copy
    rc = normal_copy(from, to, BSIZE);
    check(rc == BSIZE, "Normal copy failed: %d", rc);
    check(valid_copy(to, BSIZE, 'x'), "Normal copy failed.");

    // reset
    memset(to, 'y', BSIZE);

    // duffs version
    rc = duffs_device(from, to, BSIZE);
    check(rc == BSIZE, "Duff's device failed: %d", rc);
    check(valid_copy(to, BSIZE, 'x'), "Duff's device failed copy.");

    // reset 
    memset(to, 'y', BSIZE);

    // zed's version
    rc = zeds_device(from, to, BSIZE);
    check(rc == BSIZE, "Zed's device failed: %d", rc);
    check(valid_copy(to, BSIZE, 'x'), "Zed's device failed copy.");

    // less then a block
    duffs_device(from, to, 5);
    // more then a block
    duffs_device(from, to, 11);

    return 0;
error:
    return 1;
}
