#include <stdio.h>

int is_upper(char c){
    return 'A'<=c&&c<='Z';
}
int main(){
    char ch=getchar();
    if(is_upper(ch)) printf("%c",ch);
    else printf("%c",ch-'a'+'A');
    ch=getchar();
    while(ch!='\n'&&ch!=EOF){
        if(ch==' '){
            printf(" ");
            ch=getchar();
            if(is_upper(ch)) printf("%c",ch);
            else printf("%c",ch-'a'+'A');
        }
        else{
            if(is_upper(ch)) printf("%c",ch-'A'+'a');
            else printf("%c",ch);
        }
        ch=getchar();
    }
    return 0;
}