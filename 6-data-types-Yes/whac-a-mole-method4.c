#include <stdio.h>
//这里用的是二维前缀和（不旋转，将斜的的正方形分为两个合理的正方形）
#define CHECK(x) printf(">"#x" in %s:%d\n",__func__,x)//用于简易查错（追踪变量）的带参宏