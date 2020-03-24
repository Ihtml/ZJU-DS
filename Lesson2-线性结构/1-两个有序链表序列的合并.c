#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
  ElementType Data;
  PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main() {
  List L1, L2, L;
  L1 = Read();
  L2 = Read();
  L = Merge(L1, L2);
  Print(L);
  Print(L1);
  Print(L2);
  return 0;
}

List Merge(List L1, List L2) {
  List L = (List)malloc(sizeof(struct Node));
  List head = L;
  List temp1 = L1->Next;
  List temp2 = L2->Next;
  while (temp1 && temp2) {
    if (temp1->Data < temp2->Data) {
      L->Next = temp1;
      temp1 = temp1->Next;
    } else {
      L->Next = temp2;
      temp2 = temp2->Next;
    }
    L = L->Next;
  }
  if (temp1) {
    L->Next = temp1;
  }
  if (temp2) {
    L->Next = temp2;
  }
  L1->Next = NULL;
  L2->Next = NULL;
  return head;
}