#include <stdio.h>
char stack[100000];
int top=0;//不要把top类型弄成char。。
void push(){
    char c[10];
    scanf("%s",c);
    stack[top++]=c[0];
}
void pop(){
    if(top==0) printf("Empty\n");
    else top--;
}
void topp(){
    if(top==0) printf("Empty\n");
    else printf("%c\n",stack[top-1]);
}
void print(){
    if(top==0) printf("Empty\n");
    else{
        for(int i=top-1;i>=0;i--) printf("| %c |\n",stack[i]);
        printf("|===|\n");
    }
}

int main(){
    int n;
    for(scanf("%d",&n);n>0;n--){
        char order[30];
        scanf("%s",order);
        switch(order[1]){
            case 'u': push();break;
            case 'r': print();break;
            case 'o':
                if(order[0]=='p') pop();
                else topp();
                break;
            default: break;
        }
    }
    return 0;
}