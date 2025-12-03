#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[21];
    double score,s[3];
} team;
team* teams;

int cmp(const void* a,const void* b){
    if (((team*)b)->score<((team*)a)->score) return -1;
    if (((team*)b)->score>((team*)a)->score) return 1;
    return 0;
}
void my_sort(int k,int n){
    for(int i=0;i<n;i++) teams[i].score=teams[i].s[k];
    //for (int i=0;i<n;i++) printf("%s:%lf\n",teams[i].name,teams[i].score);
    qsort(teams,n,sizeof(team),cmp);
}
int main(){
    int n;
    scanf("%d",&n);
    teams=(team*)calloc(n,sizeof(team));
    for(int i=0;i<n;i++){
        scanf("%s",teams[i].name);
        for(int j=0;j<11;j++){
            int s[3];
            scanf("%*s %d %d %d",s,s+1,s+2);
            for(int m=0;m<3;m++) teams[i].s[m]+=s[m];
        }
        for(int m=0;m<3;m++) teams[i].s[m]/=11;
    }
    for(int i=0;i<3;i++){
        my_sort(i,n);
        for(int j=0;j<n;j++){
            printf("%s",teams[j].name);
            if(j!=n-1) printf(" ");
            else printf("\n");
        }
    }
}