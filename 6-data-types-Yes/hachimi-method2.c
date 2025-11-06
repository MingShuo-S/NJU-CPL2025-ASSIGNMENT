#include <stdio.h>
#include <stdlib.h>

int compare(const void* a,const void* b){
    return *(int*)a-*(int*)b;
}

int main(){
    long long N,R,M;
    long long K=0,D,KDay=0,L;
    int d[1000006];
    int Rloc,Lloc;
    scanf("%d%d%d%lld",&N,&R,&M,&D);
    for(int i=0;i<N;i++) scanf("%d",d+i);
    qsort(d,N,sizeof(int),compare);

    for(Rloc=N-1;d[Rloc]>=R;Rloc--);
    for(Lloc=Rloc;Lloc>=0;Lloc--,K++){
        if(KDay>=D+K*d[Lloc]&&K>=M) break;
        KDay+=d[Lloc];
    }
    if(K<M){
        printf("-1");
        return 0;
    }//这里，要加一个检测，不然的话可能所有的猫加起来都没M大，然后给通过了。。。。。。。
    for(L= Lloc==-1?0:d[Lloc];KDay>=D+K*L&&L<d[Lloc+1];L++) ;
    L--;
    printf("%lld",L);
    return 0;
}