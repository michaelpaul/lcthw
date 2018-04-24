#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <string.h>
#include "../dbg.h"

#define USAGE "usage: %s [-o] word...\n"
#define CONFIG "./.logfind"
#define MAX_LINE 1000
#define MODE_AND 1
#define MODE_OR 0

int search_word(char *filename, char *word)
{
    char line[MAX_LINE];
    int found = 0;
    FILE *fp = fopen(filename, "r");
    check(fp, "filed to open file: %s", filename);
    
    // search entire file
    while (NULL != fgets(line, MAX_LINE, fp)) {
        if (strstr(line, word)) {
            found = 1;
            break;
        }
    }
    
    fclose(fp);
    return found;
error:
    if (fp) fclose(fp);
    return 0;
}

// and logic: files that contain *all* the words
// foo AND bar
int match_all(char **words, char *filename)
{
    // foreach word
    for (int j = 0; words[j]; j++) {
        debug("searching %s in %s", words[j], filename);
        if (0 == search_word(filename, words[j])) {
            return 0;
        }
    }
    return 1;
}

// or logic: file that contain *any* of the words
// foo OR bar
int match_any(char **words, char *filename)
{
    // foreach word
    for (int j = 0; words[j]; j++) {
        debug("searching %s in %s", words[j], filename);
        if (1 == search_word(filename, words[j])) {
            return 1;
        }
    }
    return 0;
}

int load_search_paths(glob_t *globbuff)
{
    char line[MAX_LINE];
    int i = 0;
    int flags = GLOB_ERR | GLOB_TILDE_CHECK;
    FILE *fp = fopen(CONFIG, "r");
    check(fp, "unable to open config file: %s", CONFIG);

    while (NULL != fgets(line, MAX_LINE, fp)) {
        line[strlen(line) - 1] = '\0';
        debug("glob path: %s", line);
        
        if (i > 0) flags |= GLOB_APPEND;
        int rc = glob(line, flags, NULL, globbuff);
        
        if (0 != rc) {
            log_err("glob failed for \"%s\"", line);
        }
        i++;
    }

    fclose(fp);
    return 1;
error:
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf(USAGE, argv[0]);
        return 2;
    }

    int mode = 0 == strcmp("-o", argv[1]) ? MODE_OR : MODE_AND;
    
    if (MODE_OR == mode && argc < 3) {
        printf(USAGE, argv[0]);
        return 2;
    }

    // search paths
    glob_t paths;
    int rc = load_search_paths(&paths);
    if (0 == rc) {
        return EXIT_FAILURE;
    }
    debug("matches: %lu", paths.gl_pathc);
    
    char **words = &argv[MODE_AND == mode ? 1 : 2];
    int match_count = 0;

    // foreach file    
    for (int i = 0; i < paths.gl_pathc; i++) {
        char *filename = paths.gl_pathv[i];
        int match = 0; 
        
        if (MODE_AND == mode) {
            match = match_all(words, filename);
        } else {
            match = match_any(words, filename);
        } 

        if (match) {
            printf("%s\n", filename);
            match_count++;
        }
    }

    globfree(&paths);

    return match_count > 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
