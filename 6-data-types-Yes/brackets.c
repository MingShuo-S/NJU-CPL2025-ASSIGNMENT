#include <stdio.h>
#include <string.h>
int stack[100005],loc,n;
int main(){
    for(scanf("%d",&n),getchar();n>0;n--){
        memset(stack,0,sizeof(stack));
        char bra;
        int go=0;
        loc=0;
        while(scanf("%c",&bra),bra!='\n'){
            switch(bra){
                case '(':
                    stack[loc]=1;
                    loc++;
                    break;
                case '[':
                    stack[loc]=2;
                    loc++;
                    break;
                case '{':
                    stack[loc]=3;
                    loc++;
                    break;
                case ')':
                    if(loc==0||stack[--loc]!=1) go=1;
                    break;
                case ']':
                    if(loc==0||stack[--loc]!=2) go=1;
                    break;
                case '}':
                    if(loc==0||stack[--loc]!=3) go=1;
                    break;
            }
            if(go==1){
                printf("False\n");
                while(getchar()!='\n');
                break;
            }
        }
        if (go==0&&loc!=0) printf("False\n");
        else if(go==0) printf("True\n");
    }
}