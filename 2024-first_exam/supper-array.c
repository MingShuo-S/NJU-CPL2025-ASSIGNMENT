#include <stdio.h>
int z=0,sz=0;
int m,arr[1000000],mia[1000000];
int i;

int iszen(){
    for(i=0;i<m-1;i++){
        if(mia[i]<0){
            return 0;
        }
    }
    return 1;
}
//判断是否是递增数列

int issuperzen(){
    for(i=0;i<m-2;i++){
        if(mia[i]>=mia[i+1]){
            return 0;
        }
    }
    return 1;
}
//判断是否是严格递增数列（用于判断超递增数列）
int main(){
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",arr+i);
    }
    for(i=0;i<m-1;i++){
        mia[i]=arr[i+1]-arr[i];
    }
    z=iszen();
    sz=issuperzen();
    if(sz==1) printf("1");
    else if(z==1) printf("0");
    else printf("-1");
    
    return 0;
}