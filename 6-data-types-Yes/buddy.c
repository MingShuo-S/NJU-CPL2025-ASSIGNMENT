#include <stdio.h>
#include <math.h>
#define CHECK(x) printf(">"#x":%d\n",x);
int memory[10004],next[10004],ids[10004],len=1;
int start=0;

int need(int mem){
    int i;
    for(i=1;!(mem<=i&&i/2<mem);i*=2);
    return i;
}//判断恰好需要多大的内存空间

int search(int ne){
    for(int i=start;i!=-1;i=next[i]){
        if(memory[i]==ne&&ids[i]==0)
            return i;
    }
    return -1;
}//根据需要的去查是否有这个空

void split(int ne,int id){
    int preloc,i;
    for(i=preloc=start;!(memory[i]>ne&&ids[i]==0);preloc=i,i=next[i]);
    //先找到第一个严格超过的，最靠前的节点,此时pre为前结点，i为后结点，要插入他俩中间
    int now=i;
    while(memory[now]>ne){
        if(now==start){
            start=len;
            next[start]=now;//如果是首节点，就替换首节点为最新结点
        }else{
            next[preloc]=len;//前结点到最新结点上去
            next[len]=now;//最新结点到目前的后节点去
        }
        memory[len]=memory[now]=memory[now]/2;
        now=len;
        //CHECK(now);
        len++;
    }
    ids[now]=id;
    //不断分裂，直到符合要求，分裂的新结点（靠前的那个）放到len处就行
}//分裂到有空，放进去（如果需要一定多次分裂的话，肯定挑这左边的分）

void AAA(int id,int mem){
    int ne=need(mem);
    int loc=search(ne);
    if(loc==-1){
        split(ne,id);
    }else{
        ids[loc]=id;
    }
}
void QQQ(){
    printf("%d\n",len);
    for(int i=start;i!=-1;i=next[i]){
        printf("%d",ids[i]);
        if(next[i]!=-1) printf(" ");
    }
    printf("\n");
}

int main(){
    int n,q;
    scanf("%d%d\n",&n,&q);
    memory[0]=pow(2,n);
    for(int i=0;i<=q;i++) next[i]=-1;//表示结束
    for(int i=0;i<q;i++){
        char ch=getchar();
        int id,mem;
        if(ch=='Q') QQQ();
        else if(ch=='A'){
            scanf("%d%d",&id,&mem);
            AAA(id,mem);
        }
        while(getchar()!='\n');
    }

    return 0;
}