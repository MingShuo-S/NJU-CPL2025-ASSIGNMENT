#include <stdio.h>
//  偷腥猫  L/  哈基米  /R    青梅猫
#define maxn 1000006
#define CHECK(x) printf(">"#x":%d\n",x)
int N,R,M,L,K,R;//N只猫,要≥M只哈基米
long long D;
int d[maxn];
//L与D和K有明显的单调性，可以二分查找
void read(){
    scanf("%d%d%d%lld",&N,&R,&M,&D);
    for(int i=0;i<N;i++){
        scanf("%d",d+i);
    }
}
int is_right(int l){
    long long sum=0;
    int num=0;
    for(int i=0;i<N;i++){
        if(d[i]<R&&d[i]>l){
            num++;
            sum+=d[i]-l;
        }
    }
    if(sum<D||num<M) return -1;//对应l过大
    //if(is_right(l+1)<0) return 0;//如果l正好的话，l+1会过大
    return 1;
}
int search(){
    int left=0,right=R-1,mid=-1;
    while(left<=right){
        mid=left+((right-left)>>1);
        if(is_right(mid)>0){
            left=mid+1;
        }else if(is_right(mid)<0){
            right=mid-1;
        }
    }
    if (is_right(mid)<0) mid--;
    return mid;
}

int main(){
    read();
    L=search();
    printf("%d",L);
    return 0;
}