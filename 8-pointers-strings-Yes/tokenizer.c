#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define CHECK(x) printf(">"#x":%d\n",x)
#define GA printf("I'm here!:%d\n",__LINE__)
#define FUCK(x) printf(">"#x":%s\n",x)
char *reserved[]={"const","int","float","double","long","static","void","char","extern","return","break","enum","struct","typedef","union","goto"};
char *oper[]={"+","-","*","/","=","==","!=",">=","<=",">","<"};
char *words[]={"","reserved","integer","float","operator","variable","\n"};
//保留字、运算符直接判断是否在内即可，保留字优先判断
//符号不应直接与整数直接相连，需要避免除数字外有其他符号
//符号不属于浮点数，浮点数开头可以为.，浮点数有且只有一个点
//变量开头不能是数字
//输入的末尾必须是分号
int ans[20000],loc;//记录答案

void output(){
    for(int i=0;i<loc;i++){
        printf("%s",words[ans[i]]);
        if(ans[i]!=6) printf(" ");
    }
}//输出答案
int pocess(char* s){
    int len=strlen(s);
    if (len==0) return 6;
    if(!isalnum(s[0])&&s[0]!='.'&&s[0]!='_'){
        int flag=0;
        for(int i=0;i<11;i++) flag|=!strcmp(s,oper[i]);
        if(flag) return 4;
    }
    else if(isdigit(s[0])||s[0]=='.'){
        int count=0,flag1=1,countn=0;
        for(int i=0;i<len;i++){
            flag1 = flag1&&isdigit(s[i]);
            if(isdigit(s[i])) countn++;
            if(s[i]=='.') count++;
            //CHECK(countn);
            //CHECK(count);
        }if(flag1) return 2;
        if(countn&&count==1&&countn==len-1) return 3;
    }else{
        int flag=0;
        for(int i=0;i<16;i++) flag|=!strcmp(s,reserved[i]);
        if(flag) return 1;
        for(int i=0;i<len;i++){
            if(!isalnum(s[i])&&s[i]!='_') return 0;
        }return 5;
    }return 0;
}//只是处理一个字，返回类型
int main(){
    freopen("1.txt","r",stdin);
    char *s=malloc(4096*sizeof(char));
    int flag=0;
    while(scanf("%s",s)!=EOF){
        flag=0;
printf(">%s\n",s);
        for(char *pos=strchr(s,';');pos;s=pos+1,pos=strchr(s,';'),flag=0){
            *pos='\0',flag=1;
//printf(">>%s\n",s);
            if((ans[loc++]=pocess(s))==0){
//printf("1!\n");
                printf("1Compile Error");
                return 0;
            }else if(ans[loc-1]!=6) ans[loc++]=6;
        }
        if((ans[loc]=pocess(s))==0){
//printf("2!\n");
            printf("2Compile Error");
            return 0;
        }if(ans[loc]!=6) loc++;
        //output();
    }
    if(flag) output();
    else printf("3Compile Error");
    return 0;
}