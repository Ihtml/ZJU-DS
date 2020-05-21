## 1、本文前提

- 排序算法用**void** **X_Sort ( ElementType A[],** **int** **N )**表示；

- 大多数情况下，为简单起见，讨论从小大的整数排序；

- **N**是正整数；

- 只讨论基于**比较**的排序(**> = <** 有定义)；

- 只讨论**内部**排序；（假设内存空间充分大，所有数据都可以一次性导到内存空间里，排序过程在内存空间里一次性完成）

- 要**稳定性**:任意两个相等的数据，排序前后的相对位置不发生改变；

- 没有一种排序是任何情况下 都表现最好的；

  
  
## 冒泡排序

```c
void Bubble_Sort(ElementType A[], int N) {
  for (int p = N - 1; p >= 0; p--) {
    flag = 0;
    for (i = 0; i < p; i++) {
      if (A[i] > A[i + 1]) {
        Swap(A[i], A[i + 1]);
        flag = 1;
      }
    }
  }
  if (flag == 0)
    break;
}
```
最好情况：顺序 T=O(N)
最坏情况：逆序 T=O(N^2)



## 插入排序

想象打扑克牌摸排

```c
void Insertion_Sort(ElementType A[], int N){
  for	(P=1; P<N; P++){
    Tmp = A[p]; // 取下一位
    for(int i =P; i>0 && Tmp <A[i-1]; i--){
      A[i] = A[i-1]; // 移除空位
    }
    A[i] = Tmp; // 落位
  }
}
```

最好情况：顺序 T=O(N)
最坏情况：逆序 T=O(N^2)