#include <stdio.h>
#include <string.h>
#define max_n 26
#define max_len 100005
char tree[3][max_n][max_len],pre=2,now=0,next=1;
//next_len=1+pre_len+now_len
int len[max_n];
void exchange(){
    now=(now+1)%3;
    pre=(pre+1)%3;
    next=(next+1)%3;
}
void copy(char dest[][max_len],char s[][max_len],int x,int y0,int y1){
    for(int i=y0;i<y1;i++){
        for(int j=0;j<x;j++){
            if(dest[i][j]=='\0') dest[i][j]=' ';
        }
        strcpy(dest[i]+x,s[i-y0]);
    }
}
int get_len(int i){
    if(i<=1) return 1;
    if(i==2) return 3;
    if(!len[i]){
        len[i]=get_len(i-1)+get_len(i-2)+1;
    }
    return len[i];
}
void get_tree(int n){
    int len_pp=get_len(n-3),len_n=get_len(n-1);
    if(n==1){
        tree[now][0][0]='\\';
    }else if(n==2){
        get_tree(1);
        exchange();
        tree[now][0][0]='\\';
        strcpy(tree[now][1]," \\/");
    }else{
        get_tree(n-1);
        copy(tree[next],tree[now],0,0,n-1);
        copy(tree[next],tree[pre],len_n+1,1,n-1);
        int i=0;
        while (tree[next][n-2][i]!='/') tree[next][n-1][i++]=' ';
        tree[next][n-1][i++]='\\';
        while(tree[next][n-2][i]==' '){
            tree[next][n-1][i++]='_';
        }tree[next][n-1][i]='/';
        exchange();
    }
}
int main(){
    int n;
    scanf("%d",&n);
    get_len(n);
    for(int i=1;i<=n;i++){
        printf("%d\n",len[i]);
    }
    return 0;
}