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

// 栈的顺序存储类型
typedef struct {
    int data[MaxSize];  // 存放栈中元素
    int top;  // 栈顶指针  初始时设置s.top=-1; 栈顶元素：s.data[s.top]
} SqStack;

typedef struct Linknode {
    int data;               // 数据域
    struct Linknode* next;  // 指针域
} * LiStack;                // 栈类型定义

// 初始化
void InitStack(SqStack& S) {
    S.top = -1;
}
// 判栈空
bool StackEmpty(SqStack S) {
    if (S.top == -1)  // 栈空
        return true;
    else  // 不空
        return false;
}
// 进栈
bool Push(SqStack& S, int x) {
    if (S.top == MaxSize - 1)  // 栈满 报错
        return false;
    S.data[++S.top] = x;  // 指针先加1
    return true;
}
// 出栈
bool Pop(SqStack& S, int& x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top--];  // 先出栈 指针再减一
    return true;
}

// 读栈顶元素
bool GetTop(SqStack S, int& x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
}

#include <stack>
bool BracketsCheck(string str) {
    stack<char> S;
    int i = 0;
    while (i < str.length()) {
        switch (str[i]) {
            // 左括号入栈
            case '(':
                S.push('(');
                break;
            case '[':
                S.push('[');
                break;
            case '{':
                S.push('{');
                break;
            // 遇到右括号 检测栈顶
            case ')':
                if (S.top() != '(')
                    return false;
                break;
            case ']':
                if (S.top() != '[')
                    return false;
                break;
            case '}':
                if (S.top() != '{')
                    return false;
                break;
            default:
                break;
        }
        i++;
    }
    if (S.size() != 0) {
        cout << "括号不匹配" << endl;
        return false;
    } else {
        cout << "括号匹配" << endl;
        return true;
    }
}

typedef struct LNode {   // 定义单链表结点类型
    struct LNode* next;  // 数据域
    int data;            // 指针域
} LNode, *LinkList;
// 判断链表是否中心对称
int dc(LinkList L, int n) {
    int i, s[n / 2];
    LinkList p = L->next;
    for (i = 0; i < n / 2; i++) {
        s[i] = p->data;
        p = p->next;
    }
    i--;               // 恢复最后的i值
    if (n % 2 == 1) {  // 若n是奇数 后移过中心结点
        p = p->next;
    }
    while (p != NULL && s[i] == p->data) {  // 检测是否中心对称
        i--;                                // i充当栈顶指针
        p = p->next;
    }
    if (i == -1) {  // 栈为空栈
        return 1;   // 链表中心对称
    } else {
        return 0;  // 链表不中心对称
    }
}

// 共享空间的两个栈，栈底设在向量两端，初始时，s1栈顶指针为-1
// s2栈顶指针为maxsize 两个栈顶指针相邻时为栈满
// 两个栈顶相向、迎面增长，栈顶指针指向栈顶元素
const int maxsize = 100;
typedef struct {
    int stack[maxsize];  // 栈空间
    int top[2];          // top为两个栈顶指针
} stk;
stk s;  // s是如上定义的结构类型变量 为全局变量

int stk_push(int i, int x) {
    if (i < 0 || i > 1) {
        cout << "栈号输入不对";
        exit(0);
    }
    if (s.top[1] - s.top[0] == 1) {
        cout << "栈已满";
        return 0;
    }
    switch (i) {
        case 0:
            s.stack[++s.top[0]] = x;
            return 1;
            break;
        case 1:
            s.stack[--s.top[1]] = x;
            return 1;
    }
}

int stk_pop(int i) {
    // 退栈算法 i表示栈号 i=0表示s1栈 i=1时为s2栈
    // 退栈成功返回退栈元素 否则返回-1
    if (i < 0 || i > 1) {
        cout << "栈号输入不对";
        exit(0);
    }
    switch (i) {
        case 0:
            if (s.top[0] == -1) {
                cout << "栈空";
                return -1;
            } else {
                return s.stack[s.top[0]--];
            }
            break;
        case 1:
            if (s.top[1] == maxsize) {
                cout << "栈空";
                return -1;
            } else {
                return s.stack[s.top[1]++];
            }
            break;
    }
}