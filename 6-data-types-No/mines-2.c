#include <stdio.h>
#define CHECK(x) printf(">"#x":%d\n",x)
//把*弄成7，?弄成-1输入到地图里面（不用初始化了就）
int map[606][606][606],n,loc[3],is7=1;
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

int is_num(int m){
    return 0<=m&&m<=6;
}
int is_in(int m) {
    return 1<=m&&m<=n;
}
int get_num(){
    int count=0;
    for(int o=0;o<6;o++){
        if(map[loc[0]+dx[o]][loc[1]+dy[o]][loc[2]+dz[o]]==7) count++;
    }
    return count;
}
int get_no() {
    int count=0;
    for(int o=0;o<6;o++){
        if(!is_in(loc[0]+dx[o])||!is_in(loc[1]+dy[o])||!is_in(loc[2]+dz[o])) count++;
    }
    return count;
}
int is_right(int i,int j,int k){
    int count=0;
    if(map[i][j][k]==7) return 1;
    if(!is_in(i)||!is_in(j)||!is_in(k)) return 1;
    for(int o=0;o<6;o++){
        if(map[i+dx[o]][j+dy[o]][k+dz[o]]==7) count++;
        if(map[i+dx[o]][j+dy[o]][k+dz[o]]==-1) return 2;
    }
    return count==map[i][j][k];
}
int is_other_valid(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(is_num(map[i][j][k])){
                    if(is_right(i,j,k)==2) continue;
                    if(is_right(i,j,k)==0) return 0;
                }
            }
        }
    }
    return 1;
}
int is_query_valid(){
    map[loc[0]][loc[1]][loc[2]]=7;
    int right=1;
    for(int i=0;i<6;i++){
        right&=is_right(loc[0]+dx[i],loc[1]+dy[i],loc[2]+dz[i]);
    }
    if(!right||get_num()+get_no()==6){
        is7=0;
        map[loc[0]][loc[1]][loc[2]]=9;
        right=1;
        for(int i=0;i<6;i++){
            right&=is_right(loc[0]+dx[i],loc[1]+dy[i],loc[2]+dz[i]);
        }
        if(!right) return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                char c;
                scanf("%c",&c);
                if(c=='*') map[i][j][k]=7;
                else if(c=='?'){
                    map[i][j][k]=-1;
                    loc[0]=i;loc[1]=j;loc[2]=k;
                }else map[i][j][k]=c-'0';
            }
        }
    }
    if(is_query_valid()&&is_other_valid()){
        printf("valid\n");
        if(is7==1) printf("*\n");
        else printf("%d\n",get_num());
    }else{
        printf("invalid\n");
        map[loc[0]][loc[1]][loc[2]]=7;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(is_num(map[i][j][k])){
                        if(is_right(i,j,k)==0) printf("%d %d %d\n",i,j,k);
                    }
                }
            }
        }
    }
    return 0;
}