#include <stdio.h>
#include <stdlib.h>

typedef struct content {
    //内容想放啥放啥
} content;
typedef struct node {
    content content ;
    struct node* next;
}node ;//最基础的链表结点
//链表进阶：双向链表，树，类别检测 等等
typedef struct {
    node* head;
} linked_list;
//链表可用指针的变体：维护尾指针（方便append或pop，类似栈），特殊类别尾指针（特殊查找），可以带长度啥的
//栈、队列这些数据结构如果不用静态的方式写的话，都得用链表
void copy(const content* dest,content source) {

}
void print(content a) {

}
void display(linked_list* this) {
    if (this->head) {
        for (node* now=this->head; now ;now=now->next) {
            print(now->content);
            if (now->next) printf(" ");
        }
    }else {
        printf("(linked_list is null)");
    }
    printf("\n");
}
int get_len(linked_list* this) {
    int count=0;
    for (node* now=this->head; now; now=now->next ) count++;
    return count;
}
void init(linked_list* this,content a) {
    this->head=malloc(sizeof(node));
    this->head->next=NULL;
    copy(&this->head->content,a);
}//初始化链表
void append_node(linked_list* this,content a) {
    if (this->head) {
        node* now;
        for (now=this->head; now->next ; now=now->next) {}
        now->next=malloc(sizeof(now));
        copy(&now->next->content,a);
    }else {
        init(this,a);
    }
}//在最后添加一个内容为a的节点，时间要O(0)
void quick_add_node(linked_list* this, content a) {
    if (this->head) {
        node* now=malloc(sizeof(node));
        copy(&now->content,a);
        now->next=this->head->next;
        this->head->next=now;
    }else {
        init(this,a);
    }
}//插在第head结点后面，时间要O(0)
void insert_node(linked_list* this, int i, content a) {
    if (this->head) {
        int count=1;
        node* new=malloc(sizeof(node)),*now;
        for (now=this->head; now->next && count<i; now=now->next) count++;
        if (i > count) {
            printf("注意！链表长度仅有%d,已添加至链表最后！\n",count);
        }
        new->next=now->next;
        now->next=new;
        copy(&new->content,a);
    }else {
        if (i!=0) printf("注意！链表为空！已新添链表！\n");
        init(this,a);
    }
}//插在第i个结点后面，时间要O(0)
content pop_node(linked_list* this) {
    content a;
    if (this->head) {
        if (this->head->next) {
            node* now;
            for (now=this->head;now->next->next;now=now->next){}
            copy(&a,now->next->content);
            free(now->next);
            now->next=NULL;
        }
        else {
            copy(&a,this->head->content);
            free(this->head);
            this->head=NULL;
        }
    }
    return a;
}//删除最后一个节点并返回值，时间要O(0)
void delete_node(linked_list* this,int i) {
    if (i<=0) {
        printf("索引有误！\n");
        return ;
    }
    if (this->head) {
        if (this->head->next) {
            node* now;
            int count=1;
            for (now=this->head; now->next->next&&count<i-1; now=now->next) count++;
            if (count < i - 1) {
                printf("注意！节点长度只有 %d ，已删除最后一个节点！\n",count+1);
            }
            free(now->next);
            now->next=NULL;
        }else {
            printf("注意！节点长度只有 %d ，已删除最后一个节点！\n",1);
            free(this->head);
            this->head=NULL;
        }
    }
}//删除第i个节点，时间要O(0)
void reverse_node(linked_list* this, int a, int b) {
    int len=get_len(this);
    if (this->head) {
        if (a==b) return;
        if (a<0||a>len||b<0||b>len) {
            printf("索引越界，交换操作失败。正确的索引为：0-%d\n",len);
        }else {
            node *na,*nb,*na_prev,*nb_prev;
            if (a==0) {
                na=this->head;
            }
        }

    }else {
        printf("链表为空，交换操作失败\n");
    }

}
node* search(linked_list* this, content target) {

}//遍历链表查找，时间要O(n)
content get(linked_list* this,int i) {

}//拿到第i个列表的内容
void reverse(linked_list* this) {

}//反转链表
void delete(){

}//删除这个链表，时间要O(n)
void link(linked_list* a,linked_list* b) {

}//链接两个链表，时间要O(len(a))
int main() {
    return 0;
}