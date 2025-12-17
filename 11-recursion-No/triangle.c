#include <stdio.h>
#define CHECK(x) printf(">"#x":%d\n",x)
char triangle[2][1100][2200],now=0,next=1;
int high=2;
void exchange() {
    now= now? 0:1;
    next=next? 0:1;
}
void my_strcpy(char* dest, const char* s){
    int i=0;
    while((dest[i]=s[i])) i++;
    dest[i]='\0';
}
void my_copy(char dest[][2200],char s[][2200],int x,int y0,int y1) {
    for (int i=y0; i<y1; i++) {
        for (int j=0;j<=x;j++) {
            if (dest[i][j]=='\0') dest[i][j]=' ';
        }
        my_strcpy(dest[i]+x,s[i-y0]);
    }
}
void draw(int n){
    int m_high=2<<(n-2),m_len=4<<(n-2);
    if(n==1){
        my_strcpy(triangle[now][0]," /\\ ");
        my_strcpy(triangle[now][1],"/__\\");
    }else {
        draw(n-1);
        for (int i=0;i<m_high;i++) {
            for (int j=0;j<m_len>>1;j++) {
                triangle[next][i][j]=' ';
            }
        }
        my_copy(triangle[next],triangle[now],m_len>>1,0,m_high);
        my_copy(triangle[next],triangle[now],0,m_high,m_high<<1);
        my_copy(triangle[next],triangle[now],m_len,m_high,m_high<<1);
        exchange();
    }
}

int main(){
    int n;
    scanf("%d",&n);
    high<<=n-1;
    draw(n);
    for(int i=0;i<high;i++){
        printf("%s\n",triangle[now][i]);
    }
    return 0;
}