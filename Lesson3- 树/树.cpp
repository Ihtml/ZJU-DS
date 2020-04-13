typedef int ElementType;/* ElemType类型根据实际情况而定，这里假设为int */

// 二叉树的链表结构
typedef struct TNode *Position;
typedef Position BinTree; // 二叉树类型
struct TNode{ // 树节点定义
    ElementType Data;
    BinTree Left; // 指向左树
    BinTree Right; // 指向右树
};
