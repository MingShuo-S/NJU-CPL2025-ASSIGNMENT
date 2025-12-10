#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//输出字符串保存的宏替代演示,注意可变宏参数的运用
#define ADDOUT(format,...)  \
    pos+=  sprintf(output+pos,format,__VA_ARGS__)
//和 int pos; char* output 配合使用

int main() {
    char *output = malloc(4096), *rules = malloc(128);
    char *name = malloc(1024), *arg = malloc(1024);
    char *value = malloc(1024);
    int pos = 0;
    scanf("%s%s", rules, name);
    pos += sprintf(output + pos, "%s\n", name);//思想1:用sprintf代替结果字符串的拼接，可用宏替代
    while ((scanf("%s", arg) != EOF)) {
        if (*arg != '-') continue;
        char *rule = strchr(rules, *(arg + 1)); //思想2: (1)不造轮子 (2)用字符串直接存储规则，用对应函数查找使用
        if (rule != NULL) {//如果说这个参数arg在规则集内
            if (*(rule + 1) == ':') {//并且这个arg要求一个参数
                if (scanf("%s", value) == EOF) {//那么如果后续没有输入，则缺少参数
                    printf("%s: option requires an argument -- '%c'\n", name, *rule);
                    free(output);free(rules);free(name);free(arg);free(value);
                    return 0;
                }else//不然的话将结果输入到结果字符串当中
                    pos += sprintf(output + pos, "%c=%s\n", *rule, value);
            } else//如果不要求参数的话，那就直接把这个字符输入进去，用rule可以避免不一致
                pos += sprintf(output + pos, "%c\n", *rule);
        } else {//如果这个arg不在规则集内，则是无用指令，报错
            printf("%s: invalid option -- '%c'\n", name, *(arg + 1));
            free(output);free(rules);free(name);free(arg);free(value);
            return 0;
        }
    }
    printf("%s", output);//输出结果
    free(output);free(rules);free(name);free(arg);free(value);
    return 0;
}