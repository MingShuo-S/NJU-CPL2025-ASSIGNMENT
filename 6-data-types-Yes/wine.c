#include <stdio.h>
#define CHECK(x) printf(">"#x":%d\n",x)
int v[10000],w[10000],L,V,n;
//声明变量，保存酒的容量和价值，都是整数
int max(){
    int val=0,loc=0;
    for(int i=0;i<n;i++){
        if(v[i]>val){
            val=v[i];
            loc=i;
        }
    }
    //CHECK(loc);
    return loc;
}
//判断当下的最大价值酒的位置（如果有同价值酒不用担心，总会装满）
void drink(int loc){
    if(L>=w[loc]){
        L-=w[loc];
        V+=w[loc]*v[loc];
        v[loc]=0;
    }else{
        V+=L*v[loc];
        L=0;
        w[loc]-=L;
    }
}
//根据位置，加满(判断L是否到0)，减价值

int main(){
    scanf("%d%d",&n,&L);
    for(int i=0;i<n;i++) scanf("%d",v+i);
    for(int i=0;i<n;i++) scanf("%d",w+i);
    while(L>0){
        int loc=max();
        drink(loc);
    }
    printf("%d",V);

    //输出最贵价值：从最贵的开始加，一点一点往前面加
}