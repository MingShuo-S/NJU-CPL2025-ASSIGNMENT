#include <stdio.h>
#define maxn 36

int dp[maxn][maxn];
int pasca(int a,int b){
    if (a<0||b<1) return 0;
    if (b==1) dp[a][b]=1;
    if (!dp[a][b])
        dp[a][b]=pasca(a-1,b-1)+pasca(a-1,b);
    return dp[a][b];
}

int main(){
    int a,b,ans;
    scanf("%d%d",&a,&b);
    ans=pasca(a-1,b);
    printf("%d",ans);
}