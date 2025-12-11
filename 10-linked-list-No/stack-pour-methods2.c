//这个做法更适合喜欢链表且熟练链表的宝宝
#include <stdio.h>
#include <stdlib.h>

int n, m;
typedef struct node {
    int data;
    struct node* next;
} Node;
typedef struct {
    Node* top;  // 只需要栈顶指针
} Stack;
// 简化版链表栈实现
void push(Stack* s, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(Stack* s) {
    if (s->top == NULL) return -1; // 栈空

    Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

void move_stack(Stack* from, Stack* to) {
    // 直接反转链表连接，O(1)时间复杂度
    if (from->top == NULL) return;

    // 找到from栈的底部
    Node* bottom = from->top;
    while (bottom->next != NULL) {
        bottom = bottom->next;
    }

    // 连接两个栈
    bottom->next = to->top;
    to->top = from->top;
    from->top = NULL;  // 清空from栈
}

void print_stack(Stack* s) {
    if (s->top == NULL) {
        printf("0\n");
        return;
    }

    // 临时反转打印（或者用数组暂存）
    int arr[1000]; // 根据n的大小调整
    int count = 0;
    Node* current = s->top;

    while (current != NULL) {
        arr[count++] = current->data;
        current = current->next;
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%d", arr[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
}