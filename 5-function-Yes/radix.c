#include <stdio.h>

int main(){
    int a[3],i,j,m;
    //存入数字，循环变量，所有数字里的最大数啥的
    int b[3]={0};
    //放进制转换之后的数字（int足矣）
    scanf("%d%d%d",a,a+1,a+2);
    m=a[0]%10;
    for(i=0;i<3;i++){
        if(m<a[i]%10) m=a[i]%10;
        if(m<a[i]/10) m=a[i]/10;
    }
    //找数字里的最大数m，进制从m+1开始，40结束
    for(i=m+1;i<=40;i++){
        b[0]=b[1]=b[2]=0;
        for(j=0;j<3;j++){
            b[j]=a[j]%10+(a[j]/10)*i;
        }
        if(b[0]*b[1]==b[2]){
            printf("%d",i);
            return 0;
        }
    }
    //从m+1开始从小到大遍历，如果符合条件则直接退出
    printf("0");
    //如果没有的话就输出0
    return 0;
}