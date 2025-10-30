#include <stdio.h>

int main(){
    int n,t,res,sum=0;
    scanf("%d%d",&n,&t);
    res=t;
    for(int i=0;i<n;i++){
        sum+=res;
        res=res*10+t;
    }
    printf("%d",sum);
    return 0;
}