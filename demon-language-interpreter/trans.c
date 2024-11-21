#include <demon.h>

char *reverseString(const char *str);
char *append_c(char c, Stack *s);
char *translate_internal(Stack *input_stack, Stack *result_stack, Stack *attach);
char *translate(char *input, int size)
{
    Stack *input_stack = init_stack(size * 100, "input stack");
    Stack *result_stack = init_stack(size * 100, "result stack");
    Stack *attach = init_stack(size * 100, "attach stack");
    push_s(input_stack, reverseString(input));
    return translate_internal(input_stack, result_stack, attach);
}

char *translate_internal(Stack *input_stack, Stack *result_stack, Stack *attach)
{
    char c;
    while((c = pop(input_stack)) != -1){
        switch (c)
        {
        case 'A':
            push_s(input_stack, "sae");
            break;
        case 'B':
            push_s(input_stack, reverseString("tAdA"));
            break;
        case '(':
            if(nopop(input_stack) != ')'){
                Stack *tmp = init_stack(input_stack->size, "tmp stack");
                push_c(attach, pop(input_stack));
                char c_tmp;
                //TODO:嵌套有bug
                while((c_tmp = pop(input_stack)) != ')'){
                    if(c_tmp == '('){
                        push_c(input_stack, '('); 
                        push_s(tmp, translate_internal(input_stack, result_stack, attach)); 
                    }
                    push_c(tmp, c_tmp);
                }
                push_c(input_stack, ')');
                char *tmp_str = stack2str(tmp);
                Stack *tmp2 = init_stack(tmp->size, "tmp2 stack");
                push_s(tmp2, reverseString(tmp_str));
                while((c_tmp = pop(tmp2)) != -1){push_c(input_stack, c_tmp);}
            }
            break;
        case ')':
            push_c(result_stack, pop(attach));
            break;
        default:
            push_s(result_stack, append_c(c, attach));
            break;
        }
    }

    return stack2str(result_stack);

}

char *append_c(char c, Stack *s)
{
    #ifdef DEBUG
    printf("\nAPPEND: %c\n", c);
    #endif
    push_c(s, c);
    char *str = stack2str(s);
    pop(s);
    #ifdef DEBUG
    printf("\n");
    #endif
    return str;
}

char *reverseString(const char *str) {
    int len = strlen(str);
    char *reversed = malloc((len + 1) * sizeof(char)); // 为新字符串分配内存

    if (reversed == NULL) {
        return NULL; // 内存分配失败时返回 NULL
    }

    // 复制并反转字符串
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0'; // 添加字符串终止符

    return reversed;
}

