#include <hfm.h>

void decode(){
  FILE *encoded = fopen("./file/CodeFile", "r");
  FILE *hfmtree = fopen("./file/hfmtree", "r");
  FILE *decoded = fopen("./file/TextFile", "w");

  char *huffmanCode[MAX_CHAR];
  char reverseCode[MAX_CHAR][MAX_CHAR];
  char c, code[128];

  while(fscanf(hfmtree, "%c %s\n", &c, code) != EOF){
    huffmanCode[(unsigned char)c] = strdup(code);
    strcpy(reverseCode[(unsigned char)c], huffmanCode[(unsigned char)c]);
  }

  char buffer[MAX_CHAR] = {0};  // 用于存储当前读取的编码
  char bit;
  int index = 0;

  while ((bit = fgetc(encoded)) != EOF) {
    buffer[index++] = bit;  // 将当前位加入 buffer
    buffer[index] = '\0';   // 确保是字符串

    // 查找反向查找表
    for (int i = 0; i < MAX_CHAR; i++) {
      if (reverseCode[i][0] != '\0' && strcmp(reverseCode[i], buffer) == 0) {
        fputc(i, decoded);  // 输出对应字符
        index = 0;          // 重置 buffer
        break;
      }
    }
  }
  if(index != 0){
    panic("decode: error");
  }
}