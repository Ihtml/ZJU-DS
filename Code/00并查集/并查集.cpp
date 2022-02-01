#define SIZE 20
int UFSets[SIZE]; // 集合元素数组

// 初始化并查集
void Initial(int S[]){
    for (int i = 0; i < SIZE; i++)
        S[i] = -1;
}

// Find 查操作，找x所属集合，返回x所属结点
int Find(int S[], int x){
    while (S[x] >= 0)  // 循环寻找x的根
        x = S[x];
    return x;  // 根的S[]小于0
}

// Union 并操作，将两个集合合并为一个
void Union(int S[], int Root1, int Root2){
    // 要求Root1与Root2是不同的集合
    if (Root1 == Root2)  return;
    // 将根Root2连接到另一个根Root1下面
    S[Root2] = Root1;
}


