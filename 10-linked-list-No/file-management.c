#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//只用做文件管理的保存类型，不用输出图像性文字
//二叉树，可以做一个特殊链表，记录子文件数与子文件地址
typedef struct node{
    int sub_num;//注意，包括s自己
    char name[20];
    struct node *sub1, *sub2, *father;
}node ;
//关于找爹操作，可以建立一个存放地址的数组和对应的映射
char names[10004][12];
node* nodes[10004], *head;
int count;//存放找表的数据大小
//随后，找祖宗是很线性的，直接向上+1就行
node* search(char* name){
    for(int i=0;i<count;i++){
        if(!strcmp(name,names[i])){
            return nodes[i];
        }
    }
    return NULL;
}
void add_node(char* father, char* name){
    node* now=malloc(sizeof(node));
    if(!strcmp(father,"~~~")){
        head=now;
        head->father=head->sub1=head->sub2=NULL;
    }//__init__
    else{
        node* fa=search(father);
        now->father=fa;
        if(!fa->sub1){
            fa->sub1=now;
        }else{
            fa->sub2=now;
        }
        for(;fa!=NULL;fa=fa->father){
            fa->sub_num++;
        }
    }
    strcpy(now->name,name);
    now->sub_num=1;

    strcpy(names[count],name);
    nodes[count++]=now;
}
void delete_node(node* now, int flag){
    if(now->sub1){
        delete_node(now->sub1, 1);
    }
    if(now->sub2){
        delete_node(now->sub2, 2);
    }
    if(flag==1) now->father->sub1=NULL;
    else if(flag==2) now->father->sub2=NULL;
    free(now);
}
void remove_t(char* name){
    node* now=search(name);
    int now_num=now->sub_num;
    for(node* fa=now->father; fa ; fa=fa->father){
        fa->sub_num-=now_num;
    }
    node* fa=now->father;
    if(fa->sub1 == now) delete_node(now,1);
    else delete_node(now,2);
    //remove一下，其包括其子节点全部消失，想办法free掉
    //那么其以上的所有祖宗都会一下减掉这个节点的sub_num
}
int query(char* name){
    node* now=search(name);
    printf("%d\n",now->sub_num);
    return now->sub_num;
}

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0; i<n; i++){
        char name[20],father[20];
        scanf("%s%s",name,father);
        add_node(father,name);
    }
    for(int i=0; i<q; i++){
        char order[10],name[20];
        scanf("%s%s",order,name);
        if(order[0]=='q'){
            query(name);
        }else if(order[0]=='r'){
//printf("now___remove %s\n",name);
            remove_t(name);
        }
    }
    return 0;
}