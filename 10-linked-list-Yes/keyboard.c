#include <stdio.h>
#include <stdlib.h>
#define CHECKLIST() for(node*now=head;now!=NULL;now=now->next) printf("%c ",now->c); printf("***\n")
#define CHECK(x) printf(">"#x":%d\n",x)
typedef struct node {
    char c;
    struct node *prev,       // 上一个节点
                *next,       // 下一个节点
                *last_same;  // 上一个大小写相同的节点
} node;

node *head=NULL, *last_upper=NULL, *last_lower=NULL, *tail=NULL;
int is_upper(const char c){
    return 'A'<=c&&c<='Z';
}
node* get_node(const char c) {      //在函数里申请新指针就给老子乖乖malloc，复合字面量出函数就死了
    node* now=malloc(sizeof(node));
    now->c=c;
    now->prev=now->next=now->last_same=NULL ;
    return now;
}
void save(const char c){
    if(c=='m'){
        if (last_lower) {
            node* now=last_lower;//要free的话要想办法记住要删除的结点，这块是可以合并优化的
            if (now==head) {
                if (head==tail) tail=NULL;     //由于结点特殊，在删除头节点的时候后面有可能会跟着其他节点，要注意操作
                head=now->next;
                free(now);
                last_lower=NULL;
            }else {
                now->prev->next=now->next;
                if(now==tail){
                    tail=last_lower->prev;
                }else {
                    now->next->prev=now->prev;
                }
                last_lower=now->last_same;
                free(now);
            }
        }
    }else if(c=='M'){
        if (last_upper) {
            node* now=last_upper;
            if (now==head) {
                if (head=tail) tail==NULL;
                head=now->next;
                last_upper=NULL;
                free(now);
            }else{
                now->prev->next=now->next;
                if (now==tail){
                    tail=last_upper->prev;
                }else {
                    now->next->prev=now->prev;
                }
                last_upper=last_upper->last_same;
                free(now);
            }
        }
    }else{
        node* now=get_node(c);
        if(head==NULL){
            now->prev=now->next=now->last_same=NULL;    //头节点总要单独考虑，包括删除
            head=tail=now;c
        }else{
            if (tail) {                                 //在维护tail指针的时候就可以好好用它
                now->prev=tail;
                tail->next=now;
                tail=now;
            }
        }
        if(is_upper(c)){
            now->last_same=last_upper;
            last_upper=now;
        }else{
            now->last_same=last_lower;     //双向链表也要记得管理后继链表的prev哦，不然炸炸炸
            last_lower=now;
        }
    }
}
void print(int K){
    //CHECK(K);
    if (tail) {
        node* now;
        for(now=tail;K>1;K--,now=now->prev){}
        for(;now!=NULL;now=now->next){
            printf("%c",now->c);
        }printf("\n");
    }
}
int main(){
    int Q,K;
    scanf("%d",&Q);
    getchar();
    for(int i=0;i<Q;i++){
        for(char c=getchar();c!='\n';c=getchar()){
            //printf(">%c\n",c);
            if(c=='?'){
                scanf("%d",&K);
                print(K);
            }
            else save(c);
            //CHECKLIST();
        }
    }
    return 0;
}