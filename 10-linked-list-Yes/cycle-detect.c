#include <stdio.h>

int n, book[100005], next[100005], count;
char s[100005][21];
//节点里，字符串，静态链表，序号（1头）
//寻找环的入口，不存在输出-1
//最开始就把n个结点建立出来，并且标上号
//可以用数组存储地址，用桶来记录是否已被遍历
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s %d",s[i],next+i);
    }
    for(int i=1; count<=n; i=next[i]){
        if(!book[i]){
            book[i]=1;
            count++;
        }else{
            printf("%s",s[i]);
            return 0;
        }
    }printf("-1");
    return 0;
}