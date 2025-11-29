#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CHECK(x) printf(">"#x":%d\n",x)
#define FUCK(x) printf(">"#x":%s\n",x)
char order[500005],str[1000006];
char *stringA[400],*stringB[400];
int modify[400][2];
int len;//str[len]='\0'
//在存指令的同时还要存一个状态数组，看是否完成
int modi(char c){
    switch(c){
        case '.':return 0;
        case '^':return 1;
        case '$':return 2;
        default: return 0;
    }
}
//动态更新一下字符串的长度，方便在结尾增加\删除子串
void analyse(int i){
    int j,loc=0;
    char string[500005];
    modify[i][0]=modi(order[0]);
    for(j=2;order[j]!=']';j++){
        string[loc++]=order[j];
    }string[loc]='\0';
    stringA[i]=malloc(loc*sizeof(char));
    strcpy(stringA[i],string);

    modify[i][1]=modi(order[++j]);
    for(j+=2,loc=0;order[j]!=']';j++){
        string[loc++]=order[j];
    }string[loc]='\0';
    stringB[i]=malloc(loc*sizeof(char));
    strcpy(stringB[i],string);
}
//处理指令，提取串A和串B与对应的修饰符，解析需要最开始完成并存储，避免多次解析
int search(char* substr,int mod){
    int ls=strlen(substr);
    if(mod==1){
        for(int j=0;j<ls;j++){
            if(str[j]!=substr[j]) return -1;
        }return 0;
    }else if(mod==2){
        for(int j=len-ls;j<len;j++){
            if(str[j]!=substr[j-len+ls]) return -1;
        }return len-ls;
    }else{
        for(int j=0;j<=len-ls;j++){
            int flag=1;
            for(int i=j;i<j+ls;i++){
                if(str[i]!=substr[i-j]){
                    flag=0;
                    break;
                }
            }
            if(flag) return j;
        }
    }
    return -1;
}//搜索子串是否在整个字符串中,输出位置，没有输出-1（注意复杂度）
//对于不同的修饰符，可以给不同的位置loc，
void go(int loc1,int i){
    char newstr[500005];
    int loc2=loc1;
    int lenA=strlen(stringA[i]),lenB=strlen(stringB[i]);
    if(modify[i][1]==0){
        strncpy(newstr,str,loc1);
        for(int j=0;j<lenB;j++){
            newstr[loc2++]=stringB[i][j];
        }
        for(loc1+=lenA;loc1<len;loc1++){
            newstr[loc2++]=str[loc1];
        }newstr[loc2]='\0';
    }else if(modify[i][1]==1){
        for(int j=0;j<lenB;j++){
            newstr[j]=stringB[i][j];
        }
        for(loc2=lenB;loc2<loc1+lenB;loc2++){
            newstr[loc2]=str[loc2-lenB];
        }
        for(loc1+=lenA;loc1<len;loc1++){
            newstr[loc2++]=str[loc1];
        }newstr[loc2]='\0';
    }else{
        strncpy(newstr,str,loc1);
        for(loc1+=lenA;loc1<len;loc1++){
            newstr[loc2++]=str[loc1];
        }
        for(int j=0;j<lenB;j++){
            newstr[loc2++]=stringB[i][j];
        }newstr[loc2]='\0';
    }
    len=len-lenA+lenB;
    strcpy(str,newstr);
}
//完成一次修改，可以先申请一个新串，然后再新串上做粘贴，会好很多
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",order);
        analyse(i);
    }
    scanf("%s",str);
    len=strlen(str);
    while(1){
        int i;
        for(i=0;i<n;i++){
            int loc1=search(stringA[i],modify[i][0]);
            if(loc1+1){
                go(loc1,i);
                break;
            }
        }
        if (i==n) break;
    }
    printf("%s",str);
    return 0;
}