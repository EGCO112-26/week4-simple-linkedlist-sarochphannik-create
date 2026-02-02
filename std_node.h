// std_node.h
// Simple standard node definition for a linked list

#ifndef STD_NODE_H
#define STD_NODE_H

typedef struct std_node {
    int id;
    char name[30];
    struct std_node *next;
} StdNode;

typedef StdNode* NodePtr;

#endif /* STD_NODE_H */