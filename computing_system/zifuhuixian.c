#include <stdio.h>

int main() {
    char str[101];
    gets(str);
    for (int i=0;str[i]!='\0'&&str[i]!=EOF;i++) {
        //if (str[i]==' ') continue;//跳过空格
        if ('a'<=str[i]&&str[i]<='z') str[i]=str[i]-'a'+'A';
        putchar(str[i]);
    }
    return 0;
}
