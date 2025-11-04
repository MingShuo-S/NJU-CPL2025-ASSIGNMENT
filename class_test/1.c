#include<stdio.h>
#include <string.h>

#define CHECK(x) printf(">"#x":%d\n",x);

int len=4;
char map[8088][22];
int W,k,flag,pos,H,l;
int height[22];//该列有的方块数

void draw(){
    for(int i=H-1;i>=0;i--){
        for(int j=0;j<W;j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

void Down(){
    int h=0;//该列有的方块数
    int i;
    if(flag==0){
        for(i=0;i<len;i++)//横着
            if(height[pos-1+i]>h) h=height[pos-1+i];
        for(i=0;i<len;i++){
            map[h][pos-1+i]='#';
        }
        H++;
    }
    if(flag==1){
        h=height[pos-1];//竖着
        for(i=0;i<len;i++){
            map[h+i][pos-1]='#';
        }
        H+=4;
    }
}

void Refresh(){
    int i,j;
    for(j=0;j<W;j++)
        for(i=H;i>=0;i--){
            if(map[i][j]=='#') {
                height[j]=i+1;
                break;
            }
            height[j]=0;//更新要注意给默认值
        }
    H=0;
    for(j=0;j<W;j++) if(H<height[j]) H=height[j];
}

void Check(){
    int i,j;
    for(i=0;i<H;i++){
        int condition=1;
        for(j=0;j<W;j++){
            condition&= map[i][j]=='#'? 1:0;
        }//判断该行需不需要消除
        if(condition==1){
            for(int row=i;row<H;row++){
                for(j=0;j<W;j++){
                    map[row][j]=map[row+1][j];
                }
            }//完成消除
            l++;
            i--;//避免i增加导致无法检测该行
        }
    }//该轮消除完毕
}

int main(){
    memset(map,'.',sizeof(map));
    scanf("%d%d",&W,&k);
    for(int i=0;i<k;i++){
        scanf("%d%d",&flag,&pos);
        Down();//把这个方块降下来
        Refresh();//更新全局高度与H
        Check();//检查是否需要以及实施消除
        Refresh();//再次更新全局高度与H
        draw();
    }
    printf("%d %d\n",H,l);
    return 0;
}