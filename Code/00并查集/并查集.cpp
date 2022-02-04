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

// 查优化，先找到根节点，再压缩路径
int Find2(int S[], int x){
    int root = x;
    while (S[root] >= 0)
        root = S[root];
    while (root != x) { // 压缩路径
        int t = S[x];  // t指向x的父结点
        S[x] = root;   // x直接挂到根结点下
        x = t;
    }
    return root;
}

// 并优化，小树合并到大树
void Union2(int S[], int Root1, int Root2){
    if (Root1 == Root2) return;
    if(S[Root1] >S[Root2]){  // -1 > -3 Root2结点更多
        S[Root2] += S[Root1];  // 累加结点总数
        S[Root1] = Root2;  // 小树合并到大树
    }else{
        S[Root1] += S[Root2];  // 累加结点总数
        S[Root2] = Root1;  // 小树合并到大树
    }
}

// 判断图的连通分量数,图用邻接矩阵表示 g[5][5]是用二维数组表示的邻接矩阵
int ComponentCount(int g[5][5]){
    int S[5];
    for (int i = 0; i < 5; i++) S[i] = -1;
    // 无向图，遍历上三角部分即可
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            if (g[i][j] > 0) {  // 结点i、j之间有边
                int iRoot = Find2(S, i);
                int jRoot = Find2(S, j);
                if (iRoot != jRoot)  
                    Union2(S, iRoot, jRoot);
            }
        }
    }
    int count = 0;  // 统计有几个连通分量
    for (int i = 0; i < 5; i++)
        if(S[i]<0) count++;
    return count;
}

// 并查集判断是否有环
int hasAcyclic(int g[5][5]){
    int S[5];
    for (int i = 0; i < 5; i++)
        S[i] = -1;
    // 无向图，遍历上三角部分即可
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (g[i][j] > 0) {  // 结点i、j之间有边
                int iRoot = Find2(S, i);  // 找到i所属集合
                int jRoot = Find2(S, j);  // 找到j所属集合
                if (iRoot != jRoot)  // i j不在同一集合，Union
                    Union2(S, iRoot, jRoot);
                else  // i、j原本就在同一个集合，即原本就连通
                    return 1; // 在连通子图中，但凡再多一条边，必有环
            }
        }
    }
    return 0;  // 图中没有环
}