#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>

using namespace std;
typedef struct find {  // 查找表的数据结构
    int* elem;  // 元素存储空间基址，建表时按实际长度分配，0号单元留空
    int TableLen;
} SSTable;
int Search_Seq(SSTable ST, int key) {
    ST.elem[0] = key;  // 哨兵
    int i;
    for (i = ST.TableLen; ST.elem[i] != key; --i)
        ;
    return i;
}

int Binary_Search(SSTable L, int key) {
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.elem[mid] == key) {
            return mid;
        } else if (L.elem[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}