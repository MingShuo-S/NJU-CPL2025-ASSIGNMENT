#include <stdio.h>
int K,d[10000006],N,M;
long long D;
//如果对L用二分法的话
int judge(int L){
    long long Days=0;
    K=0;
    for(int i=0;i<N;i++){
        if(d[i]>L){
            Days+=d[i];
            K++;
        }
    }
    return Days>=D+(long long)K*L&&K>=M;//这里，两个整数相乘可能会溢出，然后导致条件判断出现问题。。。
}
//计算现在的多养天数总和是否大于等于D，并得到K
int main(){
    int R,L,l,r;
    scanf("%d%d%d%lld",&N,&R,&M,&D);
    //D的范围在long long（很大）,其他的都是int
    for(int i=0;i<N;i++){
        scanf("%d",d+i);
        if(d[i]>=R) i--,N--;
    }
    //输入的时候可以把大于等于R的都扔掉
    l=0,r=R-1;
    L=((r-l)>>1)+l;
    while(l<r){
        if(judge(L)){
            if(!judge(L+1)){
                printf("%d",L);
                return 0;
            }
            l=L+1;
        }else{
            r=L-1;
        }
        L=((r-l)>>1)+l;
        //printf("l:%d r:%d L:%d\n",l,r,L);
    }
    if (!judge(L)) L--;
    printf("%d",L);
    return 0;
}