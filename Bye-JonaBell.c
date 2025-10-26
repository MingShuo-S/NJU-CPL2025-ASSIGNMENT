#include <stdio.h>

int main(){
    int n,k,b,l;
    int gun,fox[1500],ah=0;//根据k循环,报数0开始k-1结束
    int i,now,loc=-1;//根据n循环
    //声明变量（得有一个桶来装还能s几次），还得有个计数循环
    //1.水枪可能没水（也用一个flag表示） 2.尾巴数量很多
    //每次报数报到第k个的时候发射！
    scanf("%d%d%d%d",&n,&k,&b,&l);
    gun=b;
    for(i=0;i<n;i++) fox[i]=l;
    now=n;

    while(now!=1){
        while(ah<k){
            loc=(loc+1)%n;
            if(fox[loc]!=0){
                ah++;
            }
        }
        //ah=k-1
        if(gun>0){
            fox[loc]--;
            gun--;
        }else{
            gun=b;
        }
        if(fox[loc]==0){
            now--;
        }
        ah=0;
    }
    for(i=0;i<n;i++)
        if(fox[i]!=0){
            printf("%d",i+1);
            break;
        }

    return 0;
}