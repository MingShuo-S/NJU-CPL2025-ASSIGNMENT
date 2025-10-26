#include <stdio.h>
#include <math.h>

int main(){
    int n,k;
    double x[100],T,var,y,esum;
    int i,j;

    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%lf",x+i);
    }
    for(i=0;i<k;i++){
        scanf("%lf",&T);
        esum=0;
        var=0;
        for(j=0;j<n;j++){
            esum+=exp(x[j]/T);
        }
        for(j=0;j<n;j++){
            y=exp(x[j]/T)/esum;
            var+=(y-1.0/n)*(y-1.0/n);
            printf("%.3lf ",y);
        }
        var/=n;
        printf("%.3lf\n",var);
    }
}