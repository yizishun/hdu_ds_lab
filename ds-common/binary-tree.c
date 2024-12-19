#include "./include/binary-tree.h"
#include "./include/utils.h"
#include "./include/common.h"
#include "./include/stack.h"
#include <math.h>

BTree *btree_init(char *name)
{
    BTree *t = (BTree *)malloc(sizeof(BTree));
    t->root = NULL;
    t->depth = 0;
    t->name = name;
    #ifdef DEBUG
    printf("[DEBUG] btree_init: %s\n", t->name);
    #endif
    return t;
}

BNode *bnode_init(int val, char *name, char c){
    BNode *victim = (BNode *)malloc(sizeof(BNode));
    #ifdef DEBUG
    printf("[DEBUG] bnode_init: %d\n", val);
    #endif
    victim->left = NULL;
    victim->name = name;
    victim->parent = NULL;
    victim->right = NULL;
    victim->val = val;
    victim->c = c;
    return victim;
}

int btree_insert(BTree *t, BNode *victim, BNode *parent, int val, char *name){
    panic_a(t == NULL, "btree_insert: t is NULL");
    panic_a(parent == NULL, "btree_insert: parent is NULL");
    //TODO: check if parent in this tree
    if(parent->left == NULL){
        parent->left = victim;
    }else if(parent->right == NULL){
        parent->right = victim;
    }else{
        #ifdef DEBUG
        printf("[DEBUG] btree_insert: insert fail\n");
        #endif
        return -1;
    }
    victim->parent = parent;
    #ifdef DEBUG
    printf("[DEBUG] btree_insert val = %d name = %s: insert success\n", val, name);
    #endif
    return 0;
}
void btree_print(BNode *root, int depth) {
    if (!root) {
        printf("Tree is empty.\n");
        return;
    }

    int maxNodes = (pow(2, depth) - 1) * 2; // 最大可能的节点数
    BNode **queue = malloc(maxNodes * sizeof(BNode*) * 2); // 队列存储节点
    int front = 0, rear = 0;

    // 初始化队列
    queue[rear++] = root;

    for (int level = 1; level <= depth; level++) {
        int levelNodes = pow(2, level - 1); // 当前层的节点数
        int space = pow(2, depth - level) - 1; // 节点之间的空格数
        if (rear >= maxNodes) {
            fprintf(stderr, "Queue overflow detected.\n");
            free(queue);
            return;
        }

        // 打印每层的节点
        for (int i = 0; i < levelNodes; i++) {
            // 打印左侧的前导空格
            if (i == 0) {
                for (int j = 0; j < space; j++) printf(" ");
            } else {
                for (int j = 0; j < space * 2 + 1; j++) printf(" ");
            }

            // 从队列中取出节点
            BNode *node = queue[front++];
            if (node) {
                printf("%d", node->val);
                queue[rear++] = node->left;
                queue[rear++] = node->right;
            } else {
                printf("#");
                queue[rear++] = NULL;
                queue[rear++] = NULL;
            }
        }
        printf("\n");
    }

    free(queue);
}
void btree_fprint(BNode *root, int depth) {
    if (!root) {
        printf("Tree is empty.\n");
        return;
    }
    FILE *fp = fopen("./file/treePrint", "w");

    int maxNodes = (pow(2, depth) - 1) * 2; // 最大可能的节点数
    BNode **queue = malloc(maxNodes * sizeof(BNode*) * 2); // 队列存储节点
    int front = 0, rear = 0;

    // 初始化队列
    queue[rear++] = root;

    for (int level = 1; level <= depth; level++) {
        int levelNodes = pow(2, level - 1); // 当前层的节点数
        int space = pow(2, depth - level) - 1; // 节点之间的空格数
        if (rear >= maxNodes) {
            fprintf(stderr, "Queue overflow detected.\n");
            free(queue);
            return;
        }

        // 打印每层的节点
        for (int i = 0; i < levelNodes; i++) {
            // 打印左侧的前导空格
            if (i == 0) {
                for (int j = 0; j < space; j++) fprintf(fp, " ");
            } else {
                for (int j = 0; j < space * 2 + 1; j++) fprintf(fp, " ");
            }

            // 从队列中取出节点
            BNode *node = queue[front++];
            if (node) {
                fprintf(fp, "%d", node->val);
                queue[rear++] = node->left;
                queue[rear++] = node->right;
            } else {
                fprintf(fp, "#");
                queue[rear++] = NULL;
                queue[rear++] = NULL;
            }
        }
        fprintf(fp, "\n");
    }

    free(queue);
}


char *btree_serialize(BTree *t){
    panic_a(t == NULL, "btree_serialize: t is NULL");
    panic_a(t->root == NULL, "btree_serialize: t->root is NULL");
    return NULL;
}

BTree *btree_deserialize(char *s){
    panic_a(s == NULL, "btree_deserialize: s is NULL");
    return NULL;
}