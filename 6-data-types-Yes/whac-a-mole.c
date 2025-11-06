#include <stdio.h>
#include <math.h>
#define CHECK(x) printf(">"#x":%d\n",x)

int y2=101,x0=101,i,j;
int dy[4]={1,-1,1,-1};//↖↙↗↘
int dx[4]={-1,-1,1,1};
int map[800][800],val[800][800],n,m,d;

void draw(int a[][800]) {
    for (int i=y2;i<n;i++) {
        for (int j=x0;j<m;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int is_in(){
    return abs(j-x0)+abs(i-y2)<=d;
}
void move(int di){//0↖ 1↙ 2↗ 3↘
    i+=dy[di],j+=dx[di];
}
int get(int x,int y,int di){//0123上下左右
    int num=0;
    switch(di){
        case 0:
            for(j=x-d,i=y;j<=x;move(2)) num+=map[i][j];
            for(j=x+d,i=y;j>x;move(0)) num+=map[i][j];
            break;
        case 1:
            for(j=x-d,i=y;j<=x;move(3)) num+=map[i][j];
            for(j=x+d,i=y;j>x;move(1)) num+=map[i][j];
            break;
        case 2:
            for(i=y+d,j=x;i>=y;move(1)) num+=map[i][j];
            for(i=y-d,j=x;i<y;move(0)) num+=map[i][j];
            break;
        case 3:
            for(i=y+d,j=x;i>=y;move(3)) num+=map[i][j];
            for(i=y-d,j=x;i<y;move(2)) num+=map[i][j];
            break;
        default:
            break;
    }
    return num;
}
int gogogo(){
    int j=101;
    for(int i=y2;i<n;i++){
        if(j<=101){
            j=101;
            while(j<=m){
                val[i][j+1]=val[i][j];
                val[i][j+1]-=get(j,i,2);
                val[i][j]+=get(++j,i,3);
                //CHECK(val[i][j]);
            }
            j--;
        }
        if(j>=m){
            j=m-1;
            while(j>=101){
                val[i][j-1]=val[i][j];
                val[i][j-1]-=get(j,i,3);
                val[i][j]+=get(--j,i,2);
            }
            j++;
        }
        val[i+1][j]=val[i][j];
        val[i+1][j]-=get(j,i,1);
        val[i+1][j]+=get(j,i+1,0);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&d);
    n+=101;
    m+=101;
    for(int i=y2;i<n;i++)
        for(int j=x0;j<m;j++)
            scanf("%d",*(map+i)+j);
    for(i=y2-d;i<=y2+d;i++){
        for(j=x0-d;j<=x0+d;j++){
            if(is_in()) val[y2][x0]+=map[i][j];
        }
    }
    //CHECK(val[y2][x0]);
    gogogo();
    //draw(map);printf("\n");
    //draw(val);
    int max=val[101][101],count=0;
    for(int i=y2;i<n;i++)
        for(int j=x0;j<m;j++) {
            if(max<val[i][j]) max=val[i][j],count=1;
            else if(max==val[i][j]) count++;
        }
    printf("%d %d\n",max,count);
    for(int i=y2;i<n;i++)
        for(int j=x0;j<m;j++) {
            if(max==val[i][j]) printf("%d %d\n",i-100,j-100);
        }
    return 0;
}