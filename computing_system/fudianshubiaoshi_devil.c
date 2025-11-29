#include<stdio.h>

int main() {
    union {
        float f;
        int a;
    } u;
    scanf("%f",&u.f);
    for (int i=0;i<32;i++) {
        printf("%d",u.a>>(31-i)&1);
    }
}