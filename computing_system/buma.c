#include <stdio.h>
int main() {
    int a;
    scanf("%d",&a);
    for (int i=0;i<16;printf("%d",(a&(1<<15))>>15),a<<=1,i++);
}