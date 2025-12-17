#include <stdio.h>
#include <stdlib.h>

int R,C;
int map[3003][3003];//LRUD1234
int locs[10000007][2], count, min;
int dr[4]={0,0,1,-1};
int dc[4]={-1,1,0,0};
char director[5]={'?','L','R','U','D'};

void dead(){
    printf("-1");
    exit(0);
}

int check(int i){
    int dir=-1,r=locs[i][0],c=locs[i][1];
    for(int di=0;di<4;di++){//要注意各个标记在不同地方的意义是否一致
        int lr=r+dr[di], lc=c+dc[di];
        while(map[lr][lc]&&lr>=0&&lc>=0){
            if(map[lr][lc]!=-1&&map[lr][lc]!=0) {
                if(di==map[r][c]-1) return 0;
                dir=di;
            }
            lr+=dr[di];
            lc+=dc[di];
        }
    }
    if(dir==-1) dead();
    else {
        //printf("%c at %d,%d will be adjusted to %c\n",director[map[r][c]],r,c,director[dir]);
        return 1;
    }
}
void print() {
    for (int i=R-1;i>=0;i--) {
        for (int j=0;j<C;j++) {
            printf("%2d ",map[i][j]);
        }printf("\n");
    }
    for (int i=0;i<count;i++) {
        printf("(%d,%d) ",locs[i][0],locs[i][1]);
    }printf("\n");
}
int main(){
    scanf("%d%d",&R,&C);
    for(int i=R-1;i>=0;i--){
        char s[3003];
        scanf("%s",s);
        for(int j=0;j<C;j++){
            if(s[j]=='.') map[i][j]=-1;
            else if(s[j]=='L') map[i][j]=1;
            else if(s[j]=='R') map[i][j]=2;
            else if(s[j]=='U') map[i][j]=3;
            else if(s[j]=='D') map[i][j]=4;
            if(s[j]!='.'){
                locs[count][0]=i;
                locs[count++][1]=j;
            }
        }
    }
    //print();
    for(int i=0;i<count;i++){
        min+=check(i);
    }
    printf("%d",min);
    return 0;
}