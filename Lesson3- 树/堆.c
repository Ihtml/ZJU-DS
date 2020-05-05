#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
typedef int ElementType; /* ElemType类型根据实际情况而定，这里假设为int */

// 最大堆的创建
typedef struct HeapStruct* MaxHeap;
struct HeapStruct {
  ElementType* Elements;  // 储存元素的数组
  int Size;               // 堆当前元素的个数
  int Capacity;           // 堆最大容量
};

#define MaxData INT_MAX
MaxHeap Create(int MaxSize) {
  MaxHeap H =
      malloc(sizeof(struct HeapStruct));  // 创建容量为MaxSize的空的最大堆
  H->Elements = malloc((MaxSize + 1) * sizeof(ElementType));
  H->Size = 0;
  H->Capacity = MaxSize;
  H->Elements[0] =
      MaxData;  // 定义“哨兵”为大于堆中所有可能的元素的值，便于以后更快操作
  return H;
}
bool isFull(MaxHeap H) {
  return H->Size >= H->Capacity;
}
bool isEmpty(MaxHeap H) {
  return H->Size == 0;
}
void Insert(MaxHeap H, ElementType item) {
  if (isFull(H)) {
    printf("最大堆已满");
    return;
  }
  int i = ++H->Size;  // i指向插入后堆中的最后一个元素的位置
  for (; H->Elements[i / 2] < item; i /= 2) {
    H->Elements[i] = H->Elements[i / 2];  // 向下过滤节点
  }
  H->Elements[i] = item;  // 将item 插入
}

// 最大堆的删除,从最大堆H中取出键值为最大的元素，并删除一个结点
ElementType DeleteMax(MaxHeap H) {
  int Parent, Child;
  ElementType MaxItem, temp;
  if (isEmpty(H)) {
    printf("最大堆已空");
    return;
  }
  MaxItem = H->Elements[1];  // 取出根节点最大值
  // 用最大堆中最后一个元素从根节点开始向上过滤下层节点
  temp = H->Elements[H->Size--];
  for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
    Child = Parent * 2;
    if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1])) {
      Child++;  // Child指向左右子节点的较大者
    }
    if (temp >= H->Elements[Child]) {
      break;
    } else {
      H->Elements[Parent] = H->Elements[Child];
    }
  }
  H->Elements[Parent] = temp;
  return MaxItem;
}