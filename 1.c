#include <stdio.h>
#include <stdlib.h>
int n,ids[10004],*locs[10004],sec;

void exchange(int **a,int **b){
    int *temp=*a;
    *a=*b;
    *b=temp;
}
void bsort(int * a[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(*a[j]<*a[j+1])
                exchange(a+j,a+j+1);
        }
    }
}

void print(){
    for(int i=0;i<n;i++){
        printf("%d",ids[i]);
        printf(" \0\n"+ (i==n-1? 2 : 0));
    }
}

void zha(){
    printf("%d\n",sec);
    print();
    exit(0);
}

void my_malloc(int size){
    for(int i=0;i<n-1;i++){
        if(*locs[i]<*locs[i+1]){
            exchange(locs+i,locs+i+1);
        }else if(*locs[i]==*locs[i+1]){
            if(locs[i]>locs[i+1]){
                exchange(locs+i,locs+i+1);
            }
        }else break;
    }
    if(size>*locs[0]) zha();
    else{
        *locs[0]-=size;
    }
}

int main(){
    char order[20];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",ids+i);
        locs[i]=ids+i;
    }
    bsort(locs);
    while(scanf("%s",order)!=EOF){
        sec++;
        if(order[0]=='m'){
            int size;
            scanf("%d",&size);
            my_malloc(size);
        }else{
            print();
        }
    }
    return 0;
}