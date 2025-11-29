#include <stdio.h>
#include <stdlib.h>
char *a,*b;
int is_right(int loc){
    for(int i=0;*(b+i)!='\0';i++){
        if(*(a+loc+i)!=*(b+i)) return 0;
    }
    return 1;
}
int main(){
    a=malloc(sizeof(char)*100005);
    b=malloc(sizeof(char)*100005);
    scanf("%s",a);
    scanf("%s",b);
    for(int i=0;*(a+i)!='\0';i++){
        if(is_right(i)) printf("%d ",i);
    }
    free(a);
    free(b);
    return 0;
}