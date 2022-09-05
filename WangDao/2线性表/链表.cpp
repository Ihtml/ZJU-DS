#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>
using namespace std;

const int MaxSize = 50;
typedef struct LNode {   // 定义单链表结点类型
    struct LNode* next;  // 数据域
    int data;            // 指针域
} LNode, *LinkList;

typedef struct DNode {  // 定义双链表结点类型
    int data;  // 数据域
    struct DNode *prior, *next;  // 前驱和后继指针
}DNode, *DLinkList;

// 头插法
LinkList List_HeadInsert(LinkList& L) {  // 逆向建立单链表
    LNode* s;
    int x;
    L = new LNode;  // 创建头结点
    // L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;     // 初始为空链表
    cin >> x;           // 输入结点的值
    while (x != 999) {  // 输入999表示结束
        s = new LNode;
        // s=(LNode*)malloc(sizeof(LNode)); // 创建新结点
        s->data = x;
        s->next = L->next;
        L->next = s;  // 将新结点插入表中 L为头指针
        cin >> x;
    }
    return L;
}

// 尾插法
LinkList List_TailInsert(LinkList& L) {  // 正向建立单链表
    int x;
    L = new LNode;  // 创建头结点
    // L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;   // r为表尾指针
    cin >> x;           // 输入结点的值
    while (x != 999) {  // 输入999表示结束
        s = new LNode;
        // s=(LNode*)malloc(sizeof(LNode)); // 创建新结点
        s->data = x;
        r->next = s;
        r = s;  // r指向新的表尾结点
        cin >> x;
    }
    r->next = NULL;  // 尾结点指针置空
    return L;
}

LNode* GetElem(LinkList L, int i) {
    int j = 1;  // 计数 初始为1
    LNode* p = L->next;  // 第1个结点指针赋给p
    if (i == 0)
        return L;  // 若i等于0 则返回头结点
    if (i < 1)     // 若i无效 则返回NULL
        return NULL;
    while (p && j < i) {  // 从第i个结点开始找 查找第i个结点
        p = p->next;
        j++;
    }
    return p;  // 返回第i个结点的指针，若i大于表长，则返回NULL
}

// 按值查找表结点
LNode *LocateElem(LinkList L, int e){
    LNode *p = L->next;
    while (p!=NULL&&p->data!=e)
        p=p->next;
    return p;
}

// 插入结点
// p=GetElem(L, i-1);
// s->next=p->next;
// p->next=s;

// 前插操作，将*s结点插入到*p之前
// s->next=p->next;
// p->next=s;
// temp=p->data;
// p->data=s->data;
// s->data=temp;

// 删除结点
// p=GetElem(L, i-1);  // 查找删除位置的前驱结点
// q=p->next;  // 令q指向被删除结点
// p->next=q->next;  // 将*q结点从链中断开
// free(q);

// 删除结点 *p，可用删除*p的后继结点操作来实现 
// 即将其后继结点的值赋予其自身 然后删除后继结点
// q=p->next;  // 令q指向*p的后继结点
// p->data=p->next->data;  // 和后继结点交换数据域
// p->next=q->next;  // 将*q结点从链中断开
// free(q);  //  释放后继结点的存储空间
// 时间复杂度O(1)


// 双链表
// 将结点*s插入到结点*p之后
// s->next=p->next;
// p->next->prior=s;
// s->prior=p;
// p->next=s;

int main() {
    LNode* LN;
    List_HeadInsert(LN);
    return 0;
}