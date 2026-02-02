/*
 Build a linked list using the `struct node` defined in `node.h`.
 Insert nodes from program arguments, print all node values, then free the list.
 Usage: ./main-exercise 5 8 11 2 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_node.h"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Usage: %s <id> <name> [<id> <name> ...]\n", argv[0]);
        return 0;
    }

    NodePtr head = NULL, tail = NULL, tmp;
    int i = 1;
    while (i < argc) {
        int id = atoi(argv[i]);
        const char *name = NULL;
        if (i + 1 < argc) name = argv[i+1];

        NodePtr n = (NodePtr) malloc(sizeof(StdNode));
        if (!n) { fprintf(stderr, "Allocation failed\n");
            tmp = head; while (tmp) { head = head->next; free(tmp); tmp = head; };
            return 1;
        }
        n->id = id;
        if (name) {
            strncpy(n->name, name, sizeof(n->name)-1);
            n->name[sizeof(n->name)-1] = '\0';
        } else {
            snprintf(n->name, sizeof(n->name), "Student%d", id);
            n->name[sizeof(n->name)-1] = '\0';
        }
        n->next = NULL;

        if (!head) { head = n; tail = n; }
        else { tail->next = n; tail = n; }

        i += (name ? 2 : 1);
    }

    tmp = head;
    while (tmp) {
        printf("%d %s\n", tmp->id, tmp->name);
        tmp = tmp->next;
    }

    tmp = head;
    while (tmp) {
        head = head->next;
        free(tmp);
        tmp = head;
    }

    return 0;
}
