#include <hfm.h>
int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"init"             , no_argument      , NULL, 'i'},
    {"encoding"         , no_argument      , NULL, 'e'},
    {"decoding"         , no_argument      , NULL, 'd'},
    {"print"            , no_argument      , NULL, 'p'},
    {"tree"             , no_argument      , NULL, 't'},
    {"help"             , no_argument      , NULL, 'h'},
    {0                  , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-iedpth", table, NULL)) != -1) {
    switch (o) {
      case 'i': hfm_init(); break;
      case 'e': encode(); break;
      case 'd': decode(); break;
      case 'p': print_code(); break;
      case 't': printf("pls use -i to generate treeprint"); break;
      default:
        printf("Usage: %s [OPTION...]\n\n", argv[0]);
        printf("******** 哈夫曼编码系统 ********\n");
        printf("1. I：初始化（Initialization）\n");
        printf("   - 从终端读入字符集大小 n，以及 n 个字符和 n 个权值\n");
        printf("   - 建立哈夫曼树，并将它存于文件 hfmTree 中\n");
        printf("2. E：编码（Encoding）\n");
        printf("   - 利用已建好的哈夫曼树（如不在内存，则从文件 hfmTree 中读入）\n");
        printf("   - 对文件 ToBeTran 中的正文进行编码\n");
        printf("   - 将结果存入文件 CodeFile 中\n");
        printf("3. D：译码（Decoding）\n");
        printf("   - 利用已建好的哈夫曼树将文件 CodeFile 中的代码进行译码\n");
        printf("   - 结果存入文件 TextFile 中\n");
        printf("4. P：印代码文件（Print）\n");
        printf("   - 将文件 CodeFile 以紧凑格式显示在终端上，每行 50 个代码\n");
        printf("   - 同时将此字符形式的编码文件写入文件 CodePrin 中\n");
        printf("5. T：印哈夫曼树（Tree）\n");
        printf("   - 打印哈夫曼树结构\n");
        printf("*********************************\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}