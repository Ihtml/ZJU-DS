typedef struct TreeNode* HuffmanTree;
struct TreeNode {
  int Weight;
  HuffmanTree Left, Right;
};

typedef struct HeapStruct* MinHeap;
struct HeapStruct {
  HuffmanTree Elements;  // 储存元素的数组
  int Size;              // 堆当前元素的个数
  int Capacity;          // 堆最大容量
};

HuffmanTree Huffman(MinHeap H) {
  // 假设H->Size个权值已经存在H->Elements[]->Weight里
  HuffmanTree T;
  BuildMinHeap(H);  // 将H->Elements[]按权值调整为最小值
  for (int i = 1; i < H->Size; i++) {  // 做H->Size-1次合并，最后堆里只有一棵树
    T = malloc(sizeof(struct TreeNode)); // 建立新结点
    T->Left = DeleteMin(H); // 从最小堆中删除一个结点，作为新T的左子结点
    T->Right = DeleteMin(H); // 从最小堆中删除一个结点，作为新T的右子结点
    T->Weight = T->Left->Weight + T->Right->Weight; // 计算新权值
    Insert(H, T); // 将新T插入最小堆
  }
  T = DeleteMin(H);
  return T;
}