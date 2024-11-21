#include <demon.h>
int len = 100;
char *get_demon_lang(){
    char *lang = malloc(sizeof(char) * 100);
    assert(lang != NULL);

    char c;
    int i = 0;
    while((c = getchar()) != '\n' && c != EOF){
        lang[i++] = c;
        if(i > len-1){
            lang = realloc(lang, sizeof(char) * (len += 100));
            assert(lang != NULL);
        }
    }
    lang[i] = '\0';
    #ifdef DEBUG
    printf("lang: %s size = %lu\n", lang, strlen(lang));
    #endif
    //check if it is a valid demon language
    Stack *s = init_stack(100, "lang");
    for(int i = 0; i < strlen(lang); i++){
        if(lang[i] == '(')
            push_c(s, '(');
        else if(lang[i] == ')')
            if(pop(s) != '(') {panic("invalid demon language");};
    }
    if(!is_empty(s)){
        panic("invalid demon language");
    }
    return lang;
}