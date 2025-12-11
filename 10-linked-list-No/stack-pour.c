#include <stdio.h>
#include <stdlib.h>
//这题就纯纯逼人用链表实现栈，淦
int n,m;
typedef struct node{
    int i;
    struct node* next, *prev;
} node;
typedef struct{
    node* head;
    node* top;//正好指结尾
} stack;//0就是结尾
//声明n,m,总共有n个元素，每一个栈的首地址可以用数组存
int pop_node(stack* list) {
    node* now=list->top;
    if (!now) return 0;
    if (now->prev) {
        now->prev->next=now->next;
        if (!now->next) list->top=now->prev;
    }
    else {
        list->head=list->top=NULL;
    }
    int i=now->i;
    free(now);
    return i;
}
stack* init_stack(int i,stack* now){
    now->top=now->head=malloc(sizeof(node));
    now->head->prev=now->head->next=NULL;
    now->head->i=i;
    return now;
}
void add_node(int i, stack* list) {
    if (list->top) {
        node* new=malloc(sizeof(node));
        list->top->next=new;
        new->prev=list->top;
        new->i=i;
        new->next=NULL;
        list->top=new;
    }else {
        init_stack(i, list);
    }
}
void from_to(stack* a,stack* b){
    while(a->top!=NULL){
        add_node(pop_node(a),b);
    }
}
void print(stack* now){
    if(now->top==NULL){
        printf("0\n");
        return;
    }
    for(node* no=now->head;no!=NULL;no=no->next){
        printf("%d",no->i);
        if(no!=now->top) printf(" ");
    }printf("\n");
}
int main(){
    scanf("%d%d",&n,&m);
    stack* stacks=calloc(n+1,sizeof(stack));
    for(int i=1;i<=n;i++){
        init_stack(i,&stacks[i]);
    }
    for(int i=0 ;i < m; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        from_to(&stacks[a],&stacks[b]);
    }
    for(int i=1;i<=n;i++){
        print(&stacks[i]);
        while (stacks[i].top) pop_node(&stacks[i]);
    }
    free(stacks);
    return 0;
}