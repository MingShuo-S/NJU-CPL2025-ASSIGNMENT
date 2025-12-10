#include <stdio.h>
#include <math.h>

// Interpreter without pointer :p
int main(void) {
    int n;
    float frac = 0;//初始化
    scanf("%x", &n);//传入了一个32位地址
    for (int i = 0; i < 23; ++i)
        frac += (((n & 0x7fffff) >> i) & 1) * powf(0.5, 23 - i);//对这个表示的后23位进行小数位的转换，0. .....
    float ans_f = ((n >> 31) ? -1.0f : 1.0f) * (((n >> 23) & 0xff) ?
                                                 (1 + frac) * powf(2, ((n >> 23) & 0xff) - 127) :
                                                 frac * powf(2, -126));
    printf("%d\n%u\n%.6f\n%.3e", n, n, ans_f, ans_f);
    return 0;
}