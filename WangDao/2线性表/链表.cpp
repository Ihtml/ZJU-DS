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

int main() {
    LNode* LN;
    List_HeadInsert(LN);
    return 0;
}