#include <stdio.h>
#define CHECK(x) printf(">"#x":%d\n",x)

int res[20008],P1[20004],P2[20004];
char var[20];
int p1,p2,pr;

void plus_minus(int flag){//0+1-，没有进位
    int ga= flag==0? 1 : -1;
    pr= p1>p2? p1:p2;
    for(int i=pr;i>=0;i--){
        res[i]=P1[i]+ga*P2[i];
    }
}

void multiple(){
    pr=p1+p2;
    for(int i=pr;i>=0;i--){
        res[i]=0;
        for(int j=0;j<=i;j++){
            res[i]+=P1[j]*P2[i-j];//这里数据太大的话P1用10004会爆掉哦亲，我***服了
        }
    }
}

void print(){//每一个次数判断是否输出，符号 等
    int flag=1;
    for(int i=pr;i>=0;i--){
        if(res[i]>0){
            if(!flag) printf("+");
            else flag=0;
        }else if(res[i]<0){
            flag=0;
            printf("-");
            res[i]=-res[i];
        }else{
            continue;
        }
        if (res[i]!=1||i==0) printf("%d",res[i]);
        if (i>=1) printf("%s",var);
        if (i>1) printf("^%d",i);
    }
    if (flag) printf("0");
    printf("\n");
}

int main(){
    freopen("2.in","r",stdin);
    freopen("res.out","w",stdout);
    scanf("%d%d%s",&p1,&p2,var);
    for(int i=p1;i>=0;i--) scanf("%d",P1+i);
    for(int i=p2;i>=0;i--) scanf("%d",P2+i);
    plus_minus(0);
    print();
    plus_minus(1);
    print();
    multiple();
    print();
    return 0;
}