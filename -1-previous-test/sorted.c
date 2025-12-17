#include <stdio.h>
//每次操作是把第i个数放到数组第一个，可以用数组实现，也可以用链表
//题目说用数组实现即可
void move(int arr[],int p){
    for(int i=p;i>0;i--){
        int temp=arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=temp;
    }
}
int is_sorted(int arr[],int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]) return 0;
    }
    return 1;
}
int print(int arr[],int n) {
    for (int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n,m,p;
        scanf("%d%d",&n,&m);
        int arr[1003];
        for(int j=0;j<n;j++) scanf("%d",arr+j);
        for(int j=0;j<m;j++){
            scanf("%d",&p);
            move(arr,p-1);
            //print(arr,n);
        }
        if(is_sorted(arr,n)){
            printf("I love C programming language\n");
        }else{
            printf("mayi is a good teacher\n");
        }
    }
    return 0;
}