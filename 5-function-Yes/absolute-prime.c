#include <stdio.h>

int main(){
    int book[1001]={0},n,i,j,temp,rev,count=0;
    book[0]=book[1]=1;
    //可以先找出所有的素数，随后判断每个素数是否是旋转素数
    //（如果是的话后面那个桶变成1，0是素数，避免重复计数）
    scanf("%d",&n);
    for(i=2;i<=1000;i++){
        if(book[i]==0){
            for(j=i*2;j<1001;j+=i){
                book[j]=1;
            }
        }
    }
    for(i=2;i<=n;i++){
        if(book[i]==0){
            temp=i;
            rev=0;
            while(temp!=0){
                rev=rev*10+temp%10;
                temp/=10;
            }
            if(book[rev]==0){
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}