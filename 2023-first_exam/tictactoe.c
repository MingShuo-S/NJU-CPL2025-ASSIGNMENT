#include <stdio.h>
int map[10][10],x,n;
int max[3],win[3],who[3]={1,2,4};
//全局声明棋盘，x棋子数，n宽，124的最长连线长度,获胜状态

void get(){
    int i,j,p,k,now,len;
    for(i=0;i<n;i++){
        j=0;
        while(j<n){
            now=len=0;
            while(map[j][i]==0&&j<n) j++; //注意在这些地方设置范围限制，不然会溢出；且不要把范围限制小，会导致死循环（j加不起来）
            for(k=0;k<3;k++){
                if(who[k]==map[j][i]) now=k;
            }
            while(map[j][i]==who[now]&&j<n) len++,j++;
            if(len>max[now]) max[now]=len;
        }
    }
    //竖 n,y-
    for(i=0;i<n;i++){
        j=0;
        while(j<n){
            now=len=0;
            while(map[i][j]==0&&j<n) j++;
            for(k=0;k<3;k++){
                if(who[k]==map[i][j]) now=k;
            }
            while(map[i][j]==who[now]&&j<n) len++,j++;
            if(len>max[now]) max[now]=len;
        }
    }
    //横 n,x-
    for(i=0;i<n;i++){
        j=n-1-i;//竖 对角线起点
        p=0;//横 对角线起点
        while(j>=0&&p<n){
            now=len=0;
            while(map[j][p]==0&&j>=0&&p<n) j--,p++;
            for(k=0;k<3;k++){
                if(who[k]==map[j][p]) now=k;
            }
            while(map[j][p]==who[now]&&j>=0&&p<n) len++,j--,p++;
            if(len>max[now]) max[now]=len;
        }
        j=n-1-i;//竖 对角线起点
        p=0;//横 对角线起点
        while(j<n&&p<n){
            now=len=0;
            while(map[j][p]==0&&j<n&&p<n) j++,p++;
            for(k=0;k<3;k++){
                if(who[k]==map[j][p]) now=k;
            }
            while(map[j][p]==who[now]&&j<n&&p<n) len++,j++,p++;
            if(len>max[now]) max[now]=len;
        }
    }
    //1对角线 n-x
    for(i=0;i<n;i++){
        j=n-1-i;//竖 对角线起点
        p=0;//横 对角线起点
        while(j>=0&&p<n){
            now=len=0;
            while(map[p][j]==0&&j>=0&&p<n) j--,p++;
            for(k=0;k<3;k++){
                if(who[k]==map[p][j]) now=k;
            }
            while(map[p][j]==who[now]&&j>=0&&p<n) len++,j--,p++;
            if(len>max[now]) max[now]=len;
        }
        j=n-1-i;//竖 对角线起点
        p=0;//横 对角线起点
        while(j<n&&p<n){
            now=len=0;
            while(map[p][j]==0&&j<n&&p<n) j++,p++;
            for(k=0;k<3;k++){
                if(who[k]==map[p][j]) now=k;
            }
            while(map[p][j]==who[now]&&j<n&&p<n) len++,j++,p++;
            if(len>max[now]) max[now]=len;
        }
    }
    //-1对角线 n-x
}
//算法更新每个数字的最长连线（可以用与）直接检查每一行、列以及长度大于x的对角线

void winner(){
    int i,flag=0;
    for(i=0;i<3;i++){
        if(max[i]>=x){
            win[i]=1;
            flag++;
        }
    }
    if(flag==1){
       for(i=0;i<3;i++){
            if(win[i]==1){
                printf("%d\n",who[i]);
            }
        }
    }else{
        printf("draw\n");
    }
}
//判断获胜状态并输出

int main() {
    int t;
    int i;
    //声明变量 ，t组
    scanf("%d %d",&t,&x);
    for(int k=0;k<t;k++){
        for (i=0;i<3;i++) max[i]=win[i]=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",*(map+i)+j);
            }
        }
        //输入棋盘
        get();
        winner();
    }
    //for循环，每次判断，注意开头变量清零
    return 0;
}