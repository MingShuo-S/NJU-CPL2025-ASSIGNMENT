#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) printf(">"#x": %d\n",x)

typedef struct node{
    int mem;//放的是2的指数
    int id; //0代表未被分配
    struct node* next;
} node;

node *start=NULL;
int n,q,num=1;

int how_much(int m){
    int i=0;
    for (int j=1;j<m;i+=1,j*=2) {}
    return i;
}
void divide(node* now,const int need){
    while(now->mem > need){
        node* ne=malloc(sizeof(node));
        ne->next=now->next;
        now->next=ne;
        ne->mem = --(now->mem);
        ne->id=0;
        num++;
    }
}
void alloc(int id,int m){
    int need=how_much(m),flag=1;
    node* max=NULL;
    for(node* now=start;now!=NULL;now=now->next){
        if(now->id || now->mem < need) continue;
        if(flag && now->mem > need){
            max=now;
            flag=0;
        }else if (now->mem == need){
            now->id=id;
            return ;
        }
    }
    if(max){
        divide(max,need);
        max->id=id;
    }
}
void query(){
    printf("%d\n",num);
    for(node* now=start;now!=NULL;now=now->next){
        printf("%d ",now->id);
    }printf("\n");
}
int main(){
    scanf("%d%d",&n,&q);
    start=&(node){.mem=n,.id=0,.next=NULL};
    for(int i=0; i < q; i++){
        char order;
        scanf("\n%c",&order);
        if(order=='Q'){
            query();
        }else{
            int m,id;
            scanf("%d%d",&id,&m);
            alloc(id,m);
        }
    }
    return 0;
}