#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHECKLIST(head) for(node* now=head;now;now=now->next) printf("%s ",now->s);printf("\n")
#define CHECK(x) printf(">"#x":%d\n",x)
#define N (m*2)
int m,q;

typedef struct node{
    char* s;
    struct node* next;
}node;

node* hash_heads; 
int flags[1000006];
int hash(char *s){
    int len=strlen(s);
    int ret=0;
    for(int i=0;i<len;i++)ret=(ret+s[i]*(i+1))%N;
    return ret;
}
void init_node(char *s, node* head){
    head->s=malloc(sizeof(char)*(strlen(s)+1));
    strcpy(head->s,s);
    head->next=NULL;
}
void add_node(char *s,node* head){
    node* now=malloc(sizeof(node));
    now->next=head->next;
    head->next=now;
    now->s=malloc(strlen(s)+1);
    strcpy(now->s,s);
}
void free_list(node** head){
    node* next=(*head)->next;
    for(node* now=*head;now;now=next,next=now->next){
        free(now->s);
        free(now);
    }
    *head=NULL;
}
int search(int sign, char* s){
    if (!hash_heads[sign].s) return 0;
    for(node* now=hash_heads+sign;now;now=now->next){
        if(!strcmp(s,now->s)){
            return 1;
        }
    }
    return 0;
}

int main(){
    scanf("%d%d",&m,&q);
    hash_heads=calloc(N,sizeof(node));
    for (int i=0;i<N;i++) {
        hash_heads[i].next=NULL;
        hash_heads[i].s=NULL;
    }
    for(int i=0;i<m;i++){
        char s[1003];
        scanf("%s",s);
        int sign=hash(s);
        //CHECK(sign);
        if(!flags[sign]){
            init_node(s,&hash_heads[sign]);
            flags[sign]=1;                 //状态量的下标不要写错了啊笨蛋
        }else{
            add_node(s,&hash_heads[sign]);
        }
    }
    for(int i=0;i<q;i++){
        char s[1003];
        scanf("%s",s);
        int sign=hash(s);
        //CHECK(sign);
        //CHECKLIST(hash_heads+sign);
        if(search(sign,s)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}