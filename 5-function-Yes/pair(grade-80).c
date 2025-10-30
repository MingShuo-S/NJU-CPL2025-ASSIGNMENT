#include <stdio.h>

int main(){
    int a[1000000],b[1000000],n,m,t;
    int i,j,bmin=1000000000,bmax=0,min=-1,now;
    //声明变量
    scanf("%d%d%d",&n,&m,&t);
    //先不对b数组进行排序试试，如果排序的话应该是快速排序
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for(i=0;i<m;i++){
        scanf("%d",b+i);
        if(bmin>b[i]) bmin=b[i];
        if(bmax<b[i]) bmax=b[i];
    }
    //输入，输入a的时候挑不重复的输进去，可以记录b的最大与最小值
    for(i=n-1;i>=0;i--){
        while(i>0&&a[i]==a[i-1]) i--;
        if(t-a[i]-bmin<0) continue;
        if (min==-1) min=t-a[i]-bmin;
        if (t-a[i]-bmax>min||min==0) break;
        for(j=0;j<m;j++){
            now=t-a[i]-b[j];
            if(now>=0&&now<min) min=now;
        }
        //printf(">%d min:%d\n",i,min);
    }
    //从a的高位向低遍历，确保遍历完一遍b数组后检测min是否大于等于0
    //有的话就直接输出退出了
    if (min>=0) printf("%d ",min);
    else printf("-1");
    return 0;
}