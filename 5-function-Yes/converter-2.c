#include <stdio.h>

int k[4]={0};
//通常的变量声明，输入用long long，避免给-max炸了
char* arge[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
//个位数
char* arten[]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
//十几
char* arth[]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
//十位数
char* gaga[]={"","thousand","million","billion"};
//gaga
void output(int m){
    int a[3],i;
    for(i=0;i<3;i++){
        a[i]=m%10;
        m/=10;
    }
    if(a[2]!=0){
        printf("%s hundred",arge[2[a]]);
        if(a[0]||a[1]!=0) printf(" and ");
    }
    if(a[1]!=0){
        if(a[1]==1){
            printf("%s",arten[a[0]]);
            return;
        }else{
            printf("%s",arth[1[a]]);
            if(a[0]!=0) printf("-");
        }
    }
    if(a[0]!=0){
        printf("%s",arge[0[a]]);
    }
}
//输出三位的函数（复用）

int main(){
    long long n;
    scanf("%lld",&n);

    if (n==0) {
        printf("zero");
        return 0;
    }else if(n<0){
        printf("minus ");
        n=-n;
    }
    //判断正负，取绝对值
    for(int i=0;i<4;i++){
        k[i]=n%1000;
        n/=1000;
        if(n==0) break;
    }
    //判断位数，按需截断
    for(int i=3;i>=0;i--){
        if(k[i]!=0){
            output(k[i]);
            printf(" %s ",gaga[i]);
        }
    }
    //一点一点输出，在每三位中间不需要and
    return 0;
}