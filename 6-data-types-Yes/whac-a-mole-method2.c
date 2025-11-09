#include <stdio.h>
//这里用的是一维前缀和法（效率略低,将每次算值的d^2复杂降为了d复杂度） 71ms
#define CHECK(x) printf(">"#x" in %s:%d\n",__func__,x)//用于简易查错（追踪变量）的带参宏
int n,m,d;
int map[800][800],val[800][800],sum[800][800];
int x0=101,y0=101;
//起始点从101开始，x范围为101~100+m(后，横坐标，包含),y范围为101~100+n(前，纵坐标，包含)
void get_sum() {
    for (int i=y0;i<=100+n;i++) {
        for (int j=x0;j<=200+m;j++) {
            sum[i][j]=sum[i][j-1]+map[i][j];
        }
    }
}//计算一维前缀和的数值
int get(int y,int l,int r) {
    return sum[y][r]-sum[y][l-1];
}//通过一维前缀和快速获得数值,两端均包含
void calculate(int y,int x) {
    for (int i=d;i>=0;i--) val[y][x]+=get(y+i,x+i-d,x+d-i);
    for (int i=-d;i<0;i++) val[y][x]+=get(y+i,x-d-i,x+i+d);
}//计算val(单个格子足矣),注意到一个特点，菱形边界上的每一个点都满足曼哈顿距离正好等于d,
//左上满足i=j+d，右上满足i+j=d,左下满足i+j=-d，右下满足i-j=-d
int main() {
    scanf("%d%d%d",&n,&m,&d);
    for (int i=y0;i<y0+n;i++)
        for (int j=x0;j<x0+m;j++)
            scanf("%d",*(map+i)+j);
    get_sum();
    for (int i=y0;i<y0+n;i++)
        for (int j=x0;j<x0+m;j++)
            calculate(i,j);

    int max=val[101][101],count=0;
    for(int i=y0;i<y0+n;i++)
        for(int j=x0;j<x0+m;j++) {
            if(max<val[i][j]) max=val[i][j],count=1;
            else if(max==val[i][j]) count++;
        }
    printf("%d %d\n",max,count);
    for(int i=y0;i<y0+n;i++)
        for(int j=x0;j<x0+m;j++) {
            if(max==val[i][j]) printf("%d %d\n",i-100,j-100);
        }
    return 0;
}