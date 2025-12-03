#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b){
    return strcmp((char*)a,(char*)b);
}
int main(){
    char str[10004], aft[100][101], split;
    int now=0;
    scanf("%s\n%c",str,&split);
    char *start=str;
    for(char* loc=str;*loc!='\0';loc++){
        if(*loc==split){
            *loc='\0';
            strcpy(aft[now++],start);
            start=loc+1;
        }
    }strcpy(aft[now++],start);
    qsort(aft,now,101*sizeof(char),cmp);
    for (int i=0;i<now;i++) {
        printf("%s\n",aft[i]);
    }
    return 0;
}