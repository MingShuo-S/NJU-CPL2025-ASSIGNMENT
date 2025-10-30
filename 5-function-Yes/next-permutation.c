#include <stdio.h>

int main(){
    int n,m=1,loc,i,num[2000];
    //声明变量，n,m,loc,i,
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",num+i);
    }
    for(i=n-1;i-1>=0&&num[i-1]>num[i];i--) m++;
    //找到最长递降后缀（从最后开始找就行），并给出长度
    int *gugugaga=num+i-1;
    //记住后缀前的那个数
    for(loc=i;i<n;i++) if(num[i]>*gugugaga&&num[i]<num[loc]) loc=i;
    num[loc]^=*gugugaga^=num[loc]^=*gugugaga;
    //找到大于后缀的最小的那个数，得记住位置，然后交换
    for(i=0;i<m/2;i++)
        num[n-1-i]^=num[n-m+i]^=num[n-1-i]^=num[n-m+i];
    //最后m个长度翻转
    for(i=0;i<n;i++)
        printf("%d ",num[i]);
    return 0;
}