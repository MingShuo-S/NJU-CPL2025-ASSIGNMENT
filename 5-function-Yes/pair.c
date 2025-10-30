#include <stdio.h>

int main(){
    int a[1000000],b[1000000];
    int m,n,t;
    int i,min=-1;
    //循环变量声明

    scanf("%d%d%d",&n,&m,&t);
    for(i=0;i<n;i++){
        scanf("%d",a+i);
        if(i>=0&&a[i]==a[i-1]) i--,n--;
    }
    for(i=0;i<m;i++) scanf("%d",b+i);
    //读入

    for(i=m-1;i>=0;i--){
        if(b[i]>t) continue;
        int upper=t-b[i];
        if(upper<a[0]) continue;

        int l=0,r=n-1,mid=(l+r)>>1;
        while(l<r){
            if(a[mid]<upper) {
                l=mid+1;
                if (mid==n-1||a[mid+1]>upper) break;
            }else if(a[mid]>upper) r=mid-1;
            else break;
            mid=(l+r)>>1;
            printf(">%d %d %d\n",l,mid,r);
        }
        if(min==-1||upper-a[mid]<min) min=upper-a[mid];
    }
    //忽略过大的b，对每个b计算t-b,二分查找离t-b最大的a(mlogn)
    printf("%d",min);
    return 0;
}