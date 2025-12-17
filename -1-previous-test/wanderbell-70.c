#include <stdio.h>
#include <stdlib.h>
int R,C,count;
int locs[10000007][3];//r,c,direction-UDLR
int safe[10000007][2];//is_safe,straight
void refresh(){//将所有的箭头遍历更新
    for(int i=0;i<count;i++){
        int r=locs[i][0],c=locs[i][1],arrow=locs[i][2];
        for(int j=i+1;j<count;j++){
            if(locs[j][0]==r){//同一行
                safe[i][0]=safe[j][0]=1;
                if(arrow==4) safe[i][1]=1;
                if(locs[j][2]==3) safe[j][1]=1;
            }else if(locs[j][1]==c){
                safe[i][0]=safe[j][0]=1;
                if(arrow==2) safe[i][1]=1;
                if(locs[j][2]==1) safe[j][1]=1;
            }
        }
    }
}

int get_all(){
    int sum=0;
    for(int i=0;i<count;i++){
        if(!safe[i][1]){
            if(safe[i][0]){
                sum++;
            }else{
                printf("-1");
                exit(0);
            }
        }
    }
    printf("%d",sum);
}

void read(){//从上往下，从左往右读的
    scanf("%d%d",&R,&C);
    for(int i=R-1;i>=0;i--){
        char s[3003];
        scanf("%s",s);
        for(int j=0;j<C;j++){
            if(s[j]!='.'){
                if(s[j]=='U'){
                    locs[count][2]=1;
                }else if(s[j]=='D'){
                    locs[count][2]=2;
                }else if(s[j]=='L'){
                    locs[count][2]=3;
                }else if(s[j]=='R'){
                    locs[count][2]=4;
                }
                locs[count][0]=i;
                locs[count][1]=j;
                count++;
            }
        }
    }
}

int main(){
    read();
    refresh();
    get_all();
    return 0;
}