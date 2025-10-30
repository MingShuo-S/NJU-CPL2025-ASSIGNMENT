#include <stdio.h>
#include <stdlib.h>

int a[1000000],b[1000000];
int m,n,t;

int compare(const void* a,const void* b){
    return *(int*)a>*(int*)b;
}

int main(){
    int i,min=-1;
    //循环变量声明
    scanf("%d%d%d",&n,&m,&t);
    for(i=0;i<n;i++){
        scanf("%d",a+i);
        if(i>=0&&a[i]==a[i-1]) i--,n--;
    }
    for(i=0;i<m;i++) scanf("%d",b+i);
    //读入
    qsort(b,m,sizeof(int),compare);
    for(i=0;i<m;i++) printf("%d ",b[i]);
    printf("\n");
    //b数组排序（用排序函数）
    for(i=n-1;i>=0;i--){
        if(a[i]>t) continue;
        int upper=t-a[i];
        if(upper<b[0]) continue;

        int l=0,r=m-1,mid=(l+r)>>1;
        while(l<r){
            if(b[mid]<upper) {
                l=mid+1;
                if (mid==m-1||b[mid+1]>upper) break;
            }else if(b[mid]>upper) r=mid-1;
            else break;
            mid=(l+r)>>1;
            printf(">%d %d %d\n",l,mid,r);
        }
        if(min==-1||upper-b[mid]<min) min=upper-b[mid];
    }
    //忽略过大的a，对每个a计算t-a,二分查找离t-a最大的b(nlogm)
    printf("%d",min);
    return 0;
}