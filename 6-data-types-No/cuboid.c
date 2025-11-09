#include <stdio.h>

void line_a(int a){
    for(int i=0;i<a;i++) printf("+-");
    printf("+");
}
void left_blank_a(int m){
    for(int i=0;i<m;i++) printf("  ");
}//从b开始递减到0
void right_a(int n){
    for(int i=0;i<n;i++) printf(" +");
}//从0开始递增到b
//上面都是画行的，每一行应该满足m+n=b,但n至多加到c
void width_a(int a){
    for(int i=0;i<=a;i++) printf(" /");
}//一共使用b次
void width0_a(int a){
    for(int i=0;i<a;i++) printf("| ");
}//一共使用
void side_right(int k){
    printf("|");
    for(int i=0;i<k-1;i++) printf("/|");
}
void side_bottom(int k){
    for(int i=0;i<k;i++) printf("|/");
}
//这些都画斜线的，左留空格时要满足m+k=b,空格用完后先k=b
//当高度c画完之后，用bottom，要满足递减
void print(int a,int b,int c){
    int m= b>c? b:c;
    int n=b+c-m;
    for(int i=0;i<b;i++){
        left_blank_a(b-i);
        line_a(a);
        if (i>n){
            right_a(n);
        }else right_a(i);
        printf("\n");
        left_blank_a(b-i-1);
        width_a(a);
        if (i>=n){
            side_bottom(n);
        }else side_right(i+1);
        printf("\n");
    }
    //上，一共b行横边与b行斜边
    for(int i=0;i<c-b;i++){
        line_a(a);
        right_a((b>c)? c:b);
        printf("\n");
        width0_a(a);
        side_right((b>c)? c+1:b+1);
        printf("\n");
    }
    line_a(a);
    right_a((b>c)? c:b);
    printf("\n");
    //中，一共c-b+1行横边与c-b行竖边
    for(int i=0;i<n;i++){
        width0_a(a);
        side_bottom(n-i);
        printf("\n");
        line_a(a);
        right_a(n-i-1);
        printf("\n");
    }
    //下，一共b行斜边和b行横边
}
int main(){
    int T,a,b,c;
    for(scanf("%d",&T);T>0;T--){
        scanf("%d%d%d",&a,&b,&c);
        print(a,b,c);
    }
    return 0;
}