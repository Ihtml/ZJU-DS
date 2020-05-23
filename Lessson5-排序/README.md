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
  for(int D = N/2; D>0; D/=2){
    for(int P = D; P<N; P++){
      int tmp = A[p];
      for(int i = P; i > D && A[i-D] > tmp; i-=D){
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

