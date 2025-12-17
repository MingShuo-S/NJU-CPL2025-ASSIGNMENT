#include <stdio.h>
int A[1000006];

int search(int target,int n){
    int l=0,r=n,mid;
    while(l<=r){
        mid=l+((r-l)>>1);
        if(A[mid]>target){
            r=mid-1;
        }else if(A[mid]<target){
            l=mid+1;
        }else{
            break;
        }
    }
    if(A[mid]==target)
        return mid;
    else return -1;
}

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) scanf("%d",A+i);
    for(int i=0;i<q;i++){
        int target;
        scanf("%d",&target);
        int loc=search(target,n);
        printf("%d\n",loc);
    }
}