## 前提

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



## 时间复杂度下界

- 对于下标**i，如果**A[i]>A[j]**，则称**(i,j)是 一对逆序对(inversion)
- 插入排序：T跟元素个数N和逆序对个数I的关系为：T(N, I) = O(N+1); 如果序列**基本有序**，则插入排序简单且高效；
- 冒泡排序和插入排序，每次循环只能去掉一个逆序对；
- 定理:任意**N**个不同元素组成的序列平均具有 **N** **(** **N** - **1 ) / 4** 个逆序对。
- 定理:任何仅以交换相邻两元素来排序的算法，其平均时间复杂度为  $\Omega$**(** N^2 **)** 。
- 要提高算法效率，必须: 1, 每次消去不止一个逆序对；2，每次交换相隔较远的**2**个元素；



## 希尔排序

定义增量序列Dm > Dm-1 > ... > D1=1,对每个Dk进行“Dk-1”间隔排序(k=m,m-1,...1)

Dk间隔有序的序列，在执行Dk-1间隔排序后，仍然是Dk间隔有序的；

原始希尔排序 Dm = N/2, Dk = (Dk+1) /2

```c
void Shell_Sort(ElementType A[], int N){
  int D, P, tmp, i;
  for( D = N/2; D>0; D/=2){
    for( P = D; P<N; P++){
       tmp = A[p];
      for(i = P; i > D && A[i-D] > tmp; i-=D){
        A[i] = A[i-D]
      }
      A[i] = tmp;
    }
  }
}
```



如果增量元素不互质(没有公约数)，则小增量可能根本不起作用。

**Sedgewick**增量序列：{1,5,9,41,109...}

9✖️4^i - 9✖️2^i + 1 或 4^i -3*2^i + 1

```c
void Shell_Sort(ElementType A[], int N){
  // 用Sedgewick增量序列
  int Si, D, P, i;
  ElementType tmp;
  int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
  for(Si = 0; Sedgewick[Si]>=N; Si++)
    //初始的增量Sedgewick[Si]不能超过待排序列长度
  for(D=Sedgewick[Si]; D>0; D=Sedgewick[++Si]){
    for(P=D; P<N; P++){ // 插入排序
      tmp = A[p];
      for(i=P; i>=D && A[i-D]>tmp; i-=D){
        A[i] = A[i-D];
      }
      A[i] = tmp;
    }
  }
}
```



## 选择排序

```c
void Selection_Sort (ElementType A[], int N){
	for(int i = 0; i < N; i++){
		int MinPostion = ScanForMin(A, i, N-1);
		// 从A[i]到A[N-1]中找最小元，并将其位置赋给MinPosition
		Swap(A[i], A[MinPostion])
		// 将未排序部分最小元换到有序部分的最后位置
	}
}
```

时间复杂度，T=$\theta$(N^2);



## 堆排序

- 算法1

```c
void Heap_Sort(ElementType A[], int N){
	BuildHeap(A); // O(N)  把数组A转换成最小堆
	for(int i = 0; i < N; i++){
		TemA[i] = DeleteMin(A); // O(logN)
	}
  for(int i = 0; i<N; i++){
    A[i] = TmpA[i];
  }
}
```

时间复杂度T(N) = O(N logN)

需要额外O(N)空间，并且复制元素需要时间

- 算法2

```c
void Swap(ElementType *a; ElementType *b){
  ElementType t = *a; *a = *b; *b = t;
}
void PercDown(ElementType A[], int p, int N){
  int Parent, Child;
  ElementType X;
  X = A[p];
  for(Parent=p; (Parent*2+1)<N; Parent=Child){
    Child = Parent*2 +1;
    if( (Child!= N-1) && (A[Child] < A[Child+1]))
      Child++;
    if(X >= A[Child]) break;
    else A[Parent] = A[Child];
  }
  A[Parent] = X;
}
void Heap_Sort (ElementType A[], int N){
	for(int i = N/2; i>=0; i--){
    PercDown(A, i, N) // 向下过滤，建最大堆
  }
  for(int i = N-1; i>0; i--){
    Swap(&A[0], &A[i]); // DeleteMax, A[0]是最大的元素
    PercDown(A, 0, i); // 剩下元素继续调整成最大堆， 0为根节点，i为当前最大堆元素个数
  }
}
```

定理：堆排序处理N个不同元素的随机排列的平均比较次数是：2NlogN - O(N log logN)

虽然堆排序给出最佳平均时间复 杂度，但实际效果不如用 **Sedgewick**增量序列的希尔排序。



## 归并排序

核心：有序子列的归并

```c
// L=左边起始位置 R=右边起始位置 RightEnd=右边终点位置
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd){
  LeftEnd = R -1; // 左边终点位置，前提左右两边挨着
  Tmp = L; // 存放结果的数组的初始位置
  NumElements = RightEnd - L + 1;
  while(L <= LeftEnd && R <= RightEnd){
    if(A[L] <= A[R]) TmpA[Tmp++] = A[L++]
    else TmpA[Tmp++] = A[R++]
    while(L <= LeftEnd){ // 直接复制左边剩下的
      TmpA[Tmp++] = A[L++]
    }
    while(R <= RightEnd){ // 复制右边剩下的
      TmpA[Tmp++] = A[R++]
    }
    for(int i = 0; i < NumElements; i++, RightEnd--)
      A[RightEnd] = TmpA[RightEnd]
  }
}
```

