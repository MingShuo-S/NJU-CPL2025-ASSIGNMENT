#include <stdio.h>

int main(){
    int a;
    scanf("%x",&a);
    printf("%d\n%u\n%.6f\n%.3e",a,*((unsigned*)&a),*((float*)&a),*((float*)&a));
    return 0;
}