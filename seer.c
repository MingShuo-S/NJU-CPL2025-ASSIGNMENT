#include <stdio.h>

int main(){
    int T=2000;
    double al=0.01,theta1=1.000,theta0=1.000,x[100],y[100];
    double J0,J1,h;
    int i,j,m;
    //声明变量，赋予初始值，要有一个存属性的二维数组
    for(scanf("%*d"),m=0;scanf("%lf %lf",x+m,y+m)==2;m++);
    //读取个数与所有数组内容
    for(i=0;i<T;i++){
        J0=J1=h=0;
        for(j=0;j<m;j++){
            h=theta0+theta1*x[j];
            J0+=h-y[j];
            J1+=(h-y[j])*x[j];
        }
        J0/=m;
        J1/=m;
        theta0-=al*J0;
        theta1-=al*J1;
    }
    //循环，一次循环遍历所有的数组（二维），算和更新
    printf("y = %.3lf + %.3lfx",theta0,theta1);
    //输出
    return 0;
}