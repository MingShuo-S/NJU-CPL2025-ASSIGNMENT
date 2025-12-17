#include <stdio.h>
#include <stdlib.h>
int R,C,count;//R行C列，有空白与四个方向的箭头
//只要某个方向上有箭头即是安全，为了加速，可以同时用两个桶
//一个检索来存储每一列上的箭头坐标，一个检索来存储每一行上的
//寻找左右的时候只用在这一行检索，寻找上下的时候只用在这一列检索
int arrows[10000007][3];//存箭头坐标与方向(UDLR)
int top_row[3003],top_col[3003];
int* arrow_in_row[3003][3003],*arrow_in_col[3003][3003];
void add_arrow(int r,int c,int di){
    arrows[count][0]=r;
    arrows[count][1]=c;
    arrows[count][2]=di;
    arrow_in_row[r][top_row[r]++]=arrows[count];
    arrow_in_col[c][top_col[c]++]=arrows[count];
    count++;
}
void dead(){
    printf("-1");
    exit(0);
}
int check(int i){
    int r=arrows[i][0],c=arrows[i][1],point=arrows[i][2];
    int is_valid=0,straight=0;
    for(int j=0;j<top_col[c];j++){
        int* now=arrow_in_col[c][j];
        if(now[0]>r){
            is_valid=1;
            if(point==0) straight=1;
        }else if(now[0]<r){
            is_valid=1;
            if(point==1) straight=1;
        }
    }
    for(int j=0;j<top_row[r];j++){
        int* now=arrow_in_row[r][j];
        if(now[1]<c){
            is_valid=1;
            if(point==2) straight=1;
        }else if(now[1]>c){
            is_valid=1;
            if(point==3) straight=1;
        }
    }
    if(is_valid){
        if(straight) return 0;
        return 1;
    }
    dead();
}
int main(){
    int min=0;
    scanf("%d%d",&R,&C);
    for(int i=R-1;i>=0;i--){
        char s[3003];
        scanf("%s",s);
        for(int j=0;j<C;j++){
            if(s[j]!='.'){
                if(s[j]=='U'){
                    add_arrow(i,j,0);
                }else if(s[j]=='D'){
                    add_arrow(i,j,1);
                }else if(s[j]=='L'){
                    add_arrow(i,j,2);
                }else if(s[j]=='R'){
                    add_arrow(i,j,3);
                }
            }
        }
    }
    for(int i=0;i<count;i++){
        min+=check(i);
    }
    printf("%d",min);
    return 0;
}