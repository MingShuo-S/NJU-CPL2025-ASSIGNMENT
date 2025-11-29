#include <stdio.h>
//程序名的分号后面有空格捏
int is_in(char s,char* rule){
    for(int i=0;rule[i]!='\0';i++){
        if(s==rule[i]) return 1;
    }
    return 0;
}
int main(){
    char rule_good[130],rule_index[130],order[1200];
    char c=getchar(),ans[1800]="\n";
    int loc1=0,loc2=0,loc=1;
    while(c!='\n'){
        if(c!=':') rule_good[loc1++]=c;
        else rule_index[loc2++]=rule_good[--loc1];
        c=getchar();
    }rule_good[loc1]='\0',rule_index[loc2]='\0';

    scanf("%s",order);
    printf("%s",order);
    while(scanf("%s",order)!=EOF){
        if(order[0]=='-'){
            if(is_in(order[1],rule_good)){
                ans[loc++]=order[1];
                ans[loc++]='\n';
            }else if(is_in(order[1],rule_index)){
                ans[loc++]=order[1];
                if(scanf("%s",order)==EOF){
                    printf(": option requires an argument -- '%c'",order[1]);
                    return 0;
                }
                ans[loc++]='=';
                for(int i=0;order[i]!='\0';i++) ans[loc++]=order[i];
                ans[loc++]='\n';
            }else{
                printf(": invalid option -- '%c'",order[1]);
                return 0;
            }
        }
    }ans[loc]='\0';
    printf("%s",ans);
    return 0;
}