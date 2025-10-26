#include <stdio.h>
#include <string.h>

#define N 100
int face[6][N][N];
int n;
int input1,input2[4][2];
char order[13];

//全局变量定义面数组和输入数组

void exchange(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void rotate(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n/2;j++){
            exchange(&face[input1][i][j],&face[input1][i][n-1-j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            exchange(&face[input1][i][j],&face[input1][n-1-j][n-1-i]);
        }
    }
    //翻转的时候要注意**翻转哪些元素**，如果全翻转的话会使矩阵复原
}
//rotate操作函数

void line_rotate(){
    int temp[N];
    int i,j;
    for(i=0;i<n;i++){
        temp[i]=face[input2[3][0]][input2[3][1]][i];
    }
    printf(">temp:%d %d %d\n",temp[0],temp[1],temp[2]);
    for(j=3;j>=1;j--){
        for(i=0;i<n;i++){
            face[input2[j][0]][input2[j][1]][i]=face[input2[j-1][0]][input2[j-1][1]][i];
            printf(">%d",face[input2[j][0]][input2[j][1]][i]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++){
        face[input2[0][0]][input2[0][1]][i]=temp[i];
        printf(">%d",face[input2[0][0]][input2[0][1]][i]);
    }
    printf("\n");

}
//line-rotate操作函数（在最开始想的时候一定要把具体算法实现想好想清楚，不要想当然）

int main() {
    scanf("%s %d",order,&n);
    int i,j,k;
    for(i=0;i<6;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                scanf("%d",*(*(face+i)+j)+k);
            }
        }
    }

    //printf(">rotate:%d\n>line-rotate:%d\n",strcmp(order,"rotate"),strcmp(order,"line-rotate"));

    if(strcmp(order,"rotate")==0){
        scanf("%d",&input1);
        rotate();
    }else if(strcmp(order,"line-rotate")==0){
        for(i=0;i<4;i++){
            scanf("%d %d",*(input2+i),*(input2+i)+1);
        }
        line_rotate(); //注意别写到for循环里面了……
    }

    for(i=0;i<6;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                printf("%d",face[i][j][k]);
                if(k!=n-1)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}