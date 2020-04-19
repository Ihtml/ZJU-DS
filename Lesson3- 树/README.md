## 1、树的定义 

当根据某个给定元素K，从集合中查找相同元素时，如果集合是连续切有序的，可以使用二分查找算法：

 ```c
int BinarySearch(StaticTable* Tbl, ElementType K) {
  int left, right, mid, NoFound = -1;
  left = 1;
  right = Tbl->Length;
  while (left <= right) {
    mid = (left + right) / 2;
    if (K < Tbl->Element[mid])
      right = mid - 1;
    else if (K > Tbl->Element[mid])
      left = mid + 1;
    else
      return mid;
  }
  return NotFound;
}
 ```

二分查找算法的时间复杂度为O(logN)；

11个元素的二分查找判定树

![](https://raw.githubusercontent.com/Ihtml/images/master/img/20200412162800.png)

- 判定树上每个**结点**需要的查找次数刚好 为该结点所在的**层数**;

- 查找成功时**查找次数**不会超过判定树的**深度**；

- n个结点的判定树的深度 为[log2n]+1.

- 平均查找次数：ASL = (4*4+4*3+2*2+1)/11 = 3

  

**树**(Tree): n(n≥0)个结点构成的有限集合。 当n=0时，称为**空树**;
 对于任一棵**非空树**(n> 0)，它具备以下性质:

- 树中有一个称为“**根(Root)**”的特殊结点，用 r 表示;
- 其余结点可分为m(m>0)个**互不相交的**有限集T1，T2，... ，Tm，其 中每个集合本身又是一棵树，称为原来树的“**子树**(SubTree)”
- 子树是**不相交**的;
- 除了根结点外，**每个结点有且仅有一个父结点**;
- 一棵N个结点的树有**N-1条边**。



树的一些基本术语：

1. **结点的度**(Degree):结点的**子树个数**；

2. **树的度**:树的所有结点中最大的度数；

3. **叶结点**(Leaf):度为0的结点；

4. **父结点**(Parent):有子树的结点是其子树的根结点的父结点；

5. **子结点**(Child):若A结点是B结点的父结点，则称B结点是A结点的子结点;子结点也称孩子结点。

6. **兄弟结点**(Sibling):具有同一父结点的各结点彼此是兄弟结点。

7. **路径和路径长度**:从结点n1到nk的路径为一 个结点序列n1 , n2 ,... , nk , ni是 ni+1的父结 点。路径**所包含边的个数**为路径的长度。

8. **祖先结点**(Ancestor):沿树根到某一结点路径上的所有结点都是这个结点的祖先结点。

9. **子孙结点**(Descendant):某一结点的子树 中的所有结点是这个结点的子孙。

10. **结点的层次**(Level):规定根结点在1层， 其它任一结点的层数是其父结点的层数加1。

11. **树的深度**(Depth):树中所有结点中的**最 大层次**是这棵树的深度。

    

## 2、二叉树

二叉树是一个**有穷的结点集合**，这个集合可以为空，若不为空，则它是由根结点和称为其左子树TL和右子树TR的，**两个不相交的二叉树组成**。

每个节点都有两个指针，一个指向左边，一个指向右边，每个节点最多有两个儿子(度为2)。

**完美二叉树**(Perfect Binary Tree)又叫**满二叉树**(Full Binary Tree)：每一层的节点数，都是上一层节点数的两倍。

**完全二叉树** (Complete Binary Tree)：有n个结点的二叉树，对树中结点按 从上至下、从左到右顺序进行编号， 编号为i(1 ≤ i ≤ n)结点与满二叉树 中编号为 i 结点在二叉树中位置相同。（完全二叉树可以少掉最后几个叶节点。）



二叉树的几个**重要性质：**

- 一个二叉树第 i 层的最大结点数为:**2 i-1，i >= 1**。
- 深度为k的二叉树有最大结点总数为: **2 k-1，k >=1**。
- 对任何非空二叉树 T，若**n0**表示叶结点的个数、**n2**是度为2的非叶结点个数，那么两者满足关系**n0 = n2 +1**。



二叉树的**链式储存结构**：

```c
typedef struct TNode *Position;
typedef Position BinTree; // 二叉树类型
struct TNode{ // 树节点定义
    ElementType Data;
    BinTree Left; // 指向左树
    BinTree Right; // 指向右树
};
```



**二叉树的遍历**：

核心问题：**二维结构的线性化**
 从一个结点访问其左、右儿子结点时，访问左儿子后，右儿子结点怎么办?

需要**一个存储结构保存暂时不访问的结点**。（存储结构:堆栈、队列）

1. 递归实现

- 先序遍历 先访问根节点，再对左边递归，再对右边递归

  ```c
  void PreOrderTraversal(BinTree BT) {
    if (BT) {
      printf("%d", BT->Data);
      PreOrderTraversal(BT->Left);
      PreOrderTraversal(BT->Right);
    }
  }
  ```

  

- 中序遍历 先递归访问左子树，再访问根节点，再遍历右子树

  ```c
  void InOrderTraversal(BinTree BT) {
    if (BT) {
      PreOrderTraversal(BT->Left);
      printf("%d", BT->Data);
      PreOrderTraversal(BT->Right);
    }
  }
  ```

  

- 后序遍历 先递归遍历左边，再遍历右边，最后根节点

  ```c
  void PostOrderTraversal(BinTree BT) {
    if (BT) {
      PreOrderTraversal(BT->Left);
      PreOrderTraversal(BT->Right);
      printf("%d", BT->Data);
    }
  }
  ```

  

2. **非递归遍历**（使用**堆栈**）：

- 先序

  ```c
  void PreOrderTraversal(BinTree BT) {
    BinTree T = BT;
    Stack S = CreatStack(MaxSize);
    while (T || !IsEmpty(S)) {
      while (T) {
        printf("%5d", T->Data);
        Push(S, T);
        T = T->Left;
      }
      if (!IsEmpty(S)) {
        T = Pop(S);
        T = T->Right;
      }
    }
  }
  ```

  

- 中序

  ```c
  void InorderTraversal(BinTree BT) {
    BinTree T = BT;
    Stack S = CreatStack(MaxSize);
    while (T || !IsEmpty(S)) {
      while (T) {
        Push(S, T);
        T = T->Left;
      }
      if (!IsEmpty(S)) {
        T = Pop(S);
        printf("%5d", T->Data);
        T = T->Right;
      }
    }
  }
  ```

  

- 后序

  ```c
  void PostOrderTraversal(BinTree BT) {
    BinTree T = BT, P = NULL; // P为上一个访问的节点
    Stack S = CreatStack(MaxSize);
    while (T || !IsEmpty(S)) {
      Push(S, T);
      T = T->Left;
    }
    if (!IsEmpty(S)) {
      T = Pop(S);
      if (T->Right == NULL || T->Right == P) {
        // 右节点不存在或右节点已访问，弹出节点
        printf("%5d", T->Data);
        P = T; // P指向当前被访问的节点
        T = NULL;
      } else {
        Push(T); // 如果有右节点，该节点再次入栈
        T = T->Right; // 继续遍历右树
      }
    }
  }
  ```

  

3. 层序遍历（使用队列）

   **队列实现**:遍历从根结点开始，首先将根结点入队，然后开始执行循环:结点出队、访问该结点、其左右儿子入队。

   1. 从队列中取出一个元素;
   2. 访问该元素所指结点;
   3. 若该元素所指结点的左、右孩子结点非空，则将其左右节点的指针顺序入队。

   ```c
   void LevelOrderTraversal(BinTree BT) {
     Queue Q;
     BinTree T;
     if (!BT)
       return;
     Q = CreatQueue(MaxSize);
     AddQ(Q, BT);
     while (!IsEmptyQ(Q)) {
       T = DeleteQ(Q);
       printf("%5d", T->Data);
       if (T->Left) {
         AddQ(Q, T->Left);
       }
       if (T->Right) {
         AddQ(Q, T->Right);
       }
     }
   }
   ```



4. 由两种遍历序列确定二叉树

   必须要有中序遍历，和其他一种遍历才能确定第三种遍历序列

   - 先序和中序遍历序列来确定一棵二叉树
     1. 根据**先序**遍历序列第一个结点确定**根结点;**
     2. 根据根结点在**中序遍历序列**中分割出左右两个子序列
     3. 对**左子树和右子树分别递归**使用相同的方法继续分解
   - 后序和中序遍历序列确定一棵二叉树
     1. 根据**后序**遍历序列最后一个结点确定**根结点**;
     2. 根据根结点在**中序遍历序列**中分割出左右两个子序列
     3. 对**左子树和右子树分别递归**使用相同的方法继续分解
