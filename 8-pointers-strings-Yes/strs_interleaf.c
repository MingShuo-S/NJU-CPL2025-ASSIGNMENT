#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CHECK(x) printf(">"#x":%d\n",x)
int ds1,ds2,size;
char* interleaveString(char* s1,char* s2){
    int loc1=0,loc2=0,i=0,d1=strlen(s1),d2=strlen(s2);
    char* s3=(char*)malloc(size*sizeof(char));
    while (i<size&&(loc1<d1||loc2<d2)) {
        for (int j=0;j<ds1&&loc1<d1&&i<size;j++) s3[i++]=s1[loc1++];
        for (int j=0;j<ds2&&loc2<d2&&i<size;j++) s3[i++]=s2[loc2++];
    }s3[i]='\0';
    return s3;
}
int main(){
    int T;
    char s1[1003],s2[1003];
    for(scanf("%d",&T);T>0;T--){;
        scanf("\n%[^;];%[^;];%d;%d;%d",s1,s2,&ds1,&ds2,&size);
        size--;
        char* s3=interleaveString(s1,s2);
        printf("%s\n",s3);
        free(s3);
    }
    return 0;
}