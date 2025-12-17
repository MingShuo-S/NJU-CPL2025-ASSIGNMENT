#include <stdio.h>
#include <math.h>
#define maxn 30
int n,p,as[maxn],a,b;
double epsilon=1e-5;

double my_fabs(double a){
    if(a<0) return -a;
    return a;
}

double f(double x){
    double fx=0,po=1;
    for(int i=0;i<=n;i++){
        fx+=as[i]*po;
        po*=x;
    }
    if (fx)
        fx=pow(fx,p);
    return fx;
}
double simpthon(double a,double b){
    return (4*f((a+b)/2)+f(a)+f(b))/6*(b-a);
}

double integration(double l,double r,double R){
    double S=simpthon(l,r),mid=l+(r-l)/2;
    double SL=simpthon(l,mid),SR=simpthon(mid,r);
    if(my_fabs(SL+SR-S)<=15*R){
        return SL+SR+(SL+SR-S)/15;
    }
    return integration(l,mid,R/2)+integration(mid,r,R/2);
}
int main(){
    scanf("%d%d",&n,&p);
    for(int i=0;i<=n;i++) scanf("%d",as+i);
    scanf("%d%d",&a,&b);
    printf("%lf",integration(a,b,epsilon));
    return 0;
}