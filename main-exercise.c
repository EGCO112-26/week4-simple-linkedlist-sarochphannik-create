/*
 Build a linked list using the `struct node` defined in `node.h`.
 Insert nodes from program arguments, print all node values, then free the list.
 Usage: ./main-exercise 5 8 11 2 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_node.h"

NodePtr create_node(int id) {
    NodePtr n = (NodePtr) malloc(sizeof(StdNode));
    if (!n) return NULL;
    n->id = id;
    snprintf(n->name, sizeof(n->name), "Student%d", id);
    n->name[sizeof(n->name)-1] = '\0';
    n->next = NULL;
    return n;
}

void append_node(NodePtr *head, NodePtr node) {
    if (!node) return;
    if (!*head) { *head = node; return; }
    NodePtr cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}

void print_list(const NodePtr head) {
    NodePtr cur = head;
    while (cur) {
        printf("id=%d name=%s\n", cur->id, cur->name);
        cur = cur->next;
    }
}

void free_list(NodePtr head) {
    NodePtr cur = head;
    while (cur) {
        NodePtr next = cur->next;
        free(cur);
        cur = next;
    }
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Usage: %s <id> [id ...]\n", argv[0]);
        return 0;
    }

    NodePtr head = NULL;
    for (int i = 1; i < argc; ++i) {
        int id = atoi(argv[i]);
        NodePtr n = create_node(id);
        if (!n) { fprintf(stderr, "Allocation failed\n"); free_list(head); return 1; }
        append_node(&head, n);
    }

    printf("List contents:\n");
    print_list(head);

    free_list(head);
    return 0;
}
