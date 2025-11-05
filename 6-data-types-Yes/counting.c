#include <stdio.h>
int map[102][102],num;
int R,C;

int judge(int x,int y){
    return map[x][y]==1&&map[x][y+1]==2;
}

int bottom(int x,int y){
    return map[x][y]==2&&map[x][y+1]==1;
}

int left(int x,int y,int i){
    while(x<i){
        x++,i--,y--;
        if(x>i) return 1;
        if(y<0||!(map[x][y]==1&&map[i][y]==2)) return 0;
    }
    return 1;
}

int right(int x,int y,int i){
    y++;
    while(x<i){
        x++,i--,y++;
        if(x>i) return 1;
        if(y>=C||!(map[x][y]==2&&map[i][y]==1)) return 0;
    }
    return 1;
}

void count(int x,int y){
    for(int i=x+1;i<R;i++){
        if(bottom(i,y)){
            if(i-x%2==0) continue;
            if(left(x,y,i)&&right(x,y,i)) num++;
        }
    }
}//根据思路，从loc（正对角线）的位置不断往下判断

int main(){
    scanf("%d%d",&R,&C);
    getchar();
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++) {
            char c=getchar();
            map[i][j]= c=='/'? 1:2;
        }
        getchar();
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(judge(i,j)) count(i,j);
        }
    }
    printf("%d",num);
}