#include <stdio.h>
#define maxn 3
int val[maxn],map[maxn][maxn];

int is_para(int r1,int c1,int r2,int c2){
    if((r1||c1)&&(r2||c2)){//不重合
        if(r1*c2==r2*c1){
            return 1;
        }return 0;
    }
    return 1;
}//判断向量，传入的时候记得相减

int proceed(){
    int max=0;
    for(int i=0;i<9;i++){//横坐标为i%3，纵坐标为i//3
        int ra=i/3,ca=i%3;
        for(int j=0;j<9;j++){
            int rb=j/3,cb=j%3;
            for(int k=0;k<9;k++){
                int rc=k/3,cc=k%3;
                if(!is_para(rb-ra,cb-ca,rc-rb,cc-cb)){
                    int res=val[0]*map[ra][ca]+val[1]*map[rb][cb]+val[2]*map[rc][cc];
                    if(res > max) {
                        //printf("(%d,%d):%d (%d,%d):%d (%d,%d):%d \n",ra,ca,val[0],rb,cb,val[1],rc,cc,val[2]);
                        max=res;
                    }
                }
            }
        }
    }
    return max;
}//遍历

int main(){
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            scanf("%d",*(map+i)+j);
        }
    }
    for(int i=0;i<maxn;i++) scanf("%d",val+i);//读入数据
    printf("%d",proceed());

    return 0;
}