#include <stdio.h>
int m,count=0;
int five[20]={0},uf[20]={0};
int loc=0;
//声明变量
void tofive(){
    int i;
    for (i=0;m>0;i++) {
        five[loc]=m%5;     //这块要是写法不标准，可能会造成死循环（对0）或数据溢出
        m/=5;
        loc++;
    }
}
//先转成五进制（至多14位）,可以直接用库函数（笑死）
void touf(){
    for(int i=0;i<loc;i++){
        if(uf[i]+five[i]>=3){
            uf[i]+=five[i]-5;
            uf[i+1]++;
        }else{
            uf[i]+=five[i];
        }
        count+=(uf[i]>=0)? uf[i]:-uf[i];
    }
    count+=(uf[loc]>=0)? uf[loc]:-uf[loc];
    printf("%d",count);
}
//本质上就是写个平衡五进制（-2/Y,-1/Z,0,1,2）
//然后数一下平衡五进制中的非0数的绝对值之和,直接输出得了
int main() {
    scanf("%d",&m);
    tofive();
    touf();
    return 0;
}