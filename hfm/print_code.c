#include <hfm.h>

void print_code()
{
    FILE *codeFile = fopen("./file/CodeFile", "r");
    if (!codeFile) {
        perror("Failed to open ./file/CodeFile");
        return;
    }

    FILE *codePrin = fopen("./file/CodePrin", "w");
    if (!codePrin) {
        perror("Failed to open ./file/CodePrin");
        fclose(codeFile);
        return;
    }

    char buffer[51];  // 用于存储每行 50 个字符，加 '\0' 保证是字符串
    int index = 0;
    char c;

    while ((c = fgetc(codeFile)) != EOF) {
        buffer[index++] = c;

        // 如果缓冲区满了（50 个字符），输出并写入文件
        if (index == 50) {
            buffer[index] = '\0';  // 添加字符串结束符
            printf("%s\n", buffer);
            fprintf(codePrin, "%s\n", buffer);
            index = 0;  // 重置缓冲区索引
        }
    }

    // 如果还有剩余字符（不足 50 个），也需要输出
    if (index > 0) {
        buffer[index] = '\0';  // 添加字符串结束符
        printf("%s\n", buffer);
        fprintf(codePrin, "%s\n", buffer);
    }

    fclose(codeFile);
    fclose(codePrin);
}