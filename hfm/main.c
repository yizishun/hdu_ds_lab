#include <hfm.h>
/*
设计并实现一个写一个哈夫曼码的编/译码系统，系统功能包括：
（1）I：初始化（Initialization）。从终端读入字符集大小n，以及n个字符和n个权值，建立哈夫曼树，并将它存于文件hfmTree中；
（2）E：编码（Encoding）。利用以建好的哈夫曼树（如不在内存，则从文件hfmTree中读入），对文件ToBeTran中的正文进行编码，然后将结果存入文件CodeFile中；
（3）D：译码（Decoding）。利用已建好的哈夫曼树将文件CodeFile中的代码进行译码，结果存入文件TextFile中；
（4）P：印代码文件（Print）。将文件CodeFile以紧凑格式显示在终端上，每行50个代码。同时将此字符形式的编码文件写入文件CodePrin中；
（5）T：印哈夫曼树（Tree)
*/

int parse_args(int argc, char *argv[]);
int main(int argc, char *argv[]){
    parse_args(argc, argv);
    return 0;
}
