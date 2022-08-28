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
    L->next = NULL;  // 初始为空链表
    cin >> x;  // 输入结点的值
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
    LNode* s, *r=L;  // r为表尾指针
    cin >> x;           // 输入结点的值
    while (x != 999) {  // 输入999表示结束
        s = new LNode;
        // s=(LNode*)malloc(sizeof(LNode)); // 创建新结点
        s->data = x;
        r->next = s;
        r=s;     // r指向新的表尾结点
        cin >> x;
    }
    r->next=NULL;  // 尾结点指针置空
    return L;
}

int main() {
    LNode *LN;
    List_HeadInsert(LN);
    return 0;
}