typedef int ElementType; /* ElemType类型根据实际情况而定，这里假设为int */
typedef int SetName; /* 默认用根结点的下标作为集合名称 */
#define MAXN 1000

// 树的每个节点代表一个集合元素,指向其父亲（双亲表示法）
typedef struct {
  ElementType Data;
  int Parent;  // 用-N表示，N为该集合元素的个数
} SetType;

ElementType Find(SetType S[], ElementType X) {
  int i;
  for (i = 0; i < MAXN && S[i].Data != X; i++)
    ;
  if (i >= MAXN)
    return -1;  // 未找到X元素，返回-1
  for (; S[i].Parent >= 0; i = S[i].Parent)
    ;
  return i; // 找到X所属的集合，返回树根节点在数组S中的下标
}

void Union(SetType S[], ElementType Root1, ElementType Root2) {
  ElementType Root1, Root2;
  Root1 = Find(S, Root1);
  Root2 = Find(S, Root2);
  if (S[Root2].Parent < S[Root1].Parent) { // 集合2的元素个数更多
    S[Root2].Parent += S[Root1].Parent;  // 集合1并入集合2
    S[Root1].Parent = Root2;
  } else {
    S[Root1].Parent += S[Root2].Parent;
    S[Root2].Parent = Root1;
  }
}
