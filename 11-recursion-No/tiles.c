#include <stdio.h>
#define maxn 41
int dp[maxn];

int tiles(int n){
    if(n<=1) return 1;
    if(!dp[n]) dp[n]=tiles(n-1)+tiles(n-2);
    return dp[n];
}//递归：最底层，递归方式

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",tiles(n));
    return 0;
}