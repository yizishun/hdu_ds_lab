#ifndef TREE_H
#define TREE_H
typedef struct BNode {
    int val;
    char c;
    struct BNode *left;
    struct BNode *right;
    struct BNode *parent;
    char *name;
} BNode;

typedef struct Tree {
    BNode *root;
    //meta
    int depth;
    char *name;
} BTree;


BTree *btree_init(char *name);
void btree_print(BNode *, int);
void btree_fprint(BNode *root, int depth);
BNode *bnode_init(int val, char *name, char);
int btree_insert(BTree *t, BNode *victim, BNode *parent, int val, char *name);

#endif