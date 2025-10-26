#include <stdio.h>
int op,i,j,n,A[100][100],B[100][100];
//声明op，循环变量，两个矩阵，边长
void inputA(){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",*(A+i)+j);
        }
    }
}
void inputB(){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",*(B+i)+j);
        }
    }
}
//输入一个矩阵的函数（边算边输出）
void plusminus(int flag){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",A[i][j]+flag*B[i][j]);
            if(j!=n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}
void mutiply(){
    long long res;
    int k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            res=0;
            for(k=0;k<n;k++){
                res+=A[i][k]*B[k][j];
            }
            printf("%lld",res);
            if(j!=n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}
void zhuanzhi(){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",A[j][i]);
            if(j!=n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}
//加减乘转置函数（加和减可以合并，用flag表示B元素正负）

int main() {
    scanf("%d%d",&op,&n);
    //输入op
    switch(op){
        case 1:
            inputA(),inputB();
            plusminus(1);
            break;
        case 2:
            inputA(),inputB();
            plusminus(-1);
            break;
        case 3:
            inputA(),inputB();
            mutiply();
            break;
        case 4:
            inputA();
            zhuanzhi();
            break;
    }
    //op判断
    return 0;
}