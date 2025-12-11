//AI牛的牛的,静态模拟，只改变链接方式
#include <stdio.h>
#include <stdlib.h>

int m,n;
int *prev, *tops;
int ans[1000006];

int pop(int x){
    int i=tops[x];
    tops[x]=prev[i];
    prev[i]=0;
    return i;
}
void add(int y,int i){
    if (!i) return;
    prev[i]=tops[y];
    tops[y]=i;
}
void print() {
    for(int i=1; i<=n ;i++){
        int j=0;
        if(tops[i]){
            for(int head=tops[i];head!=0;head=prev[head]){  //服了，就这块中间的判断逻辑总出错，不要再prev啦！
                ans[j++]=head;
            }j--;
            for(;j>=0;j--){
                printf("%d",ans[j]);
                if(j>0) printf(" ");
            }printf("\n");
        }else{
            printf("0\n");
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);   //NM顺序写错了就只有30分捏
    prev=calloc(n+1,sizeof(int)); //0为栈底
    tops=calloc(n+1,sizeof(int));
    //若元素数为0，则top指向0,否则指向对应栈顶
    for(int i=1 ; i<=n ; i++){
        tops[i]=i;
    }//INIT
    for(int i=0; i<m; i++){
        int x,y,j;
        scanf("%d%d",&x,&y);
        while(j=pop(x)) add(y,j);
    }
    print();
    return 0;
}