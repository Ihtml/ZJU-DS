#include <stdio.h>
typedef int ElementType;    /* 关键词类型用整型 */
typedef struct ListNode *Position, *List;
struct ListNode {
  ElementType Element;
  Position Next;
};
typedef struct HashTbl* HashTable;
struct HashTbl {
  int TableSize;
  List TheLists;
};
struct HashTbl {
  int TableSize;
  List TheLists;
} * H;

Position Find(ElementType Key, HashTable H) {
  Position P;
  int Pos;
  Pos = Hash(Key, H->TableSize); /*初始散列位置*/
  P = H->TheLists[Pos].Next;     /*获得链表头*/
  while (P != NULL && strcmp(P->Element, Key))
    P = P->Next;
  return P;
}