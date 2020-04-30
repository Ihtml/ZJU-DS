#include <stdio.h>
#include <limits.h>
typedef int ElementType; /* ElemType类型根据实际情况而定，这里假设为int */

// 最大堆的创建
typedef struct HeapStruct *MaxHeap;
struct HeapStruct
{
    ElementType *Elements; // 储存元素的数组
    int Size; // 堆当前元素的个数
    int Capacity; // 堆最大容量
};

#define MaxData INT_MAX
MaxHeap Create(int MaxSize){
    MaxHeap H = malloc(sizeof (struct HeapStruct));  // 创建容量为MaxSize的空的最大堆
    H->Elements = malloc((MaxSize+1) * sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MaxData; // 定义“哨兵”为大于堆中所有可能的元素的值，便于以后更快操作
    return H;
}
