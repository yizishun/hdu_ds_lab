#include <hfm.h>


void encode(){
  FILE *target = fopen("./file/ToBeTran", "r");
  FILE *hfmtree = fopen("./file/hfmtree", "r");
  FILE *encoded = fopen("./file/CodeFile", "w");
  char *huffmanCode[MAX_CHAR];
  char c, code[128];
  while(fscanf(hfmtree, "%c %s\n", &c, code) != EOF){
    huffmanCode[(unsigned char)c] = strdup(code);
  }
  while(fscanf(target, "%c", &c) != EOF){
    if(huffmanCode[(unsigned char)c] == NULL){
      panic("Invalid character in input file");
    }
    fprintf(encoded, "%s", huffmanCode[(unsigned char)c]);
  }
}