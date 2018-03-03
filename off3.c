// nested struct read/write from file
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    char *name;
    struct Node *child;
};

void write() {
    FILE *fp = fopen("book.db", "w");
    
    struct Node dev = { .id=0xbb, .name="admin" };
    struct Node root = {.id=0xaa, .name="sudo" };
    root.child = &dev;
    printf("write\n");
    printf("%d %s \n", root.id, root.name );
    printf("%d %s \n", root.child->id, root.child->name );

    fwrite(&root, sizeof(struct Node), 1, fp);
    fwrite(root.child, sizeof(struct Node), 1, fp);
    fflush(fp);
    fclose(fp);
}

void read() {
    FILE *fp = fopen("book.db", "r");
    struct Node *raiz = malloc(sizeof(struct Node));
    fread(raiz, sizeof(struct Node), 1, fp);
    raiz->child = malloc(sizeof(struct Node));
    fread(raiz->child, sizeof(struct Node), 1, fp);

    printf("read\n");
    printf("%d %s \n", raiz->id, raiz->name);
    printf("%d %s \n", raiz->child->id, raiz->child->name);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    printf("sizeof Node: %lu \n", sizeof(struct Node));
    write();
    read();
}
