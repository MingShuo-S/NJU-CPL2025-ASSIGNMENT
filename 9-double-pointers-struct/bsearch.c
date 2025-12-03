#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a ,const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    int n,q,what;
    scanf("%d%d",&n,&q);
    int* A=(int *)malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
        scanf("%d",A+i);
    }
    for(int i=0;i<q;i++){
        scanf("%d",&what);
        int* loc=bsearch(&what,A,n,sizeof(int),cmp);
        printf("%d\n",(int)(loc-A));
    }
    free(A);
    return 0;
}