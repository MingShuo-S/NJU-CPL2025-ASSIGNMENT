#include <stdio.h>
#include <stdbool.h>

bool map[8008][22];
int height[22],H,l,W,k;
int h;

void down(int flag,int pos){
    //pos，H在数组中需要-1，H表示方块数。
    h=0;
    if(flag==0){
        for(int i=0;i<4;i++){
            if(h<height[pos-1+i]) h=height[pos-1+i];
        }
        for(int i=0;i<4;i++){
            map[h][pos-1+i]=1;
            height[pos-1+i]=h+1;
        }
    }else if(flag==1){
        h=height[pos-1];
        for(int i=0;i<4;i++){
            map[h+i][pos-1]=1;
        }
        height[pos-1]=h+4;
    }
    if(H<height[pos-1]) H=height[pos-1];
}

bool isfull(int hi){
    bool bo=1;
    for(int j=0;j<W;j++){
        bo&=map[hi][j];
    }
    return bo;
}

bool iisblank(int hi){
    bool bo=0;
    for(int j=0;j<W;j++){
        bo|=map[hi][j];
    }
    return !bo;
}

void erase(int flag){
    int hlen=(flag==0)? 1:4;
    for(int i=0;i<hlen;i++){
        if(isfull(h+i)){
            for(int j=0;j<W;j++) map[h+i][j]=0;
        }
    }
    for(int i=h;i<H;i++){
        if(iisblank(i)){
            for(int j=i;j<H;j++){
                for(int ga=0;ga<W;ga++){
                    map[j][ga]=map[j+1][ga];
                }
            }
            i--;
            H--;
            l++;
        }
    }
    for (int i=0;i<W;i++) {
        while(height[i]>=1&&map[height[i]-1][i]==0) height[i]--;
    }
}

void draw(){
    for(int i=H-1;i>=0;i--){
        for(int j=0;j<W;j++){
            printf("%c",map[i][j]? '#':'.');
        }
        printf("\n");
    }
}

int main(){
    scanf("%d%d",&W,&k);
    while((k--)>0){
        int pos,flag;
        scanf("%d%d",&flag,&pos);
        down(flag,pos);
        erase(flag);
    }
    printf("%d %d\n",H,l);
    draw();
}