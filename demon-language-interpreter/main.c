#include <demon.h>
#include <assert.h>
/*
用规则B→tAdA和A→sae实现一个魔王语言的解释系统,把他的话解释成人能听得懂的语言。
魔王的语言是依据以下两种形式的规则由人的语言逐步抽象上去：
  (1)a→β1β2…β3
  (2)(θδ1δ2…δn)->θδnθδn-1… θδ1θ
设大写字母表示魔王语言的词汇；小写字母表示人的语言词汇；希腊字母表示可以用大写字母或小写字母代换的变量。魔王语言可含人的词汇。
*/
int main(){
    char *demon_lang = get_demon_lang();
    //char *demon_lang = "B(ehnxgz)B";
    assert(demon_lang);
    unsigned int size = strlen(demon_lang);

    char *trans = translate(demon_lang, size);
    assert(trans);
    //print result
    printf("\nRESULT:\n");
    printf("\033[1;32m" "%s -> %s\n" "\033[0m", demon_lang, trans);
    //assert(strcmp(trans, "tsaedsaeezegexenehetsaedsae"));
    return 0;
}
