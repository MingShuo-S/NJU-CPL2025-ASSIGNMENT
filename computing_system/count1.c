#include <stdio.h>
int main(){
    int a,count;
    scanf("%d",&a);
    for(count=0;a!=0;count+=a&1,a>>=1);
    printf("%d",count);
}