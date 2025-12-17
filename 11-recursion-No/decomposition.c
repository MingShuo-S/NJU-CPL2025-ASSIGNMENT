#include <stdio.h>
int ans[31];

void findDecomposition(int n, int min, int nFound){
    if(n==0){
        for(int i=0;i<nFound;i++){
            printf("%d",ans[i]);
            if(i!=nFound-1) printf(" ");
            else printf("\n");
        }
    }else if(n < min){
        return ;
    }else{
        for(int i=min; i<=n; i++){
            ans[nFound]=i;
            findDecomposition(n-i,i,nFound+1);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    findDecomposition(n,1,0);
    return 0;
}