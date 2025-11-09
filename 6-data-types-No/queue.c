#include <stdio.h>

int queue[10004],start=0,end=0;

int main(){
    char order[10];
    int n;
    for(scanf("%d",&n);n>0;n--){
        scanf("%s",order);
        switch(order[0]){
            case 'I':
                scanf("%d",&queue[end++]);
                break;
            case 'O':
                printf("%d\n",queue[start++]);
                break;
            case 'C':
                printf("%d [",end-start);
                for(int i=start;i<end;i++){
                    printf("%d",queue[i]);
                    if(i!=end-1) printf(",");
                }printf("]\n");
                break;
            default: break;
        }
    }
    return 0;
}