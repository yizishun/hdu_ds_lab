#include <hfm.h>
FILE *hfmtree;

typedef struct character {
    char c;
    int val;
    BNode *node;
    bool is_use;
}character;

typedef struct chartop{
    int n;
    character *chars;
}chartop;
BNode *construct(chartop, int *);
void encode_tree(BTree *tree);
void generateCode(BNode *node, char *code, int depth);


int hfm_init(){
    //get data
    chartop ct;
    printf("n: ");
    if (scanf("%d", &ct.n) != 1 || ct.n <= 0) {
        panic("Invalid input for n");
    }
    ct.chars = malloc(sizeof(character) * ct.n);
    if (ct.chars == NULL) {
        panic("Memory allocation failed");
    }
    for(int i = 0; i < ct.n; i++){
        printf("char%d: ", i);
        while (getchar() != '\n');
        scanf("%c", &ct.chars[i].c);
    }
    for(int i = 0; i < ct.n; i++){
        printf("val%d: ", i);
        if (scanf("%d", &ct.chars[i].val) != 1) {
            panic("Invalid input for value");
        }
        ct.chars[i].node = NULL;
        ct.chars[i].is_use = false;
    }
    printf("construct tree\n");
    //construct tree
    BTree *tree = btree_init("hfm");
    tree->root = construct(ct, &tree->depth);
    printf("tree depth: %d\n", tree->depth);
    btree_print(tree->root, tree->depth);
    btree_fprint(tree->root, tree->depth);
    encode_tree(tree);
    return 0;
}

void encode_tree(BTree *tree){
    hfmtree = fopen("./file/hfmtree", "w");
    char codeBuffer[MAX_CHAR];
    generateCode(tree->root, codeBuffer, 0);
}

void generateCode(BNode *node, char *code, int depth){
    if(node == NULL)
        return;
    if(node->left == NULL && node->right == NULL){
        int c = node->c;
        char *encode = strdup(code);
        fprintf(hfmtree, "%c %s\n", c, encode);
        return;
    }else{
        code[depth] = '0';
        generateCode(node->left, code, depth + 1);
        code[depth] = '1';
        generateCode(node->right, code, depth + 1);
    }
}

BNode *construct(chartop ct, int *depth){
    int min1=0, min2=1;
    int min1val = ct.chars[0].val;
    int min2val = ct.chars[1].val;
    int some_not_use = 0;
    *depth += 1;
    while(1){
        some_not_use = 0;
    //find min1 and min2
        for(int i = 0;i < ct.n; i++){
            if(ct.chars[i].is_use == false){
                some_not_use ++;
                if(min1 == -1 || min1val == -1){
                    min1 = i;
                    min1val = ct.chars[i].val;
                }
                if(ct.chars[i].val < min1val){
                    min1val = ct.chars[i].val;
                    min1 = i;
                }
            }
        }
        for(int i = 0;i < ct.n; i++){
            if(ct.chars[i].is_use == false && i != min1){
                if(min2 == -1 || min2val == -1){
                    min2 = i;
                    min2val = ct.chars[i].val;
                }
                if(ct.chars[i].val < min2val){
                    min2val = ct.chars[i].val;
                    min2 = i;
                }
            }
        }
        assert(min1 != min2);
    //----------
        if(some_not_use == 1){
            *depth += 1;
            break;
        }else{
            #ifdef DEBUG
            printf("min1: %d, min2: %d\n", min1, min2);
            printf("min1val: %d, min2val: %d\n", min1val, min2val);
            printf("not_use : %d\n", some_not_use);
            #endif
            //construce two nodes and generate a new node
            BNode *node1 = ct.chars[min1].node;
            BNode *node2 = ct.chars[min2].node;
            if(node1 == NULL)
                node1 = bnode_init(min1val, "lnode", ct.chars[min1].c);
            if(node2 == NULL)
                node2 = bnode_init(min2val, "lnode", ct.chars[min2].c);
            BNode *nodep = bnode_init(min1val + min2val, "node", (char)0);

            //depth logic
            if(strcmp(node1->name, "node") == 0 || strcmp(node2->name, "node") == 0){
                *depth += 1;
            }

            //connect the three nodes
            node1->parent = nodep;
            node2->parent = nodep;
            nodep->left = node1;
            nodep->right = node2;
            ct.chars[min1].node = node1;
            ct.chars[min2].node = node2;
            ct.chars[min1].is_use = true;
            ct.chars[min2].is_use = true;
            ct.n ++;
            ct.chars = realloc(ct.chars, sizeof(character) * ct.n);
            ct.chars[ct.n - 1].node = nodep;
            ct.chars[ct.n - 1].is_use = false;
            ct.chars[ct.n - 1].val = min1val + min2val;

            min1 = -1 ; min2 = -1; min1val = -1; min2val = -1;
        }
    }
    return ct.chars[ct.n - 1].node;
}
    
