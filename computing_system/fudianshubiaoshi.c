#include <stdio.h>
#include <stdbool.h>

int timekeeper[502][502],field[502][502],t[250004];

int position[250004][2];

double x[501],y[501];

bool left_up(int i, int j, int m, int n) {
    if (i <= 0 || j <= 0) return false;
    if (field[i-1][j-1]==2&&field[i-1][j]==2&&field[i][j-1]==2) {
        field[i][j]=0;
        field[i][j-1]=0;
        field[i-1][j]=0;
        field[i-1][j-1]=0;
        return true;
    }
    return false;
}

bool left_down(int i,int j,int m,int n) {
    if (i >= m || j <= 0) return false;
    if (field[i+1][j-1]==2&&field[i+1][j]==2&&field[i][j-1]==2) {
        field[i][j]=0;
        field[i+1][j-1]=0;
        field[i][j-1]=0;
        field[i+1][j]=0;
        return true;
    }
    return false;

}

bool right_up(int i, int j, int m, int n) {
    if (i <= 0 || j >= n) return false;
    if (field[i-1][j+1]==2&&field[i-1][j]==2&&field[i][j+1]==2) {
        field[i][j]=0;
        field[i-1][j+1]=0;
        field[i][j+1]=0;
        field[i-1][j]=0;
        return true;
    }
    return false;
}

bool right_down(int i, int j, int m, int n) {
    if (i >= m || j >= n) return false;
    if (field[i+1][j+1]==2&&field[i+1][j]==2&&field[i][j+1]==2) {
        field[i][j]=0;
        field[i+1][j+1]=0;
        field[i][j+1]=0;
        field[i+1][j]=0;
        return true;
    }
    return false;
}

int main() {
    int m,n;
    scanf("%d %d",&m,&n);
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            scanf("%d",&timekeeper[i][j]);
            if (timekeeper[i][j]) {
                field[i][j]=1;    //表示这一块能长出南瓜？
            }
        }
    }

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (timekeeper[i][j]) {
                position[timekeeper[i][j]][0]=i;
                position[timekeeper[i][j]][1]=j;//这块甚至可以直接合并到上面的，没有必要再写一个循环
            }
        }
    }
    int time = 1,count=0;
    while (time<=m*n) {//问题1，不一定每个时间都有南瓜长出来
        int i=position[time][0],j=position[time][1];//也就是你这块会一直循环[0][0]点
        field[i][j]=2;
        if (left_up(i,j,m,n)) {t[count]=time,x[count]=i+1-0.5,y[count]=j+1-0.5;count++;}
        else if (right_up(i,j,m,n)){t[count]=time,x[count]=i+1-0.5,y[count]=j+1+0.5;count++;}
        else if (left_down(i,j,m,n)){t[count]=time,x[count]=i+1+0.5,y[count]=j+1-0.5;count++;}
        else if (right_down(i,j,m,n)){t[count]=time,x[count]=i+1+0.5,y[count]=j+1+0.5;count++;}
        time++;
    }
    printf("%d\n",count);
    for (int i = 0;i<count;i++) {
        printf("%d %.1lf %.1lf\n",t[i],x[i],y[i]);
    }
    return 0;
}