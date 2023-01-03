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

typedef struct DNode {           // 定义双链表结点类型
    int data;                    // 数据域
    struct DNode *prior, *next;  // 前驱和后继指针
} DNode, *DLinkList;

// 静态链表  以next==-1作为其结束的标志
typedef struct {
    int data;
    int next;  // 下一个元素的数组下标
} SLinkList[MaxSize];

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
    int j = 1;           // 计数 初始为1
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
LNode* LocateElem(LinkList L, int e) {
    LNode* p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
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

// 删除操作
// p->next = q->next;
// q->next->prior=p;
// free(q);

// 递归实现在单链表L中删除值为x的结点
void Del_X_3(LinkList& L, int x) {
    LNode* p;
    if (L == NULL) {
        return;
    }
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);
        Del_X_3(L, x);
    } else {
        Del_X_3(L->next, x);
    }
}

// 非递归删除带头结点的单链表中所有值为x的结点
void Del_X_1(LinkList& L, int x) {
    LNode *p = L->next, *pre = L, *q;
    while (p != NULL) {
        if (p->data == x) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}

// 尾插法建立单链表 用P扫描L的所有结点 当其值不为x时 将其链接到L之后
// 否则将其释放
void Del_X_2(LinkList& L, int x) {
    LNode *p = L->next, *r = L, *q;  // r指向尾结点 初值为头结点
    while (p != NULL) {
        if (p->data != x) {
            r->next = p;  // L->next = p; 尾插法
            r = p;
            p = p->next;
        } else {  // p结点为x时将其释放
            q = p;
            p = p->next;
            free(q);
        }
        r->next = NULL;
    }
}

// 递归从尾到头输出单链表L中每个结点的值
void R_Print(LinkList L) {
    if (L->next != NULL) {
        R_Print(L->next);
    }
    if (L != NULL) {
        cout << L->data;
    }
}
void R_Ignore_Head(LinkList L) {
    if (L->next != NULL) {
        R_Print(L->next);
    }
}

// 删除带头结点的单链表的最小值结点
LinkList Delete_Min(LinkList& L) {
    LNode *pre = L, *p = pre->next;  // p为工作指针 pre指向其前驱
    LNode *minpre = pre, *minp = p;  // 保存最小值结点及其前驱
    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
    return L;
}

LinkList reverse_2(LinkList L) {
    // 依次遍历线性表L， 并将结点指针反转
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL;
    while (r != NULL) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
    return L;
}
// 头插法逆置单链表
LinkList reverse_1(LinkList L) {
    // 依次遍历线性表L， 并将结点指针反转
    LNode *p, *r;
    p = L->next;
    L->next = NULL;
    while (p != NULL) {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L;
}

void LinkListSort(LinkList& L) {
    LNode *p = L->next, *pre;
    LNode* r = p->next;  // r保持*p后继结点指针 以保证不断链
    p->next = NULL;
    p = r;
    while (p != NULL) {
        r = p->next;
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;  // 有序表中查找插入*p的前驱结点*pre
        p->next = pre->next;  // 将*p插入到*pre之后
        pre->next = p;
        p = r;  // 扫描原单链表中剩下的结点
    }
}
void RangeDelete(LinkList& L, int min, int max) {
    LNode *pre = L, *p = L->next;
    while (p != NULL) {
        if (p->data > min && p->data < max) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

// 找两个单链表的第一个公共结点
LinkList Search_1st_Common(LinkList L1, int len1, LinkList L2, int len2) {
    LinkList longList, shortList;
    int dist;
    if (len1 > len2) {
        longList = L1->next;
        shortList = L2->next;
        dist = len1 - len2;
    } else {
        longList = L2->next;
        shortList = L1->next;
        dist = len2 - len1;
    }
    while (dist--) {
        longList = longList->next;
    }
    while (longList != NULL) {
        if (longList == shortList) {
            return longList;
        } else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;
}

// 将A表中结点按序号的奇偶性分解到表A或表B中
LinkList DisCreat_1(LinkList& A) {
    int i = 0;
    LinkList B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra = A, *rb = B, *p;
    p = A->next;
    A->next = NULL;
    while (p != NULL) {  // 尾插法，
        i++;
        if (i % 2 == 0) {
            rb->next = p;
            rb = p;
        } else {
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}
LinkList DisCreat_2(LinkList& A) {
    LinkList B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra = A, *p, *q;
    p = A->next;
    while (p != NULL) {  // 头插法
        ra->next = p;
        ra = p;
        p = p->next;
        if (p != NULL) {
            q = p->next;
            p->next = B->next;
            B->next = p;
            p = q;
        }
    }
    ra->next = NULL;
    return B;
}

// 删除递增有序的单链表中数值相同的元素
void Del_Same(LinkList& L) {
    LNode *p = L->next, *q;
    if (p == NULL) {
        return;
    }
    while (p->next != NULL) {
        q = p->next;
        if (p->data == q->data) {
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
}

// 合并两个递增有序链表（带头结点），并使合并后的链表递减排列
void MergeListReverse(LinkList& La, LinkList& Lb) {
    LNode *r, *pa = La->next, *pb = Lb->next;
    La->next = NULL;  // La做结果链表的头指针
    while (pa && pb) {
        if (pa->data <= pb->data) {
            r = pa->next;
            pa->next = La->next;  // 头插法
            La->next = pa;
            pa = r;
        } else {
            r = pb->next;
            pb->next = La->next;
            La->next = pb;
            pb = r;
        }
    }
    if (pa) {
        pb = pa;
    }
    while (pb) {
        r = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = r;
    }
    free(Lb);
}

// 产生单链表A和B的公共元素的单链表
void Get_Common(LinkList A, LinkList B) {
    LNode *p = A->next, *q = B->next, *r, *s;
    LinkList C = (LinkList)malloc(sizeof(LNode));
    r = C;
    while (p != NULL && q != NULL) {
        if (q->data < p->data) {
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else {  // 找到公共元素结点
            s = (LNode*)malloc(sizeof(LNode));
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
}

// 对两个链表进行归并扫描，只有同时出现在两个集合中的元素才能链接到结果表且仅保留一个
LinkList Union(LinkList& la, LinkList& lb) {
    LinkList pa = la->next;
    LinkList pb = lb->next;
    LinkList pc = la, u;
    while (pa && pb) {
        if (pa->data == pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
            free(u);
        } else if (pa->data < pb->data) {
            u = pa;
            pa = pa->next;
            free(u);
        } else {
            u = pb;
            pb = pb->next;
            free(u);
        }
    }
    while (pa) {
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb) {
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = NULL;
    free(lb);
    return la;
}

int main() {
    LNode* LN;
    List_HeadInsert(LN);
    return 0;
}